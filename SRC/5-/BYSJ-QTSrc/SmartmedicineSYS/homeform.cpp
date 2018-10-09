#include "homeform.h"
#include "ui_homeform.h"

homeForm::homeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homeForm)
{
    ui->setupUi(this);
    this->hide();

    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);
    this->setWindowTitle(QString::fromLocal8Bit("设备信息"));
    //风扇开关
    button1 = new SwitchButton(this);
    button1->setGeometry(rect().x()+315, rect().y()+265,60, 25);
    button1->setParent(this);
    button2 = new SwitchButton(this);
    button2->setGeometry(rect().x()+705, rect().y()+265,60, 25);
    button2->setParent(this);

    connect(button1,SIGNAL(checkedChanged(bool)),this,SLOT(button1CheckHandle(bool)));
    connect(button2,SIGNAL(checkedChanged(bool)),this,SLOT(button2CheckHandle(bool)));

    sensorflag0 = false;
    sensorflag1 = false;
    sensorflag2 = false;
    sensorflag3 = false;
    sensorflag4 = false;
    tempdwThresholdValue = 18;
    tempupThresholdValue = 35;
    humiThresholdValue = 60;

    tempdata = new SensorRevData();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(changeStatus()));
    timer->start(10000);
}

homeForm::~homeForm()
{
    delete ui;
}

void homeForm::reveiceData(QByteArray sensorData)
{
    this->updataValue(sensorData.mid(9,8));
    if(saveDatatoList(sensorData))
    {
       qDebug()<<"SEVE TO LIST SUCCESS";
    }
}

void homeForm::updataValue(QByteArray sensorData)
{
    QString sensorStr;
    double tempData;
    switch((quint8)sensorData[1])
    {
        case DEVICE_HT11: //温湿度
            tempData = (((quint8)sensorData[4]<<8)+(quint8)sensorData[5]); //温度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->tempNumber->display(sensorStr.setNum(tempData));
            ui->tempStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit tempcheck(tempData);

            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7]); //湿度
            ui->humiNumber->display(sensorStr.setNum(tempData));
            ui->humiStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit humicheck(tempData);
            break;
        case DEVICE_FAN: //风扇
            ui->fanStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap fanpixmap_on(":/rcs/fancheck_on.png");
                ui->fanpixlabel->setPixmap(fanpixmap_on);
                emit hummancheck(true);
            }
            else
            {
                QPixmap fanpixmap_off(":/rcs/fancheck_off.png");
                ui->fanpixlabel->setPixmap(fanpixmap_off);
                emit hummancheck(false);
            }
            break;
        case DEVICE_HOT: //加热
            ui->hotStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap hotrpixmap_on(":/rcs/fancheck_on.png");
                ui->hotpixlabel->setPixmap(hotrpixmap_on);
            }
            else
            {
                QPixmap hotpixmap_off(":/rcs/fancheck_off.png");
                ui->hotpixlabel->setPixmap(hotpixmap_off);
            }
            break;
       default:
            break;
     }
}
void homeForm::button1CheckHandle(bool buttonstate)
{
    if(buttonstate)
    {
        SensorCtrolReq(DEVICE_FAN, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_FAN, SETOFF);
    }
}
void homeForm::button2CheckHandle(bool buttonstate)
{
    if(buttonstate)
    {
        SensorCtrolReq(DEVICE_HOT, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_HOT, SETOFF);
    }
}

void homeForm::SensorCtrolReq(quint8 sensortype, quint8 state)
{
    QByteArray cmddata;

    /*int listAddr = -1,i;
    listAddr = getsensorConfig(ZBID, sensortype);
    if(listAddr == -1)
    {
        qDebug()<<"quit button";
        return;
    }
    for(i=0;i<SensorInfolist.size();i++)
    {
        if(SensorInfolist[i].sensortype == sensortype)
        {
            listAddr = i;
            break;
        }
    }
    if(listAddr != -1)
    {
    }*/
        qDebug()<<"FAN SET";
        cmddata[0] = 0xEE;
        cmddata[1] = 0xCC;
        cmddata[2] = 0;
        cmddata[3] = 0;
        cmddata[4] = 0;
        cmddata[5] = 0;
        cmddata[6] = 0;
        cmddata[7] = 0;
        cmddata[8] = 0;
        cmddata[9] = 0x80;
        cmddata[10] = sensortype;
        cmddata[11] = 0;
        cmddata[12] = 0;
        cmddata[13] = 0;
        cmddata[14] = 0;
        cmddata[15] = 0;
        cmddata[16] = state;
        cmddata[17] = 0xFF;
        cmddata[18] = 0x0D;
        cmddata[19] = 0x0A;

        emit sensorCtrol(cmddata);
}
void homeForm::SensorSetModelReq(quint8 model)
{
    QByteArray cmddata;

    cmddata[0] = 0xEE;
    cmddata[1] = 0xCC;
    cmddata[2] = 0;
    cmddata[3] = 0;
    cmddata[4] = 0;
    cmddata[5] = 0;
    cmddata[6] = 0;
    cmddata[7] = 0;
    cmddata[8] = 0;
    cmddata[9] = 0x2A; //模式设置
    cmddata[10] = 0;
    cmddata[11] = 0;
    cmddata[12] = 0;
    cmddata[13] = tempdwThresholdValue;
    cmddata[14] = tempupThresholdValue;
    cmddata[15] = humiThresholdValue;
    cmddata[16] = model; //模式
    cmddata[17] = 0xFF;
    cmddata[18] = 0x0D;
    cmddata[19] = 0x0A;

    emit sensorCtrol(cmddata);
}


bool homeForm::saveDatatoList(QByteArray &sensorData)
{
    tempdata->netid = sensorData[2];
    tempdata->nodeaddress[0] = sensorData[3];
    tempdata->nodeaddress[1] = sensorData[4];
    tempdata->nodeaddress[2] = sensorData[5];
    tempdata->nodeaddress[3] = sensorData[6];
    tempdata->nodechannel = sensorData[7];
    tempdata->connectport = sensorData[8];
    tempdata->sensortype = sensorData[10]; //传感器类型

    updateSensorStatus(sensorData[10]); //更新在线状态

    if((SensorInfolist.indexOf(*tempdata,0)) == -1)//判断链表中是否已经有改设备
    {
      SensorInfolist.append(*tempdata);
      return true;
    }
    return false;
}

void homeForm::changeStatus()
{
    resetSensorStatus();

    sensorflag0 = false;
    sensorflag1 = false;
    sensorflag2 = false;
    sensorflag3 = false;
}
void homeForm::updateSensorStatus(quint8 sensortype)
{
    switch(sensortype)
    {
        case DEVICE_HT11:
            sensorflag0 = true;
            break;
        case DEVICE_FAN:
            sensorflag1 = true;
            break;
        case DEVICE_HOT:
            sensorflag2 = true;
            break;
        default:
            break;
    }
}
void homeForm::resetSensorStatus()
{
    if(!sensorflag0)
    {
        ui->tempStatelabel->setText(QString::fromLocal8Bit("离线"));
        ui->humiStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag1)
    {
       ui->fanStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag2)
    {
        ui->hotStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
}
int homeForm::getsensorConfig(quint8 netid,quint8 sensorType)
{
    SensorRevData data;
    int listnum= -1;
    data.netid = netid;
    data.sensortype = sensorType;
    data.dataheadh = 0xee;
    data.dataheadl = 0xcc;
    data.dataend = 0xff;
    if((listnum=SensorInfolist.indexOf(data,0)) != -1)
    {
        return listnum;///出现在链表中的第一个位置
    }
    else
    {
        return -1;
    }
}

void homeForm::switchRunModle(bool modelflag)
{
    if(modelflag)
        SensorSetModelReq(0x01); //智能模式
    else
        SensorSetModelReq(0x00); //普通模式
}

void homeForm::on_tempButton_clicked()
{
    QString  data;
    tempdwThresholdValue = ui->tempdwspinBox->value();
    tempupThresholdValue = ui->tempupspinBox->value();
    qDebug()<<data.setNum(tempdwThresholdValue);
}

void homeForm::on_humiButton_clicked()
{
    QString  data;
    humiThresholdValue = ui->humispinBox->value();
    qDebug()<<data.setNum(humiThresholdValue);
}




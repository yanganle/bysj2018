#include "homeform.h"
#include "ui_homeform.h"

homeForm::homeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homeForm)
{
    ui->setupUi(this);
    this->hide();

    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForLocale(codec);
    this->setWindowTitle(QString::fromLocal8Bit("设备信息"));

    //水泵开关
    button1 = new SwitchButton(this);
    button1->setGeometry(rect().x()+705, rect().y()+265,60, 25);
    button1->setParent(this);
    //水泵开关
    button2 = new SwitchButton(this);
    button2->setGeometry(rect().x()+325, rect().y()+265,60, 25);
    button2->setParent(this);

    connect(button1,SIGNAL(checkedChanged(bool)),this,SLOT(button1CheckHandle(bool)));
    connect(button2,SIGNAL(checkedChanged(bool)),this,SLOT(button2CheckHandle(bool)));

    sensorflag0 = false;
    sensorflag1 = false;
    sensorflag2 = false;
    sensorflag3 = false;
    sensorflag4 = false;

    tempThresholdValue = 35;
    watlThresholdValue = 70;

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

    //qDebug()<<QString("RX:%1").arg(sensorData.toHex().data());
    switch((quint8)sensorData[1])
    {
        case DEVICE_DS18B20: //温度
            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7]);
            ui->tempNumber->display(sensorStr.setNum(tempData));
            ui->tempStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit tempcheck(tempData);
            break;
        case DEVICE_WATERLEVEL: //水位
            ui->watlStatelabel->setText(QString::fromLocal8Bit("在线"));
            ui->watlprogressBar->setValue(sensorData[7]);
            emit humicheck((double)sensorData[7]);
            break;
        case DEVICE_LAMP: //热灯
            ui->lampStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap lamppixmap_on(":/rcs/lamp_on.png");
                ui->lamppixlabel->setPixmap(lamppixmap_on);
            }
            else
            {
                QPixmap lamppixmap_off(":/rcs/lamp_off.png");
                ui->lamppixlabel->setPixmap(lamppixmap_off);
            }
            break;
        case DEVICE_WATER_PUMP: //水泵
            ui->pumpStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap pumppixmap_on(":/rcs/pump_on.png");
                ui->pumppixlabel->setPixmap(pumppixmap_on);
                emit humancheck(true);
            }
            else
            {
                QPixmap pumppixmap_off(":/rcs/pump_off.png");
                ui->pumppixlabel->setPixmap(pumppixmap_off);
                emit humancheck(false);
            }
            break;
        case DEVICE_TURBIDITY: //水质
            ui->turbStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap turbpixmap_on(":/rcs/fancheck_on.png");
                ui->turbpixlabel->setPixmap(turbpixmap_on);
            }
            else
            {
                QPixmap turbpixmap_off(":/rcs/fancheck_off.png");
                ui->turbpixlabel->setPixmap(turbpixmap_off);
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
        SensorCtrolReq(DEVICE_WATER_PUMP, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_WATER_PUMP, SETOFF);
    }
}
void homeForm::button2CheckHandle(bool buttonstate)
{
    if(buttonstate)
    {
        SensorCtrolReq(DEVICE_LAMP, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_LAMP, SETOFF);
    }
}

void homeForm::SensorCtrolReq(quint8 sensortype, quint8 state)
{
    QByteArray cmddata;
    qDebug()<<"CONTRL SET";
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
    cmddata[13] = 0;
    cmddata[14] = tempThresholdValue; //湿度
    cmddata[15] = watlThresholdValue; //水位
    cmddata[16] = model; //模式
    cmddata[17] = 0xFF;

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
        case DEVICE_DS18B20:
            sensorflag0 = true;
            break;
        case DEVICE_WATERLEVEL:
            sensorflag1 = true;
            break;
        case DEVICE_LAMP:
            sensorflag2 = true;
            break;
        case DEVICE_WATER_PUMP:
            sensorflag3 = true;
            break;
        case DEVICE_TURBIDITY:
            sensorflag4 = true;
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
    }
    if(!sensorflag1)
    {
        ui->watlStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag2)
    {
        ui->lampStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag3)
    {
        ui->pumpStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag4)
    {
        ui->turbStatelabel->setText(QString::fromLocal8Bit("离线"));
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
        return listnum;//出现在链表中的第一个位置
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
    tempThresholdValue = ui->tempspinBox->value();
    qDebug()<<data.setNum(tempThresholdValue);
}

void homeForm::on_watlButton_clicked()
{
    QString  data;
    watlThresholdValue = ui->watlspinBox->value();
    qDebug()<<data.setNum(watlThresholdValue);
}

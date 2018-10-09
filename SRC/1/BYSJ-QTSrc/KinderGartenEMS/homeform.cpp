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
    //风扇开关
    button1 = new SwitchButton(this);
    button1->setGeometry(rect().x()+320, rect().y()+412,60, 25);
    button1->setParent(this);

    connect(button1,SIGNAL(checkedChanged(bool)),this,SLOT(button1CheckHandle(bool)));

    sensorflag0 = false;
    sensorflag1 = false;
    sensorflag2 = false;
    sensorflag3 = false;
    sensorflag4 = false;

    tempThresholdValue = 35;
    humiThresholdValue = 60;
    methThresholdValue = 30;

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
        case DEVICE_SOUND: //声响检测
            ui->soundStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap soundpixmap_bright(":/rcs/light_bright.png");
                ui->soundpixlabel->setPixmap(soundpixmap_bright);
                ui->soundvaluelabel->setText(QString::fromLocal8Bit("噪声"));
            }else
            {
                QPixmap soundpixmap_dark(":/rcs/light_dark.png");
                ui->soundpixlabel->setPixmap(soundpixmap_dark);
                ui->soundvaluelabel->setText(QString::fromLocal8Bit("安静"));
            }
            break;
        case DEVICE_HT11: //温湿度
            tempData = (((quint8)sensorData[4]<<8)+(quint8)sensorData[5]); //温度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->tempNumber->display(sensorStr.setNum(tempData));
            ui->tempStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit tempcheck(tempData);

            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7]); //湿度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->humiNumber->display(sensorStr.setNum(tempData));
            ui->humiStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit humicheck(tempData);
            break;

        case DEVICE_HUMAN: //人体红外
            ui->humanStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap humanpixmap_bright(":/rcs/light_bright.png");
                ui->humanpixlabel->setPixmap(humanpixmap_bright);
                ui->humanvaluelabel->setText(QString::fromLocal8Bit("有人"));
                emit hummancheck(true);
            }else
            {
                QPixmap humanpixmap_dark(":/rcs/light_dark.png");
                ui->humanpixlabel->setPixmap(humanpixmap_dark);
                ui->humanvaluelabel->setText(QString::fromLocal8Bit("无人"));
                emit hummancheck(false);
            }
            break;
        case DEVICE_FAN: //风扇
            ui->fanStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap fanpixmap_on(":/rcs/fancheck_on.png");
                ui->fanpixlabel->setPixmap(fanpixmap_on);
                //QMovie *movie = new QMovie(":/rcs/fan_move.gif"); //动图设置
                //ui->fanpixlabel->setMovie(movie);
                //movie->start();
            }
            else
            {
                QPixmap fanpixmap_off(":/rcs/fancheck_off.png");
                ui->fanpixlabel->setPixmap(fanpixmap_off);
            }
            break;
        case DEVICE_METHANAL: //甲醛
            tempData = (((quint8)sensorData[4]<<8)+(quint8)sensorData[5]);
            //qDebug()<<sensorStr.setNum(tempData);
            ui->methNumber->display(sensorStr.setNum(tempData));
            ui->methStatelabel->setText(QString::fromLocal8Bit("在线"));
            break;
       default:
            break;
     }
}
void homeForm::button1CheckHandle(bool buttonstate)
{
    if(buttonstate)
    {
        qDebug()<<"FAN ON";
        SensorCtrolReq(DEVICE_FAN, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_FAN, SETOFF);
        qDebug()<<"FAN OFF";
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
    cmddata[13] = methThresholdValue;
    cmddata[14] = humiThresholdValue; //湿度
    cmddata[15] = tempThresholdValue; //温度
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
        case DEVICE_SOUND:
            sensorflag0 = true;
            break;
        case DEVICE_HUMAN:
            sensorflag1 = true;
            break;
        case DEVICE_HT11:
            sensorflag2 = true;
            break;
        case DEVICE_FAN:
            sensorflag3 = true;
            break;
        case DEVICE_METHANAL:
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
       ui->soundStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag1)
    {
        ui->humanStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag2)
    {
        ui->tempStatelabel->setText(QString::fromLocal8Bit("离线"));
        ui->humiStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag3)
    {
        ui->fanStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag4)
    {
        ui->methStatelabel->setText(QString::fromLocal8Bit("离线"));
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
    tempThresholdValue = ui->tempspinBox->value();
    qDebug()<<data.setNum(tempThresholdValue);
}

void homeForm::on_humiButton_clicked()
{
    QString  data;
    humiThresholdValue = ui->humispinBox->value();
    qDebug()<<data.setNum(humiThresholdValue);
}

void homeForm::on_methButton_clicked()
{
    QString  data;
    methThresholdValue = ui->methspinBox->value();
    qDebug()<<data.setNum(methThresholdValue);
}

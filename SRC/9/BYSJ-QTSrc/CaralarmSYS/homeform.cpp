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

    //开关
    button1 = new SwitchButton(this);
    button1->setGeometry(rect().x()+325, rect().y()+265,60, 25);
    button1->setParent(this);

    connect(button1,SIGNAL(checkedChanged(bool)),this,SLOT(button1CheckHandle(bool)));

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
    //qDebug()<<QString("RX:%1").arg(sensorData.toHex().data());
    switch((quint8)sensorData[1])
    {
        case DEVICE_HUMAN:
            ui->manStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap lamppixmap_on(":/rcs/lamp_on.png");
                ui->manpixlabel->setPixmap(lamppixmap_on);
                emit humancheck(true);
            }
            else
            {
                QPixmap lamppixmap_off(":/rcs/lamp_off.png");
                ui->manpixlabel->setPixmap(lamppixmap_off);
                emit humancheck(false);
            }
            break;
        case DEVICE_SHAKE:
            ui->shakeStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap pumppixmap_on(":/rcs/pump_on.png");
                ui->shakepixlabel->setPixmap(pumppixmap_on);
                emit tempcheck(true);
            }
            else
            {
                QPixmap pumppixmap_off(":/rcs/pump_off.png");
                ui->shakepixlabel->setPixmap(pumppixmap_off);
                emit tempcheck(false);
            }
            break;
        case DEVICE_SL_ALARM:
            ui->alarmStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap turbpixmap_on(":/rcs/pump_on.png");
                ui->alarmpixlabel->setPixmap(turbpixmap_on);
                emit humicheck(true);
            }
            else
            {
                QPixmap turbpixmap_off(":/rcs/pump_off.png");
                ui->alarmpixlabel->setPixmap(turbpixmap_off);
                emit humicheck(false);
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
        SensorCtrolReq(DEVICE_SL_ALARM, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_SL_ALARM, SETOFF);
    }
}

void homeForm::SensorCtrolReq(quint8 sensortype, quint8 state)
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
    cmddata[14] = 0;
    cmddata[15] = 0;
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
        case DEVICE_HUMAN:
            sensorflag0 = true;
            break;
        case DEVICE_SHAKE:
            sensorflag1 = true;
            break;
        case DEVICE_SL_ALARM:
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
       ui->manStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag1)
    {
        ui->shakeStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag2)
    {
        ui->alarmStatelabel->setText(QString::fromLocal8Bit("离线"));
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

}

void homeForm::on_watlButton_clicked()
{

}

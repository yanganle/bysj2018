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

    //风扇开关
    button2 = new SwitchButton(this);
    button2->setGeometry(rect().x()+700, rect().y()+412,60, 25);
    button2->setParent(this);

    connect(button1,SIGNAL(checkedChanged(bool)),this,SLOT(button1CheckHandle(bool)));
    connect(button2,SIGNAL(checkedChanged(bool)),this,SLOT(button2CheckHandle(bool)));

    sensorflag0 = false;
    sensorflag1 = false;
    sensorflag2 = false;
    sensorflag3 = false;
    sensorflag4 = false;

    tempThresholdValue = 35;
    humiThresholdValue = 60;
    gasThresholdValue = 30;
    runingModelFlag = false;

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
   // qDebug()<<QString("RX:%1").arg(sensorData.toHex().data());
    if(!runingModelFlag) //普通模式
    {
        qDebug()<<"Runing in the normal model";
        this->updataValue(sensorData.mid(9,8));
    }else //智能模式
    {
        qDebug()<<"Runing in the smart model";
        this->runingSmartModel(sensorData.mid(9,8));
    }

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
        case DEVICE_LIGHT: //光照
            ui->lightStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap lightpixmap_bright(":/rcs/light_bright.png");
                ui->lightpixlabel->setPixmap(lightpixmap_bright);
                ui->lightvaluelabel->setText(QString::fromLocal8Bit("强光"));
            }else
            {
                QPixmap lightpixmap_dark(":/rcs/light_dark.png");
                ui->lightpixlabel->setPixmap(lightpixmap_dark);
                ui->lightvaluelabel->setText(QString::fromLocal8Bit("弱光"));
            }
            break;
        case DEVICE_HT11: //温湿度
            tempData = (((quint8)sensorData[4]<<8)+(quint8)sensorData[5])/10.0; //温度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->tempNumber->display(sensorStr.setNum(tempData));
            ui->tempStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit tempcheck(tempData);

            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7])/10.0; //湿度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->humiNumber->display(sensorStr.setNum(tempData));
            ui->humiStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit humicheck(tempData);
            break;

        case DEVICE_GAS_MQ135: //气体
            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7])/10.0; //温度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->gasNumber->display(sensorStr.setNum(tempData));
            ui->gasStatelabel->setText(QString::fromLocal8Bit("在线"));

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
        case DEVICE_LAMP: //灯光
            ui->lampStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap lamppixmap_on(":/rcs/lampcheck_on.png");
                ui->lamppixlabel->setPixmap(lamppixmap_on);
                emit lightcheck(true);
            }
            else
            {
                QPixmap lamppixmap_off(":/rcs/lampcheck_off.png");
                ui->lamppixlabel->setPixmap(lamppixmap_off);
                emit lightcheck(false);
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
        qDebug()<<"FAN ON";
        SensorCtrolReq(DEVICE_FAN, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_FAN, SETOFF);
        qDebug()<<"FAN OFF";
    }
}

void homeForm::button2CheckHandle(bool buttonstate)
{
    if(buttonstate)
    {
        qDebug()<<"LAMP ON";
        SensorCtrolReq(DEVICE_LAMP, SETON);
    }
    else
    {
        qDebug()<<"LAMP OFF";
        SensorCtrolReq(DEVICE_LAMP, SETOFF);
    }
}

void homeForm::SensorCtrolReq(quint8 sensortype, quint8 state)
{
    int listAddr = -1,i;
    QByteArray cmddata;

    /*listAddr = getsensorConfig(ZBID, sensortype);
    if(listAddr == -1)
    {
        qDebug()<<"quit button";
        return;
    }*/
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
        cmddata[0] = 0xEE;
        cmddata[1] = 0xCC;
        cmddata[2] = SensorInfolist[listAddr].netid;
        cmddata[3] = SensorInfolist[listAddr].nodeaddress[0];
        cmddata[4] = SensorInfolist[listAddr].nodeaddress[1];
        cmddata[5] = SensorInfolist[listAddr].nodeaddress[2];
        cmddata[6] = SensorInfolist[listAddr].nodeaddress[3];
        cmddata[7] = SensorInfolist[listAddr].nodechannel;
        cmddata[8] = SensorInfolist[listAddr].connectport;
        cmddata[9] = SensorInfolist[listAddr].datalenth;
        cmddata[10] = SensorInfolist[listAddr].sensortype;
        cmddata[11] = 0;
        cmddata[12] = 0;
        cmddata[13] = 0;
        cmddata[14] = 0;
        cmddata[15] = 0;
        cmddata[16] = state;
        cmddata[17] = 0xFF;

        emit sensorCtrol(cmddata);
    }
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
    sensorflag4 = false;
}
void homeForm::updateSensorStatus(quint8 sensortype)
{
    switch(sensortype)
    {
        case DEVICE_LIGHT:
            sensorflag0 = true;
            break;
        case DEVICE_GAS_MQ135:
            sensorflag1 = true;
            break;
        case DEVICE_HT11:
            sensorflag2 = true;
            break;
        case DEVICE_FAN:
            sensorflag3 = true;
            break;
        case DEVICE_LAMP:
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
       ui->lightStatelabel->setText(QString::fromLocal8Bit("离线"));
    }
    if(!sensorflag1)
    {
        ui->gasStatelabel->setText(QString::fromLocal8Bit("离线"));
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
        ui->lampStatelabel->setText(QString::fromLocal8Bit("离线"));
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

void homeForm::runingSmartModel(QByteArray sensorData)
{
    QString sensorStr;
    double tempData;

    //qDebug()<<QString("RX:%1").arg(sensorData.toHex().data());
    switch((quint8)sensorData[1])
    {
        case DEVICE_LIGHT: //光照
            ui->lightStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap lightpixmap_bright(":/rcs/light_bright.png");
                ui->lightpixlabel->setPixmap(lightpixmap_bright);
                ui->lightvaluelabel->setText(QString::fromLocal8Bit("强光"));
            }else
            {
                QPixmap lightpixmap_dark(":/rcs/light_dark.png");
                ui->lightpixlabel->setPixmap(lightpixmap_dark);
                ui->lightvaluelabel->setText(QString::fromLocal8Bit("弱光"));
            }

            if(tempData) //强光
            {
                //关闭电灯
                SensorCtrolReq(DEVICE_LAMP, SETOFF);
            }else
            {
                //打开电灯
                SensorCtrolReq(DEVICE_LAMP, SETON);
            }

            break;
        case DEVICE_HT11: //温湿度
            tempData = (((quint8)sensorData[4]<<8)+(quint8)sensorData[5])/10.0; //温度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->tempNumber->display(sensorStr.setNum(tempData));
            ui->tempStatelabel->setText(QString::fromLocal8Bit("在线"));
            if(tempData > tempThresholdValue)
            {
                //打开风扇
                SensorCtrolReq(DEVICE_FAN, SETON);
            }else
            {
                SensorCtrolReq(DEVICE_FAN, SETOFF);
            }

            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7])/10.0; //湿度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->humiNumber->display(sensorStr.setNum(tempData));
            ui->humiStatelabel->setText(QString::fromLocal8Bit("在线"));

            if(tempData > humiThresholdValue)
            {

            }
            break;

        case DEVICE_GAS_MQ135: //气体
            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7])/10.0; //温度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->gasNumber->display(sensorStr.setNum(tempData));
            ui->gasStatelabel->setText(QString::fromLocal8Bit("在线"));

            if(tempData > gasThresholdValue)
            {
                //打开风扇
                SensorCtrolReq(DEVICE_FAN, SETON);
            }else
            {
                SensorCtrolReq(DEVICE_FAN, SETOFF);
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
        case DEVICE_LAMP: //灯光
            ui->lampStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap lamppixmap_on(":/rcs/lampcheck_on.png");
                ui->lamppixlabel->setPixmap(lamppixmap_on);
            }
            else
            {
                QPixmap lamppixmap_off(":/rcs/lampcheck_off.png");
                ui->lamppixlabel->setPixmap(lamppixmap_off);
            }
            break;
       default:
            break;
     }
}
void homeForm::switchRunModle(bool modelflag)
{
    runingModelFlag = modelflag;
    qDebug()<<runingModelFlag;
}

void homeForm::on_tempButton_clicked()
{
    tempThresholdValue = ui->tempspinBox->value();
}

void homeForm::on_humiButton_clicked()
{
    humiThresholdValue = ui->humispinBox->value();
}

void homeForm::on_gasButton_clicked()
{
    gasThresholdValue = ui->gasspinBox->value();
}



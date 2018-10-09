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
    button1->setGeometry(rect().x()+320, rect().y()+412,60, 25);
    button1->setParent(this);

    //LED开关
    button2 = new SwitchButton(this);
    button2->setGeometry(rect().x()+700, rect().y()+412,60, 25);
    button2->setParent(this);

    //制冷开关
    button3 = new SwitchButton(this);
    button3->setGeometry(rect().x()+700, rect().y()+265,60, 25);
    button3->setParent(this);
    connect(button1,SIGNAL(checkedChanged(bool)),this,SLOT(button1CheckHandle(bool)));
    connect(button2,SIGNAL(checkedChanged(bool)),this,SLOT(button2CheckHandle(bool)));
    connect(button3,SIGNAL(checkedChanged(bool)),this,SLOT(button3CheckHandle(bool)));
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
        case DEVICE_MAN: //人体
            if((quint8)sensorData[7] == 0x01) emit lightcheck(true);
            else emit lightcheck(false);
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

        case DEVICE_MQ2: //烟雾
            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7])/10.0; //烟雾
            //qDebug()<<sensorStr.setNum(tempData);
            ui->gasNumber->display(sensorStr.setNum(tempData));
            ui->gasStatelabel->setText(QString::fromLocal8Bit("在线"));
            break;
        case DEVICE_PUMP: //水泵
            ui->pumpStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap pumppixmap_on(":/rcs/pump_on.png");
                ui->pumppixlabel->setPixmap(pumppixmap_on);
            }
            else
            {
                QPixmap pumppixmap_off(":/rcs/pump_off.png");
                ui->pumppixlabel->setPixmap(pumppixmap_off);
            }
            break;
        case DEVICE_LAMP: //灯光
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
        case DEVICE_COLD: //制冷
            ui->coldStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap coldpixmap_on(":/rcs/pump_on.png");
                ui->coldpixlabel->setPixmap(coldpixmap_on);

            }
            else
            {
                QPixmap coldpixmap_off(":/rcs/pump_off.png");
                ui->coldpixlabel->setPixmap(coldpixmap_off);
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
        SensorCtrolReq(DEVICE_PUMP, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_PUMP, SETOFF);
    }
}

void homeForm::button2CheckHandle(bool buttonstate)
{
    if(buttonstate)
    {;
        SensorCtrolReq(DEVICE_LAMP, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_LAMP, SETOFF);
    }
}
void homeForm::button3CheckHandle(bool buttonstate)
{
    if(buttonstate)
    {
        SensorCtrolReq(DEVICE_COLD, SETON);
    }
    else
    {
        SensorCtrolReq(DEVICE_COLD, SETOFF);
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
        case DEVICE_COLD:
            sensorflag0 = true;
            break;
        case DEVICE_MQ2:
            sensorflag1 = true;
            break;
        case DEVICE_HT11:
            sensorflag2 = true;
            break;
        case DEVICE_PUMP:
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
       ui->coldStatelabel->setText(QString::fromLocal8Bit("离线"));
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
        ui->pumpStatelabel->setText(QString::fromLocal8Bit("离线"));
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
        case DEVICE_MAN: //人体
            if((quint8)sensorData[7] == 0x01)
            {
                emit lightcheck(true);
                SensorCtrolReq(DEVICE_LAMP, SETON);
            }
            else
            {
                emit lightcheck(false);
                //SensorCtrolReq(DEVICE_LAMP, SETOFF);
            }

            break;
        case DEVICE_HT11: //温湿度
            tempData = (((quint8)sensorData[4]<<8)+(quint8)sensorData[5])/10.0; //温度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->tempNumber->display(sensorStr.setNum(tempData));
            ui->tempStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit tempcheck(tempData);
            if(tempData > tempThresholdValue)
            {
                //打开制冷
                SensorCtrolReq(DEVICE_COLD, SETON);
            }else
            {
                SensorCtrolReq(DEVICE_COLD, SETOFF);
            }

            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7])/10.0; //湿度
            //qDebug()<<sensorStr.setNum(tempData);
            ui->humiNumber->display(sensorStr.setNum(tempData));
            ui->humiStatelabel->setText(QString::fromLocal8Bit("在线"));
            emit humicheck(tempData);
            break;

        case DEVICE_MQ2: //烟雾
            tempData = (((quint8)sensorData[6]<<8)+(quint8)sensorData[7])/10.0;
            ui->gasNumber->display(sensorStr.setNum(tempData));
            ui->gasStatelabel->setText(QString::fromLocal8Bit("在线"));

            if(tempData > gasThresholdValue)
            {
                //打开水泵
                SensorCtrolReq(DEVICE_PUMP, SETON);
            }else
            {
                SensorCtrolReq(DEVICE_PUMP, SETOFF);
            }
            break;
        case DEVICE_PUMP: //水泵
            ui->pumpStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap pumppixmap_on(":/rcs/pump_on.png");
                ui->pumppixlabel->setPixmap(pumppixmap_on);
            }
            else
            {
                QPixmap pumppixmap_off(":/rcs/pump_off.png");
                ui->pumppixlabel->setPixmap(pumppixmap_off);
            }
            break;
        case DEVICE_LAMP: //灯光
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
        case DEVICE_COLD: //制冷
            ui->coldStatelabel->setText(QString::fromLocal8Bit("在线"));
            if((quint8)sensorData[7] == 0x01)
            {
                QPixmap coldpixmap_on(":/rcs/pump_on.png");
                ui->coldpixlabel->setPixmap(coldpixmap_on);
            }
            else
            {
                QPixmap coldpixmap_off(":/rcs/pump_off.png");
                ui->coldpixlabel->setPixmap(coldpixmap_off);
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



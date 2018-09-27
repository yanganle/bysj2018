#include "nodemessage.h"
#include "ui_nodemessage.h"
#include "QDebug"
nodeMessage::nodeMessage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nodeMessage)
{
    ui->setupUi(this);
    this->hide();
    listNum = 0;
    //this->showFullScreen();  //整屏显示

    atListfirstFlag = true;
    atListsecondFlag = true;
    atListthridFlag = true;

    date = new SensorRevData();
    timer = new QTimer(this);
    //by cxue
    connect(timer,SIGNAL(timeout()),this, SLOT(changeStatus()));
    timer->start(4000);
}
void nodeMessage::reveiceSensordata(QByteArray sensorData)
{
    qDebug()<<QString("RX:%1").arg(sensorData.toHex().data());
    this->updataSensor(sensorData.mid(11,7));
    if(saveDatatoList(sensorData))
    {
        listNum = SensorInfolist.size();
        QString listString = sensorData.toHex().data();
        switch((quint8)sensorData[11])
        {
            case 0x07:

                newItem = new QTableWidgetItem(QString::fromLocal8Bit("人体检测"));
                newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->tableWidget->setItem(listNum-1,0,newItem);
                break;
            case 0x0A:
                newItem = new QTableWidgetItem(QString::fromLocal8Bit("温湿度检测"));
                newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->tableWidget->setItem(listNum-1,0,newItem);
                break;
            case 0x0B:
                newItem = new QTableWidgetItem(QString::fromLocal8Bit("烟雾检测"));
                newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->tableWidget->setItem(listNum-1,0,newItem);
                break;
           default:
                break;
         }
        newItem = new QTableWidgetItem("0X"+listString.mid(10,4));
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(listNum-1,1,newItem);
        newItem = new QTableWidgetItem("0X"+listString.mid(18,4));
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(listNum-1,2,newItem);
        if(sensorData[11])
        {
            newItem = new QTableWidgetItem(QString::fromLocal8Bit("工作中"));
        }
        else
        {
            newItem = new QTableWidgetItem(QString::fromLocal8Bit("断开"));
        }
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(listNum-1,3,newItem);
        newItem = new QTableWidgetItem("Channel "+listString.mid(24,2));
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(listNum-1,4,newItem);
        newItem = new QTableWidgetItem("COM "+listString.mid(26,2));
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(listNum-1,5,newItem);
    }

}

//查找链表中是否存在信息，并将信息存入链表。
bool nodeMessage::saveDatatoList(QByteArray &sensorData)
{
    date->netid = sensorData[2];
    date->nodeaddress[0] = sensorData[3];
    date->nodeaddress[1] = sensorData[4];
    date->nodeaddress[2] = sensorData[5];
    date->nodeaddress[3] = sensorData[6];
    date->nodechannel = sensorData[7];
    date->connectport = sensorData[8];
    date->datalenth = sensorData[9];
    date->sensortype = sensorData[10];

    recordLocation(SensorInfolist.indexOf(*date));

    if((SensorInfolist.indexOf(*date,0)) == -1)//先检查是不是有相应的选项
    {
      SensorInfolist.append(*date);
      return true;
    }
    return false;
}
nodeMessage::~nodeMessage()
{
    delete ui;
}

void nodeMessage::on_back_triggered()
{
    emit exitSender();
    this->hide();
}
void nodeMessage::updataSensor(QByteArray sensorData)
{
    double temp;
    switch((quint8)sensorData[0])
    {
        case 0x07:
            if((quint8)sensorData[6] == 0x01)
            {
                qDebug()<<"GET MAN SEND TRUE";
                emit manCheck(true);
            }
            else
            {
                qDebug()<<"GET MAN SEND FALSE";
                emit manCheck(false);
            }
            break;
        case 0x0A:
            temp = (((quint8)sensorData[7]<<8)+(quint8)sensorData[8])/10.0;
            qDebug()<<temp;
            emit tempCheck(temp);
            temp = (((quint8)sensorData[5]<<8)+(quint8)sensorData[6])/10.0;
            emit humCheck(temp);
            qDebug()<<temp;
            break;

        case 0x0B:
            if((quint8)sensorData[6] == 0x01)
            {
                emit smokeCheck(true);
            }
            else
            {
                emit smokeCheck(false);
            }
            break;
       default:
            break;
     }

}

void nodeMessage::changeStatus()
{

    writeStatus(0,3,atListfirstFlag);
    writeStatus(1,3,atListsecondFlag);
    writeStatus(2,3,atListthridFlag);

    atListfirstFlag = false;
    atListsecondFlag = false;
    atListthridFlag = false;

}
void nodeMessage::recordLocation(int location)
{
    switch(location)
    {
        case 0:
            atListfirstFlag = true;
            break;
        case 1:
            atListsecondFlag = true;
            break;
        case 2:
            atListthridFlag = true;
            break;
        default:
            break;
    }
}

void nodeMessage::writeStatus(int row,int column,bool status)
{
    if((ui->tableWidget->item(row,column))&&(status == false))
    {
        newItem = new QTableWidgetItem(QString::fromLocal8Bit("断开"));
        newItem->setTextColor(QColor("red"));
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(row,column,newItem);
    }
    if((ui->tableWidget->item(row,column))&&(status == true))
    {
        newItem = new QTableWidgetItem(QString::fromLocal8Bit("工作中"));
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(row,column,newItem);
    }

}
/*
void SensorWidget::setClose()
{
    QByteArray cmd;

    cmd[0]=0xEE;
    cmd[1]=0xCC;
    cmd[2]=networkFlag;
    cmd[3] = SensorInfolist[listAddr].netInfoChannelList[0];
    cmd[4] = SensorInfolist[listAddr].netInfoChannelList[1];
    cmd[5] = SensorInfolist[listAddr].netInfoChannelList[2];
    cmd[6] = SensorInfolist[listAddr].netInfoChannelList[3];
    cmd[7] = SensorInfolist[listAddr].netInfoChannelList[4];
    cmd[8] = SensorInfolist[listAddr].netInfoChannelList[5];
    cmd[9] = SensorInfolist[listAddr].netInfoChannelList[6];
    cmd[10] = SensorInfolist[listAddr].netInfoChannelList[7];
    cmd[11] = SensorInfolist[listAddr].netInfoPanID[0];
    cmd[12] = SensorInfolist[listAddr].netInfoPanID[1];
    cmd[13] = SensorInfolist[listAddr].nodeIEEEAddress[0];
    cmd[14] = SensorInfolist[listAddr].nodeIEEEAddress[1];
    cmd[15] = SensorInfolist[listAddr].nodeIEEEAddress[2];
    cmd[16] = SensorInfolist[listAddr].nodeIEEEAddress[3];
    cmd[17] = SensorInfolist[listAddr].nodeIEEEAddress[4];
    cmd[18] = SensorInfolist[listAddr].nodeIEEEAddress[5];
    cmd[19] = SensorInfolist[listAddr].nodeIEEEAddress[6];
    cmd[20] = SensorInfolist[listAddr].nodeIEEEAddress[7];
    cmd[21] = SensorInfolist[listAddr].nodeaddress[0];
    cmd[22] = SensorInfolist[listAddr].nodeaddress[1];
    cmd[23] = SensorInfolist[listAddr].nodeaddress[2];
    cmd[24] = SensorInfolist[listAddr].nodeaddress[3];
    cmd[25] = SensorInfolist[listAddr].familyaddress[0];
    cmd[26] = SensorInfolist[listAddr].familyaddress[1];
    cmd[45] = 0xff;  //结束位
    emit commandSender(cmd);

    qDebug()<<"##################";
    qDebug()<<"cmd close:"<<cmd.toHex();
}*/


#include "QByteArray"
#include "SensorData.h"
#include "wifithread.h"

WifiThread::WifiThread(QObject *parent=0) :
    QThread(parent)
{

}

bool WifiThread::SocketInit() //socket init
{
    udpSocket = new QUdpSocket(this);
    if(udpSocket->bind(QHostAddress("192.168.1.2"), 8086)==true)
    //if(udpSocket->bind(QHostAddress("127.0.0.1"), 45000)==true)
    //if(udpSocket->bind(QHostAddress::Any, 8086)==true)
    {
        emit wifiStatesender(true);
        qDebug()<<"bind OK";
    }
    else
    {
        emit wifiStatesender(false);
        qDebug()<<"bind false";
        return false;
    }
    udpSocket->open(QUdpSocket::ReadWrite);

    qDebug()<<"udpSocket open succeefull...";

    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(readPendingDatagrams()));

    qDebug()<<"udpSocket connect succeefull...";

    return true;
}

void WifiThread::readPendingDatagrams()
{
    qDebug()<<"start read socket data...";
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram; //创建一个数据接收的字节数组
        datagram.resize(udpSocket->pendingDatagramSize()); //获取数据包大小

        udpSocket->readDatagram(datagram.data(), datagram.size(),
                                &socketSender, &senderPort); //读取数据包

        qDebug()<<QString("UDPRX:%1").arg(datagram.toHex().data());

        QString tempString = datagram.toHex();
        qDebug()<<"tempString : "<<tempString;
        if(!datagram.isEmpty())                     //判断是否为空
        {
            if(datagram.size()<COMDATAMAXLENGTH && (quint8)datagram[0]!=0xee && (quint8)datagram[1]!=0xcc)
            {
                datagram.clear();
                //return;
            }
            if(datagram.size()==COMDATAMAXLENGTH && (quint8)datagram[COMDATAMAXLENGTH-1]==0xff)
            {
                emit sensorWifiData(datagram); //发送传感器信息
            }
        }
    }
}

void WifiThread::run()
{
    readPendingDatagrams();
    //msleep(20);   //延时20ms
}

void WifiThread::wifiClose()
{
    //comPort->close();
}

void WifiThread::SendWifiData(QByteArray msg)
{
    qDebug()<<"######*******"<<msg.toHex()<<"*******#######";

    udpSocket->writeDatagram(msg,msg.length(),QHostAddress::Broadcast, 8086); //广播发送
}






#include <QDebug>
#include "comthread.h"
#include "QByteArray"
#include "SensorData.h"

comThread::comThread(QObject *parent=0) :
    QThread(parent)
{

}

void comThread::ReceiveData()
{
    QByteArray temp = comPort->read(1);
    if(!temp.isEmpty())
    {
        sensormessage.clear();
        sensormessage.append(temp);
        temp.clear();
        if((quint8)sensormessage[0] != 0xee)
        {
            sensormessage.clear();
        }
        else
        {
            temp = comPort->read(1);
            if(!temp.isEmpty())
            {
                sensormessage.append(temp);
                temp.clear();
                if((quint8)sensormessage[1] != 0xcc)
                {
                    sensormessage.clear();
                }
                else
                {
                    int i = 0;
                    for(i = 0;i<16;++i)
                    {
                        temp = comPort->read(1);
                        if(!temp.isEmpty())
                        {
                            sensormessage.append(temp);
                            temp.clear();
                        }
                        else
                        {
                            i = i-1;
                        }
                    }
                    if(sensormessage.length()==COMDATAMAXLENGTH && (quint8)sensormessage[0] == 0xee
                            && (quint8)sensormessage[1] == 0xcc && (quint8)sensormessage[COMDATAMAXLENGTH-1] == 0xff)
                    {
                        emit sensorData(sensormessage);
                        sensormessage.clear();
                    }
                    else
                    {
                        sensormessage.clear();
                    }
                }
            }
        }
    }
}

bool comThread::comInit(QString com)
{
     comNo = com;
     comPort = new Win_QextSerialPort(comNo,QextSerialBase::EventDriven);
     if(comPort->open(QIODevice::ReadWrite)){
      emit comStatesender(true);
     }else{
        emit comStatesender(false);
        delete comPort;
        return false;
     }
    //���ò�����115200
    comPort->setBaudRate((BaudRateType)19);
    //��������λ8
    comPort->setDataBits((DataBitsType)3);
    //����У��0
    comPort->setParity((ParityType)0);
    //����ֹͣλ1
    comPort->setStopBits((StopBitsType)0);
    //����������
    comPort->setFlowControl(FLOW_OFF);
    //������ʱ
    comPort->setTimeout(10);
    return true;
}

void comThread::run()
{
    while(1)
    {
       ReceiveData();
       msleep(1);   //ÿ20������һ�δ���
    }
}

void comThread::comClose()
{
    comPort->close();
}

void comThread::SendComData(QByteArray msg)
{
    qDebug()<<QString("**TX:%1").arg(msg.toHex().data());
    comPort->write(msg);
}


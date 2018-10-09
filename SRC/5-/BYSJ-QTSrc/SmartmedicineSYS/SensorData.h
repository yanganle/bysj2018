#ifndef SENSORDATA_H
#define SENSORDATA_H
#include <QString>
#include <QtGlobal>

#define ZBID   0x01
#define BTID   0x02
#define WIFIID 0x03

//#define DEVICE_LIGHT          0x01  //����
//#define DEVICE_GAS_MQ135      0x02  //��Ⱦ����MQ135
//#define DEVICE_PM25           0x03  //PM2.5
#define DEVICE_HT11           0x04  //��ʪ��
//#define DEVICE_HUMAN          0x05  //human
//#define DEVICE_SOUND          0x06  //sound

#define DEVICE_FAN            0x10  //����
//#define DEVICE_LAMP           0x11  //LED�ƹ�
#define DEVICE_HOT            0x14  //����

#define SETON                 0x01
#define SETOFF                0x00
//��Ϣ�������
#define COMDATAMAXLENGTH 18

class SensorRevData{
public:
    quint8 dataheadh;        //���ݵ�ͷ 0xee
    quint8 dataheadl;        //���ݵ�ͷ 0xcc
    quint8 netid;            //���������ʾ
    quint8 nodeaddress[4];   //�ڵ��ַ
    quint8 nodechannel;      //�ڵ������ŵ�
    quint8 connectport;      //ͨ�Ŷ˿�
    quint8 datalenth;        //���ݳ���
    quint8 sensortype;         //��������ʾ
    quint8 dataend;          //�ڵ��β0xff

    SensorRevData()          //Ĭ�Ϲ��캯��
        :dataheadh(0xee),dataheadl(0xcc),netid(0),nodechannel(0),connectport(0),datalenth(7),sensortype(0),dataend(0xff){};
    //���ƹ��캯��
    SensorRevData (const SensorRevData &org)
    {
        dataheadh = org.dataend;               //���ݵİ�ͷ
        dataheadl = org.dataheadl;             //���ݵİ�ͷ
        netid = org.netid;                     //����ڵ��ʾ
        nodeaddress[0] = org.nodeaddress[0];   //�ڵ��ַ
        nodeaddress[1] = org.nodeaddress[1];
        nodeaddress[2] = org.nodeaddress[2];
        nodeaddress[3] = org.nodeaddress[3];
        nodechannel = org.nodechannel;          //�ڵ������ŵ�
        connectport = org.connectport;          //ͨ�Ŷ˿�
        //quint8 sensorno;                      //��������ǺŽڵ�
        sensortype = org.sensortype;                //�ڵ㴫��������id��
        dataend = org.dataend;                  //���ݵİ�β
    }
    //��ֵ���캯��
    SensorRevData &operator = (const SensorRevData &org)
    {
        dataheadh = org.dataend;               //���ݵİ�ͷ
        dataheadl = org.dataheadl;             //���ݵİ�β
        netid = org.netid;                     //����ڵ��ʾ
        nodeaddress[0] = org.nodeaddress[0];   //�ڵ��ַ
        nodeaddress[1] = org.nodeaddress[1];
        nodeaddress[2] = org.nodeaddress[2];
        nodeaddress[3] = org.nodeaddress[3];
        nodechannel = org.nodechannel;          //�ڵ������ŵ�
        connectport = org.connectport;          //ͨ�Ŷ˿�
        //quint8 sensorno;                      //��������ǺŽڵ�
        sensortype = org.sensortype;                 //�ڵ㴫��������id��

        dataend = org.dataend;
        return *this;
    }

    //���������
    bool operator == (const SensorRevData &org)
    {
       if( dataheadh == org.dataend &&
        dataheadl == org.dataheadl &&
        netid == org.netid &&
        nodechannel == org.nodechannel &&
        connectport == org.connectport &&
        //quint8 sensorno;
        sensortype == org.sensortype &&
        dataend == org.dataend
        )
        return true;
       else
        return false;
    }

};

#endif // SENSORDATA_H

#ifndef SENSORDATA_H
#define SENSORDATA_H
#include <QString>
#include <QtGlobal>

#define ZBID   0x01
#define BTID   0x02
#define WIFIID 0x03

//#define DEVICE_LIGHT          0x01  //光照
//#define DEVICE_GAS_MQ135      0x02  //污染气体MQ135
//#define DEVICE_PM25           0x03  //PM2.5
#define DEVICE_HT11           0x04  //温湿度
//#define DEVICE_HUMAN          0x05  //human
//#define DEVICE_SOUND          0x06  //sound

#define DEVICE_FAN            0x10  //风扇
//#define DEVICE_LAMP           0x11  //LED灯光
#define DEVICE_HOT            0x14  //风扇

#define SETON                 0x01
#define SETOFF                0x00
//信息的命令长度
#define COMDATAMAXLENGTH 18

class SensorRevData{
public:
    quint8 dataheadh;        //数据的头 0xee
    quint8 dataheadl;        //数据的头 0xcc
    quint8 netid;            //所属网络标示
    quint8 nodeaddress[4];   //节点地址
    quint8 nodechannel;      //节点所属信道
    quint8 connectport;      //通信端口
    quint8 datalenth;        //数据长度
    quint8 sensortype;         //传感器标示
    quint8 dataend;          //节点包尾0xff

    SensorRevData()          //默认构造函数
        :dataheadh(0xee),dataheadl(0xcc),netid(0),nodechannel(0),connectport(0),datalenth(7),sensortype(0),dataend(0xff){};
    //复制构造函数
    SensorRevData (const SensorRevData &org)
    {
        dataheadh = org.dataend;               //数据的包头
        dataheadl = org.dataheadl;             //数据的包头
        netid = org.netid;                     //网络节点标示
        nodeaddress[0] = org.nodeaddress[0];   //节点地址
        nodeaddress[1] = org.nodeaddress[1];
        nodeaddress[2] = org.nodeaddress[2];
        nodeaddress[3] = org.nodeaddress[3];
        nodechannel = org.nodechannel;          //节点所属信道
        connectport = org.connectport;          //通信端口
        //quint8 sensorno;                      //所属具体记号节点
        sensortype = org.sensortype;                //节点传感器类型id号
        dataend = org.dataend;                  //数据的包尾
    }
    //赋值构造函数
    SensorRevData &operator = (const SensorRevData &org)
    {
        dataheadh = org.dataend;               //数据的包头
        dataheadl = org.dataheadl;             //数据的包尾
        netid = org.netid;                     //网络节点标示
        nodeaddress[0] = org.nodeaddress[0];   //节点地址
        nodeaddress[1] = org.nodeaddress[1];
        nodeaddress[2] = org.nodeaddress[2];
        nodeaddress[3] = org.nodeaddress[3];
        nodechannel = org.nodechannel;          //节点所属信道
        connectport = org.connectport;          //通信端口
        //quint8 sensorno;                      //所属具体记号节点
        sensortype = org.sensortype;                 //节点传感器类型id号

        dataend = org.dataend;
        return *this;
    }

    //重载运算符
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

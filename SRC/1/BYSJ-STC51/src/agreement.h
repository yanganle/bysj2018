/******************************
** @time；2018/08/15 11:26:02
** @Author: superman
** @email: ***@qq.com
** @brief: 通讯定义
*******************************/
#include <reg52.h>
#include <stdio.h>

#define DATA_LENGTH 	            0x12
#define MAX_SENSOR_LENGTH 	      4

//命令ID
#define CMDID_UP									0x6A
#define CMDID_DOWN								0x80
#define CMDID_MODE								0x2A

//通讯头
#define DATA_HEADH 	0xEE
#define DATA_HEADL 	0xCC
#define DATA_END  	0xFF

//传感器
//#define DEVICE_LIGHT          0x01  //光照
//#define DEVICE_GAS_MQ135      0x02  //MQ135
//#define DEVICE_PM25           0x03  //PM2.5
#define SENSOR_DHT11		  0x04   //温湿度检测
#define SENSOR_HUMAN			0x05   //人体检测
#define SENSOR_SOUND			0x06	 //声响检测

#define SENSOR_FAN				0x10   //风扇
#define SENSOR_LAMP				0x11   //灯光

typedef struct  sensor{
		u8 sensorType; //传感器类型
		u8 sensorID;//传感器ID
		u8 sensorPostion;//传感器位置
		u8 Sensorvalue[MAX_SENSOR_LENGTH];//传感器数据
}sensorData;

typedef union {
	u8 dataArry[DATA_LENGTH];
	struct {	
		u8 dataHeadH; //包头
		u8 dataHeadL; //包头
		u8 nodeNetID; //网络ID
		u8 nodeAddr[4]; //网络短地址
		u8 nodeChannel;//物理信道
		u8 nodePort;//PORT
		u8 dataID;//数据命令ID
		sensorData value;//传感器包数据
		u8 dataEnd;
	}dataDetail;
}agreementData;

extern u8 TEMPTHRESHOLD,SMARTMODE;
void Send_SensorData(u8 _SensorStyle, u8 _SenserIndex, u8 *_pData);
void agreementParse(u8 *str);//协议解析接口

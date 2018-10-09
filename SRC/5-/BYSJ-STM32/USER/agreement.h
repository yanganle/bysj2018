#include "sys.h"

#define DATA_LENGTH 	            18

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
#define SENSOR_DHT11		  		0x04  //温湿度检测
//#define SENSOR_HUMAN			0x05   //人体检测
//#define SENSOR_SOUND			0x06	 //声响检测
//#define SENSOR_SHAKE			0x07	 //震动检测
//#define SENSOR_DS18B20			0x08	 //温度检测
//#define SENSOR_PH						0x09	 //PH值检测
//#define SENSOR_WATERLEVEL		0x0A	 //水位检测
#define SENSOR_MEDICINE		  	0x0D  //药品

#define SENSOR_FAN				0x10   //风扇
//#define SENSOR_LAMP				0x11   //灯光
//#define SENSOR_SL_ALARM		0x12   //声光报警
//#define SENSOR_WATER_PUMP		0x13	 //水泵
#define SENSOR_HOT				0x14   //加热

typedef union {
	u8 dataArry[DATA_LENGTH];
	struct {	
		u8 HeadH; //包头
		u8 HeadL; //包头
		u8 NetID;
		u8 Addr[4];//网络短地址
		u8 Channel;
		u8 NetPort;
		u8 CmdID; //数据命令ID
		u8 sType; //传感器类型
		u8 sIndex; //传感器类型
		u8 sPosition;
		u8 sValue[4];//传感器数据
		u8 dataEnd;//结束符
	}dataDet;
}sysData;

extern u8 SMARTMODE;
extern u8 tempup_threshold;
extern u8 tempdown_threshold;
extern u8 humi_threshold;

void Send_SensorData(u8 _SensorStyle, u8 _SenserIndex, u8 *_pData);
void agreementParse(u8 *str);//协议解析接口

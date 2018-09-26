/******************************
** @time；2018/08/15 11:26:02
** @Author: superman
** @email: ***@qq.com
** @brief: 通讯定义
*******************************/
#include "hal_types.h"

#define DATA_AGREEMENT_LENGTH 	  18
#define MAX_SENSOR_LENGTH 	   4
#define SENSOR_DATA_LENGTH 	   7

//通讯头
#define DATA_HEADH 	0xEE
#define DATA_HEADL 	0xCC
#define DATA_END  	0xFF
//网络ID
#define NWK_ZIGBEE 	0x01
#define NWK_BLUE  	0x02
#define NWK_WIFI 	0x03

typedef  unsigned char u8;

typedef struct  sensor{
		uint8 sensorType; //传感器类型
		uint8 sensorID;//传感器ID
		uint8 sensorPostion;//传感器位置
		uint8 SensorData[MAX_SENSOR_LENGTH];      //传感器数据
}sensorData;

typedef union {
	uint8 dataArry[DATA_AGREEMENT_LENGTH];
	struct {	
		uint8 dataHeadH; //包头
		uint8 dataHeadL; //包头
		uint8 nodeNetID; //网络ID
		uint8 nodeAddr[4]; //网络短地址
		uint8 nodeChannel;//物理信道
		uint8 nodePort;//PORT
		uint8 dataLenth;//数据域长度
		sensorData data;//传感器包数据
		uint8 dataEnd;
	}dataDetail;
}agreementData;

void *agreementParse(unsigned char *str);//协议解析接口

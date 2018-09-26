

/******************************
** @time；2017/11/9 18:10:14
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief: 通讯定义
*******************************/ 
#include "STC15Wxxxx.h"

//通讯头
#define CBT_HEADH 	0xEE
#define CBT_HEADL 	0xCC

#define MAX_SENSOR_LENGTH 	20
/******IO控制类*********/
#define SENSOR_RELAY			0x12   //继电器
#define SENSOR_ALARM			0x10//声光报警
#define SENSOR_MOTOR			0x11 	//步进电机
#define SENSOR_LED				0x13 		//LED灯

/******IO检测类*********/
#define SENSOR_MAGNETIC		0x01   //磁检测
#define SENSOR_INFRARED_REFLECTANCE			0x02   //红外反射
#define SENSOR_WAVE			0x03   //超声波
#define SENSOR_IRDA			0x04   //红外遥控
#define SENSOR_TRACK			0x05   //循迹
#define SENSOR_BODY			0x06   //人体
#define SENSOR_CRASH			0x07   //碰撞
#define SENSOR_KEY			0x08   //按键

/******ADC采集类*********/
#define SENSOR_VOLTAGE			0x20   //电压检测
#define SENSOR_LIGHT			0x21   //光照
#define SENSOR_GAS		0x22   //可燃气
#define SENSOR_SHAKE			0x23   //震动检测
#define SENSOR_PRESSURE			0x24   //压力检测
#define SENSOR_FIRE			0x25   //火焰检测
#define SENSOR_WINE			0x26   //酒精检测
#define SENSOR_VOICE			0x27   //声响检测
#define SENSOR_DEW			0x28   //结露传感器
#define SENSOR_METHANAL		0x29   //甲醛检测
#define SENSOR_CO2			0x2A   //二氧化碳
#define SENSOR_CURRENT	0x2B   //电流检测
#define SENSOR_JOKER			0x2D   //五向摇杆

/******PWM控制类*********/
#define SENSOR_FAN     		0x31   //调速风扇    返回0~20级，发送1加快，0减慢
#define SENSOR_DUST			0x30   //粉尘传感器

/******IIC通讯类*********/
#define SENSOR_AM231		  0x41   //温湿度检测
#define SENSOR_MPU9250		0x40   //人体姿态
#define SENSOR_BMP180			0x43   //气压检测
#define SENSOR_GESTURE  0x42//手势识别

/******SPI通讯类*********/
#define SENSOR_TUBE		0x50   //数码管

/******UART通讯类*********/
#define SENSOR_SPEAK		0x60   //语音模块
#define SENSOR_FINGER			0x61   //指纹模块



//通讯方式类
#define  COMMUNICATION_ZIGBEE  0x00
#define  COMMUNICATION_IPV6  0x01
#define  COMMUNICATION_BLUETOOTH  0x02
#define  COMMUNICATION_WIFI  0x03
#define  COMMUNICATION_433M  0x04

//typedef  unsigned char u8;


typedef struct  sensor{
		u8 sensorType; //传感器类型
		u8 sensorID;//传感器ID
		u8 sensorCMD;        //节点命令序号
		u8 sensorDataLen;      //传感器数据长度n
		u8 SensorData[MAX_SENSOR_LENGTH];      //传感器数据
}sensorData;


typedef struct zigbee{
	u8 nodeAddr[4]; //网络短地址
	u8 nodeChannel;//物理信道
	u8 nodePanID;//PANID
	u8 nodeMacAddr[8];//mac地址
	sensorData sensorDa;//传感器包数据
}zigbeeData;

typedef struct ipv6{
	u8 nodeAddr[4]; //网络短地址
	u8 nodeMacAddr[8];//mac地址
	sensorData sensorDa;//传感器包数据
}ipv6Data;

typedef struct bluetooth{
	u8 nodeAddr[4];  //UUID节点唯一标识符
	u8 nodeRssi;
	u8 nodeMacAddr[8];//mac地址
	sensorData sensorDa;//传感器包数据
}bluetoothData;

typedef struct wifi{
	u8 nodeAddr[4]; //IPV4地址
	u8 nodePortH;//端口号高8位
	u8 nodePortL;//端口号低8位
	u8 nodeMacAddr[8];//mac地址
	sensorData sensorDa;//传感器包数据
}wifiData;

typedef struct m433{
	u8 nodeAddr[4]; //网络短地址
	u8 nodeMacAddr[8];//mac地址
	sensorData sensorDa;//传感器包数据
}m433Data;


void* agreementParse(unsigned char *str);//协议解析接口



/******************************
** @time��2017/11/9 18:10:14
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief: ͨѶ����
*******************************/ 
#include "STC15Wxxxx.h"

//ͨѶͷ
#define CBT_HEADH 	0xEE
#define CBT_HEADL 	0xCC

#define MAX_SENSOR_LENGTH 	20
/******IO������*********/
#define SENSOR_RELAY			0x12   //�̵���
#define SENSOR_ALARM			0x10//���ⱨ��
#define SENSOR_MOTOR			0x11 	//�������
#define SENSOR_LED				0x13 		//LED��

/******IO�����*********/
#define SENSOR_MAGNETIC		0x01   //�ż��
#define SENSOR_INFRARED_REFLECTANCE			0x02   //���ⷴ��
#define SENSOR_WAVE			0x03   //������
#define SENSOR_IRDA			0x04   //����ң��
#define SENSOR_TRACK			0x05   //ѭ��
#define SENSOR_BODY			0x06   //����
#define SENSOR_CRASH			0x07   //��ײ
#define SENSOR_KEY			0x08   //����

/******ADC�ɼ���*********/
#define SENSOR_VOLTAGE			0x20   //��ѹ���
#define SENSOR_LIGHT			0x21   //����
#define SENSOR_GAS		0x22   //��ȼ��
#define SENSOR_SHAKE			0x23   //�𶯼��
#define SENSOR_PRESSURE			0x24   //ѹ�����
#define SENSOR_FIRE			0x25   //������
#define SENSOR_WINE			0x26   //�ƾ����
#define SENSOR_VOICE			0x27   //������
#define SENSOR_DEW			0x28   //��¶������
#define SENSOR_METHANAL		0x29   //��ȩ���
#define SENSOR_CO2			0x2A   //������̼
#define SENSOR_CURRENT	0x2B   //�������
#define SENSOR_JOKER			0x2D   //����ҡ��

/******PWM������*********/
#define SENSOR_FAN     		0x31   //���ٷ���    ����0~20��������1�ӿ죬0����
#define SENSOR_DUST			0x30   //�۳�������

/******IICͨѶ��*********/
#define SENSOR_AM231		  0x41   //��ʪ�ȼ��
#define SENSOR_MPU9250		0x40   //������̬
#define SENSOR_BMP180			0x43   //��ѹ���
#define SENSOR_GESTURE  0x42//����ʶ��

/******SPIͨѶ��*********/
#define SENSOR_TUBE		0x50   //�����

/******UARTͨѶ��*********/
#define SENSOR_SPEAK		0x60   //����ģ��
#define SENSOR_FINGER			0x61   //ָ��ģ��



//ͨѶ��ʽ��
#define  COMMUNICATION_ZIGBEE  0x00
#define  COMMUNICATION_IPV6  0x01
#define  COMMUNICATION_BLUETOOTH  0x02
#define  COMMUNICATION_WIFI  0x03
#define  COMMUNICATION_433M  0x04

//typedef  unsigned char u8;


typedef struct  sensor{
		u8 sensorType; //����������
		u8 sensorID;//������ID
		u8 sensorCMD;        //�ڵ��������
		u8 sensorDataLen;      //���������ݳ���n
		u8 SensorData[MAX_SENSOR_LENGTH];      //����������
}sensorData;


typedef struct zigbee{
	u8 nodeAddr[4]; //����̵�ַ
	u8 nodeChannel;//�����ŵ�
	u8 nodePanID;//PANID
	u8 nodeMacAddr[8];//mac��ַ
	sensorData sensorDa;//������������
}zigbeeData;

typedef struct ipv6{
	u8 nodeAddr[4]; //����̵�ַ
	u8 nodeMacAddr[8];//mac��ַ
	sensorData sensorDa;//������������
}ipv6Data;

typedef struct bluetooth{
	u8 nodeAddr[4];  //UUID�ڵ�Ψһ��ʶ��
	u8 nodeRssi;
	u8 nodeMacAddr[8];//mac��ַ
	sensorData sensorDa;//������������
}bluetoothData;

typedef struct wifi{
	u8 nodeAddr[4]; //IPV4��ַ
	u8 nodePortH;//�˿ںŸ�8λ
	u8 nodePortL;//�˿ںŵ�8λ
	u8 nodeMacAddr[8];//mac��ַ
	sensorData sensorDa;//������������
}wifiData;

typedef struct m433{
	u8 nodeAddr[4]; //����̵�ַ
	u8 nodeMacAddr[8];//mac��ַ
	sensorData sensorDa;//������������
}m433Data;


void* agreementParse(unsigned char *str);//Э������ӿ�

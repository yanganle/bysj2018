/******************************
** @time��2018/08/15 11:26:02
** @Author: superman
** @email: ***@qq.com
** @brief: ͨѶ����
*******************************/
#include <reg52.h>
#include <stdio.h>

#define DATA_LENGTH 	            0x12
#define MAX_SENSOR_LENGTH 	      4

//����ID
#define CMDID_UP									0x6A
#define CMDID_DOWN								0x80
#define CMDID_MODE								0x2A

//ͨѶͷ
#define DATA_HEADH 	0xEE
#define DATA_HEADL 	0xCC
#define DATA_END  	0xFF

//������
//#define DEVICE_LIGHT          0x01  //����
//#define DEVICE_GAS_MQ135      0x02  //MQ135
//#define DEVICE_PM25           0x03  //PM2.5
#define SENSOR_DHT11		  0x04   //��ʪ�ȼ��
#define SENSOR_HUMAN			0x05   //������
#define SENSOR_SOUND			0x06	 //������

#define SENSOR_FAN				0x10   //����
#define SENSOR_LAMP				0x11   //�ƹ�

typedef struct  sensor{
		u8 sensorType; //����������
		u8 sensorID;//������ID
		u8 sensorPostion;//������λ��
		u8 Sensorvalue[MAX_SENSOR_LENGTH];//����������
}sensorData;

typedef union {
	u8 dataArry[DATA_LENGTH];
	struct {	
		u8 dataHeadH; //��ͷ
		u8 dataHeadL; //��ͷ
		u8 nodeNetID; //����ID
		u8 nodeAddr[4]; //����̵�ַ
		u8 nodeChannel;//�����ŵ�
		u8 nodePort;//PORT
		u8 dataID;//��������ID
		sensorData value;//������������
		u8 dataEnd;
	}dataDetail;
}agreementData;

extern u8 TEMPTHRESHOLD,SMARTMODE;
void Send_SensorData(u8 _SensorStyle, u8 _SenserIndex, u8 *_pData);
void agreementParse(u8 *str);//Э������ӿ�

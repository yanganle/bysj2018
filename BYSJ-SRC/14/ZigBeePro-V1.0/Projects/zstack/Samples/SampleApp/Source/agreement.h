/******************************
** @time��2018/08/15 11:26:02
** @Author: superman
** @email: ***@qq.com
** @brief: ͨѶ����
*******************************/
#include "hal_types.h"

#define DATA_AGREEMENT_LENGTH 	  18
#define MAX_SENSOR_LENGTH 	   4
#define SENSOR_DATA_LENGTH 	   7

//ͨѶͷ
#define DATA_HEADH 	0xEE
#define DATA_HEADL 	0xCC
#define DATA_END  	0xFF
//����ID
#define NWK_ZIGBEE 	0x01
#define NWK_BLUE  	0x02
#define NWK_WIFI 	0x03

typedef  unsigned char u8;

typedef struct  sensor{
		uint8 sensorType; //����������
		uint8 sensorID;//������ID
		uint8 sensorPostion;//������λ��
		uint8 SensorData[MAX_SENSOR_LENGTH];      //����������
}sensorData;

typedef union {
	uint8 dataArry[DATA_AGREEMENT_LENGTH];
	struct {	
		uint8 dataHeadH; //��ͷ
		uint8 dataHeadL; //��ͷ
		uint8 nodeNetID; //����ID
		uint8 nodeAddr[4]; //����̵�ַ
		uint8 nodeChannel;//�����ŵ�
		uint8 nodePort;//PORT
		uint8 dataLenth;//�����򳤶�
		sensorData data;//������������
		uint8 dataEnd;
	}dataDetail;
}agreementData;

void *agreementParse(unsigned char *str);//Э������ӿ�

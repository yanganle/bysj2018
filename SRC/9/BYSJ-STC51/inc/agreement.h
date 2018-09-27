#include <reg52.h>
#include <stdio.h>

#define DATA_LENGTH 	            14

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
//#define SENSOR_DHT11		  		0x04  //��ʪ�ȼ��
#define SENSOR_HUMAN			0x05   //������
//#define SENSOR_SOUND			0x06	 //������
#define SENSOR_SHAKE			0x07	 //�𶯼��

#define SENSOR_FAN				0x10   //����
#define SENSOR_LAMP				0x11   //�ƹ�
#define SENSOR_SL_ALARM		0x12   //���ⱨ��


typedef union {
	u8 dataArry[DATA_LENGTH];
	struct {	
		u8 HeadH; //��ͷ
		u8 HeadL; //��ͷ
		u8 Addr[4]; //����̵�ַ
		u8 CmdID; //��������ID
		u8 sType; //����������
		u8 sIndex; //����������
		u8 sValue[4];//����������
		u8 dataEnd;//������
	}dataDet;
}sysData;

extern u8 SMARTMODE;

void Send_SensorData(u8 _SensorStyle, u8 _SenserIndex, u8 *_pData);
void agreementParse(u8 *str);//Э������ӿ�

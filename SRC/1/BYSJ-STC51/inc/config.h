

/******************************
** @time��2017/11/6 16:30:40
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief:	�Զ�ģʽʱ�����õ���ֵ
*******************************/ 

#ifndef __CONFIG_H__
#define __CONFIG_H__


//���ഫ������ֵ
#define LIGHT_SETTING 	2
#define SMOKE_SETTING 	20
#define TEMP_SETTING 		24
#define HUMI_SETTING 		60
#define FAN_SPEED_SETTING 	280
#define FAN_SPEED_SETTING_LOW 0
#define DUST_SETTING  1
#define SHAKE_SETTING 20


//���ִ�������ʾ��ַ
#define TEMP_ADDR_DISPLAY  			0x0020  //�¶���ʾ��ַ
#define HUMI_ADDR_DISPLAY   		0x0010  //ʪ����ʾ��ַ
#define LIGHT_ADDR_DISPLAY 			0x0030 //����ǿ��
#define SMOKE_ADDR_DISPLAY   0x0040   //����
#define DUST_ADDR_DISPLAY  0x0050  //�۳�
#define FAN_ADDR_DISPLAY  0x0070  //����״̬��ͼ��
#define RELAY_ADDR_DISPLAY 0x0060 //�̵���״̬��ͼ��
#define MODE_ADDR_DISPLAY 		0x00A0 //ģʽ״̬
#define DISTANCE_ADDR_DISPLAY 0x00C0 //����������
#define SHAKE_ADDR_DISPLAY  	0x00D0 //����ʾ
#define CO2_ADDR_DISPLAY 			0x00E0 //CO2��ʾ
#define ALARM_ADDR_DISPLAY 		0x00F0 //���ⱨ����ʾ��ַ

#define MPU9960_ADDR_AX_DISPLAY  0X0100 //x���ٶ�
#define MPU9960_ADDR_AY_DISPLAY  0X0110 //y���ٶ�
#define MPU9960_ADDR_AZ_DISPLAY  0X0120 //z���ٶ�
#define MPU9960_ADDR_WX_DISPLAY  0X0130 //x���ٶ�
#define MPU9960_ADDR_WY_DISPLAY  0X0140 //y���ٶ�
#define MPU9960_ADDR_WZ_DISPLAY  0X0150 //z���ٶ�
#define MPU9960_ADDR_MAX_DISPLAY  0X0160 //x�ش�
#define MPU9960_ADDR_MAY_DISPLAY  0X0170 //y�ش�
#define MPU9960_ADDR_MAZ_DISPLAY  0X0180 //z�ش�
#define MPU9960_ADDR_TEMP_DISPLAY 0x0190 //�¶�

#define GESTYRE_ADDR_DISPLAY  0x01A0 //������ʾ
#define BATTERY_ADDR_DISPLAY  0x01B0 //��ʾ���
#define LED_GREEN_ADDR_DISPLAY  0x01C0 //��ʾ�̵�
#define LED_YELLOW_ADDR_DISPLAY  0x01D0 //��ʾ�Ƶ�
#define LED_RED_ADDR_DISPLAY   0x01E0 //��ʾ���
#define FINGER_ADDR_DISPLAY  0x01F0 //��ʾָ��
#define COMMUNICATION_ADDR_DISPLAY  0x0200 //��ʾͨѶ��ʽ
#define CARSH_ADDR_DISPLAY 		0x0210 //��ײ���


#define FAN_CONTROL_ADDR  0x0080   //���ȿ��Ƶ�ַ
#define RELAY_CONTROL_ADDR 0x0090  //�̵������Ƶ�ַ
#define MODE_CONTROL_ADDR 	0x00B0 //ģʽ���Ƶ�ַ





///#define FAN_CONTROL_KEY_VALUE 		 0x0001
//#define RELAY_CONTROL_KEY_VALUE 		0x0002


#endif

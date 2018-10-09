

/******************************
** @time��2017/11/6 15:22:01
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief: �����¶Ȳɼ���ʾ
*******************************/ 



#ifndef __DISPLAY_H__
#define __DISPLAY_H__

void display_temp (float temp);//��ʾ�¶�
void display_humi (float humi);//��ʾʪ��
void display_pm (float dust);//��ʾ�۳�Ũ��
void display_smoke (float smoke);//��ʾ����Ũ��
void display_light (float light);//��ʾ����ǿ��
void display_mode (unsigned char);//��ʾ��ǰģʽ
void display_fan_speed(unsigned int speed);//��ʾ��ǰ����ת��
void display_relay(unsigned char);//��ʾ�̵���״̬
void display_mode (unsigned char mode);//��ʾ��ǰ����ģʽ
void display_shake (float shake);//��ʾ��״̬
void display_interface(unsigned short interfanceNum);//�л�����
void display_distance(float distance);//��ʾ����
void display_CO2(float co2);//��ʾCO2Ũ��
void display_alarm(unsigned char );//���ⱨ����ʾ
void display_mpu9960(float ax,float ay,float az,float wx,float wy,float wz,float max,float may,float maz,float temp);//��ʾmpu9960 ����


void display_gestrue(unsigned char num);//��ʾ����
void display_battery(unsigned char bat);//��ʾ����
void display_led(unsigned char rl,unsigned char yl,unsigned char gl);
void display_finger(unsigned char status);//��ʾָ��
void display_communication(unsigned char status);//��ʾͨѶ��ʽ
void display_carsh(unsigned char status);//��ʾ��ײ

#endif

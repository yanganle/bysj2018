#ifndef __DHT11_H__
#define __DHT11_H__

#define uchar unsigned char
#define uint16 unsigned short
extern void Delay_ms(unsigned int xms);	//��ʱ����
extern void COM(void);                  // ��ʪд��
extern void GetHt11Value(void);         //��ʪ��������

extern uchar temp1[5];
extern uchar humidity[2];
extern uchar humidity1[9];
extern uint16 temp,humi;

#endif
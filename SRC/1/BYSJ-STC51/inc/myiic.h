#ifndef	_MYIIC_H
#define	_MYIIC_H
#include "STC15Wxxxx.H"

void IIC_Init();             //��ʼ��
void IIC_Start();       //�����ź�
void IIC_Stop();            //ֹͣ�ź�
u8 IIC_Wait_Ack();             //��Ӧ�ź�
void IIC_Ack(); 					//����Ӧ���ź�
void IIC_Nack();//������Ӧ���ź�

void IIC_Send_Byte(u8 date);//дһ���ֽ�
u8 IIC_Read_Byte(u8 ack);//��һ���ֽ�

#endif
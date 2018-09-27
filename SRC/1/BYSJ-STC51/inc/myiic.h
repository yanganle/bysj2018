#ifndef	_MYIIC_H
#define	_MYIIC_H
#include "STC15Wxxxx.H"

void IIC_Init();             //初始化
void IIC_Start();       //启动信号
void IIC_Stop();            //停止信号
u8 IIC_Wait_Ack();             //回应信号
void IIC_Ack(); 					//产生应答信号
void IIC_Nack();//不产生应答信号

void IIC_Send_Byte(u8 date);//写一个字节
u8 IIC_Read_Byte(u8 ack);//读一个字节

#endif
#ifndef __AM231X_H
#define __AM231X_H
#include "STC15Wxxxx.H"
#include "myiic.h"
#include "uart.h"
#include "delay.h"
#include "stdio.h"

//内部数据定义
#define IIC_Add 0xB8    //器件地址
#define IIC_RX_Length 15


u8 WriteNByte(unsigned char sla,unsigned char *s,unsigned char n);
u8 ReadNByte(unsigned char Sal, unsigned char *p,unsigned char n);
unsigned int CRC16(unsigned char *ptr, unsigned char len);
unsigned char CheckCRC(unsigned char *ptr,unsigned char len);
void Waken(void);
unsigned char AM231X_getValue(float* tempValue,float* humiValue);
void Clear_Data (void);

#endif

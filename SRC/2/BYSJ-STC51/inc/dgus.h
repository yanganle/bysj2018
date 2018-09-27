#ifndef __DGUS_H__
#define __DGUS_H__

#include "uart3.h"

#define uchar unsigned char 
#define ushort unsigned short

#define CMD_WRITE_REG  0x80
#define CMD_READ_REG  0x81
#define CMD_WIRTE_VAR 	0x82
#define CMD_READ_VAR 		0x83
#define CMD_CURVE_BUFFER 0x84


#define REG_ADDR_INTERFACE 		0x03


#define HEADH 	0xA5
#define HEADL 	0x5A
#define DGUS_STA  uart3RxSta	
#define DGUS_RX_BUF  UART3_RX_BUF
#define DGUS_RX_COUNT  uart3RxCount
#define dgusSentOneByte(x)  uart3SendData(x)

#define DGUS_MAX_READ_LENGTH  10

typedef struct dgusReg
{
	ushort regAddr;
	ushort regValue;
}dgusReg;

extern dgusReg dgusRx[DGUS_MAX_READ_LENGTH]; 

void sentHead (void);//发送帧头
void dgusWrite(uchar addr,ushort myData);//写寄存器
void dgusReadNbyte(uchar addr,uchar length);//读寄存器
void dgusWriteVar(ushort varAddr,ushort varData);//写变量地址
void dgusReadVar(ushort varAddr,uchar length);//读变量地址
void dgusDrawCurve(uchar mode,ushort* chData);//曲线绘制寄存器
void dgusDealKeyValue (void);//处理返回变量寄存器的数据
void dgusClear(uchar i);//清除数据



#endif


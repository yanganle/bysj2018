#include"uart2.h"

sfr AUXR1 = 0xA2;
sfr	AUXR = 0x8E;
sfr S2CON = 0x9A;	//12C5A60S2双串口系列
sfr S2BUF = 0x9B;	//12C5A60S2双串口系列
sfr IE2   = 0xAF;	//STC12C5A60S2系列
sfr BRT   = 0x9C;

bit busy2;
u8 UART2_RX_BUF[BUFFER_LENGTH];
u8 uart2RxSta = 0;
u8 uart2RxCount;
u8 uart2RxTimeOut;
u8 flag_uart2_rx;

void Uart2Init(void)		//9600@12.000MHz
{
	AUXR |=  (1 << 3);		//串口2波特率加倍
	S2CON  = (S2CON & 0x3f) | (1<<6);	//串口2模式1，8位UART，(2^S2SMOD / 32) * BRT溢出率
	S2CON |= 1 << 4;		//允许串2接收

	AUXR |=  1 << 4;	//baudrate use BRT
	BRT = BRT_Reload;

	IE2 |=  1;			//允许串口2中断
}

/*----------------------------
UART2 中断服务程序
-----------------------------*/
void Uart2() interrupt 8 using 1
{
	if (RI2)
	{
		CLR_RI2();         //清除S2RI位
		if (uart2RxSta == 0) flag_uart2_rx = 1;
		if(uart2RxCount < BUFFER_LENGTH){
			uart2RxTimeOut = TIME_OUT;
			UART2_RX_BUF[uart2RxCount++] = S2BUF;
		}else{
			uart2RxSta = 1;
    	uart2RxCount = 0;
		}
	}
	if (TI2)
	{
			CLR_TI2();         //清除S2TI位
			busy2 = 0;         //清忙标志
	}
}

/*----------------------------
发送串口数据
----------------------------*/
void SendData(u8 dat)
{
	  S2BUF = dat;                //写数据到UART2数据寄存器
    busy2 = 1;
	  while (busy2);               //等待前面的数据发送完成
}

/*----------------------------
发送字符串
----------------------------*/
void UART2_SendString(char *s)
{
    while (*s)                  //检测字符串结束标志
    {
        SendData(*s++);         //发送当前字符
    }
}

void uart2SendData(char *buffer, u8 datalen)
{
	u8 i;
	for(i=0;i<datalen;i++)
		SendData(buffer[i]);
}

void clearBuf2(){
	u8 i;
	for(i = 0; i < BUFFER_LENGTH;i++){
		UART2_RX_BUF[i] = 0;
		uart2RxCount = 0;
	}
}



/******************************
** @time；2017/11/17 14:30:17
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief:
*******************************/ 

#include "uart3.h"

bit busy3;
u8 UART3_RX_BUF[BUFFER_LENGTH];
u8 uart3RxSta = 0;
u8 uart3RxCount;
u8 uart3RxTimeOut;
u8 flag_uart3_rx;

void Uart3Init(void)		//115200bps@24.000MHz
{
	P_SW2 &= ~0x02; 
	S3CON = 0x10;		//8位数据,可变波特率
	S3CON &= 0xBF;		//串口3选择定时器2为波特率发生器
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
	T2L = 0xCC;		//设定定时初值
	T2H = 0xFF;		//设定定时初值
	AUXR |= 0x10;		//启动定时器2
	S3_Int_Enable();
	S3_RX_Enable();
}

/*----------------------------
UART3 中断服务程序
-----------------------------*/
void Uart3() interrupt 17 using 1
{
    if (RI3)
    {
       CLR_RI3(); 
			 if (uart3RxSta == 0) flag_uart3_rx = 1;
			 if(uart3RxCount < BUFFER_LENGTH){
			 uart3RxTimeOut = TIME_OUT;
			 UART3_RX_BUF[uart3RxCount++] = S3BUF;
			 }else{
			 uart3RxSta = 1;
    	uart3RxCount = 0;
			}
		}
    if (TI3)
    {
			CLR_TI3();
        busy3 = 0;               //清忙标志
    }
}

/*----------------------------
发送串口数据
----------------------------*/
void uart3SendData(char dat)
{
    while (busy3);               //等待前面的数据发送完成
    busy3 = 1;
    S3BUF = dat;                //写数据到UART3数据寄存器
}

/*----------------------------
发送字符串
----------------------------*/
void uart3SendString(char *s)
{
    while (*s)                  //检测字符串结束标志
    {
        uart3SendData(*s++);         //发送当前字符
    }
}

void clearBuf3(void)
{
	int i;
	for (i=0; i<BUFFER_LENGTH; i++)
	{
		UART3_RX_BUF[i] = 0;
		uart3RxCount = 0;
	}
}

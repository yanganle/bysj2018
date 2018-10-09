#include "uart.h"

bit busy;
u8 UART_RX_BUF[BUFFER_LENGTH];
u8 uartRxSta = 0;
u8 uartRxCount;
u8 uartRxTimeOut;
u8 flag_uart_rx;

unsigned char cmd;

void UartInit(void)		//115200bps@24.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;
	TMOD |= 0x20;		//设定定时器1为16位自动重装方式
	TH1 = 256-MAIN_Fosc/(Baud_Rate*12*16);			//设定定时初值
	TL1 = 256-MAIN_Fosc/(Baud_Rate*12*16);			//设定定时初值
	PCON |= 0x80;     //波特率加倍
	ES = 1;					//串行中断允许
	TR1 = 1;				//启动定时器1
	REN = 1;        //允许接收
	EA = 1; 				//开启总中断
}

/*----------------------------
UART 中断服务程序
-----------------------------*/
void Uart() interrupt 4
{
    if (RI)
    {
        RI = 0;                 //清除RI位
				if (uartRxSta == 0) flag_uart_rx = 1;
				if(uartRxCount < BUFFER_LENGTH)
				{
					uartRxTimeOut = TIME_OUT;
					UART_RX_BUF[uartRxCount++] = SBUF;
				}else{
					uartRxSta = 1;
					uartRxCount = 0;
				}
    }
    if (TI)
    {
        TI = 0;                 //清除TI位
        busy = 0;               //清忙标志
    }
}


/*----------------------------
发送串口数据
----------------------------*/
void Putchar(char dat)
{
    SBUF = dat;                //写数据到UART3数据寄存器
	  busy = 1;
	  while (busy);               //等待前面的数据发送完成
}

/*----------------------------
发送字符串
----------------------------*/
void uartSendString(char *s)
{
    while (*s)                  //检测字符串结束标志
    {
        Putchar(*s++);         //发送当前字符
    }
}

void uartSendData(char *buffer, u8 datalen)
{
	u8 i;
	for(i=0;i<datalen;i++)
		Putchar(buffer[i]);
}

void clearBuf(void)
{
	int i;
	for (i=0; i<BUFFER_LENGTH; i++)
	{
		UART_RX_BUF[i] = 0;
		uartRxCount = 0;
	}
}

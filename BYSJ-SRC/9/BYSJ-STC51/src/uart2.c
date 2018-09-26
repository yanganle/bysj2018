#include"uart2.h"

#define S2RI  0x01              //S2CON.0
#define S2TI  0x02              //S2CON.1
#define TIME_OUT 		40

bit busy2;
u8 UART2_RX_BUF[BUFFER_LENGTH];
u8 uart2RxSta = 0;
u8 uart2RxCount;
u8 uart2RxTimeOut;
u8 flag_uart2_rx;



void Uart2Init(void)		//115200@24.000MHz
{
	P_SW2 &= ~0x01;
	S2CON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
//	T2L = 0x98;		//设定定时初值
//	T2H = 0xFF;		//设定定时初值
	T2L = 0xCC;		//设定定时初值
	T2H = 0xFF;		//设定定时初值
	AUXR |= 0x10;		//启动定时器2
	
	UART2_INT_ENABLE();
	S2_RX_Enable();
}

/*----------------------------
UART2 中断服务程序
-----------------------------*/
void Uart2() interrupt 8 using 1
{
    if (S2CON & S2RI)
    {
        S2CON &= ~S2RI;         //清除S2RI位
		if (uart2RxSta == 0) flag_uart2_rx = 1;
		if(uart2RxCount < BUFFER_LENGTH){
			uart2RxTimeOut = TIME_OUT;
			UART2_RX_BUF[uart2RxCount++] = S2BUF;
		}else{
			uart2RxSta = 1;
    	uart2RxCount = 0;
		}
    }
    if (S2CON & S2TI)
    {
        S2CON &= ~S2TI;         //清除S2TI位
        busy2 = 0;               //清忙标志
    }
}

/*----------------------------
发送串口数据
----------------------------*/
void SendData(u8 dat)
{
    while (busy2);               //等待前面的数据发送完成
    busy2 = 1;
    S2BUF = dat;                //写数据到UART2数据寄存器
}

/*----------------------------
发送字符串
----------------------------*/
void SendString2(char *s)
{
    while (*s)                  //检测字符串结束标志
    {
        SendData(*s++);         //发送当前字符
    }
}
void clearBuf2(){
	unsigned char i;
	for(i = 0; i < BUFFER_LENGTH;i++){
		UART2_RX_BUF[i] = 0;
		uart2RxCount = 0;
	}
}

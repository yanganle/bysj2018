#include "mysys.h"
#include "uart.h"
#include "uart2.h"

u32 heartBeat;
u8 flag_taskOne = 0;
u8 flag_taskTwo = 0;
u8 flag_taskThree = 0;
u8 flag_taskFour = 0;
u8 flag_taskFive = 0;

void mysysinit()
{
	TMOD &= 0xF0;
	TMOD |= 0x01;    //设置为16位自动重装定时器，溢出值自动重装入TL0和TH0中
	TH0=(65536-46080)/256; //50ms = 46080 进入中断
	TL0=(65536-46080)%256;
	TR0 = 1;				//定时器0的运行控制位
	ET0 = 1;				//定时器0的中断允许控制位
	EA = 1;					//打开总中断
}

// 描述: timer0中断函数.50ms
// 中断时间太短会导致串口异常
void timer0(void) interrupt TIMER0_VECTOR
{
	TH0=(65536-46080)/256;
	TL0=(65536-46080)%256;
	
	if(heartBeat < 30000) heartBeat++;
	else heartBeat = 0;

	if((heartBeat%40)==0)flag_taskOne = 1;
  if(heartBeat%50 == 0)flag_taskTwo = 1;
	if(heartBeat%20 == 0)flag_taskThree = 1;
	if(heartBeat%30 == 0)flag_taskFour = 1;
	if(heartBeat%70 == 0)flag_taskFive = 1;
	
	//串口控制相关
	if(flag_uart_rx) //uart1
	{
		if(uartRxTimeOut>0)uartRxTimeOut--;
		else 
		{
			flag_uart_rx = 0;
			uartRxSta = 1;
		}
	}
	if(flag_uart2_rx) //uart2
	{
		if(uart2RxTimeOut>0)uart2RxTimeOut--;
		else 
		{
			flag_uart2_rx = 0;
			uart2RxSta = 1;
		}
	}
}

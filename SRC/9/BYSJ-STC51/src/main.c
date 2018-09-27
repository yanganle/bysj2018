#include <reg52.h>  
#include <stdio.h>
#include "mysys.h"
#include "io.h"
#include "uart.h"
#include "uart2.h"
#include "tasklist.h"
#include "agreement.h"
#include "SIM800A.h"
#include "TFT_LCD.h"

void bsp_init(void);
void display_background(void);

u8 *mynumber = "00310038003100340031003900320031003600360031"; //目标号码
u8 *manmsg = "4EBA545862A58B66"; //人员报警
u8 *shakemsg = "970752A862A58B66"; //震动报警

void main(void)
{
	bsp_init();
	while(1)
	{	
		if(flag_taskOne)
		{
			MyTask_One(); //任务一:人体检测
			flag_taskOne=0;
		}
		if(flag_taskTwo)
		{
			MyTask_Two(); //任务二:震动检测
			flag_taskTwo=0;
		}

		if(SMARTMODE) //自动模式
		{
			if(uartRxSta)
			{
				agreementParse(UART_RX_BUF);
				clearBuf();
				uartRxSta = 0;
				uartRxCount = 0;
			}
			if(IO_HUMAN) //人体检测报警
			{
				if(sendManMsgFlag)
				{
					if(sam800a_send_chmessage(mynumber, manmsg))
					{
						sendManMsgFlag = 0;
						sendManMsgTout = 200; 
					}
				}
				//BEEP_ON();
			}else if(IO_SHAKE) //震动报警
			{
				if(sendShkMsgFlag)
				{
					if(sam800a_send_chmessage(mynumber, shakemsg))
					{
						sendShkMsgFlag = 0;
						sendShkMsgTout = 200; 
					}
				}
				//BEEP_ON();
			}else{
			}
		}else //手动模式
		{	
			if(uartRxSta)
			{
				//uartSendData(UART_RX_BUF, uartRxCount); //通过串口输出
				agreementParse(UART_RX_BUF);
				uartRxSta = 0;
				uartRxCount = 0;
			}
		}
	}	
}

void bsp_init(void)
{
	UartInit();
	Uart2Init();
	mysysinit();
	lcd_initial();
	display_background();
	while(sim800a_work_init());
}
void display_background(void)
{
	dsp_single_colour(WHITE);
	Fast_DrawFont_GBK16(15,10,BLUE,WHITE, "车辆防盗系统");
	Fast_DrawFont_GBK16(5,40,BLACK,WHITE, "人体:");
	Fast_DrawFont_GBK16(5,80,BLACK,WHITE, "震动:");
}



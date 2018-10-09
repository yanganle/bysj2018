#include <reg52.h>  
#include <stdio.h>
#include "mysys.h"
#include "io.h"
#include "adc.h"
#include "uart.h"
#include "uart2.h"
#include "tasklist.h"
#include "agreement.h"
#include "TFT_LCD.h"
#include "DHT11.h"

void bsp_init(void);
void display_background(void);

void main(void)
{
	bsp_init();
	while(1)
	{	
		if(flag_taskOne)
		{
			MyTask_One(); //任务一:温湿度
			flag_taskOne=0;
		}
		if(flag_taskTwo)
		{
			MyTask_Two(); //任务二:甲醛
			flag_taskTwo=0;
		}
		if(flag_taskThree)
		{
			MyTask_Three(); //任务三:声响
			flag_taskThree=0;
		}
		if(flag_taskFour)
		{
			MyTask_Four(); //任务四:人体
			flag_taskFour=0;
		}
		if(flag_taskFive)
		{
			MyTask_Five(); //任务五:风扇
			flag_taskFive=0;
		}
		if(SMARTMODE) //自动模式
		{
			if(uartRxSta)
			{
				agreementParse(UART_RX_BUF);
				uartRxSta = 0;
				uartRxCount = 0;
			}
			if(TH>temp_threshold) FAN_ON(); //超标
			else FAN_OFF();
			if(RH>humi_threshold) FAN_ON(); //超标
			else FAN_OFF();
			if(methanal_value>meth_threshold)BEEP_ON();
			else BEEP_OFF();
		}else //手动模式
		{	
			if(uartRxSta)
			{
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
	adc_Init();
	lcd_initial();
	display_background();
}
void display_background(void)
{
	dsp_single_colour(WHITE);
	Fast_DrawFont_GBK16(15,10,BLUE,WHITE, "智能散热系统");
	Fast_DrawFont_GBK16(5,40,BLACK,WHITE, "温度:");
	Fast_DrawFont_GBK16(5,60,BLACK,WHITE, "湿度:");
	Fast_DrawFont_GBK16(5,80,BLACK,WHITE, "甲醛:");
	Fast_DrawFont_GBK16(5,100,BLACK,WHITE, "风扇");
}



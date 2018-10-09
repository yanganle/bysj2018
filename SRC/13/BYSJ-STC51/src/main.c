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
			MyTask_One(); //����һ:��ʪ��
			flag_taskOne=0;
		}
		if(flag_taskTwo)
		{
			MyTask_Two(); //�����:PM25
			flag_taskTwo=0;
		}
		if(flag_taskThree)
		{
			MyTask_Three(); //������:�������
			flag_taskThree=0;
		}

		if(SMARTMODE) //�Զ�ģʽ
		{
			if(uartRxSta)
			{
				agreementParse(UART_RX_BUF);
				uartRxSta = 0;
				uartRxCount = 0;
			}
			//if(watl_value>watl_threshold) PUMP_ON(); //����
			//else PUMP_OFF();
		}else //�ֶ�ģʽ
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
	Fast_DrawFont_GBK16(15,10,BLUE,WHITE, "����ɢ��ϵͳ");
	Fast_DrawFont_GBK16(5,40,BLACK,WHITE, "�¶�:");
	Fast_DrawFont_GBK16(5,60,BLACK,WHITE, "ʪ��:");
	Fast_DrawFont_GBK16(5,80,BLACK,WHITE, "�۳�:");
	Fast_DrawFont_GBK16(5,100,BLACK,WHITE, "���");
}


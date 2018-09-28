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

void bsp_init(void);
void display_background(void);

void main(void)
{
	bsp_init();
	while(1)
	{	
		if(flag_taskOne)
		{
			MyTask_One(); //����һ:�¶�DS18B20
			flag_taskOne=0;
		}
		if(flag_taskTwo)
		{
			MyTask_Two(); //�����:ˮλ
			flag_taskTwo=0;
		}
		if(flag_taskThree)
		{
			MyTask_Three(); //������:��ů��
			flag_taskThree=0;
		}
		if(flag_taskFour)
		{
			MyTask_Four(); //������:ˮ��
			flag_taskFour=0;
		}

		if(SMARTMODE) //�Զ�ģʽ
		{
			if(uartRxSta)
			{
				agreementParse(UART_RX_BUF);
				uartRxSta = 0;
				uartRxCount = 0;
			}
			if(watl_value>watl_threshold) PUMP_ON(); //ˮλ����
			else PUMP_OFF();
			
			if(tempvalue<temp_threshold) LAMP_ON(); //�¶ȹ���
			else LAMP_OFF();
		}else //�ֶ�ģʽ
		{	
			if(uartRxSta)
			{
				//uartSendData(UART_RX_BUF, uartRxCount); //ͨ���������
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
	Fast_DrawFont_GBK16(33,10,BLUE,WHITE, "�������");
	Fast_DrawFont_GBK16(5,40,BLACK,WHITE, "�¶�:");
	Fast_DrawFont_GBK16(5,60,BLACK,WHITE, "ˮλ:");
	Fast_DrawFont_GBK16(5,80,BLACK,WHITE, "�ȵ�:"); 
	Fast_DrawFont_GBK16(5,100,BLACK,WHITE, "ˮ��:");
}



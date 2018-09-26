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

u8 *mynumber = "00310038003100340031003900320031003600360031"; //Ŀ�����
u8 *manmsg = "4EBA545862A58B66"; //��Ա����
u8 *shakemsg = "970752A862A58B66"; //�𶯱���

void main(void)
{
	bsp_init();
	while(1)
	{	
		if(flag_taskOne)
		{
			MyTask_One(); //����һ:������
			flag_taskOne=0;
		}
		if(flag_taskTwo)
		{
			MyTask_Two(); //�����:�𶯼��
			flag_taskTwo=0;
		}

		if(SMARTMODE) //�Զ�ģʽ
		{
			if(uartRxSta)
			{
				agreementParse(UART_RX_BUF);
				clearBuf();
				uartRxSta = 0;
				uartRxCount = 0;
			}
			if(IO_HUMAN) //�����ⱨ��
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
			}else if(IO_SHAKE) //�𶯱���
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
	lcd_initial();
	display_background();
	while(sim800a_work_init());
}
void display_background(void)
{
	dsp_single_colour(WHITE);
	Fast_DrawFont_GBK16(15,10,BLUE,WHITE, "��������ϵͳ");
	Fast_DrawFont_GBK16(5,40,BLACK,WHITE, "����:");
	Fast_DrawFont_GBK16(5,80,BLACK,WHITE, "��:");
}



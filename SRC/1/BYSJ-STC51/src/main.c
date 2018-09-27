#include <reg52.h>  
#include <stdio.h>
#include "mysys.h"
#include "io.h"
#include "uart.h"
#include "DHT11.h"
#include "tasklist.h"
#include "agreement.h"
#include "LCD12864.h"

void bsp_init(void);

void main(void)
{
	bsp_init();
	while(1)
	{	
		if(flag_taskOne)
		{
			MyTask_One(); //��ʪ��
			flag_taskOne=0;
		}
		if(flag_taskTwo)
		{
			MyTask_Two(); //������
			flag_taskTwo=0;
		}
		if(flag_taskThree)
		{
			MyTask_Three(); //������
			flag_taskThree=0;
		}
				if(flag_taskThree)
		{
			MyTask_Four(); //������
			flag_taskFour=0;
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
			if(TH>TEMPTHRESHOLD)
			{
				FAN_ON();
			}
			else{
				FAN_OFF();
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
	mysysinit();
	display_init();
}
	



#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "usart3.h"
#include "timer.h"
#include "agreement.h"
#include "wifiap.h"
#include "tasklist.h"
#include "DHT11.h"
#include "SIM800A.h"
#include "led.h"
#include "adc.h"

void bsp_init(void);
 
int main(void)
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
			MyTask_Two(); //�����:ˮλ
			flag_taskTwo=0;
		}
		if(flag_taskThree)
		{
			MyTask_Three(); //������:ˮ��
			flag_taskThree=0;
		}
		if(flag_taskFour)
		{
			MyTask_Four(); //������:��ˮ
			flag_taskFour=0;
		}
		
		if(SMARTMODE) //�Զ�ģʽ
		{
			//receive_wifi_msg(); 
			receive_usart1_msg();
			
			if(tempup_threshold<TH || humi_threshold<RH ) IO_PUMP = 1;
			else IO_PUMP = 0;
		}else
		{
			//receive_wifi_msg();
			receive_usart1_msg();
		}
	}
}

void bsp_init(void)
{
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 	//���ڳ�ʼ�� 	
	usart3_init(115200);		//��ʼ������3 
	TIM3_Int_Init(9,7199);//10Khz�ļ���Ƶ�ʣ�������9,1ms����һ���ж�
	//ESP8266_WifiAP_Init(); //��ʼ��wifiģ��
	//sim800a_work_init();
	IO_Init();
	Adc_Init();
}
 

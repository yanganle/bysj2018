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

void bsp_init(void);
 
int main(void)
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
			MyTask_Two(); //任务二:风扇
			flag_taskTwo=0;
		}
		if(flag_taskThree)
		{
			MyTask_Three(); //任务三:供暖灯
			flag_taskThree=0;
		}
		if(SMARTMODE) //自动模式
		{
			//receive_wifi_msg(); 
			receive_usart1_msg();
			
			if(tempup_threshold<TH || humi_threshold<RH ) IO_FAN = 1;
			else IO_FAN = 0;
			if(tempdown_threshold>TH) IO_HOT = 1;
			else IO_HOT = 0;
		}else
		{
			//receive_wifi_msg();
			receive_usart1_msg();
		}
	}
}

void bsp_init(void)
{
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为115200	 	
	usart3_init(115200);		//初始化串口3 
	TIM3_Int_Init(9,7199);//10Khz的计数频率，计数到9,1ms进入一次中断
	//ESP8266_WifiAP_Init(); //初始化wifi模块
	sim800a_work_init();
	IO_Init();
}
 

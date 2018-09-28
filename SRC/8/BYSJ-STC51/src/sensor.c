#include  "sensor.h"

#define   CHANNEL   3
#define	  Cal_MODE 	0	//每次测量只读1次ADC.

u16	Bandgap;
u16	value_old;
u32 value = 1;
unsigned long caltmp;
float Curr_value;
float vertical,horizontal;

// 描述: 查询法读一次ADC结果.
// 参数: channel: 选择要转换的ADC.
u16	Get_ADC10bitResult(u8 channel)	//channel = 0~7
{
	ADC_RES = 0;
	ADC_RESL = 0;

	ADC_CONTR = (ADC_CONTR & 0xe0) | 0x08 | channel; 	//start the ADC
	NOP(4);

	while((ADC_CONTR & 0x10) == 0)	;	//wait for ADC finish
	ADC_CONTR &= ~0x10;		//清除ADC结束标志
	return	(((u16)ADC_RES << 2) | (ADC_RESL & 3));
}

void ADC_Init(void)
{
	P1M1 |= (1<<CHANNEL);		// 把ADC口设置为高阻输入
	P1M0 &= ~(1<<CHANNEL);
	P1ASF |= (1<<CHANNEL);		//P1.2做ADC	
	ADC_CONTR = 0xE0;	//90T, ADC power on
	
}

float get_ADC1_value(void)
{	
			//=================== 只读1次ADC, 10bit ADC. ====================
				P1ASF = 0;
				Get_ADC10bitResult(0);	//改变P1ASF后先读一次并丢弃结果, 让内部的采样电容的电压等于输入值.
				Bandgap = Get_ADC10bitResult(0);	//读内部基准ADC, P1ASF=0, 读0通道
				P1ASF = 1<<CHANNEL;
				value_old = Get_ADC10bitResult(CHANNEL);	//读外部电压ADC
				value =value_old;
		
						
			caltmp = value;
			caltmp = (caltmp << 5) + value;           //caltmp = value * 33
			caltmp = (caltmp << 3) + (caltmp << 1);     //caltmp = caltmp * 10
			value = caltmp >> 10;                   //value = caltmp / 2^n 1024	
			Curr_value = 	(float)value/100;
		//	Curr_value = (float)(Curr_value*400/(5+(float)(2000/2.08)));
			vertical = Curr_value;
			//printf("The vertical is = %.2f \n",Curr_value);
			//printf("The vertical is = %.2f KG\n",Curr_value);
			return vertical;
}


float get_ADC0_value(void)
{	
			//=================== 只读1次ADC, 10bit ADC. ====================		
				P1ASF = 0;
				Get_ADC10bitResult(0);	//改变P1ASF后先读一次并丢弃结果, 让内部的采样电容的电压等于输入值.
				Bandgap = Get_ADC10bitResult(0);	//读内部基准ADC, P1ASF=0, 读0通道
				P1ASF = 1<<CHANNEL;
				value_old = Get_ADC10bitResult(2);	//读外部电压ADC
				value =value_old;		
			caltmp = value;
			caltmp = (caltmp << 5) + value;           //caltmp = value * 33
			caltmp = (caltmp << 3) + (caltmp << 1);     //caltmp = caltmp * 10
			value = caltmp >> 10;                   //value = caltmp / 2^n 1024	
			Curr_value = 	(float)value/100;
			horizontal = Curr_value;
//			printf("The horizontal is = %.2f \n",horizontal);
			return horizontal;
}
#include "adc.h"

//P1.0 P1.1 P1.2 ADC输入

void adc_Init(void)
{
	P1ASF = 0x07;			//12C5A60AD/S2系列模拟输入(AD)选择
	ADC_CONTR = ADC_360T | ADC_ON;
}

u16 adc_getValue(u8 channel)	//channel = 0~7
{
	u16	adc;
	u8	i = 250;

	ADC_RES = 0;
	ADC_RESL = 0;

	ADC_CONTR = (ADC_CONTR & 0xe0) | ADC_START | channel; 
	do{
		if(ADC_CONTR & ADC_FLAG)
		{
			ADC_CONTR &= ~ADC_FLAG;
			adc = (u16)ADC_RES;
			adc = (adc << 2) | (ADC_RESL & 3);
			return	adc;
		}
	}while(--i);
	return	1024;
}

u8 watl_value;
u8 get_WTL_value(u8 *str)
{
	watl_value = adc_getValue(0);
	
	return watl_value;
}

u8 get_PH_value(u8 *str)
{
	u8 sdata;
	sdata = adc_getValue(1);
	
	return sdata;
}


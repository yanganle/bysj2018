#include "adc.h"

//P1.0 P1.1 P1.2 ADC输入

void adc_Init(void)
{
	P1ASF = 0x07;			//12C5A60AD/S2系列模拟输入(AD)选择
	ADC_CONTR = ADC_360T | ADC_ON;
}
/*0~vcc 0~1024*/
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
	u16 value = 0;
	value = adc_getValue(0);
	
	str[0] = '0'+(value/1000);
	str[1] = '0'+(value%1000/100);
	str[2] = '0'+(value%100/10);
	str[3] = '0'+(value%10);
	str[4] = '\0';
	return watl_value;
}

u8 get_PH_value(u8 *str)
{
	u8 phvalue;
	u16 value;
	value = adc_getValue(1);
	
	str[0] = '0'+(value/1000);
	str[1] = '0'+(value%1000/100);
	str[2] = '0'+(value%100/10);
	str[3] = '0'+(value%10);
	str[4] = '\0';
	/*str[0] = '0'+(sdata/10);
	str[1] = '0'+(sdata%10);
	str[2] = '\0';*/
	return phvalue;
}


#ifndef __ADC_H__
#define __ADC_H__

#include <reg52.h>

sfr P1ASF     = 0x9D;	//12C5A60AD/S2系列模拟输入(AD或LVD)选择
sfr ADC_CONTR = 0xBC;	//带AD系列
sfr ADC_RES   = 0xBD;	//带AD系列
sfr ADC_RESL  = 0xBE;	//带AD系列

#define ADC_OFF()	ADC_CONTR = 0
#define ADC_ON		(1 << 7)
#define ADC_90T		(3 << 5)
#define ADC_180T	(2 << 5)
#define ADC_360T	(1 << 5)
#define ADC_540T	0
#define ADC_FLAG	(1 << 4)	//软件清0
#define ADC_START	(1 << 3)	//自动清0
#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7

extern u8 watl_value;

void adc_Init(void);
u16 adc_getValue(u8 channel);

u8 get_WTL_value(u8 *str);
u8 get_PH_value(u8 *str);

#endif

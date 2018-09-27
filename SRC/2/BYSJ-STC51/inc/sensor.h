#include <reg52.h> 
#include <stdio.h>
#include "uart.h"



u16	Get_ADC10bitResult(u8 channel);
void ADC_Init(void);
float get_ADC0_value(void);
float get_ADC1_value(void);
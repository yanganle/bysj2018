#include <ioCC2530.h>
#include "hal_adc.h"
#include "hal_types.h"
#include "adc_sensor.h"
#include "adc.h"

float getVol(void)
{
  unsigned char i = 0;
  uint16 value = 0;
  uint32 AdcValue = 0;//防止溢出
  float vol = 0.0;
  P0DIR &= ~0x40;//设置P0.6为输入模式
  ADC_ENABLE_CHANNEL(6);    //使能通道6作为ADC的采样通道
  for(i=0; i<4; i++)
  {
    ADC_SINGLE_CONVERSION(HAL_ADC_REF_AVDD|ADC_12_BIT|ADC_AIN6 );//片上3.3V参考电压,12位，7通道
    ADC_SAMPLE_SINGLE(); 
    while(!(ADCCON1 & 0x40));              //等待AD转换完成
    asm("NOP");asm("NOP");
    value = ADCL>>4;                      
    value |= (((uint8)ADCH) << 4);
    AdcValue += value;  
  }
  AdcValue = AdcValue >> 2;                 //累加除以4，得到平均值
  vol = (AdcValue/2048.0)*3.3;  //换算成电压值
  return vol;
}


uint16 ReadGasData( void )
{
  uint16 reading = 0;
  reading = (uint16)(getVol()*1000); //放大了一千倍
  
  return reading;
}
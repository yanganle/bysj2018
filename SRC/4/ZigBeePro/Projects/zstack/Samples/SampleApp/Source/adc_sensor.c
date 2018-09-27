#include <ioCC2530.h>
#include "hal_adc.h"
#include "hal_types.h"
#include "adc_sensor.h"
#include "adc.h"

float getVol(void)
{
  unsigned char i = 0;
  uint16 value = 0;
  uint32 AdcValue = 0;//��ֹ���
  float vol = 0.0;
  P0DIR &= ~0x40;//����P0.6Ϊ����ģʽ
  ADC_ENABLE_CHANNEL(6);    //ʹ��ͨ��6��ΪADC�Ĳ���ͨ��
  for(i=0; i<4; i++)
  {
    ADC_SINGLE_CONVERSION(HAL_ADC_REF_AVDD|ADC_12_BIT|ADC_AIN6 );//Ƭ��3.3V�ο���ѹ,12λ��7ͨ��
    ADC_SAMPLE_SINGLE(); 
    while(!(ADCCON1 & 0x40));              //�ȴ�ADת�����
    asm("NOP");asm("NOP");
    value = ADCL>>4;                      
    value |= (((uint8)ADCH) << 4);
    AdcValue += value;  
  }
  AdcValue = AdcValue >> 2;                 //�ۼӳ���4���õ�ƽ��ֵ
  vol = (AdcValue/2048.0)*3.3;  //����ɵ�ѹֵ
  return vol;
}


uint16 ReadGasData( void )
{
  uint16 reading = 0;
  reading = (uint16)(getVol()*1000); //�Ŵ���һǧ��
  
  return reading;
}
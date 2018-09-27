#include "dig_sensor.h"

#define DATA_PIN05          P0_5    //����P0.5��Ϊ�������������

uint8 relay_one_value =0;
uint8 relay_two_value =0;

void InitDigSensor(void)
{  
#ifdef DEVICE_LIGHT
  P0DIR &= ~0x20;;        //P0.5       
  P0SEL &= ~0x20;;        //����P0.5Ϊ��ͨIO��
#endif
#ifdef DEVICE_GAS_MQ135
  P0DIR &= ~0x40;;        //P0.6      
  //P0SEL &= ~0x40;;        //����P0.6Ϊ��ͨIO��
#endif
#ifdef DEVICE_HT11
  P0DIR &= ~0x80;        //P0.7      
  P0SEL &= ~0x80;        //����P0.7Ϊ��ͨIO��
#endif
  
#ifdef DEVICE_RELAY_ONE
  P1DIR |= (0x01<<5);   //output mode
  P1INP &= ~(0x01<<5);  //Pull up 
  P1_5 = 0;// LOW 	
#endif  
#ifdef DEVICE_RELAY_TWO
  P1DIR |= (0x01<<6);   //output mode
  P1INP &= ~(0x01<<6);  //Pull up 
  P1_6 = 0;// LOW 	
#endif
}

uint8 GetLightData(void) //���մ�����
{
  uint8 LightState;
  LightState = DATA_PIN05;
  
  return LightState;
}


void CtrlRelyOne(uint8 state) //�̵����豸һ
{
  if(state == 0x01)
  {
    P1_5 = 0x01;
    relay_one_value = 0x01;
  }else
  {
    P1_5 = 0x00;
    relay_one_value = 0x00;
  }
}

void CtrlRelyTwo(uint8 state) //�̵����豸��
{
  if(state == 0x01)
  {
    P1_6 = 0x01;
    relay_two_value = 0x01;
  }else
  {
    P1_6 = 0x00;
    relay_two_value = 0x00;
  }
}
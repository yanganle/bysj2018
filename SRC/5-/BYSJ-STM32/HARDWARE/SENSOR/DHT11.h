#ifndef __DHT11_H__
#define __DHT11_H__

#include "sys.h"

//#define IO_IN()  {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=(u32)8<<4;}
//#define IO_OUT() {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=(u32)3<<4;}

#define DATA_IN  0
#define DATA_OUT 1
									   
#define	BUS_OUT    PCout(7)
#define BUS_READ   PCin(7)

extern u8 RH,RL,TH,TL;
void DHT11_receive(u8 *temp, u8 *humi);
void DHT11_DATA_INIT(u8 flag);

#endif


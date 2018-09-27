#ifndef __DHT11_H__
#define __DHT11_H__

#include <reg52.h>
#include <intrins.h>

extern u8 RH,RL,TH,TL;

void DHT11_receive(u8 *temp, u8 *humi);

#endif
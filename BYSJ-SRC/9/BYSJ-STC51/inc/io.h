#ifndef __IO_H__
#define __IO_H__

#include <reg52.h>

sbit IO_LED1 = P1^0;
sbit IO_LED2 = P1^1;
sbit IO_LED3 = P1^2;

sbit IO_HUMAN = P1^7;
sbit IO_SOUND = P1^6;
sbit IO_FAN   = P1^5;

#define FAN_ON() IO_FAN = 1
#define FAN_OFF() IO_FAN = 0

//extern u8 human_flag;

#endif


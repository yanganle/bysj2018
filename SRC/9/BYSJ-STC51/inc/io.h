#ifndef __IO_H__
#define __IO_H__

#include <reg52.h>

sbit IO_HUMAN = P0^1;
sbit IO_SHAKE = P0^2;
sbit IO_BEEP  = P0^3;
sbit IO_LED   = P0^4;

#define BEEP_ON() IO_BEEP = 1
#define BEEP_OFF() IO_BEEP = 0

//extern u8 human_flag;

#endif


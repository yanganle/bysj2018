#ifndef __IO_H__
#define __IO_H__

#include <reg52.h>

sbit IO_FAN    = P0^1;
sbit IO_DUST   = P0^2;

#define FAN_ON() IO_FAN = 1
#define FAN_OFF() IO_FAN = 0

#endif


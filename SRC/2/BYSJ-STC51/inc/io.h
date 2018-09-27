#ifndef __IO_H__
#define __IO_H__

#include <reg52.h>

sbit IO_PUMP   = P0^1;

#define PUMP_ON() IO_PUMP = 1
#define PUMP_OFF() IO_PUMP = 0

#endif


#ifndef __IO_H__
#define __IO_H__

#include <reg52.h>

sbit IO_PUMP  = P0^1;
sbit IO_LAMP  = P0^2;
sbit IO_TURB  = P0^3;

#define PUMP_ON() IO_PUMP = 1
#define PUMP_OFF() IO_PUMP = 0

#define LAMP_ON() IO_LAMP = 1
#define LAMP_OFF() IO_LAMP = 0

#endif


#ifndef __IO_H__
#define __IO_H__

#include <reg52.h>

sbit IO_FAN    = P0^1;
sbit IO_MAN    = P0^2;
sbit IO_SOUND    = P0^3;
sbit IO_BEEP   = P0^4;

#define FAN_ON() IO_FAN = 1
#define FAN_OFF() IO_FAN = 0

#define BEEP_ON() IO_BEEP = 1
#define BEEP_OFF() IO_BEEP = 0

#endif


#ifndef __MY_SYS_HH__
#define __MY_SYS_HH__

#include <reg52.h> 
#include <stdio.h>

#define TIMER0_VECTOR 1

extern u8 flag_taskOne;
extern u8 flag_taskTwo;
extern u8 flag_taskThree;

void mysysinit(void);

#endif

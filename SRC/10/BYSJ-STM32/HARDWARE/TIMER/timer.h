#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

extern u32 heartBeat;
extern u8 flag_taskOne;
extern u8 flag_taskTwo;
extern u8 flag_taskThree;
extern u8 flag_taskFour;

void TIM3_Int_Init(u16 arr,u16 psc);
void TIM7_Int_Init(u16 arr,u16 psc);
 
#endif

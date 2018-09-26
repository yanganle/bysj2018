#include "delay.h"

void delay_ms(u16 ms)    //u16 µÈ¼ÛÓÚ
{ 
	u16 i,j; 
	for(i=ms;i>0;i--) 
		for(j=114;j>0;j--);
}


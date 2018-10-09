#include "delay.h"

void Delay1ms(void)		//@12.000MHz
{
	unsigned char i, j;

	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
}

void delay_ms(u16 ms)    //u16 等价于
{ 
	u16 i; 
	for(i=ms;i>0;i--) 
		Delay1ms();
}

/*void delay_ms(u16 ms)    //u16 等价于
{ 
	u16 i,j,k; 
	for(i=ms;i>0;i--) 
		for(j=114;j>0;j--);
	
}*/


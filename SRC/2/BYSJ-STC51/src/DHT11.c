#include "DHT11.h"

sbit Data=P3^7;    
u8 RH,RL,TH,TL;

void DHT11_delay_us(u8 n)
{
    while(--n);
}

void DHT11_delay_ms(u16 z)
{
   u16 i,j;
   for(i=z;i>0;i--)
      for(j=110;j>0;j--);
}

void DHT11_start()
{
   Data=1;
   DHT11_delay_us(2);
   Data=0;
   DHT11_delay_ms(20);   
   Data=1;
   DHT11_delay_us(30);
}

u8 DHT11_rec_byte()    
{
	u8 i,dat=0;
	for(i=0;i<8;i++)   
	{          
		while(!Data);   
		DHT11_delay_us(8);    
		dat<<=1;           
		if(Data==1)   
			 dat+=1;
		while(Data);    
	}  
	return dat;
}

void DHT11_receive(u8 *temp, u8 *humi)  
{
	u8 R_H,R_L,T_H,T_L,revise; 
	EA = 0;
	DHT11_start();
	if(Data==0)
	{
		while(Data==0);    
		DHT11_delay_us(40);  
		R_H=DHT11_rec_byte();    
		R_L=DHT11_rec_byte();    
		T_H=DHT11_rec_byte();    
		T_L=DHT11_rec_byte();    
		revise=DHT11_rec_byte(); 
		DHT11_delay_us(25);   
		if((R_H+R_L+T_H+T_L)==revise)      
		{
				RH=R_H;
				RL=R_L;
				TH=T_H;
				TL=T_L;
		} 
		temp[0]='0'+(TH/10);
		temp[1]='0'+(TH%10);
		//temp[2]='.';
		//temp[3]='0'+(TL%10);
		temp[2]='C';
		temp[3]='\0';
		
		humi[0]='0'+(RH/10);
		humi[1]='0'+(RH%10);
		humi[2]='%';
		humi[3]='\0';
	}
	EA = 1;
}

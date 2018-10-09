#include "DHT11.h"  
#include "delay.h" 

u8 RH,RL,TH,TL;

void DHT11_DATA_INIT(u8 flag)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	//使能GPIOB时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	if(flag)
	{
			GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;  //推挽输出
			GPIO_SetBits(GPIOC,GPIO_Pin_7);
	}
	else{
			GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;  		//输入
	}	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void DHT11_start()
{
	 DHT11_DATA_INIT(DATA_OUT);
   BUS_OUT=1;
   delay_us(5);
   BUS_OUT=0;
   delay_ms(20);   
   BUS_OUT=1;
   delay_us(10);
}

u8 DHT11_rec_byte()    
{
	u8 i,dat=0;
	for(i=0;i<8;i++)   
	{          
		while(!BUS_READ);   
		delay_us(60);    
		dat<<=1;           
		if(BUS_READ==1)   
			 dat+=1;
		while(BUS_READ);    
	}  
	return dat;
}

void DHT11_receive(u8 *temp, u8 *humi)  
{
	u8 R_H,R_L,T_H,T_L,revise; 
	
	DHT11_start();
	DHT11_DATA_INIT(DATA_IN);
	if(BUS_READ==0)
	{
		while(BUS_READ==0);    
		delay_us(100);  
		R_H=DHT11_rec_byte();    
		R_L=DHT11_rec_byte();    
		T_H=DHT11_rec_byte();    
		T_L=DHT11_rec_byte();    
		revise=DHT11_rec_byte(); 
		delay_us(60);   
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
}

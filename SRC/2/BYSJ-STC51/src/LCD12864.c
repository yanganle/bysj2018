#include "LCD12864.h"

sbit en=P0^5;
sbit rs=P0^7;
sbit rw=P0^6;
sbit lcd_psb=P0^4;

u8 code dis1[]={"温度:"};
u8 code dis2[]={"湿度:"};
u8 code dis3[]={"人体:"};
u8 code dis4[]={"声响:"};

void delaynop()
{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
bit lcd_status()
{
	bit status;
	rs=0;
	rw=1;
	_nop_();
	_nop_();
	en=1;
	status=P2&0x80;
	delaynop();
	delaynop();
	en=0;
	return status;		
}
void lcd_wcmd(u8 cmd)
{
	while(lcd_status());
	rs=0;
	rw=0;
	_nop_();
	_nop_();
	en=1;
	P2=cmd;
	delaynop();
	delaynop();
	en=0;
}
void lcd_wdat(u8 dat)
{
	while(lcd_status());
	rs=1;
	rw=0;
	_nop_();
	_nop_();
	en=1;
	P2=dat;
	delaynop();
	delaynop();
	en=0;
}
void lcd_pos(u8 x,y)
{
	u8 pos;
	switch(x)
	{
		case 0: x=0x80; break;
		case 1: x=0x90; break;
		case 2: x=0x88; break;
		case 3: x=0x98; break;
	}
	pos=x+y;
	lcd_wcmd(pos);
}
void lcd_init()
{
	lcd_psb=1;
	lcd_wcmd(0x30);
	delaynop();
	lcd_wcmd(0x0c);
	delaynop();
	lcd_wcmd(0x01);
	delaynop();
}

void display_init(void)
{
	u8 i;
	lcd_init();

	lcd_pos(0,0);
	i=0;
	while(dis1[i]!='\0')
	{
		lcd_wdat(dis1[i]);
		i++;	
	}
	//lcd_wcmd(0x34);
	//lcd_wcmd(0x04);
	//lcd_wcmd(0x30);
	
	lcd_pos(1,0);
	i=0;
	while(dis2[i]!='\0')
	{
		lcd_wdat(dis2[i]);
		i++;	
	}

	lcd_pos(2,0);
	i=0;
	while(dis3[i]!='\0')
	{
		lcd_wdat(dis3[i]);
		i++;	
	}

	lcd_pos(3,0);
	i=0;
	while(dis4[i]!='\0')
	{
		lcd_wdat(dis4[i]);
		i++;	
	}

	P2=0xff;
}

void display_humiture(u8 *temp, u8 *humi)
{
	u8 i;
	lcd_pos(0,4);
	i=0;
	while(temp[i]!='\0')
	{
		lcd_wdat(temp[i]);
		i++;	
	}
	lcd_pos(1,4);
	i=0;
	while(humi[i]!='\0')
	{
		lcd_wdat(humi[i]);
		i++;	
	}
}
void display_human(u8 *show)
{
	u8 i;
	lcd_pos(2,4);
	i=0;
	while(show[i]!='\0')
	{
		lcd_wdat(show[i]);
		i++;	
	}
}
void display_sound(u8 *show)
{
	u8 i;
	lcd_pos(3,4);
	i=0;
	while(show[i]!='\0')
	{
		lcd_wdat(show[i]);
		i++;	
	}
}


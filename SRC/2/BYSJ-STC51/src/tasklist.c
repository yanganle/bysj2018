#include "tasklist.h"
#include "io.h"
#include "adc.h"
#include "agreement.h"
#include "TFT_LCD.h"
#include "DS18B20.h"

u8 sdata[4] = {0};

void MyTask_One(void)
{
	u8 tempstr[6];
	u16 tempvalue;
	
	tempvalue = ReadTemperature(tempstr);
	Display_ASCII8X16_Color(50,40,tempstr,RED,WHITE); //ÏÔÊ¾×Ö·û

	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = tempvalue>>8;
	sdata[3] = tempvalue;
	Send_SensorData(SENSOR_DS18B20, 0, sdata);
}

void MyTask_Two(void)
{
	u8 str[5];
	u8 waterl;
	
	waterl = get_WTL_value(str);
	Display_ASCII8X16_Color(50,60,str,RED,WHITE); 

	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = waterl>>8;
	sdata[3] = waterl;
	Send_SensorData(SENSOR_WATERLEVEL, 0, sdata);
}
void MyTask_Three(void)
{
	u8 str[5];
	u8 ph;
	
	ph = get_PH_value(str);
	Display_ASCII8X16_Color(50,80,str,RED,WHITE); 

	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = ph>>8;
	sdata[3] = ph;
	Send_SensorData(SENSOR_PH, 0, sdata);
}

void MyTask_Four(void)
{
	if(IO_PUMP) Display_ASCII8X16_Color(50,100,"ON ",RED,WHITE); 
	else Display_ASCII8X16_Color(50,100,"OFF",BLACK,WHITE); 
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	sdata[3] = IO_PUMP;
	Send_SensorData(SENSOR_WATER_PUMP, 0, sdata);
}


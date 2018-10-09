#include "tasklist.h"
#include "io.h"
#include "adc.h"
#include "agreement.h"
#include "TFT_LCD.h"
#include "DHT11.h"

u8 sdata[4] = {0};

void MyTask_One(void)
{
	u8 u8Humi[4];
	u8 u8Temp[4];

	DHT11_receive(u8Temp, u8Humi);
	Display_ASCII8X16_Color(50,40,u8Temp,RED,WHITE); //ÎÂ¶È
	Display_ASCII8X16_Color(50,60,u8Humi,RED,WHITE); //Êª¶È
	sdata[0] = 0;
	sdata[1] = TH;
	sdata[2] = 0;
	sdata[3] = RH;
	Send_SensorData(SENSOR_DHT11, 0, sdata);
}

void MyTask_Two(void)
{
	u8 str[5];
	u8 value;
	
  value = get_methanal_value(str)
	Display_ASCII8X16_Color(50,60,str,RED,WHITE); 
	
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	sdata[3] = value;
	Send_SensorData(SENSOR_METHANAL, 0, sdata);
}
void MyTask_Three(void)
{
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	sdata[3] = IO_SOUND;
	Send_SensorData(SENSOR_SOUND, 0, sdata);
}
void MyTask_Four(void)
{
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	sdata[3] = IO_MAN;
	Send_SensorData(SENSOR_MAN, 0, sdata);
}
void MyTask_Five(void)
{
	if(IO_FAN) Display_ASCII8X16_Color(50,100,"ON ",RED,WHITE); 
	else Display_ASCII8X16_Color(50,100,"OFF",BLACK,WHITE); 
	
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	sdata[3] = IO_FAN;
	Send_SensorData(SENSOR_FAN, 0, sdata);
}

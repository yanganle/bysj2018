#include "tasklist.h"
#include "agreement.h"
#include "DHT11.h"
#include "led.h"

u8 sdata[4] = {0};

void MyTask_One(void)
{
	u8 u8Temp[5];
	u8 u8Humi[5];

	DHT11_receive(u8Temp, u8Humi);
	sdata[0] = 0;
	sdata[1] = TH;
	sdata[2] = 0;
	sdata[3] = RH;
	Send_SensorData(SENSOR_DHT11, 0, sdata);
}

void MyTask_Two(void)
{
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	sdata[3] = IO_FAN;
	Send_SensorData(SENSOR_FAN, 0, sdata);
}
void MyTask_Three(void)
{
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	sdata[3] = IO_HOT;
	Send_SensorData(SENSOR_HOT, 0, sdata);
}

void MyTask_Four(void)
{ 
}


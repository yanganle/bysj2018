#include "tasklist.h"
#include "LCD12864.h"
#include "io.h"
#include "DHT11.h"
#include "agreement.h"

u8 u8Humi[4];
u8 u8Temp[4];
u8 sdata[4];
u8 show1[] = {"有人"};
u8 show2[] = {"无人"};
u8 show3[] = {"噪声"};
u8 show4[] = {"安静"};

void MyTask_One(void)
{
	DHT11_receive(u8Temp, u8Humi);
	display_humiture(u8Temp, u8Humi);
	sdata[0] = 0;
	sdata[1] = TH;
	sdata[2] = 0;
	sdata[3] = RH;
	Send_SensorData(SENSOR_DHT11, 0, sdata);
}

u8 humanflag = 0;
void MyTask_Two(void)
{
	if(IO_HUMAN == 1)
	{
		sdata[3] = 0x01;
		display_human(show1);
	}
	else{
		sdata[3] = 0x00;
		display_human(show2);
	}	
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	Send_SensorData(SENSOR_HUMAN, 0, sdata);
}

u8 soundflag = 0;
void MyTask_Three(void)
{
	if(IO_SOUND == 1)
	{
		sdata[3] = 0x01;
		display_sound(show3);
	}
	else{
		sdata[3] = 0x00;
		display_sound(show4);
	}
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	Send_SensorData(SENSOR_SOUND, 0, sdata);
}

void MyTask_Four(void)
{
	if(IO_FAN == 1)
	{
		sdata[3] = 0x01;
	}
	else{
		sdata[3] = 0x00;
	}
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	Send_SensorData(SENSOR_FAN, 0, sdata);
}


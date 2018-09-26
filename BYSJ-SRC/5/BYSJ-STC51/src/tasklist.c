#include "tasklist.h"
#include "io.h"
#include "agreement.h"
#include "SIM800A.h"
#include "TFT_LCD.h"

u8 sdata[4];

void MyTask_One(void)
{
	if(IO_HUMAN == 1)
	{
		sdata[3] = 0x01;
		Fast_DrawFont_GBK16(50,40,BLACK,WHITE, "有人");
	}
	else{
		sdata[3] = 0x00;
		Fast_DrawFont_GBK16(50,40,BLACK,WHITE, "无人");
	}
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	Send_SensorData(SENSOR_HUMAN, 0, sdata);
}

void MyTask_Two(void)
{
	if(IO_SHAKE == 1)
	{
		sdata[3] = 0x01;
		Fast_DrawFont_GBK16(50,80,BLACK,WHITE, "有震动:");
	}
	else{
		sdata[3] = 0x00;
		Fast_DrawFont_GBK16(50,80,BLACK,WHITE, "无震动:");
	}	
	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = 0;
	Send_SensorData(SENSOR_SHAKE, 0, sdata);
}



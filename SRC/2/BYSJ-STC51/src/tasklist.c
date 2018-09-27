#include "tasklist.h"
#include "adc.h"
#include "agreement.h"
#include "TFT_LCD.h"
#include "DS18B20.h"

u8 sdata[4];

void MyTask_One(void)
{
	u8 tempstr[6];
	u16 tempvalue;
	tempvalue = ReadTemperature(tempstr);
	//Fast_DrawFont_GBK16(50,40,BLACK,WHITE, "无人");

	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = tempvalue>>8;
	sdata[3] = tempvalue;
	Send_SensorData(SENSOR_DS18B20, 0, sdata);
}

void MyTask_Two(void)
{
	u8 str[4];
	u8 waterl;
	waterl = get_WTL_value(str);
	//Fast_DrawFont_GBK16(50,80,BLACK,WHITE, "无震动:");

	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = waterl>>8;
	sdata[3] = waterl;
	Send_SensorData(SENSOR_WATERLEVEL, 0, sdata);
}
void MyTask_Three(void)
{
	u8 str[4];
	u8 ph;
	ph = get_PH_value(str);
	//Fast_DrawFont_GBK16(50,80,BLACK,WHITE, "无震动:");

	sdata[0] = 0;
	sdata[1] = 0;
	sdata[2] = ph>>8;
	sdata[3] = ph;
	Send_SensorData(SENSOR_PH, 0, sdata);
}


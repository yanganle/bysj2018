

/******************************
** @time ：2017/11/6 15:20:56 
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief: 室内温度采集显示
*******************************/ 

#include "display.h"
#include "config.h"
#include "dgus.h"


void display_float(unsigned char addr,float temp)
{
	unsigned short sentValue;
	sentValue = (int)(temp*10);
	dgusWriteVar(addr,sentValue);
}

void display_ushort (unsigned char addr,unsigned short value)
{
	dgusWriteVar(addr,value);
}


void display_temp (float temp)
{	
	 display_float(TEMP_ADDR_DISPLAY,temp);
}

void display_humi (float humi)
{
	display_float(HUMI_ADDR_DISPLAY,humi);
}

void display_pm (float dust)
{
	display_float(DUST_ADDR_DISPLAY,dust);
}

void display_smoke (float smoke)
{
	display_float(SMOKE_ADDR_DISPLAY,smoke);
}

void display_light (float light)
{
	display_float(LIGHT_ADDR_DISPLAY,light);
}


void display_relay(unsigned char staus)
{
	display_ushort(RELAY_ADDR_DISPLAY,staus);
}

void display_fan_speed(unsigned int speed)
{
	display_ushort(FAN_ADDR_DISPLAY,speed);
}

void display_mode (unsigned char mode)
{
	display_ushort(MODE_ADDR_DISPLAY,mode);
}

void display_interface(unsigned short interfanceNum)
{
	dgusWrite(REG_ADDR_INTERFACE,interfanceNum);
}

void display_shake (float shake)
{
	display_float(SHAKE_ADDR_DISPLAY,shake);
}

void display_distance(float distance)
{
	display_float(DISTANCE_ADDR_DISPLAY,distance);
}

void display_CO2(float co2)
{
	display_float(CO2_ADDR_DISPLAY,co2);
}

void display_alarm(unsigned char alarm)
{
	display_ushort(ALARM_ADDR_DISPLAY,alarm);
}

void display_mpu9960(float ax,float ay,float az,float wx,float wy,float wz,float max,float may,float maz,float temp)
{
	display_float(MPU9960_ADDR_AX_DISPLAY,ax);
	display_float(MPU9960_ADDR_AY_DISPLAY,ay);
	display_float(MPU9960_ADDR_AZ_DISPLAY,az);
	display_float(MPU9960_ADDR_WX_DISPLAY,wx);
	display_float(MPU9960_ADDR_WY_DISPLAY,wy);
	display_float(MPU9960_ADDR_WZ_DISPLAY,wz);
	display_float(MPU9960_ADDR_MAX_DISPLAY,max);
	display_float(MPU9960_ADDR_MAY_DISPLAY,may);
	display_float(MPU9960_ADDR_MAZ_DISPLAY,maz);
	display_float(MPU9960_ADDR_TEMP_DISPLAY,temp);
}

void display_gestrue(unsigned char num)
{
	display_ushort(GESTYRE_ADDR_DISPLAY,num);
}

void display_battery(unsigned char bat)
{
	display_ushort(BATTERY_ADDR_DISPLAY,bat);
}

void display_led(unsigned char rl,unsigned char yl,unsigned char gl)
{
	display_ushort(LED_RED_ADDR_DISPLAY,rl);
	display_ushort(LED_YELLOW_ADDR_DISPLAY,yl);
	display_ushort(LED_GREEN_ADDR_DISPLAY,gl);
}

void display_finger(unsigned char status)
{
	display_ushort(FINGER_ADDR_DISPLAY,status);
}

void display_communication(unsigned char status)
{
	display_ushort(COMMUNICATION_ADDR_DISPLAY,status);
}
void display_carsh(unsigned char status)
{
	display_ushort(CARSH_ADDR_DISPLAY,status);
}

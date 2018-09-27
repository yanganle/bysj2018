

/******************************
** @time；2017/11/6 16:30:40
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief:	自动模式时，设置的域值
*******************************/ 

#ifndef __CONFIG_H__
#define __CONFIG_H__


//各类传感器阈值
#define LIGHT_SETTING 	2
#define SMOKE_SETTING 	20
#define TEMP_SETTING 		24
#define HUMI_SETTING 		60
#define FAN_SPEED_SETTING 	280
#define FAN_SPEED_SETTING_LOW 0
#define DUST_SETTING  1
#define SHAKE_SETTING 20


//各种传感器显示地址
#define TEMP_ADDR_DISPLAY  			0x0020  //温度显示地址
#define HUMI_ADDR_DISPLAY   		0x0010  //湿度显示地址
#define LIGHT_ADDR_DISPLAY 			0x0030 //光照强度
#define SMOKE_ADDR_DISPLAY   0x0040   //烟雾
#define DUST_ADDR_DISPLAY  0x0050  //粉尘
#define FAN_ADDR_DISPLAY  0x0070  //风扇状态（图）
#define RELAY_ADDR_DISPLAY 0x0060 //继电器状态（图）
#define MODE_ADDR_DISPLAY 		0x00A0 //模式状态
#define DISTANCE_ADDR_DISPLAY 0x00C0 //超声波距离
#define SHAKE_ADDR_DISPLAY  	0x00D0 //震动显示
#define CO2_ADDR_DISPLAY 			0x00E0 //CO2显示
#define ALARM_ADDR_DISPLAY 		0x00F0 //声光报警显示地址

#define MPU9960_ADDR_AX_DISPLAY  0X0100 //x加速度
#define MPU9960_ADDR_AY_DISPLAY  0X0110 //y加速度
#define MPU9960_ADDR_AZ_DISPLAY  0X0120 //z加速度
#define MPU9960_ADDR_WX_DISPLAY  0X0130 //x角速度
#define MPU9960_ADDR_WY_DISPLAY  0X0140 //y角速度
#define MPU9960_ADDR_WZ_DISPLAY  0X0150 //z角速度
#define MPU9960_ADDR_MAX_DISPLAY  0X0160 //x地磁
#define MPU9960_ADDR_MAY_DISPLAY  0X0170 //y地磁
#define MPU9960_ADDR_MAZ_DISPLAY  0X0180 //z地磁
#define MPU9960_ADDR_TEMP_DISPLAY 0x0190 //温度

#define GESTYRE_ADDR_DISPLAY  0x01A0 //手势显示
#define BATTERY_ADDR_DISPLAY  0x01B0 //显示电池
#define LED_GREEN_ADDR_DISPLAY  0x01C0 //显示绿灯
#define LED_YELLOW_ADDR_DISPLAY  0x01D0 //显示黄灯
#define LED_RED_ADDR_DISPLAY   0x01E0 //显示红灯
#define FINGER_ADDR_DISPLAY  0x01F0 //显示指纹
#define COMMUNICATION_ADDR_DISPLAY  0x0200 //显示通讯方式
#define CARSH_ADDR_DISPLAY 		0x0210 //碰撞检测


#define FAN_CONTROL_ADDR  0x0080   //风扇控制地址
#define RELAY_CONTROL_ADDR 0x0090  //继电器控制地址
#define MODE_CONTROL_ADDR 	0x00B0 //模式控制地址





///#define FAN_CONTROL_KEY_VALUE 		 0x0001
//#define RELAY_CONTROL_KEY_VALUE 		0x0002


#endif

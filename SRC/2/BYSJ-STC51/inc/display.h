

/******************************
** @time；2017/11/6 15:22:01
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief: 室内温度采集显示
*******************************/ 



#ifndef __DISPLAY_H__
#define __DISPLAY_H__

void display_temp (float temp);//显示温度
void display_humi (float humi);//显示湿度
void display_pm (float dust);//显示粉尘浓度
void display_smoke (float smoke);//显示烟雾浓度
void display_light (float light);//显示光照强度
void display_mode (unsigned char);//显示当前模式
void display_fan_speed(unsigned int speed);//显示当前风扇转速
void display_relay(unsigned char);//显示继电器状态
void display_mode (unsigned char mode);//显示当前运行模式
void display_shake (float shake);//显示震动状态
void display_interface(unsigned short interfanceNum);//切换界面
void display_distance(float distance);//显示距离
void display_CO2(float co2);//显示CO2浓度
void display_alarm(unsigned char );//声光报警显示
void display_mpu9960(float ax,float ay,float az,float wx,float wy,float wz,float max,float may,float maz,float temp);//显示mpu9960 数据


void display_gestrue(unsigned char num);//显示手势
void display_battery(unsigned char bat);//显示电量
void display_led(unsigned char rl,unsigned char yl,unsigned char gl);
void display_finger(unsigned char status);//显示指纹
void display_communication(unsigned char status);//显示通讯方式
void display_carsh(unsigned char status);//显示碰撞

#endif

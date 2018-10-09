#ifndef __COMMON_H__
#define __COMMON_H__	 
#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h"   	 
#include "key.h"	 	 	 	 	  
#include "malloc.h"
#include "string.h"    
#include "usart3.h" 

void atk_8266_at_response(u8 mode);
u8* atk_8266_check_cmd(u8 *str);
u8 atk_8266_send_cmd(u8 *cmd,u8 *ack,u16 waittime);
u8 atk_8266_send_data(u8 *data,u8 *ack,u16 waittime,u8 datalen);
u8 atk_8266_quit_trans(void);
u8 atk_8266_apsta_check(void);
u8 atk_8266_consta_check(void);
void atk_8266_get_wanip(u8* ipbuf);

#endif






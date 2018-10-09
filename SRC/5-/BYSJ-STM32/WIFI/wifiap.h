#ifndef __WIFIAP_H__
#define __WIFIAP_H__

#include "sys.h"

void ESP8266_WifiAP_Init(void);
void send_wifi_msg(u8 *data,u8 datalen);
void receive_wifi_msg(void);
	
#endif

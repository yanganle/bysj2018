

/******************************
** @time；2017/11/9 18:05:58
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief: 双创通讯协议解析
*******************************/

#include "agreement.h"
#include "stdio.h"
#include "string.h"

zigbeeData zd;
ipv6Data ipd;
bluetoothData bd;
wifiData wd;
m433Data md;


void sensorParse (u8 *str,sensorData* sd);
zigbeeData* parseComByZigbee( u8* str);
ipv6Data* parseComByIpv6( u8* str);
bluetoothData* parseComByBluetooth( u8 *str);
wifiData* parseComByWifi( u8 *str);
m433Data* parseComBy433m( u8* str);

unsigned char lenStr;

void* agreementParse(unsigned char *str)
{
	if (str[0] == CBT_HEADH && str[1] == CBT_HEADL)
	{
		switch (str[2])
		{
			case COMMUNICATION_ZIGBEE:
				return parseComByZigbee(str);
			break;
			case COMMUNICATION_IPV6:
				return parseComByIpv6(str);
			break;
			case COMMUNICATION_BLUETOOTH:
				return parseComByBluetooth(str);
			break;
			case COMMUNICATION_WIFI:
				return parseComByWifi(str);
			break;
			case COMMUNICATION_433M:
				return parseComBy433m(str);
			break;
			default:
				return NULL;
			break;
		}
	}
	return NULL;
}

zigbeeData* parseComByZigbee(u8* str)
{
	int i;
		for ( i=0; i<4; i++)
		{
			zd.nodeAddr[i] = str[i+3];
		}
		zd.nodeChannel = str[4+3];
		zd.nodePanID = str[5+3];
		for ( i=0; i<8; i++)
		{
			zd.nodeMacAddr[i] = str[i+6+3];
		}
		sensorParse(str,&zd.sensorDa);
		return &zd;
}

ipv6Data* parseComByIpv6( u8* str)
{
	int i;
		for (i =0; i<4; i++)
		{
			ipd.nodeAddr[i] = str[i+3];
		}
		
		for ( i=0; i<8; i++)
		{
			ipd.nodeMacAddr[i] = str[i+6+3];
		}
		sensorParse(str,&ipd.sensorDa);
		return &ipd;
}

bluetoothData* parseComByBluetooth( u8 *str)
{
	int i;
		for ( i=0; i<4; i++)
		{
			bd.nodeAddr[i] = str[i+3];
		}
		bd.nodeRssi = str[4+3];
		for ( i=0; i<8; i++)
		{
			bd.nodeMacAddr[i] = str[i+6+3];
		}
		sensorParse(str,&bd.sensorDa);
		return &bd;
}

wifiData* parseComByWifi( u8 *str)
{
	int i;
		for ( i=0; i<4; i++)
		{
			wd.nodeAddr[i] = str[i+3];
		}
		wd.nodePortH = str[4+3];
		wd.nodePortL = str[5+3];
		for ( i=0; i<8; i++)
		{
			wd.nodeMacAddr[i] = str[i+6+3];
		}
		sensorParse(str,&wd.sensorDa);
		return &wd;
}

m433Data* parseComBy433m( u8* str)
{
	int i;
		for ( i=0; i<4; i++)
		{
			md.nodeAddr[i] = str[i+3];
		}
		
		for ( i=0; i<8; i++)
		{
			md.nodeMacAddr[i] = str[i+6+3];
		}
		sensorParse(str,&md.sensorDa);
		return &md;
}

void sensorParse (u8 *str,sensorData *sd)
{
	int i;
			sd->sensorType = str[17];
			sd->sensorID = str[18];
			sd->sensorCMD = str[19];
			sd->sensorDataLen = str[20]; 
      for( i = 0;i < sd->sensorDataLen;i++)
        {
         sd->SensorData[i] = str[i+21];
        }
}

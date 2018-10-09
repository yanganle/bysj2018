#include "agreement.h"
//#include "wifiap.h"
#include "SIM800A.h"
#include "usart.h"
#include "timer.h"
#include "led.h"

u8 SMARTMODE = 0;
u8 tempup_threshold = 5;
u8 tempdown_threshold = 5;
u8 humi_threshold = 5;

sysData DataBuf = {DATA_HEADH, DATA_HEADL, 0, 0, 0, 0, 0, 0, 0, CMDID_UP, 0, 0, 0, 0, 0, 0, 0, DATA_END};

void Send_SensorData(u8 _SensorType, u8 _SenserIndex, u8 *_pData)
{
	DataBuf.dataDet.sIndex    = _SenserIndex;
	DataBuf.dataDet.sValue[0] = _pData[0];
	DataBuf.dataDet.sValue[1] = _pData[1];
	DataBuf.dataDet.sValue[2] = _pData[2];
	DataBuf.dataDet.sValue[3] = _pData[3];
	DataBuf.dataDet.sType		  = _SensorType;
	
	//send_wifi_msg(DataBuf.dataArry, DATA_LENGTH); //wifi
	UART_SendMyData(DataBuf.dataArry, DATA_LENGTH); //uart
}

void agreementParse(u8 *str)
{
	if(str[0] == DATA_HEADH && str[1] == DATA_HEADL && str[17] == DATA_END)
	{
		if(str[9] == CMDID_MODE) //设置模式
		{
			SMARTMODE = str[16];

			tempup_threshold = str[15];
		}
		
		if(str[9] == CMDID_DOWN) //下发控制指令
		{
			switch (str[10]) //不同传感器
			{
				case SENSOR_WATER_VALVE:
					IO_VALVE = str[16];
					flag_taskFour = 1;
					break;
				case SENSOR_WATER_PUMP:
					IO_PUMP = str[16];
					flag_taskThree = 1;
					break;
				default:
					break;
			}
		}
	}
}


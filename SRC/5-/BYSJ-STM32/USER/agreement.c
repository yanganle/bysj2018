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

u8 *mynumber = "00310038003100340031003900320031003600360031"; //目标号码
u8 *one = "4EBA545862A58B66"; //一号药品
u8 *two = "970752A862A58B66"; //二号药品
u8 *three = "970752A862A58B66"; //三号药品

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

			humi_threshold = str[15];
			tempup_threshold = str[14];
			tempdown_threshold = str[13];
		}
		
		if(str[9] == CMDID_DOWN) //下发控制指令
		{
			switch (str[10]) //不同传感器
			{
				case SENSOR_FAN:
					IO_FAN = str[16];
					flag_taskTwo = 1;
					break;
				case SENSOR_HOT:
					IO_HOT = str[16];
					flag_taskThree = 1;
					break;
				case SENSOR_MEDICINE:
					switch(str[16])
					{
						case 1: //药品一
							sam800a_send_chmessage(mynumber, one);
							break;
						case 2:
							sam800a_send_chmessage(mynumber, two);
							break;
						case 3:
							sam800a_send_chmessage(mynumber, three);
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}
	}
}


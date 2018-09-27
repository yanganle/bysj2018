#include "agreement.h"
#include "uart.h"
#include "uart2.h"
#include "io.h"

u8 SMARTMODE = 0;
u8 watl_threshold = 5;

sysData DataBuf = {DATA_HEADH, DATA_HEADL, 0, 0, 0, 0, CMDID_UP, 0, 0, 0, 0, 0, 0, DATA_END};

void Send_SensorData(u8 _SensorType, u8 _SenserIndex, u8 *_pData)
{
	DataBuf.dataDet.sIndex    = _SenserIndex;
	DataBuf.dataDet.sValue[0] = _pData[0];
	DataBuf.dataDet.sValue[1] = _pData[1];
	DataBuf.dataDet.sValue[2] = _pData[2];
	DataBuf.dataDet.sValue[3] = _pData[3];
	DataBuf.dataDet.sType		  = _SensorType;
	
	uartSendData(DataBuf.dataArry, DATA_LENGTH);
}

void agreementParse(u8 *str)
{
	if(str[0] == DATA_HEADH && str[1] == DATA_HEADL && str[13] == DATA_END)
	{
		if(str[9] == CMDID_MODE) //设置模式
		{
			SMARTMODE = str[12];

			watl_threshold = str[11];
		}
		
		if(str[9] == CMDID_DOWN) //下发控制指令
		{
			switch (str[8]) //不同传感器
			{
				case SENSOR_WATER_PUMP://报警设备
					if(str[12])
						PUMP_ON();
					else
						PUMP_ON();
					break;
				default:
					break;
			}
		}
	}
}


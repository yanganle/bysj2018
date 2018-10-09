#include "agreement.h"
#include "uart.h"
#include "uart2.h"
#include "io.h"
#include "mysys.h"

u8 SMARTMODE = 0;
u8 temp_threshold = 32;
u8 humi_threshold = 60;
u8 meth_threshold = 10;

sysData DataBuf = {DATA_HEADH, DATA_HEADL, 0, 0, 0, 0, 0, 0, 0, CMDID_UP, 0, 0, 0, 0, 0, 0, 0, DATA_END};

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
	if(str[0] == DATA_HEADH && str[1] == DATA_HEADL && str[17] == DATA_END)
	{
		if(str[9] == CMDID_MODE) //����ģʽ
		{
			SMARTMODE = str[16];

			meth_threshold = str[13];
			temp_threshold = str[15];
			humi_threshold = str[14];
		}
		
		if(str[9] == CMDID_DOWN) //�·�����ָ��
		{
			switch (str[10]) //��ͬ������
			{
				case SENSOR_FAN://�����豸
					if(str[16]) FAN_ON();
					else FAN_OFF();
					flag_taskFive = 1;
					break;
				default:
					break;
			}
		}
	}
}


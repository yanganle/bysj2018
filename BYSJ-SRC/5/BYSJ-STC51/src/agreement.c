#include "agreement.h"
#include "uart.h"
#include "uart2.h"
#include "io.h"

u8 SMARTMODE = 0;

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
		if(str[9] == CMDID_MODE) //����ģʽ
		{
			SMARTMODE = str[12];	
		}
		
		if(str[9] == CMDID_DOWN) //�·�����ָ��
		{
			switch (str[8]) //��ͬ������
			{
				case SENSOR_SL_ALARM://�����豸
					if(str[12])
						BEEP_ON();
					else
						BEEP_ON();
					break;
				case SENSOR_LAMP://�ƹ�
					//do somthing
					break;
				default:
					break;
			}
		}
	}
}


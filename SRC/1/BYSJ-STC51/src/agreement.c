/******************************
** @time��2018/08/15 11:26:02
** @Author: superman
** @email: ***@qq.com
** @brief: ͨѶЭ�����
*******************************/
#include "agreement.h"
#include "uart.h"
#include "io.h"

u8 SMARTMODE = 0;
u8 TEMPTHRESHOLD;

agreementData dataBuffer = {DATA_HEADH,DATA_HEADL,0x01,0,0,0,0,0,0,CMDID_UP,0,0,0,0,0,0,0,DATA_END};

void Send_SensorData(u8 _SensorStyle, u8 _SenserIndex, u8 *_pData)
{
	dataBuffer.dataDetail.value.sensorID   = _SenserIndex;
	dataBuffer.dataDetail.value.Sensorvalue[0] = _pData[0];
	dataBuffer.dataDetail.value.Sensorvalue[1] = _pData[1];
	dataBuffer.dataDetail.value.Sensorvalue[2] = _pData[2];
	dataBuffer.dataDetail.value.Sensorvalue[3] = _pData[3];
	dataBuffer.dataDetail.value.sensorType = _SensorStyle;
	
	uartSendData(dataBuffer.dataArry, DATA_LENGTH);
}

void agreementParse(u8 *str)
{
	if(str[0] == DATA_HEADH && str[1] == DATA_HEADL && str[17] == DATA_END)
	{
		if(str[9] == CMDID_MODE) //����ģʽ
		{
			SMARTMODE = str[16];
			TEMPTHRESHOLD = str[15];		
		}
		
		if(str[9] == CMDID_DOWN) //�·�����ָ��
		{
			switch (str[10]) //��ͬ������
			{
				case SENSOR_FAN://����
					if(str[16])
						FAN_ON();
					else
						FAN_OFF();
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


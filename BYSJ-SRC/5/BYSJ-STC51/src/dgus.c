

/******************************
** @time；2017/11/7 10:53:15
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief: 串口屏接口
*******************************/ 



#include "dgus.h"


dgusReg dgusRx[DGUS_MAX_READ_LENGTH]; 

void sentHead (void)
{
	
  dgusSentOneByte(HEADH);
	dgusSentOneByte(HEADL);
}

void dgusWrite(uchar addr,ushort myData)
{
//	uchar temp[3];
	sentHead();
	dgusSentOneByte(4);
//	temp[0] = CMD_WRITE_REG;
//	temp[1] = addr;
//	temp[2] = myData
	dgusSentOneByte(CMD_WRITE_REG);
	dgusSentOneByte(addr);
	dgusSentOneByte(myData<<8);
	dgusSentOneByte(myData);
	
	//dgusSentOneByte(usMBCRC16(temp,3)>>8);
	//dgusSentOneByte(usMBCRC16(temp,3));
	
}

void dgusReadNbyte(uchar addr,uchar length)
{
	//uchar temp[3];
	sentHead();
	dgusSentOneByte(5);
	//temp[0] = CMD_WRITE_REG;
	//temp[1] = addr;
	//temp[2] = length;
	dgusSentOneByte(CMD_READ_REG);
	dgusSentOneByte(addr);
	dgusSentOneByte(length);
	
	//dgusSentOneByte(usMBCRC16(temp,3)>>8);
//	dgusSentOneByte(usMBCRC16(temp,3));	
}

void dgusWriteVar(ushort varAddr,ushort varData){
	uchar temp[7],i;
	//ushort xor;
	sentHead();
	dgusSentOneByte(5);
	temp[0] = CMD_WIRTE_VAR;
	temp[1] = varAddr>>8;
	temp[2] = varAddr;
	temp[3] = varData>>8;
	temp[4] = varData;
//	xor = usMBCRC16(temp,5);
//	temp[5] = xor>>8;
//	temp[6] = xor;
	
	for(i = 0;i< 5;i++)
	{
		dgusSentOneByte(temp[i]);
	}	
}

void dgusReadVar(ushort varAddr,uchar length){
	uchar temp[6],i;
	//ushort xor;
	sentHead();
	dgusSentOneByte(6);
	temp[0] = CMD_READ_VAR;
	temp[1] = varAddr>>8;
	temp[2] = varAddr;
	temp[3] = length;
//	xor = usMBCRC16(temp,4);
//	temp[4] = xor>>8;
//	temp[5] = xor;
	
	for(i = 0;i< 4;i++)
	{
		dgusSentOneByte(temp[i]);
	}	
}

void dgusDrawCurve(uchar mode,ushort* chData)
{
	uchar temp[20],i,len = 0;
//	ushort xor;
	sentHead();
	temp[0] = CMD_CURVE_BUFFER;
	temp[1] = mode;
	
	for(i = 0;i < 8;i++){
		if((mode>>i) & 0x01){
			len++;
			temp[1+len] = chData[i]>>8;
			len++;
			temp[1+len] = chData[i];
		}
	}
	//xor = usMBCRC16(temp,len+2);
	//temp[len+2] = xor>>8;
	//temp[len+3] = xor;
	
	
	//dgusSentOneByte(len+4);
//for(i = 0;i< (len+4);i++)
	//{
///		dgusSentOneByte(temp[i]);
	//}	
}

void dgusDealKeyValue (void)
{
        uchar regNumber;
	//uchar len,cmd;
	ushort startAddr,i,j;
	if(DGUS_STA)
		{
			if(DGUS_RX_BUF[0]  == HEADH && DGUS_RX_BUF[1] == HEADL)//检验数据头
				{
					//len = DGUS_RX_BUF[2];
					//cmd = DGUS_RX_BUF[3];
					startAddr = (DGUS_RX_BUF[4]<<8)+DGUS_RX_BUF[5];
					regNumber = DGUS_RX_BUF[6];
					for(i = 0,j = 0;j < regNumber;i++,j+=2)
					{
									dgusRx[i].regAddr = startAddr+i;
									dgusRx[i].regValue = (DGUS_RX_BUF[7+j]<<8)+DGUS_RX_BUF[j+8];
									
					}
				}
		}
}

void dgusClear(uchar i)
{
  dgusRx[i].regAddr = 0;
  dgusRx[i].regValue = 0;
}


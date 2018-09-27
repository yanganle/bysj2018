#include "AM231X.h"


unsigned char IIC_TX_Buffer[]={0x03,0x00,0x04};
unsigned char IIC_RX_Buffer[IIC_RX_Length];
unsigned char WR_Flag;



//***************************************************
u8 WriteNByte(unsigned char sla,unsigned char *s,unsigned char n)
{
   unsigned char i;
   IIC_Start();
   IIC_Send_Byte(sla);	
   Delay40us();
   IIC_Wait_Ack();
   for(i=0;i<n;i++)
   {
      IIC_Send_Byte(*(s+i));
			IIC_Wait_Ack();
   }
   IIC_Stop();
   return 1;
}

u8 ReadNByte(unsigned char Sal, unsigned char *p,unsigned char n)
{
  unsigned char i;
  IIC_Start();
  IIC_Send_Byte((Sal|0x01));
	Delay40us();
  IIC_Wait_Ack();
  for(i=0;i<n;i++)
  {
     if(i == (n-1)) *(p+i)=IIC_Read_Byte(0);
     else *(p+i)=IIC_Read_Byte(1);
  }
  IIC_Stop();
  return 1;
}

unsigned int CRC16(unsigned char *ptr, unsigned char len)
{
   unsigned int crc=0xffff;
   unsigned char i;
   while(len--)
   {
       crc ^=*ptr++;
       for(i=0;i<8;i++)
	   {
	       if(crc & 0x1)
		   {
		      crc>>=1;
			  crc^=0xa001;
		   }
		   else
		   {
		      crc>>=1;
		   }
	   }
   }
   return crc;
}

unsigned char CheckCRC(unsigned char *ptr,unsigned char len)
{
  unsigned int crc;
	crc=(unsigned int)CRC16(ptr,len-2);
	if(ptr[len-1]==(crc>>8) && ptr[len-2]==(crc & 0x00ff))
	{
	    return 0xff;
	}
	else
	{
	   return 0x0;
	}
}
void Waken(void)
{

	IIC_Start();
	IIC_Send_Byte(IIC_Add);
	IIC_Wait_Ack();
	delay_ms(1);
	IIC_Stop();
}

unsigned char AM231X_getValue(float* tempValue,float* humiValue)
{
	float Tmp1,Tmp2;
	Waken();                                                                                                                                                                                                                                                                            
  WriteNByte(IIC_Add,IIC_TX_Buffer,3);
  delay_ms(2);
  ReadNByte(IIC_Add,IIC_RX_Buffer,8);
  delay_ms(3);
	if(CheckCRC(IIC_RX_Buffer,8))
	{
		Tmp1 = IIC_RX_Buffer[2]*256+IIC_RX_Buffer[3];
		Tmp1=Tmp1/10;
		Tmp2 = IIC_RX_Buffer[4]*256+IIC_RX_Buffer[5];
		Tmp2=Tmp2/10;
		*tempValue = Tmp2;
		*humiValue = Tmp1;
		return 1;
	}else
	{
		return 0;
	}
}

void Clear_Data()
{
	int i;
	for(i=0;i<IIC_RX_Length;i++)
	{
	IIC_RX_Buffer[i] = 0x00;
	}
}

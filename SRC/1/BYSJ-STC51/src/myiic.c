#include   "STC15Wxxxx.H"
#include   "myiic.h"

#define SCL P42
#define SDA P41

void delay()		//@24.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 27;
	while (--i);
}

static void delay_us(unsigned char us){
	while((us--)>0){
		delay();
	}
}

void IIC_Init()              //��ʼ��
{
       SCL=1;
       delay();
       SDA=1;
       delay();
}

void IIC_Start()         //�����ź�
{
				delay_us(6);
			 SDA=1;
	     SCL=1;
       delay_us(6);

       SDA=0;
       delay_us(6);
			 SCL=0;
}

void IIC_Stop()            //ֹͣ�ź�
{
	SCL = 0;
	delay_us(2);
  SDA=0;
  delay_us(6);
  SCL=1;
	delay_us(2);
	SDA = 1;
	delay_us(6);
}

u8 IIC_Wait_Ack()             //��Ӧ�ź�
{
       u8 i=0;
			 SDA=1;
	     SCL=1;
				delay_us(6);
			 while((SDA==1)&&i<255)
			 {
				 i++;
			 }
			 SCL=0;
			 delay_us(6);
			 return 0;

}
// ����ACKӦ��
void IIC_Ack()
{
			SCL=0;
			delay_us(3);
	    SDA=0;
			delay_us(3);
			SCL=1;
			delay_us(3);
			SCL=0;
}
// ������Ӧ��
void IIC_Nack()
{
			SCL=0;
			delay_us(3);
	    SDA=1;
			delay_us(3);
			SCL=1;
			delay_us(3);
			SCL=0;
}

void IIC_Send_Byte(u8 date)//       дһ���ֽ�
{
       u8 i,txd,temp;
       temp=date;
			 SCL=0;
       for(i=0;i<8;i++)
       {
              txd=temp/128;
							temp=temp<<1;

              SDA=txd;
							delay_us(6);
              SCL=1;
            	delay_us(6);
							SCL=0;
              delay_us(6);
       }
}

u8 IIC_Read_Byte(u8 ack)//��һ���ֽ�
{
       u8 i,ch = 0,date = 0;
       for(i=0;i<8;i++)     //����8������
       {
							SDA = 1;
				      SCL=0;
							delay_us(6);
							// delay_us(2);
              SCL=1;
              if(SDA==1)
                ch=1;
              else
                ch=0;

							date = date<<1;
              date|=ch;
              delay_us(6);
       }

			 if(!ack){
					IIC_Nack();
			 }else{
				 IIC_Ack();
			 }
       return date;
}

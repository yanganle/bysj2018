#include"uart2.h"

sfr AUXR1 = 0xA2;
sfr	AUXR = 0x8E;
sfr S2CON = 0x9A;	//12C5A60S2˫����ϵ��
sfr S2BUF = 0x9B;	//12C5A60S2˫����ϵ��
sfr IE2   = 0xAF;	//STC12C5A60S2ϵ��
sfr BRT   = 0x9C;

bit busy2;
u8 UART2_RX_BUF[BUFFER_LENGTH];
u8 uart2RxSta = 0;
u8 uart2RxCount;
u8 uart2RxTimeOut;
u8 flag_uart2_rx;

void Uart2Init(void)		//9600@12.000MHz
{
	AUXR |=  (1 << 3);		//����2�����ʼӱ�
	S2CON  = (S2CON & 0x3f) | (1<<6);	//����2ģʽ1��8λUART��(2^S2SMOD / 32) * BRT�����
	S2CON |= 1 << 4;		//����2����

	AUXR |=  1 << 4;	//baudrate use BRT
	BRT = BRT_Reload;

	IE2 |=  1;			//������2�ж�
}

/*----------------------------
UART2 �жϷ������
-----------------------------*/
void Uart2() interrupt 8 using 1
{
	if (RI2)
	{
		CLR_RI2();         //���S2RIλ
		if (uart2RxSta == 0) flag_uart2_rx = 1;
		if(uart2RxCount < BUFFER_LENGTH){
			uart2RxTimeOut = TIME_OUT;
			UART2_RX_BUF[uart2RxCount++] = S2BUF;
		}else{
			uart2RxSta = 1;
    	uart2RxCount = 0;
		}
	}
	if (TI2)
	{
			CLR_TI2();         //���S2TIλ
			busy2 = 0;         //��æ��־
	}
}

/*----------------------------
���ʹ�������
----------------------------*/
void SendData(u8 dat)
{
	  S2BUF = dat;                //д���ݵ�UART2���ݼĴ���
    busy2 = 1;
	  while (busy2);               //�ȴ�ǰ������ݷ������
}

/*----------------------------
�����ַ���
----------------------------*/
void UART2_SendString(char *s)
{
    while (*s)                  //����ַ���������־
    {
        SendData(*s++);         //���͵�ǰ�ַ�
    }
}

void uart2SendData(char *buffer, u8 datalen)
{
	u8 i;
	for(i=0;i<datalen;i++)
		SendData(buffer[i]);
}

void clearBuf2(){
	u8 i;
	for(i = 0; i < BUFFER_LENGTH;i++){
		UART2_RX_BUF[i] = 0;
		uart2RxCount = 0;
	}
}

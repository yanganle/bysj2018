

/******************************
** @time��2017/11/17 14:30:17
** @Author: mantisAlone
** @email: gxd@cyb-bot.com
** @brief:
*******************************/ 

#include "uart3.h"

bit busy3;
u8 UART3_RX_BUF[BUFFER_LENGTH];
u8 uart3RxSta = 0;
u8 uart3RxCount;
u8 uart3RxTimeOut;
u8 flag_uart3_rx;

void Uart3Init(void)		//115200bps@24.000MHz
{
	P_SW2 &= ~0x02; 
	S3CON = 0x10;		//8λ����,�ɱ䲨����
	S3CON &= 0xBF;		//����3ѡ��ʱ��2Ϊ�����ʷ�����
	AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
	T2L = 0xCC;		//�趨��ʱ��ֵ
	T2H = 0xFF;		//�趨��ʱ��ֵ
	AUXR |= 0x10;		//������ʱ��2
	S3_Int_Enable();
	S3_RX_Enable();
}

/*----------------------------
UART3 �жϷ������
-----------------------------*/
void Uart3() interrupt 17 using 1
{
    if (RI3)
    {
       CLR_RI3(); 
			 if (uart3RxSta == 0) flag_uart3_rx = 1;
			 if(uart3RxCount < BUFFER_LENGTH){
			 uart3RxTimeOut = TIME_OUT;
			 UART3_RX_BUF[uart3RxCount++] = S3BUF;
			 }else{
			 uart3RxSta = 1;
    	uart3RxCount = 0;
			}
		}
    if (TI3)
    {
			CLR_TI3();
        busy3 = 0;               //��æ��־
    }
}

/*----------------------------
���ʹ�������
----------------------------*/
void uart3SendData(char dat)
{
    while (busy3);               //�ȴ�ǰ������ݷ������
    busy3 = 1;
    S3BUF = dat;                //д���ݵ�UART3���ݼĴ���
}

/*----------------------------
�����ַ���
----------------------------*/
void uart3SendString(char *s)
{
    while (*s)                  //����ַ���������־
    {
        uart3SendData(*s++);         //���͵�ǰ�ַ�
    }
}

void clearBuf3(void)
{
	int i;
	for (i=0; i<BUFFER_LENGTH; i++)
	{
		UART3_RX_BUF[i] = 0;
		uart3RxCount = 0;
	}
}

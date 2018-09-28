#include "uart.h"

bit busy;
u8 UART_RX_BUF[BUFFER_LENGTH];
u8 uartRxSta = 0;
u8 uartRxCount;
u8 uartRxTimeOut;
u8 flag_uart_rx;

unsigned char cmd;

void UartInit(void)		//115200bps@24.000MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ
	TH1 = 256-MAIN_Fosc/(Baud_Rate*12*16);			//�趨��ʱ��ֵ
	TL1 = 256-MAIN_Fosc/(Baud_Rate*12*16);			//�趨��ʱ��ֵ
	PCON |= 0x80;     //�����ʼӱ�
	ES = 1;					//�����ж�����
	TR1 = 1;				//������ʱ��1
	REN = 1;        //�������
	EA = 1; 				//�������ж�
}

/*----------------------------
UART �жϷ������
-----------------------------*/
void Uart() interrupt 4
{
    if (RI)
    {
        RI = 0;                 //���RIλ
				if (uartRxSta == 0) flag_uart_rx = 1;
				if(uartRxCount < BUFFER_LENGTH)
				{
					uartRxTimeOut = TIME_OUT;
					UART_RX_BUF[uartRxCount++] = SBUF;
				}else{
					uartRxSta = 1;
					uartRxCount = 0;
				}
    }
    if (TI)
    {
        TI = 0;                 //���TIλ
        busy = 0;               //��æ��־
    }
}


/*----------------------------
���ʹ�������
----------------------------*/
void Putchar(char dat)
{
    SBUF = dat;                //д���ݵ�UART3���ݼĴ���
	  busy = 1;
	  while (busy);               //�ȴ�ǰ������ݷ������
}

/*----------------------------
�����ַ���
----------------------------*/
void uartSendString(char *s)
{
    while (*s)                  //����ַ���������־
    {
        Putchar(*s++);         //���͵�ǰ�ַ�
    }
}

void uartSendData(char *buffer, u8 datalen)
{
	u8 i;
	for(i=0;i<datalen;i++)
		Putchar(buffer[i]);
}

void clearBuf(void)
{
	int i;
	for (i=0; i<BUFFER_LENGTH; i++)
	{
		UART_RX_BUF[i] = 0;
		uartRxCount = 0;
	}
}

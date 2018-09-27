#include"uart2.h"

#define S2RI  0x01              //S2CON.0
#define S2TI  0x02              //S2CON.1
#define TIME_OUT 		40

bit busy2;
u8 UART2_RX_BUF[BUFFER_LENGTH];
u8 uart2RxSta = 0;
u8 uart2RxCount;
u8 uart2RxTimeOut;
u8 flag_uart2_rx;



void Uart2Init(void)		//115200@24.000MHz
{
	P_SW2 &= ~0x01;
	S2CON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
//	T2L = 0x98;		//�趨��ʱ��ֵ
//	T2H = 0xFF;		//�趨��ʱ��ֵ
	T2L = 0xCC;		//�趨��ʱ��ֵ
	T2H = 0xFF;		//�趨��ʱ��ֵ
	AUXR |= 0x10;		//������ʱ��2
	
	UART2_INT_ENABLE();
	S2_RX_Enable();
}

/*----------------------------
UART2 �жϷ������
-----------------------------*/
void Uart2() interrupt 8 using 1
{
    if (S2CON & S2RI)
    {
        S2CON &= ~S2RI;         //���S2RIλ
		if (uart2RxSta == 0) flag_uart2_rx = 1;
		if(uart2RxCount < BUFFER_LENGTH){
			uart2RxTimeOut = TIME_OUT;
			UART2_RX_BUF[uart2RxCount++] = S2BUF;
		}else{
			uart2RxSta = 1;
    	uart2RxCount = 0;
		}
    }
    if (S2CON & S2TI)
    {
        S2CON &= ~S2TI;         //���S2TIλ
        busy2 = 0;               //��æ��־
    }
}

/*----------------------------
���ʹ�������
----------------------------*/
void SendData(u8 dat)
{
    while (busy2);               //�ȴ�ǰ������ݷ������
    busy2 = 1;
    S2BUF = dat;                //д���ݵ�UART2���ݼĴ���
}

/*----------------------------
�����ַ���
----------------------------*/
void SendString2(char *s)
{
    while (*s)                  //����ַ���������־
    {
        SendData(*s++);         //���͵�ǰ�ַ�
    }
}
void clearBuf2(){
	unsigned char i;
	for(i = 0; i < BUFFER_LENGTH;i++){
		UART2_RX_BUF[i] = 0;
		uart2RxCount = 0;
	}
}

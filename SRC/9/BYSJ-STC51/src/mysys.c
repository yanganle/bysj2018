#include "mysys.h"
#include "uart.h"
#include "uart2.h"

u32 heartBeat;
u8 flag_taskOne = 0;
u8 flag_taskTwo = 0;
u8 flag_taskThree = 0;

u8 sendManMsgFlag = 1;
u8 sendManMsgTout = 0;
u8 sendShkMsgFlag = 1;
u8 sendShkMsgTout = 0;

void mysysinit()
{
	TMOD &= 0xF0;
	TMOD |= 0x01;    //����Ϊ16λ�Զ���װ��ʱ�������ֵ�Զ���װ��TL0��TH0��
	TH0=(65536-46080)/256; //50ms = 46080 �����ж�
	TL0=(65536-46080)%256;
	TR0 = 1;				//��ʱ��0�����п���λ
	ET0 = 1;				//��ʱ��0���ж��������λ
	EA = 1;					//�����ж�
}

// ����: timer0�жϺ���.50ms
// �ж�ʱ��̫�̻ᵼ�´����쳣
void timer0(void) interrupt TIMER0_VECTOR
{
	TH0=(65536-46080)/256;
	TL0=(65536-46080)%256;
	
	if(heartBeat < 30000) heartBeat++;
	else heartBeat = 0;

	if((heartBeat%20)==0)
		flag_taskOne = 1;

  if(heartBeat%15 == 0)
		flag_taskTwo = 1;
	
	if(sendManMsgTout>0)sendManMsgTout--;
	else sendManMsgFlag = 1;
	
	if(sendShkMsgTout>0)sendShkMsgTout--;
	else sendShkMsgFlag = 1;
	
	//���ڿ������
	if(flag_uart_rx) //uart1
	{
		if(uartRxTimeOut>0)uartRxTimeOut--;
		else 
		{
			flag_uart_rx = 0;
			uartRxSta = 1;
		}
	}
	if(flag_uart2_rx) //uart2
	{
		if(uart2RxTimeOut>0)uart2RxTimeOut--;
		else 
		{
			flag_uart2_rx = 0;
			uart2RxSta = 1;
		}
	}
}

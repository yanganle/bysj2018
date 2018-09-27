#ifndef __UART2_H__
#define __UART2_H__

#include <reg52.h> 
#include <stdio.h> 

#define Baudrate2		9600	
#define MAIN_Fosc		12000000UL	
#define BUFFER_LENGTH 127
#define TIME_OUT 		1

#define BRT_Reload		(256 - MAIN_Fosc / 12 / 16 / Baudrate2)		//Calculate BRT reload value

#define	TI2					(S2CON & 0x02) != 0
#define	RI2					(S2CON & 0x01) != 0
#define	CLR_TI2()		S2CON &= ~0x02
#define	CLR_RI2()		S2CON &= ~0x01

extern u8 uart2RxSta;
extern u8 UART2_RX_BUF[BUFFER_LENGTH];
extern u8 uart2RxCount;
extern u8 uart2RxTimeOut;
extern u8 flag_uart2_rx;

void Uart2Init(void);
void SendData(u8 dat);
void clearBuf2(void);
void UART2_SendString(char *s);
void uart2SendData(char *buffer, u8 datalen);

#endif

#ifndef __UART_H__
#define __UART_H__

#include <reg52.h> 
#include <stdio.h> 

#define MAIN_Fosc  12000000UL
#define Baud_Rate  9600UL

#define BUFFER_LENGTH 127
#define TIME_OUT 	1

extern u8 uartRxSta;
extern u8 UART_RX_BUF[BUFFER_LENGTH];
extern u8 uartRxCount;
extern u8 uartRxTimeOut;
extern u8 flag_uart_rx;

void UartInit(void);
void Putchar(char dat);
void uartSendString(char *s);
void uartSendData(char *buffer, u8 datalen);
void clearBuf(void);

extern unsigned char cmd;

#endif

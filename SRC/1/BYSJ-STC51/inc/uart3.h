#ifndef __UART3_H__
#define __UART3_H__
#include  "STC15Wxxxx.H"
#define BUFFER_LENGTH 200
#define TIME_OUT 	40

extern u8 uart3RxSta;
extern u8 UART3_RX_BUF[BUFFER_LENGTH];
extern u8 uart3RxCount;
extern u8 uart3RxTimeOut;
extern u8 flag_uart3_rx;

void Uart3Init(void);
void uart3SendData(u8 dat);
void uart3SendString(char *s);
void clearBuf3(void);

#endif

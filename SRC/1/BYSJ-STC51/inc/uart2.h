#ifndef __UART2_H__
#define __UART2_H__

#include  "STC15Wxxxx.H"
#define BUFFER_LENGTH 200

extern u8 uart2RxSta;
extern u8 UART2_RX_BUF[BUFFER_LENGTH];
extern u8 uart2RxCount;
extern u8 uart2RxTimeOut;
extern u8 flag_uart2_rx;


void Uart2Init(void);
void SendData(u8 dat);
void SendString2(char *s);
void clearBuf2(void);


#endif

#include "SIMxxx.h"
#include "MT_UART.h"
#include <string.h>
#include <stdio.h>

void delay_ms(uint8 Time);//n ms延时

uint8 SIM900_CSQ[4];

uint8 *sim900a_check_cmd(uint8 *str)
{
    char *strx=NULL;
    if(UART1_RX_STA)
    { 
      strx=strstr((const char*)UART1_RX_BUF,(const char*)str);
    } 
    return (uint8 *)strx;
}

uint8 sim900a_send_cmd(uint8 *cmd,uint8 *ack,uint16 waittime)
{	
	uint8 res=0;

	HalUARTWrite(UART1, cmd, sizeof(cmd));
	if(ack&&waittime)		
	{
		while(--waittime)	
		{
			delay_ms(10);
			if(UART1_RX_STA)
			{
				if(sim900a_check_cmd(ack))break; 
				UART1_RX_STA=0;
			} 
		}
		if(waittime==0)res=1; 
	}
	return res;
}
uint8 sim900a_work_test(void)
{
	if(sim900a_send_cmd((uint8 *)"AT\r\n",(uint8 *)"OK",100))
	{
		if(sim900a_send_cmd((uint8 *)"AT\r\n",(uint8 *)"OK",100))return SIM_COMMUNTION_ERR;	//通信不上
	}		
	if(sim900a_send_cmd((uint8 *)"AT+CPIN?\r\n",(uint8 *)"READY",400))return SIM_CPIN_ERR;	//没有SIM卡
	if(sim900a_send_cmd((uint8 *)"AT+CREG?\r\n",(uint8 *)"0,1",400))
	{
		if(strstr((const char*)UART1_RX_BUF,"0,5")==NULL)
		{
			 if(!sim900a_send_cmd((uint8 *)"AT+CSQ\r\n",(uint8 *)"OK",200))	
			 {
				memcpy(SIM900_CSQ,UART1_RX_BUF+15,2);
			 }
			 return SIM_CREG_FAIL;	//等待附着到网络
		}
	}
	return SIM_OK;
}
uint8 sim900a_send_chmessage_shan(uint8 *number,uint8 *content)
{
	uint8 cmd[60];
	sprintf((char*)cmd,"AT+CMGS=\"%s\"\r\n",number);
	if(sim900a_send_cmd((uint8 *)"AT+CMGF=1\r\n",(uint8 *)"OK",200))	return SIM_CMGF_ERR;
	if(sim900a_send_cmd((uint8 *)"AT+CSCS=\"UCS2\"\r\n",(uint8 *)"OK",200))	return SIM_CSCS_ERR;
	if(sim900a_send_cmd((uint8 *)"AT+CSCA?\r\n",(uint8 *)"OK",200))	return SIM_CSCA_ERR;
	if(sim900a_send_cmd((uint8 *)"AT+CSMP=17,167,0,24\r\n",(uint8 *)"OK",200))	return SIM_CSMP_ERR;
	if(sim900a_send_cmd(cmd,(uint8 *)">",200)) return SIM_CMGS_ERR;
	sim900a_send_cmd(content,"",0);
	cmd[0]=0x1a;cmd[1]=0;
	if(sim900a_send_cmd(cmd,(uint8 *)"+CMGS:",2000)) return SIM_CMGS_SEND_FAIL;
	return SIM_OK;
}

void delay_ms(uint8 Time)//n ms延时
{
  uint8 i;
  while(Time--)
  {
    for(i=0;i<100;i++)
      MicroWait(10);
  }
}
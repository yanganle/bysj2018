#include "SIM800A.h"
#include "usart3.h"
#include "string.h"
#include "delay.h"

u8 SIM900_CSQ[4];

u8* sim900a_check_cmd(u8 *str)
{
	char *strx=0;
	if(USART3_RX_STA&0X8000)
	{ 
		strx=strstr((const char*)USART3_RX_BUF,(const char*)str);
		USART3_RX_STA=0;
	} 
	return (u8*)strx;
}

u8 sim900a_send_cmd(u8 *cmd,u8 *ack,u16 waittime)
{	
	u8 res=0;
	
	u3_printf("%s\r\n",cmd);
	if(ack&&waittime)		
	{
		while(--waittime)	
		{
			delay_ms(10);
			if(USART3_RX_STA&0X8000)
			{	
				if(sim900a_check_cmd(ack))break; 
			} 
		}
		if(waittime==0)res=1; 
	}

	return res;
}

u8 sim800a_work_init(void)
{
	if(sim900a_send_cmd((u8 *)"AT\r\n",(u8 *)"OK",100))
	{
		if(sim900a_send_cmd((u8 *)"AT\r\n",(u8 *)"OK",100))return SIM_COMMUNTION_ERR;	//通信不上
	}		
	if(sim900a_send_cmd((u8 *)"AT+CPIN?\r\n",(u8 *)"READY",400))return SIM_CPIN_ERR;	//没有SIM卡
	if(sim900a_send_cmd((u8 *)"AT+CREG?\r\n",(u8 *)"0,1",400))
	{
		if(strstr((const char*)USART3_RX_BUF,"0,5")==NULL)
		{
			 if(!sim900a_send_cmd((u8 *)"AT+CSQ\r\n",(u8 *)"OK",200))	
			 {
					memcpy(SIM900_CSQ,USART3_RX_BUF+15,2);
			 }
			 return SIM_CREG_FAIL;	//等待附着到网络
		}
	}
	return SIM_OK;
}

u8 sam800a_send_chmessage(u8 *number, u8 *content)
{
	u8 cmd[60];
	sprintf((char*)cmd,"AT+CMGS=\"%s\"\r\n",number);
	//if(sim900a_send_cmd((u8 *)"ATE0\r\n",(u8 *)"OK",100))	return SIM_SETECHO_ERR; //关闭回显
	if(sim900a_send_cmd((u8 *)"AT+CMGF=1\r\n",(u8 *)"OK",100))	return SIM_CMGF_ERR;
	if(sim900a_send_cmd((u8 *)"AT+CSCS=\"UCS2\"\r\n",(u8 *)"OK",100))	return SIM_CSCS_ERR;
	if(sim900a_send_cmd((u8 *)"AT+CSCA?\r\n",(u8 *)"OK",200)) return SIM_CSCA_ERR;
	if(sim900a_send_cmd((u8 *)"AT+CSMP=17,167,0,24\r\n",(u8 *)"OK",100))	return SIM_CSMP_ERR;
	if(sim900a_send_cmd(cmd,(u8 *)">",200)) return SIM_CMGS_ERR;	
	sim900a_send_cmd(content,"",0);
	cmd[0]=0x1a;cmd[1]=0;
	if(sim900a_send_cmd(cmd,(u8 *)"+CMGS:",2000))	return SIM_CMGS_SEND_FAIL;
	return SIM_OK;
}


#include "common.h"
#include "wifiap.h"
#include "agreement.h"

//WIFI AP模式,模块对外的无线参数,可自行修改.
const u8* wifiap_ssid="ATK-ESP8266";			//对外SSID号
const u8* wifiap_encryption="wpawpa2_aes";	//wpa/wpa2 aes加密方式
const u8* wifiap_password="12345678"; 		//连接密码 

//连接端口号:8086,可自行修改为其他端口.
const u8* portnum="8086";

//UDP服务器IP地址
const u8* ipaddr="192.168.1.2";
const u8* apaddr="192.168.1.1";

//ESP8266 WIFI AP UDP
//用于测试TCP/UDP连接
//返回值:0,正常
//其他,错误代码
void ESP8266_WifiAP_Init(void)
{
	u8 *p;
	u8 *p1;
	u8 *p2;
	
	p  = mymalloc(SRAMIN,32);							//申请32字节内存
	p1 = mymalloc(SRAMIN,32);							//申请32字节内存
	p2 = mymalloc(SRAMIN,32);							//申请32字节内存
	
	while(atk_8266_send_cmd("AT","OK",20))//检查WIFI模块是否在线
	{
		atk_8266_quit_trans();//退出透传
		atk_8266_send_cmd("AT+CIPMODE=0","OK",200);  //关闭透传模式	
	}
	while(atk_8266_send_cmd("ATE0","OK",20));//关闭回显
	
	atk_8266_send_cmd("AT+CWMODE=2","OK",20);
	atk_8266_send_cmd("AT+RST","OK",20);
	delay_ms(1000);//延时2s等待模块重启
	delay_ms(1000);//
	delay_ms(1000);
	delay_ms(1000);
	sprintf((char*)p1,"AT+CWSAP=\"%s\",\"%s\",1,4",wifiap_ssid,wifiap_password);    //配置模块AP模式无线参数
	atk_8266_send_cmd(p1,"OK",1000);
	
	sprintf((char*)p2,"AT+CIPAP=\"%s\"",apaddr);
	atk_8266_send_cmd(p2,"OK",1000);
	
	//atk_8266_at_response(1);//检查ATK-ESP8266模块发送过来的数据,及时上传给电脑
	
	sprintf((char*)p,"AT+CIPSTART=\"UDP\",\"%s\",%s",ipaddr,(u8*)portnum);    //配置目标UDP服务器
	atk_8266_send_cmd("AT+CIPMUX=0","OK",100);  //单链接模式
	while(atk_8266_send_cmd(p,"OK",500));
	
	myfree(SRAMIN,p);		  //释放内存
	myfree(SRAMIN,p1);		//释放内存
	myfree(SRAMIN,p2);		//释放内存
} 

void send_wifi_msg(u8 *data,u8 datalen)
{
	u8 i;
	atk_8266_send_cmd("AT+CIPSEND=18","OK",200);  //发送指定长度的数据
	delay_ms(100);
	atk_8266_send_data(&data[i],"OK",100,datalen);  //发送指定长度的数据
}

void receive_wifi_msg(void)
{
	u8 rlen;
	
	if(USART3_RX_STA&0X8000)		//接收到一次数据了
	{ 
		rlen=USART3_RX_STA&0X7FFF;	//得到本次接收到的数据长度
		USART3_RX_BUF[rlen]=0;		//添加结束符 
		
		agreementParse(USART3_RX_BUF);
		
		USART3_RX_STA=0;
	}
}




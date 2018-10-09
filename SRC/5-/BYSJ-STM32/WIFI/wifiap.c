#include "common.h"
#include "wifiap.h"
#include "agreement.h"

//WIFI APģʽ,ģ���������߲���,�������޸�.
const u8* wifiap_ssid="ATK-ESP8266";			//����SSID��
const u8* wifiap_encryption="wpawpa2_aes";	//wpa/wpa2 aes���ܷ�ʽ
const u8* wifiap_password="12345678"; 		//�������� 

//���Ӷ˿ں�:8086,�������޸�Ϊ�����˿�.
const u8* portnum="8086";

//UDP������IP��ַ
const u8* ipaddr="192.168.1.2";
const u8* apaddr="192.168.1.1";

//ESP8266 WIFI AP UDP
//���ڲ���TCP/UDP����
//����ֵ:0,����
//����,�������
void ESP8266_WifiAP_Init(void)
{
	u8 *p;
	u8 *p1;
	u8 *p2;
	
	p  = mymalloc(SRAMIN,32);							//����32�ֽ��ڴ�
	p1 = mymalloc(SRAMIN,32);							//����32�ֽ��ڴ�
	p2 = mymalloc(SRAMIN,32);							//����32�ֽ��ڴ�
	
	while(atk_8266_send_cmd("AT","OK",20))//���WIFIģ���Ƿ�����
	{
		atk_8266_quit_trans();//�˳�͸��
		atk_8266_send_cmd("AT+CIPMODE=0","OK",200);  //�ر�͸��ģʽ	
	}
	while(atk_8266_send_cmd("ATE0","OK",20));//�رջ���
	
	atk_8266_send_cmd("AT+CWMODE=2","OK",20);
	atk_8266_send_cmd("AT+RST","OK",20);
	delay_ms(1000);//��ʱ2s�ȴ�ģ������
	delay_ms(1000);//
	delay_ms(1000);
	delay_ms(1000);
	sprintf((char*)p1,"AT+CWSAP=\"%s\",\"%s\",1,4",wifiap_ssid,wifiap_password);    //����ģ��APģʽ���߲���
	atk_8266_send_cmd(p1,"OK",1000);
	
	sprintf((char*)p2,"AT+CIPAP=\"%s\"",apaddr);
	atk_8266_send_cmd(p2,"OK",1000);
	
	//atk_8266_at_response(1);//���ATK-ESP8266ģ�鷢�͹���������,��ʱ�ϴ�������
	
	sprintf((char*)p,"AT+CIPSTART=\"UDP\",\"%s\",%s",ipaddr,(u8*)portnum);    //����Ŀ��UDP������
	atk_8266_send_cmd("AT+CIPMUX=0","OK",100);  //������ģʽ
	while(atk_8266_send_cmd(p,"OK",500));
	
	myfree(SRAMIN,p);		  //�ͷ��ڴ�
	myfree(SRAMIN,p1);		//�ͷ��ڴ�
	myfree(SRAMIN,p2);		//�ͷ��ڴ�
} 

void send_wifi_msg(u8 *data,u8 datalen)
{
	u8 i;
	atk_8266_send_cmd("AT+CIPSEND=18","OK",200);  //����ָ�����ȵ�����
	delay_ms(100);
	atk_8266_send_data(&data[i],"OK",100,datalen);  //����ָ�����ȵ�����
}

void receive_wifi_msg(void)
{
	u8 rlen;
	
	if(USART3_RX_STA&0X8000)		//���յ�һ��������
	{ 
		rlen=USART3_RX_STA&0X7FFF;	//�õ����ν��յ������ݳ���
		USART3_RX_BUF[rlen]=0;		//��ӽ����� 
		
		agreementParse(USART3_RX_BUF);
		
		USART3_RX_STA=0;
	}
}




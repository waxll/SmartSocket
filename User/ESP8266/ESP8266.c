#include "delay.h"
#include "oled.h"
#include "stm32f10x.h"
u8 at_cwmode[] = {0x41, 0x41, 0x54, 0x2B, 0x43, 0x57, 0x4D, 0x4F, 0x44, 0x45, 0x3D, 
                  0x33, 0x0D, 0x0A};//AT+CWMODE=3(回车)
u8 at_rst[] = {0x41, 0x54, 0x2B, 0x52, 0x53, 0x54, 0x0D, 0x0A};//AT+RST(回车)
u8 at_cwsap[] = {0x41, 0x54, 0x2B, 0x43, 0x57, 0x53, 0x41, 0x50, 0x3D, 0x22, 
		 0x45, 0x53, 0x50, 0x38, 0x32, 0x36, 0x36, 0x5F, 0x54, 0x45, 
		 0x53, 0x54, 0x22, 0x2C, 0x22, 0x31, 0x32, 0x33, 0x34, 0x35, 
		 0x36, 0x37, 0x38, 0x39, 0x30, 0x22, 0x2C, 0x31, 0x2C, 0x33, 
		 0x0D, 0x0A};//AT+CWSAP="ESP8266_TEST","1234567890",1,3(回车)
u8 at_cipmux[] = {0x41, 0x54, 0x2B, 0x43, 0x49, 0x50, 0x4D, 0x55, 0x58, 
		  0x3D, 0x31, 0x0D, 0x0A};//AT+CIPMUX=1(回车)
u8 at_sipserver[] = {0x41, 0x54, 0x2B, 0x43, 0x49, 0x50, 0x53, 0x45, 0x52, 0x56, 
		     0x45, 0x52, 0x3D, 0x31, 0x2C, 0x38, 0x30, 0x38, 0x30, 0x0D, 
		     0x0A};//AT+CIPSERVER=1,8080(回车)
u8 wifi[] = "WIFI";
u8 ip[] = "196.168.4.1:8080";
u8 SSID[] = "ESP8266_TEST";
u8 password[] = "1234567890";
u8 cmd[] = "1->ON,0->OFF";
u8 slh[] = "...";
void oled_1(void){
    OLED_P8x16Str(0*16,0,wifi);
    OLED_P16x16Ch(2*16,0,75);/*"初",0*/
	OLED_P16x16Ch(3*16,0,76);/*"始",1*/                   
	OLED_P16x16Ch(4*16,0,77);/*"化",2*/
    OLED_P16x16Ch(5*16,0,78);/*"中",4*/   
    OLED_P8x16Str(6*16,0,slh);
}
void oled_2(void){
    OLED_P8x16Str(0*16,2,wifi);
    OLED_P16x16Ch(2*16,2,75);                   
	OLED_P16x16Ch(3*16,2,76);                   
	OLED_P16x16Ch(4*16,2,77); 
    OLED_P16x16Ch(5*16,2,79);
    OLED_P16x16Ch(6*16,2,80);
    delay_ms(20000);
    OLED_CLS();
    OLED_P8x16Str(0,0,SSID);
    OLED_P8x16Str(0,2,password);
    OLED_P8x16Str(0,4,ip);
    OLED_P8x16Str(0,6,cmd);
}    
void ESP8266_Init(void){
	int i = 0;
    delay_ms(20000);
	for(i = 0; i < 13; i++){
		USART1->DR = at_cwmode[i];//送出AT+CWMODE=3(回车)
		while((USART1->SR & 0x40) == 0);//直到发送成功
	}
	delay_ms(20000);
	for(i = 0; i < 8; i++){
		USART1->DR = at_rst[i];//送出AT+RST(回车)
		while((USART1->SR & 0x40) == 0);//直到发送成功
	}
	delay_ms(20000);
	for(i = 0; i < 42; i++){
		USART1->DR = at_cwsap[i];//送出AT+CWSAP="ESP8266_TEST","1234567890",1,3(回车)
		while((USART1->SR & 0x40) == 0);//直到发送成功
	}
	delay_ms(20000);
	for(i = 0; i < 13; i++){
		USART1->DR = at_cipmux[i];//送出AT+CIPMUX=1(回车)
		while((USART1->SR & 0x40) == 0);//直到发送成功
	}
	delay_ms(20000);
	for(i = 0; i < 21; i++){
		USART1->DR = at_sipserver[i];//送出AT+CIPSERVER=1,8080(回车)
		while((USART1->SR & 0x40) == 0);//直到发送成功
	}
}

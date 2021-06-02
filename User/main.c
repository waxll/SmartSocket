#include "stm32f10x.h"
#include "./led/bsp_led.h" 
#include "./usart/bsp_usart.h" 
#include "oled.h"
#include "ESP8266.h"

#define JTAG_SWD_DISABLE   0X02
#define SWD_ENABLE         0X01

void JTAG_Set(u8 mode)
{
	u32 temp;
	temp=mode;
	temp<<=25;
	RCC->APB2ENR|=1<<0;     //开启辅助时钟	   
	AFIO->MAPR&=0XF8FFFFFF; //清除MAPR的[26:24]
	AFIO->MAPR|=temp;       //设置jtag模式
} 
u8 ch='0';
int main(void)
{	
	delay_init();
    LED_GPIO_Config();
	JTAG_Set(JTAG_SWD_DISABLE);   
	JTAG_Set(SWD_ENABLE);    
    USART_Config();
    IIC_Init();
	OLED_Init();
    oled_1();
    ESP8266_Init();
    oled_2();
    while(1){
        ch=getchar();
        if(ch=='0'){
            KEY_OFF
        }
        else if(ch=='1'){
            KEY_ON
        }
    }
}

//*******************************
//STM32F407工程模板
//File: main.c
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/05/30
//*******************************

#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	LED_Init();
	delay_init(84);

	while(1)
	{
		//LEDa亮500ms,灭500ms
		LEDa_ON;
		delay_ms(500);
		LEDa_OFF;
		delay_ms(500);

		//LEDb每隔1000ms翻转一次
		LEDb_Toggle;
	}
}




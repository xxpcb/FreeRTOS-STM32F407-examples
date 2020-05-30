//*******************************
//STM32F407 延时函数配置
//File: delay.h
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/05/30
//*******************************

#ifndef __DELAY_H
#define __DELAY_H 			   
#include <sys.h>	  

void delay_init(u8 SYSCLK);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#endif






























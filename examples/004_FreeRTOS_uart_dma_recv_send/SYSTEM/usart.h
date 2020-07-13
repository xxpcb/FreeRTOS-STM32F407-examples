//*******************************
//STM32F407 板载串口1配置
//File: usart.h
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/05/30
//*******************************

#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

#define Uart_Tx_DMAStream DMA2_Stream7
#define Uart_Rx_DMAStream DMA2_Stream5
	
#define BUF_SIZE  			200  	//定义最大接收字节数 200
extern u8  USART_RX_BUF[BUF_SIZE]; //接收缓冲
extern u8 ReceiveBuff[BUF_SIZE];
extern u16 USART_RX_STA;         		//接收状态标记	

void uart_init(u32 bound);
void MYDMA_Enable(DMA_Stream_TypeDef *DMA_Streamx,u16 ndtr);
void uart_DMA_send(u8 *str,u16 ndtr);
#endif

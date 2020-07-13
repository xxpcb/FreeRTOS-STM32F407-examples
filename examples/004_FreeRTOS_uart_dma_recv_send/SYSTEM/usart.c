//******************************************************
//STM32F407 板载串口1配置
//File: usart.c
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/05/30
//Modify: 2020/07/13 串口数据DMA方式发送与接收
//******************************************************

#include "sys.h"
#include "usart.h"	 
#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

extern SemaphoreHandle_t uartDMATCSemaphore;//DMA发送完成二值信号量句柄
extern SemaphoreHandle_t uartRxIDLESemaphore;

#define BUF_SIZE 200
extern u8 SendBuff[BUF_SIZE];	//发送数据缓冲区
extern u8 ReceiveBuff[BUF_SIZE];
extern u8 rxbuf[200];
extern u8 rx_cnt;//接收数据个数计数变量

//====================================================
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	
//====================================================
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
	USART1->DR = (u8) ch;      
	return ch;
}
#endif


u16 USART_RX_STA=0;       //接收状态标记	

//=======================================
//串口DMA发送配置
//=======================================
void dma_uart_tx_init()
{
	DMA_InitTypeDef  DMA_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);//DMA2时钟使能 
	
	DMA_DeInit(Uart_Tx_DMAStream);//使用----->DMA2_Stream7
	while (DMA_GetCmdStatus(Uart_Tx_DMAStream) != DISABLE){}//等待DMA可配置 

	/* 配置 DMA Stream */
	DMA_InitStructure.DMA_Channel            = DMA_Channel_4;              //通道选择
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&USART1->DR;           //目的：DMA外设地址
	DMA_InitStructure.DMA_Memory0BaseAddr    = (u32)SendBuff;              //源：DMA存储器0地址
	DMA_InitStructure.DMA_DIR                = DMA_DIR_MemoryToPeripheral; //方向：存储器到外设模式
	//DMA_InitStructure.DMA_BufferSize       = BUF_SIZE;                   //长度：数据传输量(先不配置)
	DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;  //外设非增量模式
	DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;       //存储器增量模式
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//外设数据长度:8位
	DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;    //存储器数据长度:8位
	DMA_InitStructure.DMA_Mode               = DMA_Mode_Normal;            //使用普通模式 
	DMA_InitStructure.DMA_Priority           = DMA_Priority_Medium;        //DMA优先级：中等优先级
	DMA_InitStructure.DMA_FIFOMode           = DMA_FIFOMode_Disable;       //FIFO模式 
	DMA_InitStructure.DMA_FIFOThreshold      = DMA_FIFOThreshold_Full;     //FIFO大小
	DMA_InitStructure.DMA_MemoryBurst        = DMA_MemoryBurst_Single;     //存储器单次传输
	DMA_InitStructure.DMA_PeripheralBurst    = DMA_PeripheralBurst_Single; //外设单次传输
	DMA_Init(Uart_Tx_DMAStream, &DMA_InitStructure);//初始化DMA Stream
	
	//中断配置
	DMA_ITConfig(Uart_Tx_DMAStream,DMA_IT_TC,ENABLE);  //配置DMA发送完成后产生中断
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream7_IRQn;//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=7;//抢占优先级8
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);  //使能串口1的DMA发送
	DMA_Cmd (Uart_Tx_DMAStream,DISABLE);//先不要使能DMA！           
}

//=======================================
//串口DMA接收配置
//=======================================
void dma_uart_rx_init()
{
	DMA_InitTypeDef  DMA_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);//DMA2时钟使能 
	
	DMA_DeInit(Uart_Rx_DMAStream);//使用----->DMA2_Stream5
	while (DMA_GetCmdStatus(Uart_Rx_DMAStream) != DISABLE){}//等待DMA可配置 

	/* 配置 DMA Stream */
	DMA_InitStructure.DMA_Channel            = DMA_Channel_4;              //通道选择
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&USART1->DR;           //源：DMA外设地址
	DMA_InitStructure.DMA_Memory0BaseAddr    = (u32)ReceiveBuff;           //目的：DMA存储器0地址
	DMA_InitStructure.DMA_DIR                = DMA_DIR_PeripheralToMemory; //方向：外设到存储器模式
	DMA_InitStructure.DMA_BufferSize         = BUF_SIZE;                   //长度：数据传输量
	DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;  //外设非增量模式
	DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;       //存储器增量模式
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//外设数据长度:8位
	DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;    //存储器数据长度:8位
	DMA_InitStructure.DMA_Mode               = DMA_Mode_Normal;            //使用普通模式 
	DMA_InitStructure.DMA_Priority           = DMA_Priority_Medium;        //DMA优先级：中等优先级
	DMA_InitStructure.DMA_FIFOMode           = DMA_FIFOMode_Disable;       //FIFO模式 
	DMA_InitStructure.DMA_FIFOThreshold      = DMA_FIFOThreshold_Full;     //FIFO大小
	DMA_InitStructure.DMA_MemoryBurst        = DMA_MemoryBurst_Single;     //存储器单次传输
	DMA_InitStructure.DMA_PeripheralBurst    = DMA_PeripheralBurst_Single; //外设单次传输
	DMA_Init(Uart_Rx_DMAStream, &DMA_InitStructure);//初始化DMA Stream
	
	USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);  //使能串口1的DMA接收
	DMA_Cmd (Uart_Rx_DMAStream,ENABLE);//使能          
}

//=======================================
//串口配置
//=======================================
void uart_init(u32 bound)
{
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//使能USART1时钟

	//串口1对应引脚复用映射
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9复用为USART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10复用为USART1

	//USART1端口配置
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9与GPIOA10
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;             //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	      //速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;            //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;             //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); //初始化PA9，PA10

	//USART1 初始化设置
	USART_InitStructure.USART_BaudRate            = bound;                         //波特率设置
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b;           //字长为8位数据格式
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;              //一个停止位
	USART_InitStructure.USART_Parity              = USART_Parity_No;               //无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx; //收发模式
	USART_Init(USART1, &USART_InitStructure); //初始化串口1

    //DMA Config
    dma_uart_tx_init();//串口DMA发送配置
	dma_uart_rx_init();//串口DMA接收配置
	
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);//开启串口空闲中断
	//Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;       //串口1中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=6; //抢占优先级8
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
	USART_Cmd(USART1, ENABLE);  //使能串口1 
}

//=======================================
//串口DMA发送函数
//======================================= 
void uart_DMA_send(u8 *str,u16 ndtr)
{
	u8 i;
	u8 *p=str;
	
	while(xSemaphoreTake(uartDMATCSemaphore,2)!=pdTRUE);//获取信号量，等待DMA发送可用
	
	DMA_Cmd(Uart_Tx_DMAStream, DISABLE);                      //关闭DMA传输 
	while (DMA_GetCmdStatus(Uart_Tx_DMAStream) != DISABLE){}	//确保DMA可以被设置  
	DMA_SetCurrDataCounter(Uart_Tx_DMAStream,ndtr);          //数据传输量 
	for(i=0;i<ndtr;i++)
	{
		SendBuff[i]=*p++;
	}
	DMA_Cmd(Uart_Tx_DMAStream, ENABLE);                      //开启DMA传输 
}

//=======================================
//串口1空闲中断服务程序，用于DMA接收
//=======================================
void USART1_IRQHandler(void)                	
{
	uint8_t data;//接收数据暂存变量
	BaseType_t xHigherPriorityTaskWoken;
	
	if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)//空闲中断
	{
		data = USART1->SR;
		data = USART1->DR;
		
		DMA_Cmd(Uart_Rx_DMAStream,DISABLE);//关闭DMA接收
		while (DMA_GetCmdStatus(Uart_Rx_DMAStream) != DISABLE){}	//确保DMA可以被设置 
		rx_cnt = BUF_SIZE - DMA_GetCurrDataCounter(Uart_Rx_DMAStream);//得到真正接收数据个数  
		DMA_SetCurrDataCounter(Uart_Rx_DMAStream,BUF_SIZE);//重新设置接收数据个数    
	    //printf("rx_cnt:%d\r\n",rx_cnt);
		memcpy(rxbuf,ReceiveBuff,rx_cnt);//先复制出来，防止下次的数据来了之后将其覆盖
	    DMA_ClearFlag(Uart_Rx_DMAStream,DMA_FLAG_TCIF5 | DMA_FLAG_FEIF5 | DMA_FLAG_DMEIF5 | DMA_FLAG_TEIF5 | DMA_FLAG_HTIF5);//这里的各种标志还没搞懂
		DMA_Cmd(Uart_Rx_DMAStream,ENABLE); //开启DMA接收
			
		if(uartRxIDLESemaphore!=NULL)
		{
			//printf("nnnnnnn\r\n");
			//释放二值信号量
			xSemaphoreGiveFromISR(uartRxIDLESemaphore,&xHigherPriorityTaskWoken);//释放串口空闲中断二值信号量
		}
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);//如果需要的话进行一次任务切换
	}
} 

//=======================================
//DMA发送完成中断服务程序
//=======================================
void DMA2_Stream7_IRQHandler(void)
{
	BaseType_t xHigherPriorityTaskWoken;
	//printf("ooooooo\r\n");
    if(DMA_GetITStatus(Uart_Tx_DMAStream,DMA_IT_TCIF7)!= RESET) //检查DMA传输完成中断 DMA_IT_TCIF7
    {
        DMA_ClearITPendingBit(Uart_Tx_DMAStream,DMA_IT_TCIF7); 
		//printf("dma tx ok\r\n");
		if(uartDMATCSemaphore!=NULL)
		{
			//释放二值信号量
			xSemaphoreGiveFromISR(uartDMATCSemaphore,&xHigherPriorityTaskWoken);	//释放DMA传输完成二值信号量
		}
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);//如果需要的话进行一次任务切换
    }
}
 




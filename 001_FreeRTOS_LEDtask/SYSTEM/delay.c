//*******************************
//STM32F407 延时函数配置
//File: delay.c
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/05/30
//*******************************

#include "delay.h"
#include "sys.h"
 
static u8  fac_us=0;//us延时倍乘数			   
static u16 fac_ms=0;//ms延时倍乘数,在ucos下,代表每个节拍的ms数

//=========================================
//初始化延迟函数
//SYSTICK的时钟固定为HCLK时钟的1/8
//SYSCLK:系统时钟
//=========================================
void delay_init(u8 SYSCLK)
{
 	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SYSCLK/8;		
	fac_ms=(u16)fac_us*1000;//代表每个ms需要的systick时钟数   
}								    

//=========================================
//延时nus
//nus为要延时的us数.	
//注意:nus的值,不要大于798915us
//=========================================
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; //时间加载	  		 
	SysTick->VAL=0x00;        //清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;//开始倒数 
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;//关闭计数器
	SysTick->VAL =0X00;       //清空计数器	 
}

//=========================================
//延时nms
//注意nms的范围
//SysTick->LOAD为24位寄存器,所以,最大延时为:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLK单位为Hz,nms单位为ms
//对168M条件下,nms<=798ms 
//=========================================
void delay_xms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//时间加载(SysTick->LOAD为24bit)
	SysTick->VAL =0x00;           //清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; //开始倒数  
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;//关闭计数器
	SysTick->VAL =0X00;       //清空计数器	  	    
} 

//=========================================
//延时nms 
//nms:0~65535
//=========================================
void delay_ms(u16 nms)
{	 	 
	u8 repeat=nms/540;	//这里用540,是考虑到某些客户可能超频使用,
						//比如超频到248M的时候,delay_xms最大只能延时541ms左右了
	u16 remain=nms%540;
	while(repeat)
	{
		delay_xms(540);
		repeat--;
	}
	if(remain)delay_xms(remain);
	
} 

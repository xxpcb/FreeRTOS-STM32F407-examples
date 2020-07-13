//********************************************
//STM32F407+FreeRTOS 串口数据DMA方式发送与接收
//File: main.c
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/07/13
//********************************************

#include "stm32f4xx.h"
#include "led.h"
#include "key.h"
#include "usart.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"



//任务参数--------------------------
//优先级 堆栈大小 任务句柄 任务函数
#define START_TASK_PRIO		1
#define START_STK_SIZE 		128  
TaskHandle_t StartTask_Handler;
void start_task(void *pvParameters);

#define TASK1_TASK_PRIO		3
#define TASK1_STK_SIZE 		128  
TaskHandle_t Task1Task_Handler;
void task1_task(void *pvParameters);

#define TASK2_TASK_PRIO		4	
#define TASK2_STK_SIZE 		128  
TaskHandle_t Task2Task_Handler;
void task2_task(void *pvParameters);

#define print_task_PRIO		5	
#define PRINT_STK_SIZE 		1024  
TaskHandle_t PrintTask_Handler;
void print_task(void *pvParameters);

SemaphoreHandle_t uartDMATCSemaphore;//DMA发送完成二值信号量句柄
SemaphoreHandle_t uartRxIDLESemaphore;//串口空闲中断二值信号量句柄

u8 SendBuff[BUF_SIZE];	//DMA发送数据缓冲区
u8 ReceiveBuff[BUF_SIZE];//DMA接收数据缓冲区
u8 rxbuf[200];
u8 rx_cnt=0;//接收数据个数计数变量

int main(void)
{ 	
	//设置系统中断优先级分组4(FreeRTOS中的默认方式！)
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	//初始化LED端口
	LED_Init();	

	//串口初始化
	uart_init(115200);
	
	printf("hello\r\n");

	//创建开始任务
	xTaskCreate((TaskFunction_t )start_task,            //任务函数
				(const char*    )"start_task",          //任务名称
				(uint16_t       )START_STK_SIZE,        //任务堆栈大小
				(void*          )NULL,                  //传递给任务函数的参数
				(UBaseType_t    )START_TASK_PRIO,       //任务优先级
				(TaskHandle_t*  )&StartTask_Handler);   //任务句柄  
	//开启任务调度				
	vTaskStartScheduler();          
}

//开始任务任务函数
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //进入临界区
	
    //创建TASK1任务
    xTaskCreate((TaskFunction_t )task1_task,             
                (const char*    )"task1_task",           
                (uint16_t       )TASK1_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )TASK1_TASK_PRIO,        
                (TaskHandle_t*  )&Task1Task_Handler);   
    //创建TASK2任务
    xTaskCreate((TaskFunction_t )task2_task,     
                (const char*    )"task2_task",   
                (uint16_t       )TASK2_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )TASK2_TASK_PRIO,
                (TaskHandle_t*  )&Task2Task_Handler); 
    //创建KEY任务
    xTaskCreate((TaskFunction_t )print_task,     
                (const char*    )"print_task",   
                (uint16_t       )PRINT_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )print_task_PRIO,
                (TaskHandle_t*  )&PrintTask_Handler); 
				
    vTaskDelete(StartTask_Handler); //删除开始任务
				
    taskEXIT_CRITICAL();            //退出临界区
}

//task1任务函数
void task1_task(void *pvParameters)
{
	while(1)
	{
		LEDa_Toggle;
        vTaskDelay(500); //延时500ms
	}
}

//task2任务函数
void task2_task(void *pvParameters)
{
	while(1)
	{
        LEDb_ON;
        vTaskDelay(200); //延时200ms
		LEDb_OFF;
        vTaskDelay(800); //延时800ms
	}
}

//打印任务函数(测试任务)
void print_task(void *pvParameters)
{
	//创建二值信号量
	uartDMATCSemaphore = xSemaphoreCreateBinary();
	uartRxIDLESemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(uartDMATCSemaphore);
	
	u8 str1[]="ma nong ai xue xi\r\n";
	uart_DMA_send(str1,sizeof(str1));
	
	u8 str2[]="xxpcb.github.io\r\n";
	uart_DMA_send(str2,sizeof(str2));
	
	BaseType_t err = pdFALSE;
	while(1)
	{
		err=xSemaphoreTake(uartRxIDLESemaphore,5);	//获取信号量
		if(err==pdTRUE)							//获取信号量成功
		{  
			uart_DMA_send("receive:",sizeof("receive:"));
			uart_DMA_send(rxbuf,rx_cnt);
			uart_DMA_send("\r\n",sizeof("\r\n"));
			
			rx_cnt=0;
		}
	}
}

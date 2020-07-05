//***************************************************************
//STM32F407+FreeRTOS 串口数据中断接收不定长数据与二值信号量的使用
//File: main.c
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/07/05
//***************************************************************

#include "stm32f4xx.h"
#include "led.h"
#include "key.h"
#include "usart.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define print_task_PRIO		2	
#define PRINT_STK_SIZE 		1024  
TaskHandle_t PrintTask_Handler;
void print_task(void *pvParameters);

#define N 2
typedef struct struct_dostr
{
char name[32];
int (*fun)(char *argv[]);
}struct_dostr;

int hello(char* p[]);
int led(char* p[]);
	
struct_dostr struct_dostr1[N]={
{"hello",hello},
{"led",  led},	
};

int hello(char* p[])
{
	printf("hello~~~~~~~~~~\r\n");
	return 0;
}

int led(char* p[])
{
	int p0,p1;
	p0=atoi(p[0]);
	p1=atoi(p[1]);
	
	printf("get led: %d, %d\r\n",p0,p1);
	return 0;
}

SemaphoreHandle_t uartSemaphore;//串口接收二值信号量句柄
uint8_t Recv[128];//串口接收缓存
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
	
	//创建二值信号量
	uartSemaphore = xSemaphoreCreateBinary();
	
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

//打印任务函数
void print_task(void *pvParameters)
{
	int count=0;
	BaseType_t err = pdFALSE;
	
	int size=50;
	uint8_t buf[64];//最多只取前64个数据

	//清空本地接收数组
	memset(buf,0,size);
	
	while(1)
	{
		err=xSemaphoreTake(uartSemaphore,10);	//获取信号量
		if(err==pdTRUE)							//获取信号量成功
		{  
			//printf("%s",Data);
			if(rx_cnt < size)//收到的数据长度在size范围内
			{
				//void *memcpy(void *str1, const void *str2, size_t n)  
				//从存储区 str2 复制 n 个字节到存储区 str1。
				memcpy(buf,Recv,rx_cnt);//有几个复制几个
				count=rx_cnt;
				//printf("%s\r\n", buf);
			}
			else//收到的数据长度太长了
			{
				memcpy(buf,Recv,size);//只复制size个
				count=size;
			}
			rx_cnt=0;
		}
		
		if(count>0)
		{
			count=0;
			printf("receive:%s",buf);
			
			//------------------------------------------------------------------------------
			//这里可以继续对buf进行分析和处理，比如根据buf的不同内容执行不同的小任务
			
			//先判断指令名称
			char *cmd;//表示命令
			char *paras;//表示命令后的参数
			cmd = strtok_r((char*)buf, " ", &paras);//这里有点小问题，不带参数的命令，后面需要一个空格
			
			char *ret;
			int i;
			for (i = 0; i < N;i++)
			{
				ret = strstr(struct_dostr1[i].name, cmd);
				if(ret!=NULL)
				{
//					printf("find cmd in funname[%d]\r\n", i);
					break;
				}
			}
//			printf("i:%d\r\n",i);
//			printf("cmd:%s]\r\n", cmd);
//			printf("paras:%s\r\n", paras);
			if(i==N)
			{
				printf("can't find cmd in funname[]\r\n");
			}
			else
			{				
				//是有效的指令，继续判断后续参数
				char* para[4]={0};//限定最多接收4个参数
				para[0] = strtok(paras, " ");
				int j= 1;
				while(paras != NULL)//这里有点小问题，不可以提前结束
				{
					para[j++] = strtok(NULL, " ");
					if(j==4)
						break;
				}
//				printf("paras nums:%d\r\n",j);
//				printf("para[0]:%s\r\n", para[0]);
//				printf("para[1]:%s\r\n", para[1]);
//				printf("para[2]:%s\r\n", para[2]);
//				printf("para[3]:%s\r\n", para[3]);
				
				//执行对应的函数
				struct_dostr1[i].fun(para);
			}

		}
	}
}

//*******************************************
//STM32F407+FreeRTOS 任务挂起与恢复(结合中断)
//File: main.c
//Author: xxpcb(wxgzh:码农爱学习)
//Version: V1.0
//Date: 2020/06/04
//*******************************************

#include "stm32f4xx.h"
#include "led.h"
#include "key.h"
#include "usart.h"

#include "FreeRTOS.h"
#include "task.h"

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

#define KEY_TASK_PRIO		2	
#define KEY_STK_SIZE 		128  
TaskHandle_t KeyTask_Handler;
void key_task(void *pvParameters);

void EXTIX_Init(void);

int main(void)
{ 	
	//设置系统中断优先级分组4(FreeRTOS中的默认方式！)
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	//初始化LED端口
	LED_Init();	
	//初始化按键
    KEY_Init();	
	//初始化外部中断
	EXTIX_Init();
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
    xTaskCreate((TaskFunction_t )key_task,     
                (const char*    )"key_task",   
                (uint16_t       )KEY_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )KEY_TASK_PRIO,
                (TaskHandle_t*  )&KeyTask_Handler); 
				
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

//key任务函数
void key_task(void *pvParameters)
{
	u8 key;
	static uint8_t flag=0;
	
	while(1)
	{
		key=KEY_Scan(0);
		switch(key)
		{
			case KEY1_PRES:
				if(!flag)
				{
					vTaskSuspend(Task1Task_Handler);//挂起任务1
					printf("1 suspend\r\n");
				}
				else
				{
					vTaskResume(Task1Task_Handler);	//恢复任务1
					printf("1 resume\r\n");
				}
				flag=~flag;
				break;
			case K_UP_PRES:
				vTaskSuspend(Task2Task_Handler);//挂起任务2
				printf("2 suspend\r\n");
				break;
		}
		vTaskDelay(10);			//延时10ms 
	}
}

//==============中断相关配置
void EXTIX_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	
	//KEY_Init(); //按键对应的IO口初始化
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//使能SYSCFG时钟
 
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);//PE4 连接到中断线4
	
	/* 配置EXTI_Line4 */
	EXTI_InitStructure.EXTI_Line =  EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//中断事件
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				//中断线使能
	EXTI_Init(&EXTI_InitStructure);							//配置
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;		//外部中断4
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x06;//抢占优先级6
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;	//子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);							//配置	   
}

//外部中断4服务程序
void EXTI4_IRQHandler(void)
{
	BaseType_t YieldRequired;
	
	//vTaskDelay(10);	//消抖-------//中断函数中不可以使用vTaskDelay()！！！
	if(KEY0==0)	 
	{			
        //vTaskResume(Task2Task_Handler);//这里必须使用FromISR版本的！！！	
		YieldRequired=xTaskResumeFromISR(Task2Task_Handler);//恢复任务2
		printf("2 resume\r\n");
		if(YieldRequired==pdTRUE)
		{
			/*如果函数xTaskResumeFromISR()返回值为pdTRUE，那么说明要恢复的这个
			任务的任务优先级等于或者高于正在运行的任务(被中断打断的任务),所以在
			退出中断的时候一定要进行上下文切换！*/
			portYIELD_FROM_ISR(YieldRequired);
		}
	}		 
	EXTI_ClearITPendingBit(EXTI_Line4);//清除LINE4上的中断标志位  
}

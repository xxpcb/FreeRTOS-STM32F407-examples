# 项目结构

## 库与工程模板

- **Template_lib** : STM32F407的库文件(v1.4.0)+FreeRTOS库文件(v9.0.0)
- **Template_noOS** : 基于Keil5.15的STM32F407模板工程(不包含操作系统)
- **Template_TreeRTOS** : 基于Keil5.15的STM32F407+FreeRTOS的模板工程

## 测试例程

- **001_FreeRTOS_LEDtask ** : 任务创建实验，创建两个LED闪烁任务(**独立的工程**)
- **examples** : 所有的例程，为减少存储空间，此文件的所有例程**共用相同的库文件**
  - **commonlib** : 共用的库文件
  - **001_FreeRTOS_LEDtask ** : 任务创建实验，创建两个LED闪烁任务

# FreeRTOS文件结构

![](https://img-blog.csdnimg.cn/20200531100035123.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2hic3lhYWE=,size_16,color_FFFFFF,t_70)






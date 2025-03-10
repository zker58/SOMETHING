#include "stm32f10x.h"                  // Device header
#include "TIMER.h"
#include "dingshi.h"

 
//Timer_Init函数的作用是配置定时器，当开始按键按下时，定时器打开，计时开始。
 
//1.利用库函数，配置定时器
void Timer_Init(void)
{
    //step.1开启时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
    //step.2选择时基单元的时钟
	TIM_InternalClockConfig(TIM2);
	
    //step.3配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
            //计数模式
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
 
            //根据公式“定时频率=72M/(PSC+1)/(ARR+1)”，改变这两个值可实现不同时间的计时
	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;//定时器2定时时间为1s
 
 
 
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
            //使能中断
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
 
 
//2.利用库函数，配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
//3.启动定时器
	TIM_Cmd(TIM2, ENABLE);
}
 
 
 
 
 
//Timer_Stop函数的作用是关闭时钟，当暂停按键按下时，定时器关闭，计时停止。
void Timer_Stop(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 10000- 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, DISABLE);
}
void Z_TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
    z_miao++;
	}
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
void D_TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
    z_miao--;
	}
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}

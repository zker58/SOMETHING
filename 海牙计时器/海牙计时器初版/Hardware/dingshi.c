#include "stm32f10x.h"                  // Device header
#include "TIMER.h"
#include "dingshi.h"

 
//Timer_Init���������������ö�ʱ��������ʼ��������ʱ����ʱ���򿪣���ʱ��ʼ��
 
//1.���ÿ⺯�������ö�ʱ��
void Timer_Init(void)
{
    //step.1����ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
    //step.2ѡ��ʱ����Ԫ��ʱ��
	TIM_InternalClockConfig(TIM2);
	
    //step.3����ʱ����Ԫ
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
            //����ģʽ
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
 
            //���ݹ�ʽ����ʱƵ��=72M/(PSC+1)/(ARR+1)�����ı�������ֵ��ʵ�ֲ�ͬʱ��ļ�ʱ
	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;//��ʱ��2��ʱʱ��Ϊ1s
 
 
 
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
            //ʹ���ж�
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
 
 
//2.���ÿ⺯��������NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
//3.������ʱ��
	TIM_Cmd(TIM2, ENABLE);
}
 
 
 
 
 
//Timer_Stop�����������ǹر�ʱ�ӣ�����ͣ��������ʱ����ʱ���رգ���ʱֹͣ��
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

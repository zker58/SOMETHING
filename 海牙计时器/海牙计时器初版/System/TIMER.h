#ifndef __TIMER_H
#define __TIMER_H
 

#include "stm32f10x_tim.h"
/**************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ����Ҫ�ĸ���ʱ����ʱ��ֻ��Ҫ������ĺ궨��ĳ�1����
#define GENERAL_TIM2    0
#define GENERAL_TIM3    0
#define GENERAL_TIM4    1
/*********************************************************************************
* @Function	: TIMEʵ��
**********************************************************************************/
typedef enum 
{
	TIM_2,
	TIM_3,
	TIM_4,
	TIME_NUM
}TimeModule;



extern u8 miao;
extern u8 shimiao;
extern u8 fen;
extern u8 shifen;
extern u8 mode;


/*********************************************************************************
* @Function	: �̶���Ƶ��
**********************************************************************************/
#define            GENERAL_TIM_Period            (1000-1)
#define            GENERAL_TIM_Prescaler         71 //ʱ��Ԥ��Ƶ��
 //��ʱƵ��1ms
/*********************************************************************************
* @Function	: TIM2-5 ��ʼ��
* @Input		: time,TIM��ʱ����TIM_2-TIM_5��
*						PreemptionPriority����ռ���ȼ�
*						SubPriority�������ȼ�
* @Output		:	None
* @Return		: None
* @Others		:	None
* @Date			: 2022-08-30
**********************************************************************************/
void GENERAL_TIM_Init(TimeModule time,u8 PreemptionPriority, u8 SubPriority);
 
#endif

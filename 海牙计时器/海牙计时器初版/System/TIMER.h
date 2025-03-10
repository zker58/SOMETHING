#ifndef __TIMER_H
#define __TIMER_H
 

#include "stm32f10x_tim.h"
/**************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当需要哪个定时器的时候，只需要把下面的宏定义改成1即可
#define GENERAL_TIM2    0
#define GENERAL_TIM3    0
#define GENERAL_TIM4    1
/*********************************************************************************
* @Function	: TIME实例
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
* @Function	: 固定分频率
**********************************************************************************/
#define            GENERAL_TIM_Period            (1000-1)
#define            GENERAL_TIM_Prescaler         71 //时钟预分频数
 //定时频率1ms
/*********************************************************************************
* @Function	: TIM2-5 初始化
* @Input		: time,TIM定时器（TIM_2-TIM_5）
*						PreemptionPriority，抢占优先级
*						SubPriority，子优先级
* @Output		:	None
* @Return		: None
* @Others		:	None
* @Date			: 2022-08-30
**********************************************************************************/
void GENERAL_TIM_Init(TimeModule time,u8 PreemptionPriority, u8 SubPriority);
 
#endif

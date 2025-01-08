#include "stm32f10x.h"                  // Device header
void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	
	GPIO_InitTypeDef GPIO_STRUCT0;
	GPIO_STRUCT0.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_STRUCT0.GPIO_Pin = GPIO_Pin_2;
	GPIO_STRUCT0.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_STRUCT0);
	
	GPIO_InitTypeDef GPIO_STRUCT1;
	GPIO_STRUCT1.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_STRUCT1.GPIO_Pin = GPIO_Pin_1;
	GPIO_STRUCT1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_STRUCT1);
	
	
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;				
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;		
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	
	TIM_TimeBaseInitStructure.TIM_Period = 100-1;				
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36-1;				
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;			
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);		
	
	
	TIM_OCInitTypeDef OC_STRUCT0;
	TIM_OCStructInit(&OC_STRUCT0);
	
	OC_STRUCT0.TIM_OCMode=TIM_OCMode_PWM1;
	OC_STRUCT0.TIM_OCPolarity=TIM_OCPolarity_High;
	OC_STRUCT0.TIM_OutputState=TIM_OutputState_Enable;
	OC_STRUCT0.TIM_Pulse=0 ;
    TIM_OC3Init(TIM2,&OC_STRUCT0);
	TIM_OC2Init(TIM2,&OC_STRUCT0);
	
	
	
	TIM_Cmd(TIM2, ENABLE);			

}
void pwm_SetCompare3(uint16_t compare)
{
	TIM_SetCompare3(TIM2,compare);
}

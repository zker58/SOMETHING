#include "stm32f10x.h"                  // Device header
void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	
	GPIO_InitTypeDef GPIO_STRUCT0;
	GPIO_STRUCT0.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_STRUCT0.GPIO_Pin = GPIO_Pin_0;
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
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720-1;				
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;			
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);		
	
	
	TIM_OCInitTypeDef OC_STRUCT0;
	TIM_OCStructInit(&OC_STRUCT0);
	
	OC_STRUCT0.TIM_OCMode=TIM_OCMode_PWM1;
	OC_STRUCT0.TIM_OCPolarity=TIM_OCPolarity_High;
	OC_STRUCT0.TIM_OutputState=TIM_OutputState_Enable;
	OC_STRUCT0.TIM_Pulse=0 ;
    TIM_OC1Init(TIM2,&OC_STRUCT0);//这里可以使用OC1 2来分别指向同一个结构体，这样也可实现对两个通道的控制
	
	TIM_OCInitTypeDef OC_STRUCT1;
	TIM_OCStructInit(&OC_STRUCT1);
	
	OC_STRUCT1.TIM_OCMode=TIM_OCMode_PWM2;
	OC_STRUCT1.TIM_OCPolarity=TIM_OCPolarity_High;
	OC_STRUCT1.TIM_OutputState=TIM_OutputState_Enable;
	OC_STRUCT1.TIM_Pulse=0 ;
	TIM_OC2Init(TIM2,&OC_STRUCT1);
	
	
	
	TIM_Cmd(TIM2, ENABLE);			

}
void pwm_SetComparel(uint16_t compare)
{
	TIM_SetCompare1(TIM2,compare);


}
void PWM_TIM_SetCompare2(uint16_t compare1)
{
     TIM_SetCompare2(TIM2,compare1);
}

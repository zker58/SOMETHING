#include "stm32f10x.h"                  // Device header
#include "Delay.h"
uint16_t COUNTSENSOR_COUT;



void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);// 初始化时钟引脚
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitTypeDef GPIO_STRUCT;
	GPIO_STRUCT.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_STRUCT.GPIO_Pin=GPIO_Pin_14;
	GPIO_STRUCT.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_STRUCT);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	EXTI_InitTypeDef  EXIT_STRUCT;
	EXIT_STRUCT.EXTI_Line=EXTI_Line14;
	EXIT_STRUCT.EXTI_LineCmd=ENABLE;
	EXIT_STRUCT.EXTI_Mode=EXTI_Mode_Interrupt;
	EXIT_STRUCT.EXTI_Trigger=EXTI_Trigger_Rising;
	
	EXTI_Init(&EXIT_STRUCT);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_STRUCT;
	NVIC_STRUCT.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_STRUCT.NVIC_IRQChannelCmd=ENABLE;
	NVIC_STRUCT.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_STRUCT.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_STRUCT);
	
}
uint16_t COUNTSENSOR_COUNT_GET(void)
{
	return COUNTSENSOR_COUT;
}
void EXTI15_10_IRQHandler(void)
{
	 if (EXTI_GetFlagStatus(EXTI_Line14) == SET)
	 {
		Delay_ms(500);
		 COUNTSENSOR_COUT ++;
		Delay_ms(500);
		 EXTI_ClearITPendingBit(EXTI_Line14);
	 }
	
}




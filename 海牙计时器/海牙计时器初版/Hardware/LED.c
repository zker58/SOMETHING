//这个库放led与蜂鸣器的驱动
#include "stm32f10x.h"                  // Device header
#include "Delay.h"




void LED_Buzzer_Init(void)
{

/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
															
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;					
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 |GPIO_Pin_10;				
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);					
	GPIO_SetBits(GPIOB,GPIO_Pin_9);
  GPIO_SetBits(GPIOB,GPIO_Pin_10);
}



void LED_ON_OFF(u8 c)
{
	for(int i=0;i<=c;i++)
	{
    GPIO_SetBits(GPIOA,GPIO_Pin_9);
		Delay_ms(100);
	  GPIO_ResetBits(GPIOA,GPIO_Pin_9);
		
  } 
}

void Buzzer_ON_OFF(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_10);
		Delay_ms(100);
	  GPIO_ResetBits(GPIOA,GPIO_Pin_10);
		Delay_ms(100);
		GPIO_SetBits(GPIOA,GPIO_Pin_10);
		Delay_ms(100);
		GPIO_ResetBits(GPIOA,GPIO_Pin_10);
}


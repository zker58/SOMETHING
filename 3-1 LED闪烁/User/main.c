#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
															
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;					
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);					
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	
	while(1)
	{														
	  GPIO_SetBits(GPIOB,GPIO_Pin_13);
		Delay_ms(100);
	   GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		Delay_ms(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		Delay_ms(100);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		Delay_ms(700);
	}
}

#include "stm32f10x.h"                  // Device header
#include "PWM.h"    
void Motor_Init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		

	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_8;//A8 B13对应一号电机
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure1);					
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		

	GPIO_InitTypeDef GPIO_InitStructure2;
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure2);	
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		

	GPIO_InitTypeDef GPIO_InitStructure3;
	GPIO_InitStructure3.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure3.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure3.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure3);	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		

	GPIO_InitTypeDef GPIO_InitStructure4;
	GPIO_InitStructure4.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure4.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure4.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure4);	
	
	
	PWM_TIM2Init();
}

void Motor_SetSpeed(int8_t Speed)
{
	if (Speed  >=  0  )
	{
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	 pwm_SetCompare3(Speed);
	
	}
	else
	{ 
	 GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	 GPIO_SetBits(GPIOA,GPIO_Pin_5);
	 pwm_SetCompare3(-Speed);
	}

}
void gottoward()//直走
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	 pwm_SetCompare2(50);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);
	 pwm_SetCompare3(50);
	
}
void turnlift()    //左转
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	 pwm_SetCompare2(30);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);
	 pwm_SetCompare3(50);

}
void turnright()//右转
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	 pwm_SetCompare2(50);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);
	 pwm_SetCompare3(30);
}
void stop(void)//停止
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);

	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);
	
}
void gotback()//倒退
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	 pwm_SetCompare2(50);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);
	 pwm_SetCompare3(50);
}




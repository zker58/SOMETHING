#include "stm32f10x.h"                  // Device header






void xunji_int(void)//循迹初始化
{	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	

	
GPIO_InitTypeDef GPIO_xunjistruct4;
	GPIO_xunjistruct4.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_xunjistruct4.GPIO_Pin=GPIO_Pin_4;
	GPIO_xunjistruct4.GPIO_Speed=GPIO_Speed_50MHz;
GPIO_InitTypeDef GPIO_xunjistruct5;
	GPIO_xunjistruct5.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_xunjistruct5.GPIO_Pin=GPIO_Pin_5;
	GPIO_xunjistruct5.GPIO_Speed=GPIO_Speed_50MHz;	
	
	GPIO_InitTypeDef GPIO_xunjistruct3;
	GPIO_xunjistruct3.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_xunjistruct3.GPIO_Pin=GPIO_Pin_3;
	GPIO_xunjistruct3.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_InitTypeDef GPIO_xunjistruct0;
	GPIO_xunjistruct0.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_xunjistruct0.GPIO_Pin=GPIO_Pin_0;
	GPIO_xunjistruct0.GPIO_Speed=GPIO_Speed_50MHz;
	
	
	GPIO_InitTypeDef GPIO_xunjistruct7;
	GPIO_xunjistruct7.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_xunjistruct7.GPIO_Pin=GPIO_Pin_7;
	GPIO_xunjistruct7.GPIO_Speed=GPIO_Speed_50MHz;
	
	
	
GPIO_Init(GPIOA,&GPIO_xunjistruct4);
GPIO_Init(GPIOA,&GPIO_xunjistruct5);
GPIO_Init(GPIOA,&GPIO_xunjistruct3);
GPIO_Init(GPIOA,&GPIO_xunjistruct0);
GPIO_Init(GPIOA,&GPIO_xunjistruct7);
}
uint8_t LightSensor_Get1(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
}

uint8_t LightSensor_Get2(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
}
uint8_t LightSensor_Get3(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3);
}

uint8_t LightSensor_Get4(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
}
uint8_t LightSensor_Get5(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
}

#include "stm32f10x.h"  // Device header
#include <stdio.h>
void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitTypeDef GPIO_STRUCT;
	GPIO_STRUCT.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_STRUCT.GPIO_Pin=GPIO_Pin_9;
	GPIO_STRUCT.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_STRUCT);
	
	USART_InitTypeDef USART_STRUCT;
	USART_STRUCT.USART_BaudRate=9600;
	USART_STRUCT.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_STRUCT.USART_Mode=USART_Mode_Tx;
	USART_STRUCT.USART_Parity=USART_Parity_No;
	USART_STRUCT.USART_StopBits=USART_StopBits_1;
	USART_STRUCT.USART_WordLength=USART_WordLength_8b;
	
	USART_Init(USART1,&USART_STRUCT);
	
	USART_Cmd(USART1,ENABLE);
	
}
void Serial_SendByte(uint8_t BYTE)
{
	USART_SendData(USART1,BYTE);
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE)== RESET);
}
void Serial_SendArray(uint8_t *Arrary,uint16_t Length)
{
	uint16_t i;
	for(i=0;i < Length; i++)
	{
	Serial_SendByte(Arrary[i]);
	
	}


}
void Serial_SendString(char *String)
{
	uint8_t i;
	for (i=0;String[i] !=0;i++)
	{
	Serial_SendByte(String[i]);
	}

}
uint32_t Serial_Pow(uint32_t X,uint32_t Y)//次方函数 
{
	uint32_t Result = 1;
	while (Y --)
	{
		Result *=X;
	
	}
	return Result;
}
void Serial_SendNumber(uint32_t Number,uint8_t Length)
{
	uint8_t i;
	for(i = 0;i<Length;i++)
	{
		Serial_SendByte(Number / Serial_Pow(10,Length-i-1)%10+'0');
	
	}

}
int fput(int ch, FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}






#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
int main(void)
{
	OLED_Init();
	
	Serial_Init();
	
	Serial_SendByte('A');
	uint8_t Myarrar[] ={0x42,0x43,0x44,0x45};
	Serial_SendArray(Myarrar,4);
	Serial_SendString("HelloWorld!");
	printf("123");
	while (1)
	{
		
	}
}

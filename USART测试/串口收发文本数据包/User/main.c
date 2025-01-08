#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "LED.h" 
#include <string.h>


uint8_t RxData;

int main(void)
{
	OLED_Init();
	OLED_Init();
	OLED_ShowString(3, 1, "RxPacket");
	OLED_ShowString(1,1,"TxPacket");
	
	Serial_Init();
	
	while (1)
	{
		if (Serial_RxFlag == 1)
		{
			OLED_ShowString(4,1,"				");
			OLED_ShowString(4,1,Serial_RxPacket);
			
			if (strcmp(Serial_RxPacket,"LED_ON") == 0)
			{
				LED1_ON();
				Serial_SendString("LEND_ON\r\n"); 
				OLED_ShowString(2,1,"				");
				OLED_ShowString(2,1,"LEND_ON_OK");
			}
			else if (strcmp(Serial_RxPacket,"LED_OFF") == 0)
			{	LED1_ON();
				Serial_SendString("LEND_OFF\r\n"); 
				OLED_ShowString(2,1,"				");
				OLED_ShowString(2,1,"LEND_OFF_OK");
			}
			else
			{
				Serial_SendString("ERRROR_COMAND\r\n"); 
				OLED_ShowString(2,1,"				");
				OLED_ShowString(2,1,"ERRROR_COMAND");
			}
		Serial_RxFlag = 0;
		}	
		
	}
}

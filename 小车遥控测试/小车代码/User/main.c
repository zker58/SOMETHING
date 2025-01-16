#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Motor.h"
#include "xunji.h"
#include "Serial.h"
#include "string.h"
uint8_t shuzi =0;

int main(void)
{
	OLED_Init();
	xunji_int();
	
	while (1)
	{
		
		if(LightSensor_Get1()==1)
		{
			
			shuzi++;
		}
		OLED_ShowNum(1,1,shuzi,5);
		if (Serial_RxFlag == 1)		
		{		
			
			if (strcmp(Serial_RxPacket, "Turnlift") == 0)			
			{
				 turnlift();								
				Serial_SendString("Turnlift\r\n");				
						
			}
			else if (strcmp(Serial_RxPacket, "turnright") == 0)	
			{
				turnright();										
				Serial_SendString("Turnright\r\n");			
							
			}
			else if (strcmp(Serial_RxPacket, "GOstright") == 0)	
			{
														
				Serial_SendString("GO!\r\n");			
			}
			else						
			{	gottoward();
				Serial_SendString("ERROR_COMMAND\r\n");			
						
			}
			
			Serial_RxFlag = 0;
			
			
			
			
	
			
		}
	}
}

	


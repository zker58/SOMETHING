#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Motor.h"
#include "xunji.h"
#include "Serial.h"
#include "string.h"

int main(void)
{
	while (1)
	{
		if (Serial_RxFlag == 1)		
		{		
			/*将收到的数据包与预设的指令对比，以此决定将要执行的操作*/
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
			
			Serial_RxFlag = 0;			//处理完成后，需要将接收数据包标志位清零，否则将无法接收后续数据包
		}
	}
}

	


#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Motor.h"




uint8_t KeyNum;
float ANGLE;
int main(void)
{
	
	OLED_Init();		
	Motor_Init();
	
	
	Motor_SetSpeed(20);
	
	while (1)
	{
	
	}
}

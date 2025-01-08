#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "TIMER.h"


//这个是我仿照写的能驱动两个灯的pwm，在做下一个舵机试验的时候让舵机出现了“赛博生命”现象，很搞笑啊

uint16_t i;
int main(void)
{
	
	OLED_Init();		
	PWM_Init();
			
	while (1)
	{
		 for (i = 0;i<=100;i++)
		{
			pwm_SetComparel(i);
			Delay_ms(15);
			 PWM_TIM_SetCompare2(i);
			
		}
		 for (i = 0;i<=100;i++)
		{
			pwm_SetComparel(100-i);
			Delay_ms(5);
			 PWM_TIM_SetCompare2(100-i);
		}
	}
}

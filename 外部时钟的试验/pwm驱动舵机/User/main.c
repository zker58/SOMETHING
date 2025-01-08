#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Sever.h"
#include "Key.h"


//这个是我仿照写的能驱动两个灯的pwm，在做下一个舵机试验的时候让舵机出现了“赛博生命”现象，很搞笑啊

uint8_t KeyNum;
float ANGLE;
int main(void)
{
	
	OLED_Init();		
	Sever_Init();
	Key_Init();		
	OLED_ShowString(1,1,"Angle:");
	
	while (1)
	{
	KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
		
		ANGLE += 30;
			if (ANGLE>180)
			{
			ANGLE =0;
			
			
			}
		}
		Servo_Angele(ANGLE);
		OLED_ShowNum(1,7,ANGLE,3);
     }
}

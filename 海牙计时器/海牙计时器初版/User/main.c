#include "stm32f10x.h" // Device header
#include "Key.h"
#include "TIMER.h"
#include "zhuangtaiji.h"
#include "dingshi.h"
#include "LED.h"
#include "Delay.h"

int main()
{

   Key_GPIO_Config();
	GENERAL_TIM_Init(TIM_4,0,3);
	LED_Buzzer_Init();
	
    while(1)
    {
			if(mode == 1)//待机模式下的驱动
			{
			x=0;
			y=0;
			}
			if(mode == 2)//正计时模式下驱动
			{
				if(z_miao == 10)
				{
					z_miao=0;
				z_shimiao++;
				}
				if(z_shimiao == 6)
				{
				z_shimiao =0;
				z_fen++;
				}
				
				
			 Z_TIM2_IRQHandler();//时间增加
				
				
				
			 if(z_miao == 9 && z_shimiao == 5 && z_fen ==9 )
			 {
				Timer_Stop();			 
			 }
			}
			
			if(mode == 3)//倒计时模式的驱动
			{
				if(z_fen != 0 && z_shimiao != 0 && z_miao == 0)
				{
				z_miao = 9;
				z_shimiao--;
				}
				
				if(z_fen != 0 && z_shimiao == 0 && z_miao == 0)
				{
				z_miao = 9;
				z_shimiao = 5;
				z_fen--;
				}
				
				if(z_fen == 0 && z_shimiao != 0 && z_miao == 0)
				{
				z_miao = 9;
				z_shimiao--;
				}
				if(z_fen == 0 && z_shimiao == 0 && z_miao == 0)//倒计时到0：00后进入暂停模式
				{
					Buzzer_ON_OFF();
					
					
				 Timer_Stop();
					x = 1;
					y = 0;
					z=1;
					mode = MODE4;
					
				}
				
				D_TIM2_IRQHandler();//时间减少
				
				
				
				
				
			 if(z_miao == 0 && z_shimiao == 0 && z_fen ==0 )
			 {
			  //蜂鸣器响
				mode=MODE2;//此时还需要按下一次S1按键才能开始正计时模式
			 }
			 
			 
			 
			 if(mode == 4)//倒计时模式的驱动
			 {
			 
			 }
			}
		}
}   

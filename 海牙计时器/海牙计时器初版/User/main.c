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
			if(mode == 1)//����ģʽ�µ�����
			{
			x=0;
			y=0;
			}
			if(mode == 2)//����ʱģʽ������
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
				
				
			 Z_TIM2_IRQHandler();//ʱ������
				
				
				
			 if(z_miao == 9 && z_shimiao == 5 && z_fen ==9 )
			 {
				Timer_Stop();			 
			 }
			}
			
			if(mode == 3)//����ʱģʽ������
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
				if(z_fen == 0 && z_shimiao == 0 && z_miao == 0)//����ʱ��0��00�������ͣģʽ
				{
					Buzzer_ON_OFF();
					
					
				 Timer_Stop();
					x = 1;
					y = 0;
					z=1;
					mode = MODE4;
					
				}
				
				D_TIM2_IRQHandler();//ʱ�����
				
				
				
				
				
			 if(z_miao == 0 && z_shimiao == 0 && z_fen ==0 )
			 {
			  //��������
				mode=MODE2;//��ʱ����Ҫ����һ��S1�������ܿ�ʼ����ʱģʽ
			 }
			 
			 
			 
			 if(mode == 4)//����ʱģʽ������
			 {
			 
			 }
			}
		}
}   

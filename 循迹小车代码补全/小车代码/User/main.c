#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Motor.h"
#include "xunji.h"


uint8_t lukou = 0;
uint8_t xzhou;
uint8_t yzhou = 100;
uint8_t cunchu1;
uint8_t cunchu2;
uint8_t lukou2 = 50;
int main(void)
{
	void xunji_int(void);
	Motor_Init();
	cunchu1=xzhou;
	cunchu2=yzhou;
	while (1)
	{//此处添加蓝牙任务一入口
	 if(LightSensor_Get3() == 1)
	 {
		if(LightSensor_Get1()==0)
		{
		void gottoward();
		}//直行
		if(LightSensor_Get1()==1)
		{
			Delay_ms(300);
			lukou++;
			if(lukou == xzhou)
			{
				void turnlift();
				lukou=0;
				xzhou= 100;
				Delay_s(1);//延时进行转弯。
				void gottoward();
				if(lukou == yzhou)
				{
				void stop(void);
			
				xzhou = 5-yzhou;
				yzhou = cunchu1;
				Delay_s(5);				
				}//结束任务一
			}
		} 
	 }
	 //添加蓝牙任务三入口
	 //if 判断路线1
	     
		 if(LightSensor_Get3() == 1)
		 {
		   if(LightSensor_Get1()==0)
		   {
		        void gottoward();
		   }
		   if(LightSensor_Get1()==1)
		   {
			    lukou++;
		   }
		     if(LightSensor_Get5()==1)
		   {
			    lukou2++;
		   }
			if(lukou == 3)
			{
			
			void turnlift();
			Delay_s(1);				
			void gottoward();
			}				
			if(lukou == 5)
			 {
			void turnlift();
			Delay_s(1);
			void gottoward();		
			 }
			if(lukou == 7)
			{
			
			void turnright();
			Delay_s(1);
			void gottoward();
			}
			if(lukou == 11)
			{
			
			void turnright();
			Delay_s(1);
			void gottoward();
			lukou2 = 0;
			}
			if(lukou2 == 1)
			{
			void turnright();
			Delay_s(1);
			void gottoward();
			lukou2 = 50;
			}
			if(lukou == 14)
			{
			
			void turnright();
			Delay_s(1);
			void gottoward();
				
		    }
			if(lukou == 15)
			 {
			void turnlift();
			Delay_s(1);
			void gottoward();
			lukou2=2;
			 }
			 if(lukou == 17)
			 {
			void turnright();
			Delay_s(1);
			void gottoward();
			lukou2=2;
			 }
			 if(lukou2 == 3)
			{
			void turnright();
			Delay_s(1);
			void gottoward();
				lukou2=50;
			}
			 if(lukou == 20)
			 {
			void turnlift();
			Delay_s(1);
			void gottoward();
			 }
			 if(lukou == 21)
			 {
			void turnright();
			Delay_s(1);
			void gottoward();
			lukou2 = 4;	 
			 }
			if(lukou2 == 5)
			{
			void turnright();
			Delay_s(1);
			void gottoward();
			lukou2 =50;
			}
			if(lukou == 23)
			 {
			void turnlift();
			Delay_s(1);
			void gottoward();
			 }
			 if(lukou == 25)
			 {
			void turnlift();
			Delay_s(1);
			void gottoward();
			 
           } 
	       }
		 }
}

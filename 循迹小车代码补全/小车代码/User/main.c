#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Motor.h"
#include "xunji.h"
#include "Serial.h"
#include <string.h>


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
	{
		if (Serial_RxFlag == 1)
		{
		if (strcmp(Serial_RxPacket,"project1") == 0)
		{
		if(LightSensor_Get3() == 1)
		{
		if(LightSensor_Get1()==0)
		{
		void gottoward();
		}
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
	}
 }
	 if (strcmp(Serial_RxPacket,"project31") == 0)
	 {
	     
		 if(LightSensor_Get3() == 1)
		 {
		   if(LightSensor_Get1()==0)
		   {
		        void gottoward();
		   }
		   if(LightSensor_Get1()==1)
		   {
			   Delay_s(1);
			    lukou++;
		   }
		     if(LightSensor_Get5()==1)
		   {
			    Delay_s(1);
			    lukou2++;
		   }
			if(lukou == 3)
			{
			
			void turnlift();
			Delay_s(1);				
			}				
			if(lukou == 5)
			 {
			void turnlift();
			Delay_s(1);		
			 }
			if(lukou == 7)
			{
			
			void turnright();
			Delay_s(1);
			}
			if(lukou == 11)
			{
			
			void turnright();
			Delay_s(1);
			lukou2 = 0;
			}
			if(lukou2 == 1)
			{
			void turnright();
			Delay_s(1);
			lukou2 = 50;
			}
			if(lukou == 14)
			{
			
			void turnright();
			Delay_s(1);
				
		    }
			if(lukou == 15)
			 {
			void turnlift();
			Delay_s(1);
			lukou2=2;
			 }
			 if(lukou == 17)
			 {
			void turnright();
			Delay_s(1);
			lukou2=2;
			 }
			 if(lukou2 == 3)
			{
			void turnright();
			Delay_s(1);
				lukou2=50;
			}
			 if(lukou == 20)
			 {
			void turnlift();
			Delay_s(1);
			 }
			 if(lukou == 21)
			 {
			void turnright();
			Delay_s(1);
			lukou2 = 4;	 
			 }
			if(lukou2 == 5)
			{
			void turnright();
			Delay_s(1);
			lukou2 =50;
			}
			if(lukou == 23)
			 {
			void turnlift();
			Delay_s(1);
			 }
			 if(lukou == 25)
			 {
			void turnlift();
			Delay_s(1);
			void gottoward();
			} 
	      }
	   }//结束路线1；4
	 if (strcmp(Serial_RxPacket,"project32") == 0)//路线2
	 {
	  if(LightSensor_Get3() == 1)
	  {
	   if(LightSensor_Get1()==0)
		   {
		        void gottoward();
		   }
		   if(LightSensor_Get1()==1)
		   { 
			   Delay_s(1);
			    lukou++;
		   }
		     if(LightSensor_Get5()==1)
		   {
			    Delay_s(1);
			    lukou2++;
		   }
		   if(lukou == 1)
		   {
			turnlift();
			 Delay_s(1);
		   }
		     if(lukou == 2)
		   {
			turnright();
			 Delay_s(1);
		   }
		     if(lukou == 5)
		   {
			turnlift();
			 Delay_s(1);
		   }
		     if(lukou == 6)
		   {
			turnlift();
			 Delay_s(1);
		   }
		     if(lukou == 8)
		   {
			turnright();
			 Delay_s(1);
		   }
		     if(lukou == 10)
		   {
			turnright();
			 Delay_s(1);
		   }
		    if(lukou == 13)
		   {
			turnlift();
			 Delay_s(1);
		   }
		    if(lukou == 14)
		   {
			turnlift();
			 Delay_s(1);
		   }
		    if(lukou == 16)
		   {
			turnright();
			 Delay_s(1);
		   }
		    if(lukou == 18)
		   {
			turnright();
			 Delay_s(1);
			 lukou2=0;
			 if (lukou2 == 3)
			  {
			 turnright();
			 Delay_s(1);
			  }
		   }
			  if(lukou == 24)
		   {
			turnright();
			 Delay_s(1);
		   }
		  }
  }//路线2完成
	 if (strcmp(Serial_RxPacket,"project32") == 0)//路线3，路线三我从下往上走澳
	 {
	  if(LightSensor_Get3() == 1)
	  {
	   if(LightSensor_Get1()==0)
		   {
		        void gottoward();
		   }
		   if(LightSensor_Get1()==1)
		   { 
			   Delay_s(1);
			    lukou++;
		   }
		     if(LightSensor_Get5()==1)
		   {
			    Delay_s(1);
			    lukou2++;
		   }
		   if(lukou == 5)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 6)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 8)
		   {
			turnright();
			 Delay_s(1);
		   }
		   if(lukou == 10)
		   {
			turnright();
			 Delay_s(1);
		   }
		   if(lukou == 12)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 13)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 14)
		   {
			turnright();
			 Delay_s(1);
		   }
		   if(lukou == 16)
		   {
			turnright();
			 Delay_s(1);
		   }
		   if(lukou == 19)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 20)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 25)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 26)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 28)
		   {
			turnright();
			 Delay_s(1);
		   }
		   if(lukou == 30)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 32)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 33)
		   {
			turnlift();
			 Delay_s(1);
		   }
		   if(lukou == 34)
		   {
			turnright();
			 Delay_s(1);
		   }
		   if(lukou == 36)
		   {
			turnright();
			 Delay_s(1);
		   }
		   if(lukou == 39)
		   {
			turnlift();
			 Delay_s(1);
		   }
        }
      }//路线3王结束
 }	 
}

#include "stm32f10x.h"                  // Device header
#include "PWM.h"


void Sever_Init(void)
{
    PWM_Init();
}
void Servo_Angele(float angle)
{

    pwm_SetCompare3(angle / 180 * 2000 + 500);


}

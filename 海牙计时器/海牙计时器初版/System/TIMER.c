#include "TIMER.h"	
#include "Key.h"
#include "zhuangtaiji.h"
#include "dingshi.h"
#include "Delay.h"
#include "LED.h"
/*********************************************************************************
* @Function	: 通用定时器的选择（TIM2-TIM5）
*	@Author   : HR
* @Date			: 2022-08-30
**********************************************************************************/
#if GENERAL_TIM2
		u16 Usart3_Time = 0; // ms 计时变量
		u16 Usart4_Time = 0; // ms 计时变量 
#endif
#if GENERAL_TIM3
		u32 time = 0; // ms 计时变量 
#endif
#if GENERAL_TIM4
		u16 time_4 = 0; // ms 计时变量 
#endif

/*********************************************************************************
* @Function	: TIM定时器选择
* @Input		: time,TIM定时器（TIM_2-TIM_5）
* @Output		:	TIM模块
* @Return		: None
* @Others		:	None
* @Date			: 2022-08-30
**********************************************************************************/
static TIM_TypeDef * TimeModule_get( TimeModule time )
{
	TIM_TypeDef * timeTemp;
	switch( ( u8 )time )//UART模块选择
	{
#if GENERAL_TIM2
		case TIM_2:
			timeTemp = TIM2;
		break;
#endif
#if GENERAL_TIM3
		case TIM_3:
			timeTemp = TIM3;
		break;
#endif
#if GENERAL_TIM4
		case TIM_4:
			timeTemp = TIM4;
		break;
#endif

	}
  return timeTemp;
}
/*********************************************************************************
* @Function	: TIM定时器中断初始化
* @Input		: time,TIM定时器（TIM_2-TIM_5）
*						PreemptionPriority，抢占优先级
*						SubPriority，子优先级
* @Output		:	None
* @Return		: None
* @Others		:	None
* @Date			: 2022-08-30
**********************************************************************************/
static void GENERAL_TIM_NVIC_Config( TimeModule time, u8 PreemptionPriority, u8 SubPriority)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
  // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	// 设置中断组为0
	//Usart NVIC 配置
	switch( ( u8 )time )//中断通道配置
	{
		case TIM_2: NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;break; //TIM2中断
		case TIM_3: NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;break;
		case TIM_4: NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;break;
	}
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= PreemptionPriority ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = SubPriority;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化NVIC寄存器
}
/*********************************************************************************
* @Function	: TIM时钟使能
* @Input		: time,time时钟（TIM_1-TIM_5）
* @Output		:	None
* @Return		: None
* @Others		:	None
* @Date			: 2022-08-30
**********************************************************************************/
static void GENERAL_TIMClock_Enable( TimeModule time)
{
	switch( (u8)time )
	{
		case TIM_2: RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); break;//通用定时器2时钟使能
		case TIM_3: RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); break;//通用定时器2时钟使能
		case TIM_4: RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); break;//通用定时器2时钟使能
	}
}
 
/*
 * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
 * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
 * 另外三个成员是通用定时器和高级定时器才有.
 *-----------------------------------------------------------------------------
 *typedef struct
 *{ TIM_Prescaler            都有
 *	TIM_CounterMode			     TIMx,x[6,7]没有，其他都有
 *  TIM_Period               都有
 *  TIM_ClockDivision        TIMx,x[6,7]没有，其他都有
 *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]才有
 *}TIM_TimeBaseInitTypeDef; 
 *-----------------------------------------------------------------------------
 */
static void GENERAL_TIM_Mode_Config(TimeModule time)
{
		TIM_TypeDef * timeTemp;
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	
		timeTemp = TimeModule_get( time );//TIME时钟选择
	
		// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
    TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period;
	  // 时钟预分频数
    TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler;	
		// 时钟分频因子 ，没用到不用管
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
		// 计数器计数模式，设置为向上计数
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 		
		// 重复计数器的值，没用到不用管
		TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	  // 初始化定时器
    TIM_TimeBaseInit(timeTemp, &TIM_TimeBaseStructure);
		// 清除计数器中断标志位
    TIM_ClearFlag(timeTemp, TIM_FLAG_Update);
		// 开启计数器中断
    TIM_ITConfig(timeTemp,TIM_IT_Update,ENABLE);
		// 使能计数器
    TIM_Cmd(timeTemp, DISABLE); //关闭定时器
}
/*********************************************************************************
* @Function	: TIM2-5 初始化
* @Input		: time,TIM定时器（TIM_2-TIM_5）
*						PreemptionPriority，抢占优先级
*						SubPriority，子优先级
* @Output		:	None
* @Return		: None
* @Others		:	None
* @Date			: 2022-08-30
**********************************************************************************/
void GENERAL_TIM_Init(TimeModule time,u8 PreemptionPriority, u8 SubPriority)
{
	GENERAL_TIMClock_Enable(time); //TIM使能化
	GENERAL_TIM_NVIC_Config(time,PreemptionPriority,SubPriority); //TIM中断优先级配置
	GENERAL_TIM_Mode_Config(time); //TIM初始化	
}
/*********************************************************************************
* @Function	:  TIMER2定时器中断服务
* @Input		:  None
* @Output		:	 None
* @Return		:  None
* @Others		:	 None
* @Date			:  2022-08-30
**********************************************************************************/
#if GENERAL_TIM2 
void TIM2_IRQHandler(void)   //TIM3中断
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
	{
		}else if(Usart4_Time>0){
			Usart4_Time++;//串口四接收间隔判断
		}else if(Usart3_Time>0){
			Usart3_Time++;//串口三接收间隔判断
		}
		//满足条件关定时器
		if(Usart3_Time==10||Usart4_Time==10){
			TIM_Cmd(TIM2, DISABLE); //关闭定时器
		}
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //清除TIMx更新中断标志
	}

#endif
/*********************************************************************************
* @Function	:  TIMER3定时器中断服务
* @Input		:  None
* @Output		:	 None
* @Return		:  None
* @Others		:	 None
* @Date			:  2022-08-30
**********************************************************************************/
#if GENERAL_TIM3 
void TIM3_IRQHandler(void)   //TIM3中断
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
	{
		if(time>0){
			time++;//串口五接收间隔判断
		}
		//满足条件关定时器
		if(time==10000){
			time=0;
			TIM_Cmd(TIM3, DISABLE); //关闭定时器
		}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除TIMx更新中断标志 
	}
}
#endif

// 检测按键是否按下





static u8 num_on = 0;
static u8 key_old = 0;
static u8 weixuan =1;


u8 mode = 1;
u8 miao = 0;
u8 shimiao =0;
u8 fen = 0;


int z_miao = 0;
int z_shimiao = 0;
int z_fen = 0;

u8 x =0;
u8 y =0;
u8 z=0;//伪指针

int Check_Key_ON_OFF()
{
	u8 key;
	key = KEY_Scan(1);
	//与上一次的键值比较 如果不相等，表明有键值的变化，开始计时
	if (key != 0 && num_on == 0)
	{
		key_old = key;
		num_on = 1;
	}
	if (key != 0 && num_on >= 1 && num_on <= Key_Scan_Time) // 25*12ms
	{
		num_on++; // 按键时间记录器
	}
	if (key == 0 && num_on > 0 && num_on < Key_Scan_Time) // 短按
	{
		switch (key_old)
		{
			case KEY1_PRES://按键一短按对应不同模式的效果
				switch(mode)
				{
					case MODE1://待机模式下按键一的作用
					 switch(weixuan)//选择位数
					 {
					 case miao1:
						miao++;
					  if(miao==9) miao=9;
					 break;
					 case miao2:
						shimiao++;
					  if(shimiao==5) shimiao=5;
					 break;
					 case fen1:
						fen++;
					  if(fen==9) fen=9;
					 break;
					 }
					break;
					case MODE2://正计时模式下按键1短按的作用
					 if(x == 1 && y == 0)//时间暂停函数
					 {
					 Timer_Stop();
						 x=0;
						 y=1;
						 z=1;//正计时模式的标志
					 mode = MODE4;
					 }
					//if判断，时钟已经打开就关闭并拉值出来
					//时钟关闭就打开并赋值进去
					break;
				  case MODE3://倒计时模式下按键1短按的作用
					 if(x == 1 && y == 0)
					 {
					  Timer_Stop();
						 x=0;
						 y=1;
						 z=2;
						 mode =MODE4;
					 }	
					//时间暂停函数	 
					//if判断，时钟已经打开就关闭并拉值出来
					//时钟关闭就打开并赋值进去
					break;
					 case MODE4://停止时模式下按键1短按的作用
						if(z==1)
						{
						  Timer_Init();
							x=1;
							y=0;
							z=0;
							mode = MODE2;
						}
						if(z==2)
						{
						  Timer_Init();
							x=1;
							y=0;
							z=0;
							mode = MODE3;
						}
					break;
				}
		 break;
		case KEY2_PRES:
			switch(mode)
				{
					case MODE1://待机模式下按键2的作用
					
					 switch(weixuan)//选择位数
					 {
					 case miao1:
						miao--;
					 if(miao==0) miao=0;
					 break;
					 case miao2:
						shimiao--;
					 if(shimiao==0)shimiao=0;
					 break;
					 case fen1:
						fen--;
					 if(fen==0)fen=0;
					 break;
					 }
					break;
					case MODE2:
					//正计时模式下按键2短按的作用
					break;
				  case MODE3:
					//倒计时模式下按键2短按的作用
					break;
				 case MODE4:
					//停止时模式下按键2短按的作用
					break;
				}
			break;
		case KEY3_PRES:
			switch(mode)
				{
					case MODE1:					//待机模式下短按按键3的作用
					if(weixuan == 1)
					{
						weixuan = 2;
						Delay_ms(10);
					}
					if(weixuan == 2) 
					{
					  weixuan = 3;
						Delay_ms(10);
					}
					if(weixuan == 3) 
					{
						weixuan = 1;
						Delay_ms(10);
					}
					break;
					case MODE2://正计时模式下短按按键三作用
					if(x == 0 && y == 0)//初始状态开启时钟
					{
						Timer_Init();
						 x=1;
						 y=0;
						Delay_ms(10);
					}
					if(x == 1 && y ==0)
					{
					 z_miao= 0;
					 z_shimiao =0;
					 z_fen = 0;
						Delay_ms(10);
					}
					break;
				  case MODE3:		//倒计时模式下按键3短按
						if(x == 0 && y == 0)//初始状态开启时钟
					{
						Timer_Init();
						 x=1;
						 y=0;
						Delay_ms(10);
					}
					if(x == 1 && y ==0)
					{
					 z_miao= miao;
					 z_shimiao =shimiao;
					 z_fen = fen;
						Delay_ms(10);
					}
					

						 //加入if判断，如果定时器未启动则启动模式进入mod4
					//若定时器已经启动则回归预定值并启动
					break;
					 case MODE4:
					//停止模式下按键3短按的作用
					break;
				
				}
			break;
		default:
			break;
		}
		num_on = 0;
	}
	else if (key == 0 && num_on >= Key_Scan_Time) // 长按
	{
		switch (key_old)
		{
		case KEY1_PRES:
			//按键1长按状态机
			break;
		case KEY2_PRES:
		switch(mode)
				{
					case MODE1://待机模式下按键2的作用
					break;
					case MODE2:
					//正计时模式下按键2长按的作用
					break;
				  case MODE3:
					//倒计时模式下按键2长按的作用
					break;
					case MODE4:					//停止时模式下按键2长按的作用
					
					z_miao =0;
					z_shimiao =0;
					z_fen =0;
					miao = 0;
					shimiao=0;
					fen= 0;
					weixuan =1;
					x=0;
					y=0;
					z=0;
					
					mode = MODE1; 
					break;
				
				}
			break;
		case KEY3_PRES:
			switch(mode)
				{
					case MODE1://待机模式下按键3的作用
					if(miao==0 && shimiao == 0 &&  fen == 0 )
					{
					   LED_ON_OFF(1);
						Buzzer_ON_OFF();
						mode = MODE2;//进入正计时模式
					}
					else
					{
						z_miao    = miao;
						z_shimiao = shimiao;
						z_fen     = fen;
					  mode = MODE3;//进入倒计时模式
					}
					break;
					case MODE2:
					//正计时模式下按键3长按的作用
					break;
				  case MODE3:
					//倒计时模式下按键3长按的作用
					break;
					 case MODE4:
					//停止时模式下按键3长按的作用
					break;
				
				}
			break;
		default:
			break;
		}
		num_on = 0;
	}
 
	return 1;
}
#if GENERAL_TIM4
void TIM4_IRQHandler(void) // TIM4中断
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) // 检查TIM4更新中断发生与否
	{
		time_4++;
		if (time_4 % 25 == 0)
		{
			Check_Key_ON_OFF();
			time_4 = 0;
		}
 
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update); // 清除TIMx更新中断标志
	}
}
#endif

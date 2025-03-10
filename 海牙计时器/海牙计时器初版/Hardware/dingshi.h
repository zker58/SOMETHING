#ifndef __DINGSHI_H
#define __DINGSHI_H



void Z_TIM2_IRQHandler(void);
void D_TIM2_IRQHandler(void);
void Timer_Stop(void);
void Timer_Init(void);


extern  int z_miao;
extern  int z_shimiao;
extern  int z_fen;
extern u8 x;
extern u8 y;
extern u8 z;
#endif

#include "stm32f10x.h"                  // Device header


typedef enum
{
    MODE1 = 1,   //初始进入的模式，s1加时间，s2减时间，a改位;
    MODE2 = 2,   //正计时
    MODE3 = 3,   //倒计时
	  MODE4 = 4    //时间停止模式
}MODE;

typedef enum
{
     miao1= 1, //个位数秒  
     miao2= 2, //十位秒   
     fen1 = 3, //个位分
}WEI;   //3个数字对应四位数字 对于计时的本质，是将设定值与动态变化值进行区分，设定值存储起来，而变化值做屏幕显示与计时的作用设定值仅在模式一里显示并调整，当长按按键A后，将预设值放入时钟中进行变化

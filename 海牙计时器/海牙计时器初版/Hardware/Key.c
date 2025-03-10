#include "Key.h"
#include "Delay.h"
// 协议文件
/*********************************************************************************
 * @Function	:  初始化控制LED的IO
 * @Input		:  None
 * @Output		:  None
 * @Return		:  None
 * @Others		:  None
 * @Date			:  2022-07-23
 **********************************************************************************/
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 
	/*开启按键端口的时钟*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK | KEY2_GPIO_CLK | KEY3_GPIO_CLK, ENABLE);
 
	// 选择按键的引脚
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
	// 设置按键的引脚为浮空输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	// 使用结构体初始化按键
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
 
	// 选择按键的引脚
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN;
	// 设置按键的引脚为浮空输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	// 使用结构体初始化按键
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);
 
	// 选择按键的引脚
	GPIO_InitStructure.GPIO_Pin = KEY3_GPIO_PIN;
	// 设置按键的引脚为浮空输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	// 使用结构体初始化按键
	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStructure);
 
 
	GPIO_ResetBits(KEY1_GPIO_PORT, KEY1_GPIO_PIN);
	GPIO_ResetBits(KEY2_GPIO_PORT, KEY2_GPIO_PIN);
	GPIO_ResetBits(KEY3_GPIO_PORT, KEY3_GPIO_PIN);
}
/*********************************************************************************
 * @Function	:  检测是否有按键按下
 * @Input		:  GPIOx：x 可以是 A，B，C，D或者 E
 *						:  GPIO_Pin：待读取的端口位
 * @Output		:  None
 * @Return		:  KEY_OFF(没按下按键)、KEY_ON（按下按键）
 * @Others		:  None
 * @Date			:  2022-07-23
 **********************************************************************************/
u8 Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	/*检测是否有按键按下 */
	if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
	{
		/*等待按键释放 */
		while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
			;
		return KEY_ON;
	}
	else
		return KEY_OFF;
}
/*********************************************************************************
 * @Function	:  按键处理函数
 * @Input		:  Gmode:0,不支持连续按;1,支持连续按;
 * @Output		:  None
 * @Return		:  0，没有任何按键按下
 *							 1，KEY1按下
 *						   2，KEY2按下
 *							 3，KEY3按下
 * @Others		:  注意此函数有响应优先级,KEY0>KEY1>KEY2>KEY3!!
 * @Date			:  2022-07-23
 **********************************************************************************/
u8 KEY_Scan(u8 mode)
{
	static u8 key_up = 1; // 按键按松开标志
	if (mode)
		key_up = 1; // 支持连按
	if (key_up && (KEY1 == KEY_ON || KEY2 == KEY_ON || KEY3 == KEY_ON))
	{
		Delay_ms(10); // 去抖动
		key_up = 0;
		if (KEY1 == KEY_ON)
			return KEY1_PRES;
		else if (KEY2 == KEY_ON)
			return KEY2_PRES;
		else if (KEY3 == KEY_ON)
			return KEY3_PRES;
	}
	else if (KEY1 == KEY_OFF && KEY2 == KEY_OFF && KEY3 == KEY_OFF )
		key_up = 1;
	return 0; // 无按键按下
}
 

void Sys_Restart(void)
{
	__set_FAULTMASK(1);
	NVIC_SystemReset();
}

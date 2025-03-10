#ifndef __KEY_H
#define __KEY_H
 
#include "stm32f10x.h"
 
//  ���Ŷ���
#define KEY1_GPIO_CLK RCC_APB2Periph_GPIOA
#define KEY1_GPIO_PORT GPIOA
#define KEY1_GPIO_PIN GPIO_Pin_0            //KEY1---s1
 
#define KEY2_GPIO_CLK RCC_APB2Periph_GPIOC
#define KEY2_GPIO_PORT GPIOA
#define KEY2_GPIO_PIN GPIO_Pin_7            //KEY2---s2
 
#define KEY3_GPIO_CLK RCC_APB2Periph_GPIOB
#define KEY3_GPIO_PORT GPIOA
#define KEY3_GPIO_PIN GPIO_Pin_6						//key3---A
 

 
#define KEY1 GPIO_ReadInputDataBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN) // ��ȡ����0
#define KEY2 GPIO_ReadInputDataBit(KEY2_GPIO_PORT, KEY2_GPIO_PIN) // ��ȡ����1
#define KEY3 GPIO_ReadInputDataBit(KEY3_GPIO_PORT, KEY3_GPIO_PIN) // ��ȡ����2

 
#define KEY1_PRES 1      // KEY1����
#define KEY2_PRES 2      // KEY2����
#define KEY3_PRES 3      // KEY3����
#define Key_Scan_Time 12 // �̰�ʱ��ʱ���ж�
 
/** �������±��ú�
 *  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
 *  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
 */
#define KEY_ON 1
#define KEY_OFF 0
/*********************************************************************************
 * @Function	:  ��ʼ������LED��IO
 * @Input		:  None
 * @Output		:  None
 * @Return		:  None
 * @Others		:  None
 * @Date			:  2022-07-23
 **********************************************************************************/
void Key_GPIO_Config(void);
/*********************************************************************************
 * @Function	:  ����Ƿ��а�������
 * @Input		:  GPIOx��x ������ A��B��C��D���� E
 *						:  GPIO_Pin������ȡ�Ķ˿�λ
 * @Output		:  None
 * @Return		:  KEY_OFF(û���°���)��KEY_ON�����°�����
 * @Others		:  None
 * @Date			:  2022-07-23
 **********************************************************************************/
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
/*********************************************************************************
 * @Function	:  ����������
 * @Input		:  Gmode:0,��֧��������;1,֧��������;
 * @Output		:  None
 * @Return		:  0��û���κΰ�������
 *							 1��KEY1����
 *						   2��KEY2����
 *							 3��KEY3����
 * @Others		:  ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!
 * @Date			:  2022-07-23
 **********************************************************************************/
u8 KEY_Scan(u8 mode);
/*********************************************************************************
 * @Function	:  STM32���������λ
 * @Input		:  None
 *						:  None
 * @Output		:  None
 * @Return		:  None
 * @Others		:  None
 * @Date			:  2022-08-23
 **********************************************************************************/
void Sys_Restart(void);



#endif

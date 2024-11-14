#include "stm32f10x.h"                  // Device header
#include "delay.h"

/**
  * @brief  按键初始化函数
  * @param  无
  * @retval 无
  */
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	// 这里的速度是GPIO的输出速度，在输入模式下这个参数选择没有用处
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/**
  * @brief  返回按下按键的值，若不按下按键默认返回0
  * @param  无
  * @retval KeyNum 按键对应的值，按下PB1按键返回1，按下PB11按键返回keynum++
  */
uint8_t KeyNum = 0;
uint8_t Key_GetNum(void)
{
	
		
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0)	// 读取11端口的值
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0);	// 如果不松手，程序将在此等待
		Delay_ms(20);
		KeyNum=1;
	}
	else if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)	// 读取11端口的值
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);	// 如果不松手，程序将在此等待
		Delay_ms(20);
		KeyNum=2;
	}
	
return KeyNum;
}

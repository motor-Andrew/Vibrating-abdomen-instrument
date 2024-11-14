#include "stm32f10x.h"                  // Device header
#include "PWM.h"
 
void PWM_Init(void)		//初始化PWM
{
	RCC_APB1PeriphClockCmd(PWM_TIM_PORT_CLK, ENABLE);	//打开时钟
	RCC_APB2PeriphClockCmd(PWM_GPIO_PORT_CLK, ENABLE);	//开启时钟
 
	//初始化ENA ENB GPIO
	GPIO_InitTypeDef GPIO_InitStruture;
	GPIO_InitStruture.GPIO_Mode = GPIO_Mode_AF_PP;	//只有在复用情况下，片上外设才能控制PWM
	GPIO_InitStruture.GPIO_Pin = PWM_GPIO1_Pin;
	GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_GPIO1_PORT, &GPIO_InitStruture);
	
	GPIO_InitStruture.GPIO_Pin = PWM_GPIO2_Pin;
	GPIO_Init(PWM_GPIO2_PORT, &GPIO_InitStruture);
	
	TIM_InternalClockConfig(PWM_TIM1);		//选择内部时钟
	TIM_InternalClockConfig(PWM_TIM2);
	
	//初始化时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseIniture;
	TIM_TimeBaseIniture.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseIniture.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseIniture.TIM_Period = 100 - 1;				//ARR
	TIM_TimeBaseIniture.TIM_Prescaler = 7200 - 1;			//PSC
	TIM_TimeBaseIniture.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(PWM_TIM1, &TIM_TimeBaseIniture);
	TIM_TimeBaseInit(PWM_TIM2, &TIM_TimeBaseIniture);
	
	//初始化输出比较单元
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	TIM_OCStructInit(&TIM_OCInitStructure);		//给结构体赋初始值，防止多路PWM输出通道不能输出
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//设置输出比较模式 PWM模式1
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;	//设置输出比较的极性 有效电平为高电平
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//设置输出使能
	TIM_OCInitStructure.TIM_Pulse = 0;			//设置CCR
	
	TIM_OC1Init(PWM_TIM1, &TIM_OCInitStructure);	//PA6
	TIM_OC1PreloadConfig(PWM_TIM1, TIM_OCPreload_Enable);
	TIM_OC2Init(PWM_TIM1, &TIM_OCInitStructure); //PA7
	TIM_OC2PreloadConfig(PWM_TIM1, TIM_OCPreload_Enable);
	TIM_OC3Init(PWM_TIM1, &TIM_OCInitStructure);	//PB0
	TIM_OC3PreloadConfig(PWM_TIM1, TIM_OCPreload_Enable);
	TIM_OC4Init(PWM_TIM1, &TIM_OCInitStructure);	//PB1
	TIM_OC4PreloadConfig(PWM_TIM1, TIM_OCPreload_Enable);
	TIM_OC2Init(PWM_TIM2, &TIM_OCInitStructure);	//PA8
	TIM_OC2PreloadConfig(PWM_TIM2, TIM_OCPreload_Enable);
	TIM_OC3Init(PWM_TIM2, &TIM_OCInitStructure);	//PB2
	TIM_OC3PreloadConfig(PWM_TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(PWM_TIM1, ENABLE);
	TIM_ARRPreloadConfig(PWM_TIM2, ENABLE);
	//启动定时器
	TIM_Cmd(PWM_TIM1, ENABLE);
	TIM_Cmd(PWM_TIM2, ENABLE);
 
}
 
//void PWM_SetPrescaler(uint16_t Prescaler)
//{
//	TIM_PrescalerConfig(PWM_TIM,Prescaler,TIM_PSCReloadMode_Immediate);
//}
 
void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(PWM_TIM1, Compare);
}
 
void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(PWM_TIM1, Compare);
}
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(PWM_TIM1, Compare);
}
 
void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(PWM_TIM1, Compare);
}
void PWM_SetCompare5(uint16_t Compare)
{
	TIM_SetCompare2(PWM_TIM2, Compare);
}
void PWM_SetCompare6(uint16_t Compare)
{
	TIM_SetCompare3(PWM_TIM2, Compare);
}

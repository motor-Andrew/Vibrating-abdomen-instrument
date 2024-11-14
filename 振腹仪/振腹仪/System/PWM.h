#ifndef _PWM_H
#define _PWM_H
#include "stdint.h"
 
void PWM_Init(void);
//void PWM_SetPrescaler(uint16_t Prescaler);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetCompare2(uint16_t Compare);
void PWM_SetCompare3(uint16_t Compare);
void PWM_SetCompare4(uint16_t Compare);
void PWM_SetCompare5(uint16_t Compare);
void PWM_SetCompare6(uint16_t Compare);
 
#define PWM_GPIO_PORT_CLK	RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB
#define PWM_TIM_PORT_CLK	RCC_APB1Periph_TIM3  | RCC_APB1Periph_TIM2
 
#define PWM_GPIO1_PORT		GPIOA
#define PWM_GPIO1_Pin		GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_1|GPIO_Pin_2
 
#define PWM_GPIO2_PORT		GPIOB
#define PWM_GPIO2_Pin		GPIO_Pin_0|GPIO_Pin_1



#define PWM_TIM1				TIM3
#define PWM_TIM2				TIM2
 
 
#endif

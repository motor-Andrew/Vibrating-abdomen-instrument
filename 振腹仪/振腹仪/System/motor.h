#ifndef _MOTOR_H
#define _MOTOR_H
#include "stdint.h"
void Motor_Init(void);
void Motor1_SetSpeed(uint8_t Dir, uint16_t Speed);
void Motor2_SetSpeed(uint8_t Dir, uint16_t Speed);
void Motor3_SetSpeed(uint8_t Dir, uint16_t Speed);
void Motor4_SetSpeed(uint8_t Dir, uint16_t Speed);
void Motor5_SetSpeed(uint8_t Dir, uint16_t Speed);
void Motor6_SetSpeed(uint8_t Dir, uint16_t Speed);
void Car_Stop(void);
void Car_Forward(uint16_t Speed);
void Car_Backward(uint16_t Speed);
void Car_TurnLeft(uint16_t Speed);
void Car_TurnRight(uint16_t Speed);
void Car_TransLeft(uint16_t Speed);
void Car_TransRight(uint16_t Speed);
 
#define MOTOR_GPIO_PORT1_CLK	RCC_APB2Periph_GPIOA
#define MOTOR_GPIO1_PORT		GPIOA
#define MOTOR_GPIO1_Pin			GPIO_Pin_0|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_8|GPIO_Pin_9
 
#define MOTOR_GPIO_PORT2_CLK	RCC_APB2Periph_GPIOB
#define MOTOR_GPIO2_PORT		GPIOB
#define MOTOR_GPIO2_Pin			GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_4|GPIO_Pin_5

#endif

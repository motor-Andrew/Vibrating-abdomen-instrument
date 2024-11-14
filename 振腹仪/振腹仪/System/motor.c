#include "stm32f10x.h"                  // Device header
#include "motor.h"
#include "PWM.h"
 
 
void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(MOTOR_GPIO_PORT1_CLK, ENABLE);	//开启时钟
	RCC_APB2PeriphClockCmd(MOTOR_GPIO_PORT2_CLK, ENABLE);
 
	//初始化GPIO
	GPIO_InitTypeDef GPIO_InitStruture;
	GPIO_InitStruture.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_InitStruture.GPIO_Pin = MOTOR_GPIO1_Pin;
	GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_GPIO1_PORT, &GPIO_InitStruture);
 
	//初始化GPIO
	GPIO_InitStruture.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_InitStruture.GPIO_Pin = MOTOR_GPIO2_Pin;
	GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_GPIO2_PORT, &GPIO_InitStruture);
	
}
 
//Dir = 1 正转
//Dir = 0 反转
void Motor1_SetSpeed(uint8_t Dir, uint16_t Speed)
{
	if (Speed > 1000)	Speed = 1000;
	if (Dir)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		PWM_SetCompare1(Speed);
	}
	else if (! Dir)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		PWM_SetCompare1(Speed);		
	}
}
 
void Motor2_SetSpeed(uint8_t Dir, uint16_t Speed)
{
	if (Speed > 1000)	Speed = 1000;
	if (Dir)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_9);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		PWM_SetCompare2(Speed);
	}
	else if (! Dir)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		GPIO_ResetBits(GPIOA, GPIO_Pin_9);
		PWM_SetCompare2(Speed);		
	}
}
 
void Motor3_SetSpeed(uint8_t Dir, uint16_t Speed)
{
	if (Speed > 1000)	Speed = 1000;
	if (Dir)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_9);
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
		PWM_SetCompare3(Speed);
	}
	else if (! Dir)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_8);
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
		PWM_SetCompare3(Speed);		
	}
}
 
void Motor4_SetSpeed(uint8_t Dir, uint16_t Speed)
{
	if (Speed > 1000)	Speed = 1000;
	if (Dir)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_7);
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
		PWM_SetCompare4(Speed);
	}
	else if (! Dir)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_6);
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		PWM_SetCompare4(Speed);		
	}
}
 void Motor5_SetSpeed(uint8_t Dir, uint16_t Speed)
{
	if (Speed > 1000)	Speed = 1000;
	if (Dir)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		PWM_SetCompare5(Speed);
	}
	else if (! Dir)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		PWM_SetCompare5(Speed);		
	}
}
void Motor6_SetSpeed(uint8_t Dir, uint16_t Speed)
{
	if (Speed > 1000)	Speed = 1000;
	if (Dir)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);
		PWM_SetCompare6(Speed);
	}
	else if (! Dir)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_4);
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
		PWM_SetCompare6(Speed);		
	}
}
void Car_Stop(void)
{
	Motor1_SetSpeed(1, 0);
    Motor2_SetSpeed(1, 0);
    Motor3_SetSpeed(1, 0);
    Motor4_SetSpeed(1, 0);
	Motor5_SetSpeed(1, 0);
	Motor6_SetSpeed(1, 0);
}
 
void Car_Forward(uint16_t Speed)
{
	Motor1_SetSpeed(1, Speed);
    Motor2_SetSpeed(1, Speed);
    Motor3_SetSpeed(1, Speed);
    Motor4_SetSpeed(1, Speed);	
	Motor5_SetSpeed(1, Speed);
	Motor6_SetSpeed(1, Speed);
}  
 
void Car_Backward(uint16_t Speed)
{
	Motor1_SetSpeed(0, Speed);
    Motor2_SetSpeed(0, Speed);
    Motor3_SetSpeed(0, Speed);
    Motor4_SetSpeed(0, Speed);
}
 
void Car_TurnLeft(uint16_t Speed)
{
	Motor1_SetSpeed(0,Speed);
	Motor2_SetSpeed(1,Speed);
	Motor3_SetSpeed(1,Speed);
	Motor4_SetSpeed(0,Speed);
}
 
void Car_TurnRight(uint16_t Speed)
{
	Motor1_SetSpeed(1,Speed);
	Motor2_SetSpeed(0,Speed);
	Motor3_SetSpeed(0,Speed);
	Motor4_SetSpeed(1,Speed);
}
 
void Car_TransLeft(uint16_t Speed)
{
	Motor1_SetSpeed(1,Speed);
	Motor2_SetSpeed(0,Speed);
	Motor3_SetSpeed(1,Speed);
	Motor4_SetSpeed(0,Speed);
}
 
void Car_TransRight(uint16_t Speed)
{
	Motor1_SetSpeed(0,Speed);
	Motor2_SetSpeed(1,Speed);
	Motor3_SetSpeed(0,Speed);
	Motor4_SetSpeed(1,Speed);
}

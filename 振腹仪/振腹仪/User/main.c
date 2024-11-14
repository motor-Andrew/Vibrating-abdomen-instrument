#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "key_num.h"
#include "motor.h"
#include "PWM.h"
#include "OLED.h"
 
int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	PWM_Init();
	Motor_Init();
	Key_Init();
	uint8_t num;
	OLED_Init();
	
	while(1)
	{
	num = Key_GetNum();
	if(num == 1)
	{
		OLED_Clear();
		OLED_ShowString(2,3,"Hello");
		Car_Forward(75);
	}
	
	else if(num == 2)
	{
		OLED_Clear();
		OLED_ShowChinese(3,1,4);
		OLED_ShowChinese(3,1,5);
		Car_Forward(25);
	}
	}
																																		/*Car_Stop();
																																		Car_Forward(50);
																																		Delay_ms(50000);
																																		Car_Backward(500);
																																		Delay_ms(5000);
																																		Car_TurnLeft(500);
																																		Delay_ms(5000);
																																		Car_TurnRight(500);
																																		Delay_ms(5000);
																																		Car_TransLeft(500);
																																		Delay_ms(5000);
																																		Car_TransRight(500);
																																		Car_Stop();*/
}

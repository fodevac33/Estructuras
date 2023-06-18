#include "main.h"

extern TIM_HandleTypeDef Tim3;

int main(void)
{
	HAL_Init();

	SysConfigClock();

	Global_GPIO_Init();

	GPIO_Led_Init();

	Timer_Init(100);

	HAL_TIM_Base_Start_IT(&Tim3);

	while (1) {

	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM3) {
		GPIO_Led_Toggle();
	}
}

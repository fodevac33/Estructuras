#include "main.h"


int main(void)
{
	HAL_Init();

	SysConfigClock();

	GPIO_Led_Init();

	GPIO_Button_Init();

	while (1) {
		GPIO_Led_Write(GPIO_Button_Read());

		HAL_Delay(100);
	}
}

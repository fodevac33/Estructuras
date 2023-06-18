#include "main.h"


__IO uint8_t UserButtonFlag = 0;  //__IO == volatile

int main(void)
{
	HAL_Init();

	SysConfigClock();

	GPIO_Led_Init();

	User_Button_Interrupt_Init();

	while (1) {
		if (UserButtonFlag == 1) {
			GPIO_Led_Toggle();
			UserButtonFlag = 0;
		}
	}
}

//User_Button_Interrupt HANDLER
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if (GPIO_Pin == GPIO_PIN_13) {
		UserButtonFlag = 1;
	}
}

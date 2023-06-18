/*
 * INTERRUPTS.c
 *
 *  Created on: May 19, 2023
 *      Author: felipe
 */

#include "INTERRUPTS.h"


void User_Button_Interrupt_Init() {
	//PC13 -> UserButton -> GPIOC
	GPIO_InitTypeDef gpioInit = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE();

	gpioInit.Pin = GPIO_PIN_13;
	gpioInit.Mode = GPIO_MODE_IT_FALLING;  //Sets Interrupt on falling edge
	gpioInit.Pull = GPIO_PULLUP;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOC, &gpioInit);

	//ENABLE INTERRUPT
	NVIC_SetPriority(EXTI15_10_IRQn, 5);  //Sets priority of the interrupt to 5

	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

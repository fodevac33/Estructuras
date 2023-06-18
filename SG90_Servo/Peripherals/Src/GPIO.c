/*
 * GPIO.c
 *
 *  Created on: May 19, 2023
 *      Author: felipe
 */
#include "GPIO.h"


void Global_GPIO_Init() {
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
}

//LED

void GPIO_Led_Init(){
	//PA5 -> LED -> GPIOA
	GPIO_InitTypeDef gpioInit = {0};

	gpioInit.Pin = GPIO_PIN_5;
	gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInit.Pull = GPIO_NOPULL;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOA, &gpioInit);
}


void GPIO_Led_Write(GPIO_State state){
	if (state == HIGH) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	}
}


void GPIO_Led_Toggle(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

//BUTTON

void GPIO_User_Button_Init(){
	//PC13 -> UserButton -> GPIOC
	GPIO_InitTypeDef gpioInit = {0};

	gpioInit.Pin = GPIO_PIN_13;
	gpioInit.Mode = GPIO_MODE_INPUT;
	gpioInit.Pull = GPIO_PULLUP;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOC, &gpioInit);
}


GPIO_State GPIO_User_Button_Read(){
	return !(bool)HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
}





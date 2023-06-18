/*
 * MFS_Dx.c
 *
 *  Created on: Mar 17, 2023
 *      Author: felipe
 */

#include "MFS_Dx.h"

void MFS_Dx_Init(void){
	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_OUTPUT);

	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_6, LL_GPIO_MODE_OUTPUT);
}

//Reseteo de los leds
void MFS_D1_On(){
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);

}

void MFS_D2_On(){
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);

}

void MFS_D3_On(){
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);

}

void MFS_D4_On(){
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6);

}


void MFS_D1_Off(){
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
}

void MFS_D2_Off(){
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6);
}

void MFS_D3_Off(){
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_7);
}

void MFS_D4_Off(){
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6);
}

//Abstraccion del toggle de los leds
void MFS_D1_Toggle(void){
	LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_5);
}

void MFS_D2_Toggle(void){
	LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_6);
}

void MFS_D3_Toggle(void){
	LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_7);
}

void MFS_D4_Toggle(void){
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_6);
}








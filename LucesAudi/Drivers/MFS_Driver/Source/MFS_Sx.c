/*
 * MFS_Sx.c
 *
 *  Created on: Mar 17, 2023
 *      Author: felipe
 */

#include "MFS_Sx.h"


void MFS_Sx_Init(void){
	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_1, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_INPUT);


	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_0, LL_GPIO_MODE_INPUT);
}


uint8_t MFS_S1_Read(void){
	if (LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_1) == 0){
		return 1;
	}else{
		return 0;
	}
}

uint8_t MFS_S2_Read(void){
	if (LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_4) == 0){
		return 1;
	}else{
		return 0;
	}
}

uint8_t MFS_S3_Read(void){
	if (LL_GPIO_IsInputPinSet(GPIOB, LL_GPIO_PIN_0) == 0){
		return 1;
	}else{
		return 0;
	}
}

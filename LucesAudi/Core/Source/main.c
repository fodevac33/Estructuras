/*
 * main.c
 *
 *  Created on: Mar 10, 2023
 *      Author: felipe
 */

#include "main.h"

#include "AUDI_Sx.h"
#include "AUDI_Dx.h"

#include "../Include/AUDI_fms.h"


uint8_t ShowState = 0;

uint8_t S1_Pressed = 0;
uint8_t S2_Pressed = 0;
uint8_t S3_Pressed = 0;


int main(void) {

	MSP_Init1msTick();

	AUDI_Dx_Init();

	AUDI_Sx_Init();

	AUDI_BUZZER_Init();

	AUDI_BUZZER_Off();

	AUDI_Dx_AllOff();

	for(;;){
		//Boton 1
		if (S1_Polling() == 1 && ShowState == 0 && S1_Pressed == 0){
			S1_Pressed = 1;
			ShowState = 1;
		}

		if (S1_Pressed == 1 && ShowState == 1){
			fms_LeftLightShow();
		}

		if (S1_Polling() == 1 && S1_Pressed == 1){
			AUDI_Dx_AllOff();
			S1_Pressed = 0;
			ShowState = 0;
		}

		//Boton 2
		if (S2_Polling() == 1 && ShowState == 0 && S2_Pressed == 0){
			S2_Pressed = 1;
			ShowState = 1;
		}

		if (S2_Pressed == 1 && ShowState == 1){
			fms_RightLightShow();
		}

		if (S2_Polling()  == 1 && S2_Pressed == 1){
			AUDI_Dx_AllOff();
			S2_Pressed = 0;
			ShowState = 0;
		}

		//Boton 3
		if (S3_Polling() == 1 && ShowState == 0 && S3_Pressed == 0){
			S3_Pressed = 1;
			ShowState = 1;
		}

		if (S3_Pressed == 1 && ShowState == 1){
			fms_DualLightShow();
		}

		if (S3_Polling() == 1 && S3_Pressed == 1){
			AUDI_Dx_AllOff();
			S3_Pressed = 0;
			ShowState = 0;
		}

		//Buzzer
		if (ShowState == 0){
			AUDI_BUZZER_Off();
		}
	}
	return 0;
}












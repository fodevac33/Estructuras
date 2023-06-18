/*
 * AUDI_fms.c
 *
 *  Created on: Mar 23, 2023
 *      Author: felipe
 */

#include "../../../Core/Include/AUDI_fms.h"

int beat = 500;


//Maquinas de estado
void fms_LeftLightShow(void){
	static uint32_t lastTick = 0;
	static uint8_t state = 1;
	uint8_t next_state;

	if (MSP_GetTick() - lastTick >= beat/8){
		lastTick = MSP_GetTick();

		switch(state){
		case 1:
			next_state = 2;
			break;
		case 2:
			next_state = 3;
			break;
		case 3:
			next_state = 4;
			break;
		case 4:
			next_state = 5;
			break;
		case 5:
			next_state = 6;
			break;
		case 6:
			next_state = 7;
			break;
		case 7:
			next_state = 8;
			break;
		case 8:
			next_state = 9;
			break;
		case 9:
			next_state = 10;
			break;
		case 10:
			next_state = 11;
			break;
		case 11:
			next_state = 12;
			break;
		case 12:
			next_state = 13;
			break;
		case 13:
			next_state = 14;
			break;
		case 14:
			next_state = 1;
			break;
		}

		state = next_state;
	}
	switch(state){
	case 1:
		AUDI_G1D1_On();
		AUDI_G1D2_Off();
		AUDI_G1D3_Off();
		AUDI_G1D4_Off();
		AUDI_G1D5_Off();
		AUDI_G1D6_Off();
		AUDI_G1D7_Off();
		AUDI_G1D8_Off();
		break;
	case 2:
	case 14:
		AUDI_G1D1_Off();
		AUDI_G1D2_On();
		AUDI_G1D3_Off();
		AUDI_G1D4_Off();
		AUDI_G1D5_Off();
		AUDI_G1D6_Off();
		AUDI_G1D7_Off();
		AUDI_G1D8_Off();
		break;
	case 3:
	case 13:
		AUDI_G1D1_Off();
		AUDI_G1D2_Off();
		AUDI_G1D3_On();
		AUDI_G1D4_Off();
		AUDI_G1D5_Off();
		AUDI_G1D6_Off();
		AUDI_G1D7_Off();
		AUDI_G1D8_Off();
		break;
	case 4:
	case 12:
		AUDI_G1D1_Off();
		AUDI_G1D2_Off();
		AUDI_G1D3_Off();
		AUDI_G1D4_On();
		AUDI_G1D5_Off();
		AUDI_G1D6_Off();
		AUDI_G1D7_Off();
		AUDI_G1D8_Off();
		break;
	case 5:
	case 11:
		AUDI_G1D1_Off();
		AUDI_G1D2_Off();
		AUDI_G1D3_Off();
		AUDI_G1D4_Off();
		AUDI_G1D5_On();
		AUDI_G1D6_Off();
		AUDI_G1D7_Off();
		AUDI_G1D8_Off();
		break;
	case 6:
	case 10:
		AUDI_G1D1_Off();
		AUDI_G1D2_Off();
		AUDI_G1D3_Off();
		AUDI_G1D4_Off();
		AUDI_G1D5_Off();
		AUDI_G1D6_On();
		AUDI_G1D7_Off();
		AUDI_G1D8_Off();
		break;
	case 7:
	case 9:
		AUDI_G1D1_Off();
		AUDI_G1D2_Off();
		AUDI_G1D3_Off();
		AUDI_G1D4_Off();
		AUDI_G1D5_Off();
		AUDI_G1D6_Off();
		AUDI_G1D7_On();
		AUDI_G1D8_Off();
		break;
	case 8:
		AUDI_G1D1_Off();
		AUDI_G1D2_Off();
		AUDI_G1D3_Off();
		AUDI_G1D4_Off();
		AUDI_G1D5_Off();
		AUDI_G1D6_Off();
		AUDI_G1D7_Off();
		AUDI_G1D8_On();
		break;
	}
}


void fms_RightLightShow(void){
	static uint32_t lastTick = 0;
	static uint8_t state = 1;
	uint8_t next_state;

	if (MSP_GetTick() - lastTick >= beat/8){
		lastTick = MSP_GetTick();

		switch(state){
		case 1:
			next_state = 2;
			break;
		case 2:
			next_state = 3;
			break;
		case 3:
			next_state = 4;
			break;
		case 4:
			next_state = 5;
			break;
		case 5:
			next_state = 6;
			break;
		case 6:
			next_state = 7;
			break;
		case 7:
			next_state = 8;
			break;
		case 8:
			next_state = 9;
			break;
		case 9:
			next_state = 10;
			break;
		case 10:
			next_state = 11;
			break;
		case 11:
			next_state = 12;
			break;
		case 12:
			next_state = 13;
			break;
		case 13:
			next_state = 14;
			break;
		case 14:
			next_state = 1;
			break;
		}

		state = next_state;
	}
	switch(state){
	case 1:
		AUDI_G2D1_On();
		AUDI_G2D2_Off();
		AUDI_G2D3_Off();
		AUDI_G2D4_Off();
		AUDI_G2D5_Off();
		AUDI_G2D6_Off();
		AUDI_G2D7_Off();
		AUDI_G2D8_Off();
		break;
	case 2:
	case 14:
		AUDI_G2D1_Off();
		AUDI_G2D2_On();
		AUDI_G2D3_Off();
		AUDI_G2D4_Off();
		AUDI_G2D5_Off();
		AUDI_G2D6_Off();
		AUDI_G2D7_Off();
		AUDI_G2D8_Off();
		break;
	case 3:
	case 13:
		AUDI_G2D1_Off();
		AUDI_G2D2_Off();
		AUDI_G2D3_On();
		AUDI_G2D4_Off();
		AUDI_G2D5_Off();
		AUDI_G2D6_Off();
		AUDI_G2D7_Off();
		AUDI_G2D8_Off();
		break;
	case 4:
	case 12:
		AUDI_G2D1_Off();
		AUDI_G2D2_Off();
		AUDI_G2D3_Off();
		AUDI_G2D4_On();
		AUDI_G2D5_Off();
		AUDI_G2D6_Off();
		AUDI_G2D7_Off();
		AUDI_G2D8_Off();
		break;
	case 5:
	case 11:
		AUDI_G2D1_Off();
		AUDI_G2D2_Off();
		AUDI_G2D3_Off();
		AUDI_G2D4_Off();
		AUDI_G2D5_On();
		AUDI_G2D6_Off();
		AUDI_G2D7_Off();
		AUDI_G2D8_Off();
		break;
	case 6:
	case 10:
		AUDI_G2D1_Off();
		AUDI_G2D2_Off();
		AUDI_G2D3_Off();
		AUDI_G2D4_Off();
		AUDI_G2D5_Off();
		AUDI_G2D6_On();
		AUDI_G2D7_Off();
		AUDI_G2D8_Off();
		break;
	case 7:
	case 9:
		AUDI_G2D1_Off();
		AUDI_G2D2_Off();
		AUDI_G2D3_Off();
		AUDI_G2D4_Off();
		AUDI_G2D5_Off();
		AUDI_G2D6_Off();
		AUDI_G2D7_On();
		AUDI_G2D8_Off();
		break;
	case 8:
		AUDI_G2D1_Off();
		AUDI_G2D2_Off();
		AUDI_G2D3_Off();
		AUDI_G2D4_Off();
		AUDI_G2D5_Off();
		AUDI_G2D6_Off();
		AUDI_G2D7_Off();
		AUDI_G2D8_On();
		break;
	}
}

void fms_DualLightShow(void){
	static uint32_t lastTick = 0;
	static uint8_t state = 1;
	uint8_t next_state;
	if (MSP_GetTick() - lastTick >= beat){
		lastTick = MSP_GetTick();
		switch(state){
		case 1:
			next_state = 2;
			break;
		case 2:
			next_state = 1;
			break;
		}
		state = next_state;
	}
	switch(state){
	case 1:
		AUDI_Dx_AllOff();
		AUDI_BUZZER_Off();
		break;
	case 2:
		AUDI_Dx_AllOn();
		AUDI_BUZZER_On();
		break;
	}
}

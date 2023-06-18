/*
 * AUDI_Sx.c
 *
 *  Created on: Mar 23, 2023
 *      Author: felipe
 */


//Botones
#include "AUDI_Sx.h"
#include "stm32l4xx_stk.h"

#define S1_PIN LL_GPIO_PIN_1
#define S2_PIN LL_GPIO_PIN_4
#define S3_PIN LL_GPIO_PIN_0

#define S1_GPIO GPIOA
#define S2_GPIO GPIOA
#define S3_GPIO GPIOB

uint16_t pollingTime = 50;

void AUDI_Sx_Init(void){
	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);

	LL_GPIO_SetPinMode(S1_GPIO, S1_PIN, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinMode(S2_GPIO, S2_PIN, LL_GPIO_MODE_INPUT);
	LL_GPIO_SetPinMode(S3_GPIO, S3_PIN, LL_GPIO_MODE_INPUT);
}

uint8_t AUDI_S1_Read(void){
	if (LL_GPIO_IsInputPinSet(S1_GPIO, S1_PIN) == 0){
		return 1;
	}else{
		return 0;
	}
}

uint8_t AUDI_S2_Read(void){
	if (LL_GPIO_IsInputPinSet(S2_GPIO, S2_PIN) == 0){
		return 1;
	}else{
		return 0;
	}
}

uint8_t AUDI_S3_Read(void){
	if (LL_GPIO_IsInputPinSet(S3_GPIO, S3_PIN) == 0){
		return 1;
	}else{
		return 0;
	}
}


uint8_t S1_Polling(void){
	static uint32_t lastTick = 0;

	enum S1_t {PUSHED, RELEASED};

	static enum S1_t state = RELEASED;
	enum S1_t next_state;

	static uint8_t S1_Event = 0;

	if (MSP_GetTick() - lastTick >= pollingTime){
		lastTick = MSP_GetTick();

		uint8_t input = AUDI_S1_Read();

		switch(state){
		case PUSHED:
			if (input == 0){
				next_state = RELEASED;
				S1_Event = (S1_Event == 1) ? 0 : 1;
			}else{
				next_state = PUSHED;
			}
			break;

		case RELEASED:
			if (input == 0){
				next_state = RELEASED;
			}else{
				next_state = PUSHED;
			}
			break;
		}
		state = next_state;
	}
	return S1_Event;
}

uint8_t S2_Polling(void){
	static uint32_t lastTick = 0;

	enum S1_t {PUSHED, RELEASED};

	static enum S1_t state = RELEASED;
	enum S1_t next_state;

	static uint8_t S1_Event = 0;

	if (MSP_GetTick() - lastTick >= pollingTime){
		lastTick = MSP_GetTick();

		uint8_t input = AUDI_S2_Read();

		switch(state){
		case PUSHED:
			if (input == 0){
				next_state = RELEASED;
				S1_Event = (S1_Event == 1) ? 0 : 1;
			}else{
				next_state = PUSHED;
			}
			break;

		case RELEASED:
			if (input == 0){
				next_state = RELEASED;
			}else{
				next_state = PUSHED;
			}
			break;
		}
		state = next_state;
	}
	return S1_Event;
}

uint8_t S3_Polling(void){
	static uint32_t lastTick = 0;

	enum S1_t {PUSHED, RELEASED};

	static enum S1_t state = RELEASED;
	enum S1_t next_state;

	static uint8_t S1_Event = 0;

	if (MSP_GetTick() - lastTick >= pollingTime){
		lastTick = MSP_GetTick();

		uint8_t input = AUDI_S3_Read();

		switch(state){
		case PUSHED:
			if (input == 0){
				next_state = RELEASED;
				S1_Event = (S1_Event == 1) ? 0 : 1;
			}else{
				next_state = PUSHED;
			}
			break;

		case RELEASED:
			if (input == 0){
				next_state = RELEASED;
			}else{
				next_state = PUSHED;
			}
			break;
		}
		state = next_state;
	}
	return S1_Event;
}

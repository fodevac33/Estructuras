/*
 * AUDI_Dx.c
 *
 *  Created on: Mar 23, 2023
 *      Author: felipe
 */

//LEDs

#include "AUDI_Dx.h"

//Pines LEDs Grupo1
#define G1D1_PIN  LL_GPIO_PIN_10
#define G1D1_GPIO GPIOC

#define G1D2_PIN  LL_GPIO_PIN_12
#define G1D2_GPIO GPIOC

#define G1D3_PIN  LL_GPIO_PIN_13
#define G1D3_GPIO GPIOA

#define G1D4_PIN  LL_GPIO_PIN_14
#define G1D4_GPIO GPIOA

#define G1D5_PIN  LL_GPIO_PIN_15
#define G1D5_GPIO GPIOA

#define G1D6_PIN  LL_GPIO_PIN_7
#define G1D6_GPIO GPIOB

#define G1D7_PIN  LL_GPIO_PIN_13
#define G1D7_GPIO GPIOC

#define G1D8_PIN  LL_GPIO_PIN_4
#define G1D8_GPIO GPIOC

//Pines LEDs Grupo2
#define G2D1_PIN  LL_GPIO_PIN_2
#define G2D1_GPIO GPIOC

#define G2D2_PIN  LL_GPIO_PIN_3
#define G2D2_GPIO GPIOC

#define G2D3_PIN  LL_GPIO_PIN_8
#define G2D3_GPIO GPIOC

#define G2D4_PIN  LL_GPIO_PIN_6
#define G2D4_GPIO GPIOC

#define G2D5_PIN  LL_GPIO_PIN_5
#define G2D5_GPIO GPIOC

#define G2D6_PIN  LL_GPIO_PIN_12
#define G2D6_GPIO GPIOA

#define G2D7_PIN  LL_GPIO_PIN_11
#define G2D7_GPIO GPIOA

#define G2D8_PIN  LL_GPIO_PIN_12
#define G2D8_GPIO GPIOB


#define BUZZER_PIN  LL_GPIO_PIN_3
#define BUZZER_GPIO GPIOA






void AUDI_Dx_Init(void){
	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);


	LL_GPIO_SetPinMode(G1D1_GPIO, G1D1_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G1D2_GPIO, G1D2_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G1D3_GPIO, G1D3_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G1D4_GPIO, G1D4_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G1D5_GPIO, G1D5_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G1D6_GPIO, G1D6_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G1D7_GPIO, G1D7_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G1D8_GPIO, G1D8_PIN, LL_GPIO_MODE_OUTPUT);

	LL_GPIO_SetPinMode(G2D1_GPIO, G2D1_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G2D2_GPIO, G2D2_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G2D3_GPIO, G2D3_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G2D4_GPIO, G2D4_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G2D5_GPIO, G2D5_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G2D6_GPIO, G2D6_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G2D7_GPIO, G2D7_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(G2D8_GPIO, G2D8_PIN, LL_GPIO_MODE_OUTPUT);

}

//Buzzer control
void AUDI_BUZZER_Init(void){
	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
	LL_GPIO_SetPinMode(BUZZER_GPIO, BUZZER_PIN, LL_GPIO_MODE_OUTPUT);
}

void AUDI_BUZZER_On(void){
	LL_GPIO_ResetOutputPin(BUZZER_GPIO, BUZZER_PIN);
}

void AUDI_BUZZER_Off(void){
	LL_GPIO_SetOutputPin(BUZZER_GPIO, BUZZER_PIN);
}
//LEd On
//Set Izquierdo de LEDs
void AUDI_G1D1_On(){
	LL_GPIO_ResetOutputPin(G1D1_GPIO, G1D1_PIN);
}

void AUDI_G1D2_On(){
	LL_GPIO_ResetOutputPin(G1D2_GPIO, G1D2_PIN);
}

void AUDI_G1D3_On(){
	LL_GPIO_ResetOutputPin(G1D3_GPIO, G1D3_PIN);
}

void AUDI_G1D4_On(){
	LL_GPIO_ResetOutputPin(G1D4_GPIO, G1D4_PIN);
}

void AUDI_G1D5_On(){
	LL_GPIO_ResetOutputPin(G1D5_GPIO, G1D5_PIN);
}

void AUDI_G1D6_On(){
	LL_GPIO_ResetOutputPin(G1D6_GPIO, G1D6_PIN);
}

void AUDI_G1D7_On(){
	LL_GPIO_ResetOutputPin(G1D7_GPIO, G1D7_PIN);
}

void AUDI_G1D8_On(){
	LL_GPIO_ResetOutputPin(G1D8_GPIO, G1D8_PIN);
}


//Set Derecho de LEDs
void AUDI_G2D1_On(){
	LL_GPIO_ResetOutputPin(G2D1_GPIO, G2D1_PIN);
}

void AUDI_G2D2_On(){
	LL_GPIO_ResetOutputPin(G2D2_GPIO, G2D2_PIN);
}

void AUDI_G2D3_On(){
	LL_GPIO_ResetOutputPin(G2D3_GPIO, G2D3_PIN);
}

void AUDI_G2D4_On(){
	LL_GPIO_ResetOutputPin(G2D4_GPIO, G2D4_PIN);
}

void AUDI_G2D5_On(){
	LL_GPIO_ResetOutputPin(G2D5_GPIO, G2D5_PIN);
}

void AUDI_G2D6_On(){
	LL_GPIO_ResetOutputPin(G2D6_GPIO, G2D6_PIN);
}

void AUDI_G2D7_On(){
	LL_GPIO_ResetOutputPin(G2D7_GPIO, G2D7_PIN);
}

void AUDI_G2D8_On(){
	LL_GPIO_ResetOutputPin(G2D8_GPIO, G2D8_PIN);
}


//LEd OFF
//Set Izquierdo de LEDs
void AUDI_G1D1_Off(){
	LL_GPIO_SetOutputPin(G1D1_GPIO, G1D1_PIN);
}

void AUDI_G1D2_Off(){
	LL_GPIO_SetOutputPin(G1D2_GPIO, G1D2_PIN);
}

void AUDI_G1D3_Off(){
	LL_GPIO_SetOutputPin(G1D3_GPIO, G1D3_PIN);
}

void AUDI_G1D4_Off(){
	LL_GPIO_SetOutputPin(G1D4_GPIO, G1D4_PIN);
}

void AUDI_G1D5_Off(){
	LL_GPIO_SetOutputPin(G1D5_GPIO, G1D5_PIN);
}

void AUDI_G1D6_Off(){
	LL_GPIO_SetOutputPin(G1D6_GPIO, G1D6_PIN);
}

void AUDI_G1D7_Off(){
	LL_GPIO_SetOutputPin(G1D7_GPIO, G1D7_PIN);
}

void AUDI_G1D8_Off(){
	LL_GPIO_SetOutputPin(G1D8_GPIO, G1D8_PIN);
}


//Set derecho de leds
void AUDI_G2D1_Off(){
	LL_GPIO_SetOutputPin(G2D1_GPIO, G2D1_PIN);
}

void AUDI_G2D2_Off(){
	LL_GPIO_SetOutputPin(G2D2_GPIO, G2D2_PIN);
}

void AUDI_G2D3_Off(){
	LL_GPIO_SetOutputPin(G2D3_GPIO, G2D3_PIN);
}

void AUDI_G2D4_Off(){
	LL_GPIO_SetOutputPin(G2D4_GPIO, G2D4_PIN);
}

void AUDI_G2D5_Off(){
	LL_GPIO_SetOutputPin(G2D5_GPIO, G2D5_PIN);
}

void AUDI_G2D6_Off(){
	LL_GPIO_SetOutputPin(G2D6_GPIO, G2D6_PIN);
}

void AUDI_G2D7_Off(){
	LL_GPIO_SetOutputPin(G2D7_GPIO, G2D7_PIN);
}

void AUDI_G2D8_Off(){
	LL_GPIO_SetOutputPin(G2D8_GPIO, G2D8_PIN);
}


void AUDI_Dx_AllOff(void){
	AUDI_G1D1_Off();
	AUDI_G1D2_Off();
	AUDI_G1D3_Off();
	AUDI_G1D4_Off();
	AUDI_G1D5_Off();
	AUDI_G1D6_Off();
	AUDI_G1D7_Off();
	AUDI_G1D8_Off();

	AUDI_G2D1_Off();
	AUDI_G2D2_Off();
	AUDI_G2D3_Off();
	AUDI_G2D4_Off();
	AUDI_G2D5_Off();
	AUDI_G2D6_Off();
	AUDI_G2D7_Off();
	AUDI_G2D8_Off();
}

void AUDI_Dx_AllOn(void){
	AUDI_G1D1_On();
	AUDI_G1D2_On();
	AUDI_G1D3_On();
	AUDI_G1D4_On();
	AUDI_G1D5_On();
	AUDI_G1D6_On();
	AUDI_G1D7_On();
	AUDI_G1D8_On();

	AUDI_G2D1_On();
	AUDI_G2D2_On();
	AUDI_G2D3_On();
	AUDI_G2D4_On();
	AUDI_G2D5_On();
	AUDI_G2D6_On();
	AUDI_G2D7_On();
	AUDI_G2D8_On();
}

//Toggles
void AUDI_G1D1_Toggle(){
	LL_GPIO_TogglePin(G1D1_GPIO, G1D1_PIN);
}

void AUDI_G1D2_Toggle(){
	LL_GPIO_TogglePin(G1D2_GPIO, G1D2_PIN);
}

void AUDI_G1D3_Toggle(){
	LL_GPIO_TogglePin(G1D3_GPIO, G1D3_PIN);
}

void AUDI_G1D4_Toggle(){
	LL_GPIO_TogglePin(G1D4_GPIO, G1D4_PIN);
}

void AUDI_G1D5_Toggle(){
	LL_GPIO_TogglePin(G1D5_GPIO, G1D5_PIN);
}

void AUDI_G1D6_Toggle(){
	LL_GPIO_TogglePin(G1D6_GPIO, G1D6_PIN);
}

void AUDI_G1D7_Toggle(){
	LL_GPIO_TogglePin(G1D7_GPIO, G1D7_PIN);
}

void AUDI_G1D8_Toggle(){
	LL_GPIO_TogglePin(G1D8_GPIO, G1D8_PIN);
}


//Grupo 2
void AUDI_G2D1_Toggle(){
	LL_GPIO_TogglePin(G2D1_GPIO, G2D1_PIN);
}

void AUDI_G2D2_Toggle(){
	LL_GPIO_TogglePin(G2D2_GPIO, G2D2_PIN);
}

void AUDI_G2D3_Toggle(){
	LL_GPIO_TogglePin(G2D3_GPIO, G2D3_PIN);
}

void AUDI_G2D4_Toggle(){
	LL_GPIO_TogglePin(G2D4_GPIO, G2D4_PIN);
}

void AUDI_G2D5_Toggle(){
	LL_GPIO_TogglePin(G2D5_GPIO, G2D5_PIN);
}

void AUDI_G2D6_Toggle(){
	LL_GPIO_TogglePin(G2D6_GPIO, G2D6_PIN);
}

void AUDI_G2D7_Toggle(){
	LL_GPIO_TogglePin(G2D7_GPIO, G2D7_PIN);
}

void AUDI_G2D8_Toggle(){
	LL_GPIO_TogglePin(G2D8_GPIO, G2D8_PIN);
}
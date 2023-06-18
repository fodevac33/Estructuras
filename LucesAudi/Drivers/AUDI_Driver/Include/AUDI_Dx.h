/*
 * AUDI_Dx.h
 *
 *  Created on: Mar 23, 2023
 *      Author: felipe
 */

#ifndef AUDI_DRIVER_INCLUDE_AUDI_DX_H_
#define AUDI_DRIVER_INCLUDE_AUDI_DX_H_

#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_gpio.h"

void AUDI_Dx_Init(void);

void AUDI_G1D1_On(void);
void AUDI_G1D2_On(void);
void AUDI_G1D3_On(void);
void AUDI_G1D4_On(void);
void AUDI_G1D5_On(void);
void AUDI_G1D6_On(void);
void AUDI_G1D7_On(void);
void AUDI_G1D8_On(void);

void AUDI_G1D1_Off(void);
void AUDI_G1D2_Off(void);
void AUDI_G1D3_Off(void);
void AUDI_G1D4_Off(void);
void AUDI_G1D5_Off(void);
void AUDI_G1D6_Off(void);
void AUDI_G1D7_Off(void);
void AUDI_G1D8_Off(void);

void AUDI_G2D1_On(void);
void AUDI_G2D2_On(void);
void AUDI_G2D3_On(void);
void AUDI_G2D4_On(void);
void AUDI_G2D5_On(void);
void AUDI_G2D6_On(void);
void AUDI_G2D7_On(void);
void AUDI_G2D8_On(void);

void AUDI_G2D1_Off(void);
void AUDI_G2D2_Off(void);
void AUDI_G2D3_Off(void);
void AUDI_G2D4_Off(void);
void AUDI_G2D5_Off(void);
void AUDI_G2D6_Off(void);
void AUDI_G2D7_Off(void);
void AUDI_G2D8_Off(void);

void AUDI_G1D1_Toggle(void);
void AUDI_G1D2_Toggle(void);
void AUDI_G1D3_Toggle(void);
void AUDI_G1D4_Toggle(void);
void AUDI_G1D5_Toggle(void);
void AUDI_G1D6_Toggle(void);
void AUDI_G1D7_Toggle(void);
void AUDI_G1D8_Toggle(void);

void AUDI_G2D1_Toggle(void);
void AUDI_G2D2_Toggle(void);
void AUDI_G2D3_Toggle(void);
void AUDI_G2D4_Toggle(void);
void AUDI_G2D5_Toggle(void);
void AUDI_G2D6_Toggle(void);
void AUDI_G2D7_Toggle(void);
void AUDI_G2D8_Toggle(void);


void AUDI_Dx_AllOff(void);
void AUDI_Dx_AllOn(void);

void AUDI_BUZZER_Init(void);
void AUDI_BUZZER_On(void);
void AUDI_BUZZER_Off(void);


#endif /* AUDI_DRIVER_INCLUDE_AUDI_DX_H_ */

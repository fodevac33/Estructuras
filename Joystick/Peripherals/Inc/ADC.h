/*
 * ADC.h
 *
 *  Created on: May 20, 2023
 *      Author: felipe
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"

void ADC_GPIO(ADC_HandleTypeDef* hadc);

void ADC_Init(void);

uint32_t Read_ADC(ADC_HandleTypeDef* hadc);

#endif /* INC_ADC_H_ */

/*
 * Joystick.h
 *
 *  Created on: May 25, 2023
 *      Author: felipe
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "main.h"


typedef struct {
	GPIO_TypeDef* X_Port;
	uint16_t X_Pin;
	uint32_t X_ADC_Channel;

	GPIO_TypeDef* Y_Port;
	uint16_t Y_Pin;
	uint32_t Y_ADC_Channel;

	GPIO_TypeDef* But_Port;
	uint16_t But_Pin;

	ADC_ChannelConfTypeDef* ChannelConf;
	ADC_HandleTypeDef* ADC_Handler;
} Joystick_Struct_t;


Joystick_Struct_t Joystick_Create(
	GPIO_TypeDef* x_port, uint16_t x_pin, uint32_t x_adc_channel,
	GPIO_TypeDef* y_port, uint16_t y_pin, uint32_t y_adc_channel,
	GPIO_TypeDef* but_port, uint16_t but_pin);


void Joystick_Read(Joystick_Struct_t* Joystick, int16_t* xy);

#endif /* INC_JOYSTICK_H_ */

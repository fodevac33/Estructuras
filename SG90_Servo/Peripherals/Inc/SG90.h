/*
 * SG90.h
 *
 *  Created on: May 23, 2023
 *      Author: felipe
 */

#ifndef INC_SG90_H_
#define INC_SG90_H_

#include "main.h"

#define SERVO_HANDLE TIM_HandleTypeDef


typedef struct {
	GPIO_TypeDef *SG90_GPIO;
	uint16_t SG90_PIN;
	TIM_TypeDef *TIM_Instance;
	uint32_t PWM_TIM_Channel;
	TIM_HandleTypeDef *TIM_Handle;
} SG90_Struct_t;


SG90_Struct_t Servo_Create(
		GPIO_TypeDef *sg90_gpio, uint16_t sg90_pin,
		TIM_TypeDef *tim_Instance, uint32_t pwm_channel,
		TIM_HandleTypeDef *Servo_TIM_Handle);

void Servo_Rotate(SG90_Struct_t *Servo, float angle);

#endif /* INC_SG90_H_ */

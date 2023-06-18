/*
 * PWM.h
 *
 *  Created on: May 22, 2023
 *      Author: felipe
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main.h"

void PWM_Gpio(void);

void PWM_Init(void);

void PWM_SetDutyCycle_CH1(uint8_t duty_cycle);

#endif /* INC_PWM_H_ */

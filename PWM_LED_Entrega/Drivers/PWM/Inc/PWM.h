/*
 * PWM.h
 *
 *  Created on: May 4, 2023
 *      Author: felipe
 */

#ifndef PWM_INC_PWM_H_
#define PWM_INC_PWM_H_

#include "main.h"

void AdcGrpRegularOverrunError_Callback(void);
void TimerCaptureCompare_Callback(void);
void Configure_TIMPWMOutput(void);
void Configure_DutyCycle(uint32_t OCMode);

#endif /* PWM_INC_PWM_H_ */

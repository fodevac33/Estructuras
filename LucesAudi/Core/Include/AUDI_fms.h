/*
 * AUDI_fms.h
 *
 *  Created on: Mar 23, 2023
 *      Author: felipe
 */

#ifndef INCLUDE_AUDI_FMS_H_
#define INCLUDE_AUDI_FMS_H_

#include "main.h"

#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_gpio.h"


void fms_LeftLightShow(void);
void fms_RightLightShow(void);
void fms_DualLightShow(void);


#endif /* INCLUDE_AUDI_FMS_H_ */

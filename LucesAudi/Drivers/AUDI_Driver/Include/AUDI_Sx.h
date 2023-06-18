/*
 * AUDI_Sx.h
 *
 *  Created on: Mar 23, 2023
 *      Author: felipe
 */

#ifndef AUDI_DRIVER_INCLUDE_AUDI_SX_H_
#define AUDI_DRIVER_INCLUDE_AUDI_SX_H_

#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_gpio.h"


void AUDI_Sx_Init(void);

uint8_t AUDI_S1_Read(void);
uint8_t AUDI_S2_Read(void);
uint8_t AUDI_S3_Read(void);

uint8_t S1_Polling(void);
uint8_t S2_Polling(void);
uint8_t S3_Polling(void);

#endif /* AUDI_DRIVER_INCLUDE_AUDI_SX_H_ */

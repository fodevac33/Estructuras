/*
 * MFS_Sx.h
 *
 *  Created on: Mar 17, 2023
 *      Author: felipe
 */

#ifndef MFS_DRIVER_INCLUDE_MFS_SX_H_
#define MFS_DRIVER_INCLUDE_MFS_SX_H_

#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_gpio.h"


void MFS_Sx_Init(void);


uint8_t MFS_S1_Read(void);
uint8_t MFS_S2_Read(void);
uint8_t MFS_S3_Read(void);


#endif /* MFS_DRIVER_INCLUDE_MFS_SX_H_ */

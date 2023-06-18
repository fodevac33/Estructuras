/*
 * MFS_Dx.h
 *
 *  Created on: Mar 17, 2023
 *      Author: felipe
 */

#ifndef MFS_DRIVER_INCLUDE_MFS_DX_H_
#define MFS_DRIVER_INCLUDE_MFS_DX_H_

#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_gpio.h"


void MFS_Dx_Init(void);


void MFS_D1_On(void);
void MFS_D2_On(void);
void MFS_D3_On(void);
void MFS_D4_On(void);


void MFS_D1_Off(void);
void MFS_D2_Off(void);
void MFS_D3_Off(void);
void MFS_D4_Off(void);


void MFS_D1_Toggle(void);
void MFS_D2_Toggle(void);
void MFS_D3_Toggle(void);
void MFS_D4_Toggle(void);


#endif /* MFS_DRIVER_INCLUDE_MFS_DX_H_ */

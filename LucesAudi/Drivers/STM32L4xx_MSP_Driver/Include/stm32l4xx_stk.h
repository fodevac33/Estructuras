/*
 * stm32l4xx_stk.h
 *
 *  Created on: Mar 10, 2023
 *      Author: gosorio
 */

#ifndef INCLUDE_STM32L4XX_STK_H_
#define INCLUDE_STM32L4XX_STK_H_
#include "stm32l4xx.h"


#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"


void MSP_Callback_SysTick_Handler(void);
uint32_t MSP_GetTick(void);
void MSP_Init1msTick(void);

#endif /* INCLUDE_STM32L4XX_STK_H_ */

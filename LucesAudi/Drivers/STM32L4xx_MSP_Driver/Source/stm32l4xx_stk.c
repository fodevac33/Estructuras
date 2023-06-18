/*
 * stm32l4xx_stk.c
 *
 *  Created on: Mar 10, 2023
 *      Author: gosorio
 */

#include "stm32l4xx_stk.h"

volatile uint32_t uwTick;


/**
 * @brief This function is called to increment a global variable "uwTick"
 *        used as application time base.
 * @note In the default implementation, this variable is incremented each 1ms
 *       in SysTick ISR.
 * @note This function is declared as __weak to be overwritten in case of other
 *      implementations in user file.
 * @retval None
 */
void MSP_Callback_SysTick_Handler(void)
{
	uwTick ++;
}
/**
 * @brief Provide a tick value in millisecond.
 * @note This function is declared as __weak to be overwritten in case of other
 *       implementations in user file.
 * @retval tick value
 */
uint32_t MSP_GetTick(void)
{
	return uwTick;
}

void MSP_Init1msTick(void){
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	LL_Init1msTick(4000000);
}

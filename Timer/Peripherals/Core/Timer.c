/*
 * Timer.c
 *
 *  Created on: May 20, 2023
 *      Author: felipe
 */

#include "Timer.h"


TIM_HandleTypeDef Tim3;

void Timer_Init(uint32_t period) {
	// Enable Clock
	__HAL_RCC_TIM3_CLK_ENABLE();

	Tim3.Instance = TIM3;
	Tim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	Tim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; //80 MHz
	Tim3.Init.Period = 8400 - 1;
	Tim3.Init.Prescaler = period - 1;
	Tim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	Tim3.Init.RepetitionCounter = 0;

	HAL_TIM_Base_Init(&Tim3);


	TIM_ClockConfigTypeDef TimClock = {0};
	TimClock.ClockSource = TIM_CLOCKSOURCE_INTERNAL;

	HAL_TIM_ConfigClockSource(&Tim3, &TimClock);


	TIM_MasterConfigTypeDef TimMaster = {0};
	TimMaster.MasterSlaveMode = TIM_SLAVEMODE_DISABLE;
	TimMaster.MasterOutputTrigger = TIM_TRGO_RESET;

	HAL_TIMEx_MasterConfigSynchronization(&Tim3, &TimMaster);

	HAL_NVIC_SetPriority(TIM3_IRQn, 5, 0);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);

}

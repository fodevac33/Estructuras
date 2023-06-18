/*
 * PWM.c
 *
 *  Created on: May 22, 2023
 *      Author: felipe
 */

#include "PWM.h"

TIM_HandleTypeDef Tim4;

void PWM_Gpio(void) {
	//PB6 -> CH1 TIM4
	GPIO_InitTypeDef GpioInit = {0};

	__HAL_RCC_GPIOB_CLK_ENABLE();

	GpioInit.Pin = GPIO_PIN_6;
	GpioInit.Mode = GPIO_MODE_AF_PP;
	GpioInit.Pull = GPIO_NOPULL;
	GpioInit.Speed = GPIO_SPEED_FREQ_LOW;
	GpioInit.Alternate = GPIO_AF2_TIM4;

	HAL_GPIO_Init(GPIOB, &GpioInit);
}

void PWM_Init(void) {
	PWM_Gpio();

	__HAL_RCC_TIM4_CLK_ENABLE();

	Tim4.Instance = TIM4;
	Tim4.Init.Prescaler = 80 -1;
	Tim4.Init.Period = 20000 - 1;
	Tim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	Tim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Tim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&Tim4);

	TIM_ClockConfigTypeDef sClock = {0};

	sClock.ClockSource = TIM_CLOCKSOURCE_INTERNAL;

	HAL_TIM_ConfigClockSource(&Tim4, &sClock);

	HAL_TIM_PWM_Init(&Tim4);

	TIM_OC_InitTypeDef Tim_OC = {0};

	Tim_OC.OCMode = TIM_OCMODE_PWM1;
	Tim_OC.Pulse = 0;
	Tim_OC.OCPolarity = TIM_OCPOLARITY_HIGH;
	Tim_OC.OCFastMode = TIM_OCFAST_DISABLE;

	HAL_TIM_PWM_ConfigChannel(&Tim4, &Tim_OC, TIM_CHANNEL_1);

}


void PWM_SetDutyCycle_CH1(uint8_t duty_cycle) {
	uint16_t ccr_value;

	if (duty_cycle > 100) {
		duty_cycle = 100;
	}

	ccr_value = (uint16_t)(__HAL_TIM_GET_AUTORELOAD(&Tim4) + 0.0f) * (duty_cycle/100.0f);

	__HAL_TIM_SET_COMPARE(&Tim4, TIM_CHANNEL_1, ccr_value);
}

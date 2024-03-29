/*
 * SG90.c
 *
 *  Created on: May 23, 2023
 *      Author: felipe
 */

#include "SG90.h"


static void SG90_Gpio(SG90_Struct_t *Servo) {
	GPIO_InitTypeDef GpioInit = {0};

	if (Servo->SG90_GPIO == GPIOA){
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}

	else if (Servo->SG90_GPIO == GPIOB){
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}

	else if (Servo->SG90_GPIO == GPIOC){
		__HAL_RCC_GPIOC_CLK_ENABLE();
	}

	GpioInit.Pin = Servo->SG90_PIN;
	GpioInit.Mode = GPIO_MODE_AF_PP;
	GpioInit.Pull = GPIO_NOPULL;
	GpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	if (Servo->TIM_Instance == TIM1) {
		GpioInit.Alternate = GPIO_AF2_TIM1;
	}

	else if (Servo->TIM_Instance == TIM2) {
		GpioInit.Alternate = GPIO_AF2_TIM2;
	}

	else if (Servo->TIM_Instance == TIM3) {
		GpioInit.Alternate = GPIO_AF2_TIM3;
	}

	else if (Servo->TIM_Instance == TIM4) {
		GpioInit.Alternate = GPIO_AF2_TIM4;
	}

	else if (Servo->TIM_Instance == TIM8) {
		GpioInit.Alternate = GPIO_AF3_TIM8;
	}


	HAL_GPIO_Init(Servo->SG90_GPIO, &GpioInit);
}


static void SG90_Init(SG90_Struct_t *Servo) {
	SG90_Gpio(Servo);

	if (Servo->TIM_Instance == TIM1) {
		__HAL_RCC_TIM1_CLK_ENABLE();
	}

	else if (Servo->TIM_Instance == TIM2) {
		__HAL_RCC_TIM2_CLK_ENABLE();
	}

	else if (Servo->TIM_Instance == TIM3) {
		__HAL_RCC_TIM3_CLK_ENABLE();
	}

	else if (Servo->TIM_Instance == TIM4) {
		__HAL_RCC_TIM4_CLK_ENABLE();
	}

	else if (Servo->TIM_Instance == TIM8) {
		__HAL_RCC_TIM8_CLK_ENABLE();
	}


	Servo->TIM_Handle->Instance = Servo->TIM_Instance;
	Servo->TIM_Handle->Init.Prescaler = 80 - 1;
	Servo->TIM_Handle->Init.Period = 20000 - 1;
	Servo->TIM_Handle->Init.CounterMode = TIM_COUNTERMODE_UP;
	Servo->TIM_Handle->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Servo->TIM_Handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(Servo->TIM_Handle);

	TIM_ClockConfigTypeDef sClock = {0};

	sClock.ClockSource = TIM_CLOCKSOURCE_INTERNAL;

	HAL_TIM_ConfigClockSource(Servo->TIM_Handle, &sClock);

	HAL_TIM_PWM_Init(Servo->TIM_Handle);

	TIM_OC_InitTypeDef Tim_OC = {0};

	Tim_OC.OCMode = TIM_OCMODE_PWM1;
	Tim_OC.Pulse = 0;
	Tim_OC.OCPolarity = TIM_OCPOLARITY_HIGH;
	Tim_OC.OCFastMode = TIM_OCFAST_DISABLE;

	HAL_TIM_PWM_ConfigChannel(Servo->TIM_Handle, &Tim_OC, Servo->PWM_TIM_Channel);

	HAL_TIM_PWM_Start(Servo->TIM_Handle, Servo->PWM_TIM_Channel);
}


static void Servo_SetDutyCyle(SG90_Struct_t *Servo, float duty_cycle) {
	uint16_t ccr_value;

	if (duty_cycle > 100.0f) {
		duty_cycle = 100.0f;
	}

	ccr_value = (uint16_t)(__HAL_TIM_GET_AUTORELOAD(Servo->TIM_Handle) + 0.0f) * (duty_cycle/100.0f);

	__HAL_TIM_SET_COMPARE(Servo->TIM_Handle, Servo->PWM_TIM_Channel, ccr_value);
}


SG90_Struct_t Servo_Create(
	GPIO_TypeDef *sg90_gpio, uint16_t sg90_pin,
	TIM_TypeDef *tim_Instance, uint32_t pwm_channel,
	TIM_HandleTypeDef *Servo_TIM_Handle
)
{
	SG90_Struct_t Servo;

	Servo.SG90_GPIO = sg90_gpio;
	Servo.SG90_PIN = sg90_pin;
	Servo.TIM_Instance = tim_Instance;
	Servo.PWM_TIM_Channel = pwm_channel;
	Servo.TIM_Handle = Servo_TIM_Handle;

	SG90_Init(&Servo);

	return Servo;
}


void Servo_Rotate(SG90_Struct_t *Servo, float angle) {
	float converted_cycle = (angle / 36.0) + 5; //Angles from 0 to 180 get mapped to duty cycles from 5 to 10

	Servo_SetDutyCyle(Servo, converted_cycle);
}

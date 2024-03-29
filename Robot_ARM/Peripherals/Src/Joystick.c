/*
 * Joystick.c
 *
 *  Created on: May 25, 2023
 *      Author: felipe
 */

#include "Joystick.h"


ADC_ChannelConfTypeDef channel_conf;
ADC_HandleTypeDef adc_handler;


static void Joystick_Button_Interrupt_Init(GPIO_TypeDef* Port, uint16_t Pin) {
	GPIO_InitTypeDef gpioInit = {0};

	if (Port == GPIOA) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}

	else if (Port == GPIOB) {
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}

	else if (Port == GPIOC) {
		__HAL_RCC_GPIOC_CLK_ENABLE();
	}

	gpioInit.Pin = Pin;
	gpioInit.Mode = GPIO_MODE_IT_RISING;  //Sets Interrupt on rising edge
	gpioInit.Pull = GPIO_PULLDOWN;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(Port, &gpioInit);

	//ENABLE INTERRUPT
	NVIC_SetPriority(EXTI9_5_IRQn, 5);  //Sets priority of the interrupt to 5

	NVIC_EnableIRQ(EXTI9_5_IRQn);
}


static void Joystick_Gpio_XY(GPIO_TypeDef* Port, uint16_t Pin) {
	//Intended for analog pins A0 - A5
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	if (Port == GPIOA) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}

	else if (Port == GPIOB) {
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}

	else if (Port == GPIOC) {
		__HAL_RCC_GPIOC_CLK_ENABLE();
	}

	GPIO_InitStruct.Pin = Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG_ADC_CONTROL;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(Port, &GPIO_InitStruct);
}


static void Joystick_ClkConfig() {
	RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
	PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
	PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSI;
	PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
	PeriphClkInit.PLLSAI1.PLLSAI1N = 8;
	PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
	PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
	PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
	PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK;

	HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

	__HAL_RCC_ADC_CLK_ENABLE();
}


static void Joystick_Init(Joystick_Struct_t* Joystick) {
	ADC_MultiModeTypeDef multimode = {0};

	/** Common config
	 */
	Joystick->ADC_Handler->Instance = ADC1;
	Joystick->ADC_Handler->Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	Joystick->ADC_Handler->Init.Resolution = ADC_RESOLUTION_12B;
	Joystick->ADC_Handler->Init.DataAlign = ADC_DATAALIGN_RIGHT;
	Joystick->ADC_Handler->Init.ScanConvMode = ADC_SCAN_DISABLE;
	Joystick->ADC_Handler->Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	Joystick->ADC_Handler->Init.LowPowerAutoWait = DISABLE;
	Joystick->ADC_Handler->Init.ContinuousConvMode = DISABLE;
	Joystick->ADC_Handler->Init.NbrOfConversion = 1;
	Joystick->ADC_Handler->Init.DiscontinuousConvMode = DISABLE;
	Joystick->ADC_Handler->Init.ExternalTrigConv = ADC_SOFTWARE_START;
	Joystick->ADC_Handler->Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	Joystick->ADC_Handler->Init.DMAContinuousRequests = DISABLE;
	Joystick->ADC_Handler->Init.Overrun = ADC_OVR_DATA_PRESERVED;
	Joystick->ADC_Handler->Init.OversamplingMode = DISABLE;

	HAL_ADC_Init(Joystick->ADC_Handler);

	multimode.Mode = ADC_MODE_INDEPENDENT;

	HAL_ADCEx_MultiModeConfigChannel(Joystick->ADC_Handler, &multimode);


	Joystick->ChannelConf->Rank = ADC_REGULAR_RANK_1;
	Joystick->ChannelConf->SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
	Joystick->ChannelConf->SingleDiff = ADC_SINGLE_ENDED;
	Joystick->ChannelConf->OffsetNumber = ADC_OFFSET_NONE;
	Joystick->ChannelConf->Offset = 0;

	HAL_ADC_ConfigChannel(Joystick->ADC_Handler, Joystick->ChannelConf);

	Joystick_ClkConfig();

	Joystick_Gpio_XY(Joystick->X_Port, Joystick->X_Pin);
	Joystick_Gpio_XY(Joystick->Y_Port, Joystick->Y_Pin);

	Joystick_Button_Interrupt_Init(Joystick->But_Port, Joystick->But_Pin);

}


Joystick_Struct_t Joystick_Create(
	GPIO_TypeDef* x_port, uint16_t x_pin, uint32_t x_adc_channel,
	GPIO_TypeDef* y_port, uint16_t y_pin, uint32_t y_adc_channel,
	GPIO_TypeDef* but_port, uint16_t but_pin
)
{
	Joystick_Struct_t Joystick;

	Joystick.X_Port = x_port;
	Joystick.X_Pin = x_pin;
	Joystick.Y_Port = y_port;
	Joystick.Y_Pin = y_pin;
	Joystick.But_Port = but_port;
	Joystick.But_Pin = but_pin;
	Joystick.X_ADC_Channel = x_adc_channel;
	Joystick.Y_ADC_Channel = y_adc_channel;
	Joystick.ChannelConf = &channel_conf;
	Joystick.ADC_Handler = &adc_handler;

	Joystick_Init(&Joystick);

	return Joystick;
}


static int16_t ADC_To_Joystic(uint32_t adcValue) {
	return (int16_t)((90 / pow(4095, 2)) * pow(adcValue, 2) - 45);
}


void Joystick_Read(Joystick_Struct_t* Joystick, int16_t* xy) {

	//Configure and read from channel X
	Joystick->ChannelConf->Channel = Joystick->X_ADC_Channel;
	HAL_ADC_ConfigChannel(Joystick->ADC_Handler, Joystick->ChannelConf);

    HAL_ADC_Start(Joystick->ADC_Handler);
    HAL_ADC_PollForConversion(Joystick->ADC_Handler, 100);

    xy[0] = ADC_To_Joystic(HAL_ADC_GetValue(Joystick->ADC_Handler));

	//Configure and read from channel Y
	Joystick->ChannelConf->Channel = Joystick->Y_ADC_Channel;
	HAL_ADC_ConfigChannel(Joystick->ADC_Handler, Joystick->ChannelConf);

    HAL_ADC_Start(Joystick->ADC_Handler);
    HAL_ADC_PollForConversion(Joystick->ADC_Handler, 100);

    xy[1] = ADC_To_Joystic(HAL_ADC_GetValue(Joystick->ADC_Handler));
}



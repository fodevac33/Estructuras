/*
 * ADC.c
 *
 *  Created on: May 20, 2023
 *      Author: felipe
 */
#include "ADC.h"


ADC_HandleTypeDef ADC1Handler;

void ADC_GPIO(ADC_HandleTypeDef* hadc) {
	//PA0 -> ADC -> GPIOA
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
	if(hadc->Instance==ADC1)
	{
		/* USER CODE BEGIN ADC1_MspInit 0 */

		/* USER CODE END ADC1_MspInit 0 */

		/** Initializes the peripherals clock
		 */
		PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
		PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
		PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSI;
		PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
		PeriphClkInit.PLLSAI1.PLLSAI1N = 8;
		PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
		PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
		PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
		PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK;
		if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
		{
			Error_Handler();
		}

		/* Peripheral clock enable */
		__HAL_RCC_ADC_CLK_ENABLE();

		__HAL_RCC_GPIOA_CLK_ENABLE();
		/**ADC1 GPIO Configuration
	    PA0     ------> ADC1_IN5
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_MODE_ANALOG_ADC_CONTROL;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/* USER CODE BEGIN ADC1_MspInit 1 */

		/* USER CODE END ADC1_MspInit 1 */
	}
}



void ADC_Init(void) {
	ADC_MultiModeTypeDef multimode = {0};
	ADC_ChannelConfTypeDef sConfig = {0};

	/** Common config
	 */
	ADC1Handler.Instance = ADC1;
	ADC1Handler.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	ADC1Handler.Init.Resolution = ADC_RESOLUTION_12B;
	ADC1Handler.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	ADC1Handler.Init.ScanConvMode = ADC_SCAN_DISABLE;
	ADC1Handler.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	ADC1Handler.Init.LowPowerAutoWait = DISABLE;
	ADC1Handler.Init.ContinuousConvMode = DISABLE;
	ADC1Handler.Init.NbrOfConversion = 1;
	ADC1Handler.Init.DiscontinuousConvMode = DISABLE;
	ADC1Handler.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	ADC1Handler.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	ADC1Handler.Init.DMAContinuousRequests = DISABLE;
	ADC1Handler.Init.Overrun = ADC_OVR_DATA_PRESERVED;
	ADC1Handler.Init.OversamplingMode = DISABLE;
	if (HAL_ADC_Init(&ADC1Handler) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure the ADC multi-mode
	 */
	multimode.Mode = ADC_MODE_INDEPENDENT;
	if (HAL_ADCEx_MultiModeConfigChannel(&ADC1Handler, &multimode) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Regular Channel
	 */
	sConfig.Channel = ADC_CHANNEL_5;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Offset = 0;
	if (HAL_ADC_ConfigChannel(&ADC1Handler, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}

	ADC_GPIO(&ADC1Handler);
}


uint32_t Read_ADC(ADC_HandleTypeDef* hadc) {
    HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, 100);
    uint32_t adcValue = HAL_ADC_GetValue(hadc);
    return adcValue;
}












/*
 * SysConfig.c
 *
 *  Created on: May 19, 2023
 *      Author: felipe
 */

#include "SysConfig.h"


bool SysConfigClock(void){
	RCC_OscInitTypeDef oscInit = {0};  //Init oscilator struct
	RCC_ClkInitTypeDef clkInit = {0};  //Init Clock struct

	oscInit.OscillatorType = RCC_OSCILLATORTYPE_HSE; //USes external crystal
	oscInit.HSEState = RCC_HSE_ON;
	oscInit.PLL.PLLState = RCC_PLL_ON;
	oscInit.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	oscInit.PLL.PLLM = 1;
	oscInit.PLL.PLLN = 20;
	oscInit.PLL.PLLP = RCC_PLLP_DIV7;
	oscInit.PLL.PLLQ = RCC_PLLQ_DIV2;
	oscInit.PLL.PLLR = RCC_PLLR_DIV2;

	if (HAL_RCC_OscConfig(&oscInit) != HAL_OK) {
		return false;
	}

	clkInit.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_HCLK;
	clkInit.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clkInit.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clkInit.APB2CLKDivider = RCC_HCLK_DIV1;
	clkInit.APB1CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&clkInit, FLASH_LATENCY_4) != HAL_OK ) {
		return false;
	}

	return true;
}


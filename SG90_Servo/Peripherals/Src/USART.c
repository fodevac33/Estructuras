/*
 * USART.h
 *
 *  Created on: May 22, 2023
 *      Author: felipe
 */

#include "USART.h"


UART_HandleTypeDef USART2_I;

void USART_Gpio(void){
	// PA2 -> TX & PA3 -> RX

	GPIO_InitTypeDef GpioInit = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GpioInit.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	GpioInit.Mode = GPIO_MODE_AF_PP;
	GpioInit.Pull = GPIO_NOPULL;
	GpioInit.Speed = GPIO_SPEED_FREQ_HIGH;
	GpioInit.Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(GPIOA, &GpioInit);

}

void USART_Init(uint32_t baud){
	USART_Gpio();

	__HAL_RCC_USART2_CLK_ENABLE();

	USART2_I.Instance = USART2;
	USART2_I.Init.BaudRate = baud;
	USART2_I.Init.WordLength = UART_WORDLENGTH_8B;
	USART2_I.Init.StopBits = UART_STOPBITS_1;
	USART2_I.Init.Parity = UART_PARITY_NONE;
	USART2_I.Init.Mode = UART_MODE_TX_RX;
	USART2_I.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	USART2_I.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&USART2_I);

}

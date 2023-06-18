/*
 * printf_redirect.c
 *
 *  Created on: May 22, 2023
 *      Author: felipe
 */
#include "USART.h"

extern UART_HandleTypeDef USART2_I;

int __io_putchar(int ch);
int _write(int file, char *ptr, int len);


int __io_putchar(int ch) {
	uint8_t c[1];
	c[0] = ch & 0x00FF;
	HAL_UART_Transmit(&USART2_I, &c[0], 1, 100);
	return ch;
}


int _write(int file, char *ptr, int len) {
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		__io_putchar(*ptr++);
	}

	return len;
}

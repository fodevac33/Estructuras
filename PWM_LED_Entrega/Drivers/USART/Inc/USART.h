/*
 * USART.h
 *
 *  Created on: May 8, 2023
 *      Author: felipe
 */

#ifndef USART_INC_USART_H_
#define USART_INC_USART_H_

#include "main.h"

#define APP_ERROR_NONE    0
#define APP_ERROR_TIMEOUT 1

/* Define used to enable time-out management*/
#define USE_TIMEOUT       0

/* Define used to enable Virtual Com Port use :
     USE_VCP_CONNECTION == 0
       USART1 instance is used. (TX on PA.09, RX on PA.10)
       (requires wiring USART1 TX/Rx Pins to PC connection (could be achieved thanks to a USB to UART adapter)
     USE_VCP_CONNECTION == 1
       USART2 instance is used. (TX on PA.02, RX on PA.03)
       (please ensure that USART communication between the target MCU and ST-LINK MCU is properly enabled
       on HW board in order to support Virtual Com Port)
*/
#define USE_VCP_CONNECTION       1

/* Private definitions covering GPIO clock and USART pins
   depending on selected USART instance. */
#if (USE_VCP_CONNECTION == 0)

/* USART1 instance is used. (TX on PA.09, RX on PA.10)
   (requires wiring USART1 TX/Rx Pins to USB to UART adapter) */
#define USARTx_INSTANCE               USART1
#define USARTx_CLK_ENABLE()           LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1)
#define USARTx_CLK_SOURCE()           LL_RCC_SetUSARTClockSource(LL_RCC_USART1_CLKSOURCE_PCLK2)

#define USARTx_GPIO_CLK_ENABLE()      LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)   /* Enable the peripheral clock of GPIOA */
#define USARTx_TX_PIN                 LL_GPIO_PIN_9
#define USARTx_TX_GPIO_PORT           GPIOA
#define USARTx_SET_TX_GPIO_AF()       LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_9, LL_GPIO_AF_7)
#define USARTx_RX_PIN                 LL_GPIO_PIN_10
#define USARTx_RX_GPIO_PORT           GPIOA
#define USARTx_SET_RX_GPIO_AF()       LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_10, LL_GPIO_AF_7)

#else

/* USART2 instance is used. (TX on PA.02, RX on PA.03)
   (please ensure that USART communication between the target MCU and ST-LINK MCU is properly enabled
    on HW board in order to support Virtual Com Port) */
#define USARTx_INSTANCE               USART2
#define USARTx_CLK_ENABLE()           LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2)
#define USARTx_CLK_SOURCE()           LL_RCC_SetUSARTClockSource(LL_RCC_USART2_CLKSOURCE_PCLK1)

#define USARTx_GPIO_CLK_ENABLE()      LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)   /* Enable the peripheral clock of GPIOA */
#define USARTx_TX_PIN                 LL_GPIO_PIN_2
#define USARTx_TX_GPIO_PORT           GPIOA
#define USARTx_SET_TX_GPIO_AF()       LL_GPIO_SetAFPin_0_7(GPIOA, LL_GPIO_PIN_2, LL_GPIO_AF_7)
#define USARTx_RX_PIN                 LL_GPIO_PIN_3
#define USARTx_RX_GPIO_PORT           GPIOA
#define USARTx_SET_RX_GPIO_AF()       LL_GPIO_SetAFPin_0_7(GPIOA, LL_GPIO_PIN_3, LL_GPIO_AF_7)

#endif /* (USE_VCP_CONNECTION == 0) */

void Configure_USART(void);
void BufferTransfer(void);


#endif /* USART_INC_USART_H_ */

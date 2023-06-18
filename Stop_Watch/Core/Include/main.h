/*
 * main.h
 *
 *  Created on: Nov 2, 2022
 *      Author: gosor
 */

#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_


#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_gpio.h"

#include "systick.h"
#include "mf_shield.h"
#include "keypad.h"


/* ==============   BOARD SPECIFIC CONFIGURATION CODE BEGIN    ============== */
/**
 * @brief LED2 - Nucleo 64
 */

#define LD2_PIN                           LL_GPIO_PIN_5
#define LD2_GPIO_PORT                     GPIOA
#define LD2_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)





// Finite State Machines
void FSM_LD2_Blink(void);

// SysTick Functions
void SysTick_Callback(void);
uint32_t Get_Tick(void);


//Display



#endif /* INCLUDE_MAIN_H_ */

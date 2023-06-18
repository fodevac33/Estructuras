/**
  ******************************************************************************
  * @file    Examples_LL/ADC/ADC_ContinuousConversion_TriggerSW/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_rcc.h"
#include "stm32l4xx_ll_pwr.h"
#include "stm32l4xx_ll_system.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_cortex.h"
#include "stm32l4xx_ll_gpio.h"
#include "stm32l4xx_ll_exti.h"
#include "stm32l4xx_ll_adc.h"
#include "stm32l4xx_ll_tim.h"
#include "mf_shield.h"
#include "systick.h"
#include "ADC.h"
#include "PWM.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"


#endif /* USE_FULL_ASSERT */

#define POTENTIOMETER_GPIO GPIOA
#define POTENTIOMETER_PIN LL_GPIO_PIN_0
#define POTENTIOMETER_CLOCK LL_AHB2_GRP1_PERIPH_GPIOA

#define LED_GPIO GPIOA
#define LED_PIN LL_GPIO_PIN_5
#define LED_CLOCK LL_AHB2_GRP1_PERIPH_GPIOA


// SysTick Functions
void SysTick_Callback(void);
uint32_t Get_Tick(void);


#endif /* __MAIN_H */


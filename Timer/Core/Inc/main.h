/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "SysConfig.h"
#include "GPIO.h"
#include "INTERRUPTS.h"
#include "LCD.h"
#include "Timer.h"


/* Private defines -----------------------------------------------------------*/
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB


// LCD ports
#define D4_Pin GPIO_PIN_1
#define D4_Port GPIOB
#define D5_Pin GPIO_PIN_15
#define D5_Port GPIOB
#define D6_Pin GPIO_PIN_14
#define D6_Port GPIOB
#define D7_Pin GPIO_PIN_13
#define D7_Port GPIOB
#define RS_Pin GPIO_PIN_12
#define RS_Port GPIOB
#define E_Pin GPIO_PIN_11
#define E_Port GPIOB

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

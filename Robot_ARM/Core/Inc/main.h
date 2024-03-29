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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "SysConfig.h"
#include "LCD.h"
#include "GPIO.h"
#include "Joystick.h"
#include "SG90.h"
#include "USART.h"
/* USER CODE END Includes */


/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

// LCD pins and ports
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

//Joystick
#define JOYSTICK_X_Port GPIOA
#define JOYSTICK_X_Pin GPIO_PIN_0
#define JOYSTICK_X_ADC_Channel ADC_CHANNEL_5

#define JOYSTICK_Y_Port GPIOA
#define JOYSTICK_Y_Pin GPIO_PIN_1
#define JOYSTICK_Y_ADC_Channel ADC_CHANNEL_6

#define JOYSTICK_BUTTON_Port GPIOA
#define JOYSTICK_BUTTON_Pin GPIO_PIN_8

//Servos
#define SERVO_BASE_Port GPIOC
#define SERVO_BASE_Pin GPIO_PIN_7
#define SERVO_BASE_TIM_INSTANCE TIM8
#define SERVO_BASE_PWM_CHANNEL TIM_CHANNEL_2

#define SERVO_JOINT_Port GPIOB
#define SERVO_JOINT_Pin GPIO_PIN_6
#define SERVO_JOINT_TIM_INSTANCE TIM4
#define SERVO_JOINT_PWM_CHANNEL TIM_CHANNEL_1

#define SERVO_CLAW_Port GPIOA
#define SERVO_CLAW_Pin GPIO_PIN_7
#define SERVO_CLAW_TIM_INSTANCE TIM3
#define SERVO_CLAW_PWM_CHANNEL TIM_CHANNEL_2

//Mode Change (Blue Button)
#define MODE_CHANGE_Port GPIOC
#define MODE_CHANGE_Pin GPIO_PIN_13

//Interrupts
#define Mode_Change_IRQ_Handler EXTI15_10_IRQHandler
#define Joystick_Button_IRQ_Handler EXTI9_5_IRQHandler
#define Command_Recieved_Handler USART2_IRQHandler
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

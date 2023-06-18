/*
 * GPIO.h
 *
 *  Created on: May 19, 2023
 *      Author: felipe
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

//LED
typedef enum {
	LOW,
	HIGH
} GPIO_State;

void GPIO_Led_Init(void);

void GPIO_Led_Write(GPIO_State state);

void GPIO_Led_Toggle(void);


//BUTTON
void GPIO_Button_Init(void);

GPIO_State GPIO_Button_Read(void);


#endif /* INC_GPIO_H_ */

/*
 * ROBOT.h
 *
 *  Created on: May 28, 2023
 *      Author: felipe
 */

#ifndef INC_ROBOT_H_
#define INC_ROBOT_H_

#include "main.h"

typedef enum {
	MANUAL,
	SERIAL
} Robot_Mode_t;

typedef enum {
	AWAITING,
	RECIEVED
} Serial_Status_t;

typedef enum {
	CMD_SUCCESS,
	CMD_FAILURE
}Cmd_Process_Result_t;

void Mode_Change_Interrupt_Init(void);

void Robot_Move(SG90_Struct_t* Robot[], int16_t* pos, uint32_t button);

void Robot_Neutral(SG90_Struct_t* Robot[]);

Cmd_Process_Result_t Process_Command(SG90_Struct_t* Robot[], uint8_t* input, int16_t* pos, uint32_t but);
#endif /* INC_ROBOT_H_ */

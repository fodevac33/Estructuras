/*
 * ROBOT.c
 *
 *  Created on: May 28, 2023
 *      Author: felipe
 */

#include "ROBOT.h"


void Mode_Change_Interrupt_Init() {
	GPIO_InitTypeDef gpioInit = {0};

	__HAL_RCC_GPIOC_CLK_ENABLE();

	gpioInit.Pin = MODE_CHANGE_Pin;
	gpioInit.Mode = GPIO_MODE_IT_RISING;
	gpioInit.Pull = GPIO_PULLDOWN;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(MODE_CHANGE_Port, &gpioInit);

	//ENABLE INTERRUPT
	NVIC_SetPriority(EXTI15_10_IRQn, 5);

	NVIC_EnableIRQ(EXTI15_10_IRQn);
}


static float Joystick_To_Servo(int16_t val) {
    return (val + 45.0f) * 180.0f / 100.0f;
}


void Robot_Move(SG90_Struct_t* Robot[], int16_t* pos, uint32_t button) {
	float xy[2] = {-Joystick_To_Servo(pos[0]), Joystick_To_Servo(pos[1])};

	Servo_Rotate(Robot[0], xy[0]);
	Servo_Rotate(Robot[1], xy[1]);

	Servo_Rotate(Robot[2], button == 0 ? 0 : 180);
}


void Robot_Neutral(SG90_Struct_t* Robot[]) {
	Servo_Rotate(Robot[0], -Joystick_To_Servo(0));
	Servo_Rotate(Robot[1], Joystick_To_Servo(0));

	Servo_Rotate(Robot[2], 0);
}

Cmd_Process_Result_t Process_Command(SG90_Struct_t* Robot[], uint8_t* input, int16_t* pos, uint32_t but) {
    uint8_t command[5];
    sscanf((const char*)input, "%4s", (char*)command);

    if (strcmp((const char*)command, "mov") == 0) {
        uint8_t target[6];
        sscanf((const char*)input, "%*s %5s", (char*)target);

        if (strcmp((const char*)target, "base") == 0) {
            int number;
            int matches = sscanf((const char*)input, "%*s %*s %d", &number);

            if (matches == 1) {
                pos[0] = number;
                return CMD_SUCCESS;
            } else {
                printf("Invalid number for mov base\n");
                return CMD_FAILURE;
            }
        }

        else if (strcmp((const char*)target, "joint") == 0) {
            int number;
            int matches = sscanf((const char*)input, "%*s %*s %d", &number);

            if (matches == 1) {
            	pos[1] = number;
            	return CMD_SUCCESS;
            } else {
                printf("Invalid number for mov joint\n");
                return CMD_FAILURE;
            }
        }

        else {
            printf("Invalid target for mov\n");
            return CMD_FAILURE;
        }
    }

    else if (strcmp((const char*)command, "claw") == 0) {
        uint8_t action[6];
        sscanf((const char*)input, "%*s %5s", (char*)action);

        if (strcmp((const char*)action, "open") == 0) {
        	but = 0;
        	Robot_Move(Robot, pos, but);
        	return CMD_SUCCESS;
        }
        else if (strcmp((const char*)action, "close") == 0) {
        	but = 1;
        	Robot_Move(Robot, pos, but);
        	return CMD_SUCCESS;
        }
        else {
            printf("Invalid action for claw\n");
            return CMD_FAILURE;
        }
    }

    else if (strcmp((const char*)command, "reset") == 0) {
        printf("Command: reset\n");
        return CMD_SUCCESS;
    }
    else {
        printf("Invalid command\n");
        return CMD_FAILURE;
    }
}


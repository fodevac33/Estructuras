/*
 * LCD.c
 *
 *  Created on: May 19, 2023
 *      Author: felipe
 */

#include "LCD.h"


static void LCD_Command(LCD_Struct_t *LCD_1602, char cmd){
	char command = 0;
	//RS has to be 0 before sending any command
	HAL_GPIO_WritePin(LCD_1602->RS_port, LCD_1602->RS_pin, GPIO_PIN_RESET);


	// Sending packets of 4 bits (get first 4 bits and set the last 4 to 0)
	command = (cmd>>4) & 0x0F;

	for (uint8_t i = 0; i < 4; i++){
		HAL_GPIO_WritePin(LCD_1602->dataport[i], LCD_1602->datapin[i], (command>>i) & 0x01);
		/*
		Destructures commands into respective pins

		Example: Sent command -> 0011

		i = 0 ->  0011 >> i = 0011
		0011 & 0001 = 0001
		First pint receives a 1

		i = 1 -> 0011 >> i = 0001
		0001 & 0001 = 0001
		Second pin receives a 1

		i = 2 -> 0011 >> i = 0000
		0000 & 0001 = 0000
		Third pin receives a 0

		And so on...
		*/
	}

	// At the end of every command Enable has to be on for 1ms and then be turned off
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_RESET);

	//Repeats process for the last 4 bits

	command = cmd & 0x0F;

	for (uint8_t i = 0; i < 4; i++){
		HAL_GPIO_WritePin(LCD_1602->dataport[i], LCD_1602->datapin[i], (command>>i) & 0x01);
	}

	// At the end of every command Enable has to be on for 1ms and then be turned off
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_RESET);
}


static void LCD_Init(LCD_Struct_t *LCD_1602) {
	GPIO_InitTypeDef gpioInit = {0};

	gpioInit.Pin = LCD_1602->datapin[0] | LCD_1602->datapin[1] |
				   LCD_1602->datapin[2] | LCD_1602->datapin[3] |
				   LCD_1602->RS_pin     | LCD_1602->E_pin;
	gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
	gpioInit.Pull = GPIO_NOPULL;
	gpioInit.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(LCD_1602->dataport[0], &gpioInit);

	//Execute LCD initialization sequence
	HAL_Delay(100);
	LCD_Command(LCD_1602, 0x30);
	HAL_Delay(5);
	LCD_Command(LCD_1602, 0x30);
	HAL_Delay(1);
	LCD_Command(LCD_1602, 0x32);
	LCD_Command(LCD_1602, 0x28);  //2 rows of 5x8 characters
	LCD_Command(LCD_1602, 0x0C);  //Enable display, no cursor, no cursor blinking
	LCD_Command(LCD_1602, 0x01);  //Clears screen
	LCD_Command(LCD_1602, 0x06);  //Increment DDRAM
}



void LCD_Character(LCD_Struct_t *LCD_1602, char data) {
	char dat = 0;
	//RS has to be 1 before writing a character
	HAL_GPIO_WritePin(LCD_1602->RS_port, LCD_1602->RS_pin, GPIO_PIN_SET);


	// Sending packets of 4 bits (get first 4 bits and set the last 4 to 0)
	dat = (data>>4) & 0x0F;

	for (uint8_t i = 0; i < 4; i++){
		HAL_GPIO_WritePin(LCD_1602->dataport[i], LCD_1602->datapin[i], (dat>>i) & 0x01);
	}

	// At the end of every command Enable has to be on for 1ms and then be turned off
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_RESET);

	//Repeats process for the last 4 bits

	dat = data & 0x0F;

	for (uint8_t i = 0; i < 4; i++){
		HAL_GPIO_WritePin(LCD_1602->dataport[i], LCD_1602->datapin[i], (dat>>i) & 0x01);
	}

	// At the end of every command Enable has to be on for 1ms and then be turned off
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_1602->E_port, LCD_1602->E_pin, GPIO_PIN_RESET);
}

//Ensures the string takes up all of the line
static char *LCD_PadString(const char *str) {
    static char padded_str[17];
    uint8_t length = strlen(str);
    strcpy(padded_str, str);
    if (length < 16) {
        for (uint8_t i = length; i < 16; i++) {
            padded_str[i] = ' ';
        }
        padded_str[16] = '\0';
    }
    return padded_str;
}

//Writes a string into the current cursor position
void LCD_String(LCD_Struct_t *LCD_1602, char *string) {
	char *padded_str = LCD_PadString(string);

	for (uint8_t i = 0; i < strlen(padded_str); i++) {
		LCD_Character(LCD_1602, padded_str[i]);
	}
}

//Sets the cursor in position (x, y)
void LCD_YX(LCD_Struct_t *LCD_1602, char x, char y) {
	if (x > 0) {
		LCD_Command(LCD_1602, 0xC0 + y);
	}
	else {
		LCD_Command(LCD_1602, 0x80 + y);
	}
}


void uint8_to_char(uint8_t* uint_array, char* char_array, uint8_t size) {
    for (uint8_t i = 0; i < size; i++) {
        char_array[i] = (char)uint_array[i];
    }
}


LCD_Struct_t LCD_Create(
	LCD_PortType port[], LCD_PinType pin[],
	LCD_PortType rs_port, LCD_PinType rs_pin,
	LCD_PortType e_port, LCD_PinType e_pin
)
{
	LCD_Struct_t LCD_1602;

	LCD_1602.datapin = pin;
	LCD_1602.dataport = port;

	LCD_1602.RS_pin = rs_pin;
	LCD_1602.RS_port = rs_port;

	LCD_1602.E_pin = e_pin;
	LCD_1602.E_port = e_port;

	LCD_Init(&LCD_1602);

	return LCD_1602;
}













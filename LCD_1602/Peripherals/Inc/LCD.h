/*
 * LCD.h
 *
 *  Created on: May 19, 2023
 *      Author: felipe
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"

#define LCD_PinType uint16_t
#define LCD_PortType GPIO_TypeDef*

//4 data pins
//RS and E

typedef struct {
	LCD_PortType *dataport;
	LCD_PinType *datapin;

	LCD_PortType RS_port;
	LCD_PinType RS_pin;

	LCD_PortType E_port;
	LCD_PinType E_pin;
} LCD_Struct_t;


//Construct an instance of LCD_Struct_t
LCD_Struct_t LCD_Create(
	LCD_PortType port[], LCD_PinType pin[],
	LCD_PortType rs_port, LCD_PinType rs_pin,
	LCD_PortType e_port, LCD_PinType e_pin
);


void LCD_Character(LCD_Struct_t *LCD_1602, char data);

void LCD_String(LCD_Struct_t *LCD_1602, char *string);

void LCD_YX(LCD_Struct_t *LCD_1602, char y, char x);



#endif /* INC_LCD_H_ */

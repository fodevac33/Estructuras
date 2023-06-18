#include "main.h"

#include "SysConfig.h"
#include "GPIO.h"
#include "LCD.h"

LCD_PortType LCD_Ports[] = {
	D4_Port, D5_Port, D6_Port, D7_Port
};

LCD_PinType LCD_Pins[] = {
	D4_Pin, D5_Pin, D6_Pin, D7_Pin
};



int main(void)
{
  HAL_Init();

  SysConfigClock();

  Global_GPIO_Init();

  LCD_Struct_t LCD_1602 = LCD_Create(LCD_Ports, LCD_Pins, RS_Port, RS_Pin, E_Port, E_Pin);

  LCD_YX(&LCD_1602, 0, 0);

  LCD_String(&LCD_1602, "Its working!");

  LCD_YX(&LCD_1602, 1, 0);

  LCD_String(&LCD_1602, "Row 2");

  while (1) {

  }
}





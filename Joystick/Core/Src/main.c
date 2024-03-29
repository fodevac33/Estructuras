#include "main.h"

#include "SysConfig.h"
#include "LCD.h"
#include "GPIO.h"
#include "Joystick.h"


LCD_PortType LCD_Ports[] = {
	D4_Port, D5_Port, D6_Port, D7_Port
};

LCD_PinType LCD_Pins[] = {
	D4_Pin, D5_Pin, D6_Pin, D7_Pin
};

JOYSTICK_CHANNEL_CONF Joystick_ChannelConf;
JOYSTICK_ADC_HANDLER Joystick_ADC_Handler;


__IO uint32_t button_state = 0;

int16_t xy_joystick[2];
char row1[17];
char data[17];


int main(void)
{
  HAL_Init();
  SysConfigClock();
  Global_GPIO_Init();

  LCD_Struct_t LCD_1602 = LCD_Create(LCD_Ports, LCD_Pins, RS_Port, RS_Pin, E_Port, E_Pin);

  LCD_XY(&LCD_1602, 0, 0);
  LCD_String(&LCD_1602, "Joystick: ");

  Joystick_Struct_t Joystick = Joystick_Create(
		  JOYSTICK_X_Port, JOYSTICK_X_Pin, JOYSTICK_X_ADC_Channel,
		  JOYSTICK_Y_Port, JOYSTICK_Y_Pin, JOYSTICK_Y_ADC_Channel,
		  JOYSTICK_BUTTON_Port, JOYSTICK_BUTTON_Pin,
		  &Joystick_ChannelConf, &Joystick_ADC_Handler);

  while (1)
  {
	  Joystick_Read(&Joystick, xy_joystick);
	  sprintf(data, "X: %hd, Y: %hd    ", xy_joystick[0], xy_joystick[1]);

	  LCD_XY(&LCD_1602, 1, 0);
	  LCD_String(&LCD_1602, data);

	  if (button_state == 1) {
		  LCD_XY(&LCD_1602, 0, 0);
		  LCD_String(&LCD_1602, "Button: 1");
	  }
	  else {
		  LCD_XY(&LCD_1602, 0, 0);
		  LCD_String(&LCD_1602, "Button: 0");
	  }

	  HAL_Delay(100);
  }
}

//Joystick button interruption callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == JOYSTICK_BUTTON_Pin) {
		button_state = (button_state == 0) ? 1 : 0;
	}
}


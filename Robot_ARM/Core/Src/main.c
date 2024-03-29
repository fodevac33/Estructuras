#include "main.h"

#include "ROBOT.h"

#define COMMAND_LENGTH 11


//LCD Pins and ports
LCD_PortType LCD_Ports[] = {
	D4_Port, D5_Port, D6_Port, D7_Port
};

LCD_PinType LCD_Pins[] = {
	D4_Pin, D5_Pin, D6_Pin, D7_Pin
};


//Servo handles
SERVO_HANDLE ServoBase_Handle;
SERVO_HANDLE ServoJoint_Handle;
SERVO_HANDLE ServoClaw_Handle;

//External structures
extern UART_HandleTypeDef USART2_I;

//Global variables
__IO Robot_Mode_t mode = MANUAL;

__IO Serial_Status_t status = AWAITING;

__IO uint32_t button_state = 0;

uint32_t button_serial = 0;

int16_t xy_joystick[2];
int16_t xy_serial[2] = {0, 0};

bool neutral = false;

char row1[17];
char joystick_data[17];

uint8_t RX_Data[COMMAND_LENGTH] = {0};
char LCD_RX_Data[COMMAND_LENGTH];


int main(void)
{
  //System initialization
  HAL_Init();
  SysConfigClock();
  Global_GPIO_Init();

  //Peripherals initialization
  USART_Init(9600);
  HAL_UART_Receive_IT(&USART2_I, RX_Data, 1);


  Mode_Change_Interrupt_Init();

  LCD_Struct_t LCD_1602 = LCD_Create(LCD_Ports, LCD_Pins, RS_Port, RS_Pin, E_Port, E_Pin);

  Joystick_Struct_t Joystick = Joystick_Create(
		  JOYSTICK_X_Port, JOYSTICK_X_Pin, JOYSTICK_X_ADC_Channel,
		  JOYSTICK_Y_Port, JOYSTICK_Y_Pin, JOYSTICK_Y_ADC_Channel,
		  JOYSTICK_BUTTON_Port, JOYSTICK_BUTTON_Pin);

  SG90_Struct_t ServoBase = Servo_Create(
		  SERVO_BASE_Port, SERVO_BASE_Pin, SERVO_BASE_TIM_INSTANCE,
		  SERVO_BASE_PWM_CHANNEL, &ServoBase_Handle);

  SG90_Struct_t ServoJoint = Servo_Create(
		  SERVO_JOINT_Port, SERVO_JOINT_Pin, SERVO_JOINT_TIM_INSTANCE,
		  SERVO_JOINT_PWM_CHANNEL, &ServoJoint_Handle);

  SG90_Struct_t ServoClaw = Servo_Create(
		  SERVO_CLAW_Port, SERVO_CLAW_Pin, SERVO_CLAW_TIM_INSTANCE,
		  SERVO_CLAW_PWM_CHANNEL, &ServoClaw_Handle);

  SG90_Struct_t* Robot[3] = {&ServoBase, &ServoJoint, &ServoClaw};

  //Program loop
  while (1)
  {
	  if (mode == MANUAL) {
		  Joystick_Read(&Joystick, xy_joystick);

		  Robot_Move(Robot, xy_joystick, button_state);

		  sprintf(joystick_data, "X: %hd, Y: %hd", xy_joystick[0], xy_joystick[1]);

		  LCD_YX(&LCD_1602, 1, 0);
		  LCD_String(&LCD_1602, joystick_data);

		  if (button_state == 1) {
			  LCD_YX(&LCD_1602, 0, 0);
			  LCD_String(&LCD_1602, "Claw: Closed");
		  }
		  else {
			  LCD_YX(&LCD_1602, 0, 0);
			  LCD_String(&LCD_1602, "Claw: Open");
		  }

		  HAL_Delay(50);
	  }

	  else if(mode == SERIAL) {
		  if (status == AWAITING){
			  if (!neutral) {
				  Robot_Neutral(Robot);

				  neutral = true;  // Set the flag to true after executing the function
			  }

			  LCD_YX(&LCD_1602, 0, 0);
			  LCD_String(&LCD_1602, "Awaiting Command");

			  LCD_YX(&LCD_1602, 1, 0);
			  LCD_String(&LCD_1602, "...");

		  }

		  else if (status == RECIEVED) {
			  LCD_YX(&LCD_1602, 0, 0);
			  LCD_String(&LCD_1602, "Received Command");

			  uint8_to_char(RX_Data, LCD_RX_Data, COMMAND_LENGTH);

			  LCD_YX(&LCD_1602, 1, 0);
			  LCD_String(&LCD_1602, LCD_RX_Data);

			  Cmd_Process_Result_t result = Process_Command(Robot, RX_Data, xy_serial, button_serial);

			  HAL_Delay(700);

			  if (result == CMD_SUCCESS) {
				  LCD_YX(&LCD_1602, 0, 0);
				  LCD_String(&LCD_1602, "Success!");

				  status = AWAITING;

				  memset(RX_Data, 0, COMMAND_LENGTH);

				  HAL_Delay(700);
			  }
			  else {
				  LCD_YX(&LCD_1602, 0, 0);
				  LCD_String(&LCD_1602, "Failure!");

				  status = AWAITING;

				  memset(RX_Data, 0, COMMAND_LENGTH);

				  HAL_Delay(700);
			  }
		  }
	  }
  }
}


//Interrupt callbacks
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == JOYSTICK_BUTTON_Pin) {
		button_state = (button_state == 0) ? 1 : 0;
	}

	else if (GPIO_Pin == MODE_CHANGE_Pin) {
		mode = (mode == MANUAL) ? SERIAL : MANUAL;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uartHandler)
{
    HAL_UART_Receive_IT(uartHandler, &RX_Data[1], COMMAND_LENGTH);
    status = RECIEVED;
}


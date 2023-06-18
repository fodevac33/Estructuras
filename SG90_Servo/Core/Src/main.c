#include "main.h"

#include "GPIO.h"
#include "SysConfig.h"
#include "SG90.h"


SERVO_HANDLE Servo1_Handle;
//SERVO_HANDLE Servo2_Handle;


int main(void)
{
  HAL_Init();
  SysConfigClock();
  Global_GPIO_Init();

  SG90_Struct_t Servo1 = Servo_Create(GPIOB, GPIO_PIN_6, TIM4, TIM_CHANNEL_1, &Servo1_Handle);
//  SG90_Struct_t Servo2 = Servo_Create(GPIOC, GPIO_PIN_7, TIM3, TIM_CHANNEL_2, &Servo2_Handle);
//  Servo_Rotate(&Servo2, 180.0);

  while (1)
  {
	  Servo_Rotate(&Servo1, 0);
	  HAL_Delay(400);
	  Servo_Rotate(&Servo1, 180);
	  HAL_Delay(400);
  }
}



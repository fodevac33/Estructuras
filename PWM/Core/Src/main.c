#include "main.h"

#include "GPIO.h"
#include "SysConfig.h"
#include "USART.h"
#include "PWM.h"


extern TIM_HandleTypeDef Tim4;

int main(void)
{
  HAL_Init();
  SysConfigClock();
  Global_GPIO_Init();

  PWM_Init();
  HAL_TIM_PWM_Start(&Tim4, TIM_CHANNEL_1);
  PWM_SetDutyCycle_CH1(10);

  USART_Init(115200);
  printf("It works!\r\n");

  while (1)
  {

  }
}



#include "main.h"

#include "GPIO.h"
#include "SysConfig.h"
#include "USART.h"


uint16_t var = 0;

int main(void)
{
  HAL_Init();
  SysConfigClock();
  Global_GPIO_Init();

  USART_Init(115200);
  printf("It works!\r\n");

  while (1)
  {
	  printf("Counting: %d\r\n", var++);
	  HAL_Delay(500);
  }
}



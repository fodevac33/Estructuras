
/* Includes ------------------------------------------------------------------*/

#include <stdlib.h>
#include <math.h>
#include "main.h"

/* Variables for ADC conversion data */
volatile uint16_t ADC_Data = VAR_CONVERTED_DATA_INIT_VALUE; /* ADC group regular conversion data */

/* Variables for ADC conversion data computation to physical values */
volatile uint16_t ADC_Voltage = 0;  /* Value of voltage calculated from ADC conversion data (unit: mV) */

volatile uint32_t porcentaje = 0;

uint16_t min = 0;
uint16_t max = 3300;


int main(void)
{
  /* Configure the system clock to 80 MHz */
  SystemClock_Config();

  Display_Init();

  Configure_ADC();

  Activate_ADC();
  
  ConversionStartPoll_ADC_GrpRegular();

  Configure_TIMPWMOutput();

  uint8_t msg[5]="____";

  while(1) {

	ADC_Data = ReadADC_Data();

	ADC_Voltage = ADCDataToVoltage(ADC_Data);


	porcentaje = (ADC_Voltage - min) * 100.0f / (max - min);

	double cuadratica = pow((porcentaje / 10.0), 2);

	double porcentaje_cuadratico = (cuadratica > 100) ? 100 : cuadratica;

//	double exponencial = exp(porcentaje / 21.7) - 0.7;
//
//	double porcentaje_exponencial = (exponencial > 100) ? 100 : exponencial;


	utoa((unsigned) porcentaje_cuadratico, (char *) msg, 10);

	process_string(msg);

	FSM_Write_D4(msg);

	Configure_DutyCycle((uint32_t) porcentaje_cuadratico);

  }

}





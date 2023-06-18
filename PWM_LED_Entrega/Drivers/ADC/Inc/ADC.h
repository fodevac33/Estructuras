/*
 * ADC.h
 *
 *  Created on: May 4, 2023
 *      Author: felipe
 */

#ifndef ADC_INC_ADC_H_
#define ADC_INC_ADC_H_

#include "main.h"

#define ADC_DELAY_CALIB_ENABLE_CPU_CYCLES  (LL_ADC_DELAY_CALIB_ENABLE_ADC_CYCLES * 32)


/* Definitions of environment analog values */
/* Value of analog reference voltage (Vref+), connected to analog voltage   */
/* supply Vdda (unit: mV).                                                  */
#define VDDA_APPLI                       ((uint32_t)3300)

/* Considering ADC settings, duration of 1 ADC conversion should always    */
/* be lower than 1ms.                                                      */
#define ADC_UNITARY_CONVERSION_TIMEOUT_MS ((uint32_t)   1)

/* Init variable out of expected ADC conversion data range */
#define VAR_CONVERTED_DATA_INIT_VALUE    (__LL_ADC_DIGITAL_SCALE(LL_ADC_RESOLUTION_12B) + 1)

void Configure_ADC(void);
void Activate_ADC(void);
void ConversionStartPoll_ADC_GrpRegular(void);
void SystemClock_Config(void);


uint16_t ReadADC_Data(void);
float ADCDataToVoltage(uint16_t ADC_Data);

#endif /* ADC_INC_ADC_H_ */

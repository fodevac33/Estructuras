/*
 * PWM.c
 *
 *  Created on: May 4, 2023
 *      Author: felipe
 */
#include "PWM.h"

volatile uint32_t MeasuredDutyCycle = 0;

void  Configure_TIMPWMOutput(void)
{
  /*************************/
  /* GPIO AF configuration */
  /*************************/
  /* Enable the peripheral clock of GPIOs */
  LL_AHB2_GRP1_EnableClock(LED_CLOCK);

  /* GPIO TIM2_CH1 configuration */
  LL_GPIO_SetPinMode(LED_GPIO, LED_PIN, LL_GPIO_MODE_ALTERNATE);
  LL_GPIO_SetPinPull(LED_GPIO, LED_PIN, LL_GPIO_PULL_DOWN);
  LL_GPIO_SetPinSpeed(LED_GPIO, LED_PIN, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetAFPin_0_7(LED_GPIO, LED_PIN, LL_GPIO_AF_1);

  /***********************************************/
  /* Configure the NVIC to handle TIM2 interrupt */
  /***********************************************/
  NVIC_SetPriority(TIM2_IRQn, 14);
  NVIC_EnableIRQ(TIM2_IRQn);

  /******************************/
  /* Peripheral clocks enabling */
  /******************************/
  /* Enable the timer peripheral clock */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);

  /***************************/
  /* Time base configuration */
  /***************************/
  /* Set counter mode */
  /* Reset value is LL_TIM_COUNTERMODE_UP */
  //LL_TIM_SetCounterMode(TIM2, LL_TIM_COUNTERMODE_UP);

  /* Set the pre-scaler value to have TIM2 counter clock equal to 10 kHz */
  LL_TIM_SetPrescaler(TIM2, __LL_TIM_CALC_PSC(SystemCoreClock, 10000));

  /* Enable TIM2_ARR register preload. Writing to or reading from the         */
  /* auto-reload register accesses the preload register. The content of the   */
  /* preload register are transferred into the shadow register at each update */
  /* event (UEV).                                                             */
  LL_TIM_EnableARRPreload(TIM2);

  /* Set the auto-reload value to have a counter frequency of 100 Hz */
  LL_TIM_SetAutoReload(TIM2, __LL_TIM_CALC_ARR(SystemCoreClock, LL_TIM_GetPrescaler(TIM2), 100));

  /*********************************/
  /* Output waveform configuration */
  /*********************************/
  /* Set output mode */
  /* Reset value is LL_TIM_OCMODE_FROZEN */
  LL_TIM_OC_SetMode(TIM2, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);

  /* Set output channel polarity */
  /* Reset value is LL_TIM_OCPOLARITY_HIGH */
  //LL_TIM_OC_SetPolarity(TIM2, LL_TIM_CHANNEL_CH1, LL_TIM_OCPOLARITY_HIGH);

  /* Set compare value to half of the counter period (50% duty cycle ) */
  LL_TIM_OC_SetCompareCH1(TIM2, (LL_TIM_GetAutoReload(TIM2) / 2));

  /* Enable TIM2_CCR1 register preload. Read/Write operations access the      */
  /* preload register. TIM2_CCR1 preload value is loaded in the active        */
  /* at each update event.                                                    */
  LL_TIM_OC_EnablePreload(TIM2, LL_TIM_CHANNEL_CH1);

  /**************************/
  /* TIM2 interrupts set-up */
  /**************************/
  /* Enable the capture/compare interrupt for channel 1*/
  LL_TIM_EnableIT_CC1(TIM2);

  /**********************************/
  /* Start output signal generation */
  /**********************************/
  /* Enable output channel 1 */
  LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH1);

  /* Enable counter */
  LL_TIM_EnableCounter(TIM2);

  /* Force update generation */
  LL_TIM_GenerateEvent_UPDATE(TIM2);
}


void Configure_DutyCycle(uint32_t D)
{

  uint32_t P;    /* Pulse duration */
  uint32_t T;    /* PWM signal period */

  /* PWM signal period is determined by the value of the auto-reload register */
  T = LL_TIM_GetAutoReload(TIM2);

  /* Pulse duration is determined by the value of the compare register.       */
  /* Its value is calculated in order to match the requested duty cycle.      */
  P = (D*T)/100;
  LL_TIM_OC_SetCompareCH1(TIM2, P);
}


void TIM2_IRQHandler(void)
{
		/* Enable counter */
	{
	  /* Check whether CC1 interrupt is pending */
	  if(LL_TIM_IsActiveFlag_CC1(TIM2) == 1)
	  {
	    /* Clear the update interrupt flag*/
	    LL_TIM_ClearFlag_CC1(TIM2);

	    /* TIM2 capture/compare interrupt processing(function defined in main.c) */
	    TimerCaptureCompare_Callback();
	  }
	}

}


void TimerCaptureCompare_Callback(void)
{
  MeasuredDutyCycle = (LL_TIM_GetCounter(TIM2) * 100) / LL_TIM_GetAutoReload(TIM2);
}


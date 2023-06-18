################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ADC/Src/ADC.c 

OBJS += \
./Drivers/ADC/Src/ADC.o 

C_DEPS += \
./Drivers/ADC/Src/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ADC/Src/%.o Drivers/ADC/Src/%.su Drivers/ADC/Src/%.cyclo: ../Drivers/ADC/Src/%.c Drivers/ADC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -DSTM32L4xx -c -I../Inc -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Core/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/CMSIS/Include" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/LIB/Include" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/STM32L4xx_HAL_Driver/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/STM32L4xx_LL_Drivers/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/ADC/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/PWM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ADC-2f-Src

clean-Drivers-2f-ADC-2f-Src:
	-$(RM) ./Drivers/ADC/Src/ADC.cyclo ./Drivers/ADC/Src/ADC.d ./Drivers/ADC/Src/ADC.o ./Drivers/ADC/Src/ADC.su

.PHONY: clean-Drivers-2f-ADC-2f-Src


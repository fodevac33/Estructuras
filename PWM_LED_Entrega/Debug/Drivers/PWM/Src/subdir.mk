################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/PWM/Src/PWM.c 

OBJS += \
./Drivers/PWM/Src/PWM.o 

C_DEPS += \
./Drivers/PWM/Src/PWM.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/PWM/Src/%.o Drivers/PWM/Src/%.su Drivers/PWM/Src/%.cyclo: ../Drivers/PWM/Src/%.c Drivers/PWM/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -DSTM32L4xx -c -I../Inc -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Core/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/CMSIS/Include" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/LIB/Include" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/STM32L4xx_HAL_Driver/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/STM32L4xx_LL_Drivers/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/ADC/Inc" -I"/home/felipe/Documents/Estructuras/PWM_LED_Entrega/Drivers/PWM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-PWM-2f-Src

clean-Drivers-2f-PWM-2f-Src:
	-$(RM) ./Drivers/PWM/Src/PWM.cyclo ./Drivers/PWM/Src/PWM.d ./Drivers/PWM/Src/PWM.o ./Drivers/PWM/Src/PWM.su

.PHONY: clean-Drivers-2f-PWM-2f-Src


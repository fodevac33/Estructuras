################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32L4xx_MSP_Driver/Source/stm32l4xx_stk.c 

OBJS += \
./Drivers/STM32L4xx_MSP_Driver/Source/stm32l4xx_stk.o 

C_DEPS += \
./Drivers/STM32L4xx_MSP_Driver/Source/stm32l4xx_stk.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32L4xx_MSP_Driver/Source/%.o Drivers/STM32L4xx_MSP_Driver/Source/%.su Drivers/STM32L4xx_MSP_Driver/Source/%.cyclo: ../Drivers/STM32L4xx_MSP_Driver/Source/%.c Drivers/STM32L4xx_MSP_Driver/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -DSTM32L476xx -c -I/home/felipe/Documents/Estructuras/LedBLink-C/Core/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/STM32L4xx_HAL_Driver/Inc -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Device/ST/STM32L4xx/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/MFS_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/AUDI_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/STM32L4xx_MSP_Driver/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32L4xx_MSP_Driver-2f-Source

clean-Drivers-2f-STM32L4xx_MSP_Driver-2f-Source:
	-$(RM) ./Drivers/STM32L4xx_MSP_Driver/Source/stm32l4xx_stk.cyclo ./Drivers/STM32L4xx_MSP_Driver/Source/stm32l4xx_stk.d ./Drivers/STM32L4xx_MSP_Driver/Source/stm32l4xx_stk.o ./Drivers/STM32L4xx_MSP_Driver/Source/stm32l4xx_stk.su

.PHONY: clean-Drivers-2f-STM32L4xx_MSP_Driver-2f-Source


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/Core/GPIO.c \
../Peripheral/Core/SysConfig.c 

OBJS += \
./Peripheral/Core/GPIO.o \
./Peripheral/Core/SysConfig.o 

C_DEPS += \
./Peripheral/Core/GPIO.d \
./Peripheral/Core/SysConfig.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/Core/%.o Peripheral/Core/%.su Peripheral/Core/%.cyclo: ../Peripheral/Core/%.c Peripheral/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"/home/felipe/Documents/Estructuras/Hello World/Peripheral/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Peripheral-2f-Core

clean-Peripheral-2f-Core:
	-$(RM) ./Peripheral/Core/GPIO.cyclo ./Peripheral/Core/GPIO.d ./Peripheral/Core/GPIO.o ./Peripheral/Core/GPIO.su ./Peripheral/Core/SysConfig.cyclo ./Peripheral/Core/SysConfig.d ./Peripheral/Core/SysConfig.o ./Peripheral/Core/SysConfig.su

.PHONY: clean-Peripheral-2f-Core


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Core/GPIO.c \
../Peripherals/Core/INTERRUPTS.c \
../Peripherals/Core/LCD.c \
../Peripherals/Core/SysConfig.c 

OBJS += \
./Peripherals/Core/GPIO.o \
./Peripherals/Core/INTERRUPTS.o \
./Peripherals/Core/LCD.o \
./Peripherals/Core/SysConfig.o 

C_DEPS += \
./Peripherals/Core/GPIO.d \
./Peripherals/Core/INTERRUPTS.d \
./Peripherals/Core/LCD.d \
./Peripherals/Core/SysConfig.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Core/%.o Peripherals/Core/%.su Peripherals/Core/%.cyclo: ../Peripherals/Core/%.c Peripherals/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"/home/felipe/Documents/Estructuras/LCD_1602/Peripherals/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Peripherals-2f-Core

clean-Peripherals-2f-Core:
	-$(RM) ./Peripherals/Core/GPIO.cyclo ./Peripherals/Core/GPIO.d ./Peripherals/Core/GPIO.o ./Peripherals/Core/GPIO.su ./Peripherals/Core/INTERRUPTS.cyclo ./Peripherals/Core/INTERRUPTS.d ./Peripherals/Core/INTERRUPTS.o ./Peripherals/Core/INTERRUPTS.su ./Peripherals/Core/LCD.cyclo ./Peripherals/Core/LCD.d ./Peripherals/Core/LCD.o ./Peripherals/Core/LCD.su ./Peripherals/Core/SysConfig.cyclo ./Peripherals/Core/SysConfig.d ./Peripherals/Core/SysConfig.o ./Peripherals/Core/SysConfig.su

.PHONY: clean-Peripherals-2f-Core


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Src/GPIO.c \
../Peripherals/Src/Joystick.c \
../Peripherals/Src/LCD.c \
../Peripherals/Src/SG90.c \
../Peripherals/Src/SysConfig.c \
../Peripherals/Src/USART.c 

OBJS += \
./Peripherals/Src/GPIO.o \
./Peripherals/Src/Joystick.o \
./Peripherals/Src/LCD.o \
./Peripherals/Src/SG90.o \
./Peripherals/Src/SysConfig.o \
./Peripherals/Src/USART.o 

C_DEPS += \
./Peripherals/Src/GPIO.d \
./Peripherals/Src/Joystick.d \
./Peripherals/Src/LCD.d \
./Peripherals/Src/SG90.d \
./Peripherals/Src/SysConfig.d \
./Peripherals/Src/USART.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Src/%.o Peripherals/Src/%.su Peripherals/Src/%.cyclo: ../Peripherals/Src/%.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"/home/felipe/Documents/Estructuras/Robot_ARM/Peripherals/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Peripherals-2f-Src

clean-Peripherals-2f-Src:
	-$(RM) ./Peripherals/Src/GPIO.cyclo ./Peripherals/Src/GPIO.d ./Peripherals/Src/GPIO.o ./Peripherals/Src/GPIO.su ./Peripherals/Src/Joystick.cyclo ./Peripherals/Src/Joystick.d ./Peripherals/Src/Joystick.o ./Peripherals/Src/Joystick.su ./Peripherals/Src/LCD.cyclo ./Peripherals/Src/LCD.d ./Peripherals/Src/LCD.o ./Peripherals/Src/LCD.su ./Peripherals/Src/SG90.cyclo ./Peripherals/Src/SG90.d ./Peripherals/Src/SG90.o ./Peripherals/Src/SG90.su ./Peripherals/Src/SysConfig.cyclo ./Peripherals/Src/SysConfig.d ./Peripherals/Src/SysConfig.o ./Peripherals/Src/SysConfig.su ./Peripherals/Src/USART.cyclo ./Peripherals/Src/USART.d ./Peripherals/Src/USART.o ./Peripherals/Src/USART.su

.PHONY: clean-Peripherals-2f-Src


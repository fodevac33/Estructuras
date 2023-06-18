################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/LIB/Source/keypad.c \
../Drivers/LIB/Source/mf_shield.c \
../Drivers/LIB/Source/systick.c 

OBJS += \
./Drivers/LIB/Source/keypad.o \
./Drivers/LIB/Source/mf_shield.o \
./Drivers/LIB/Source/systick.o 

C_DEPS += \
./Drivers/LIB/Source/keypad.d \
./Drivers/LIB/Source/mf_shield.d \
./Drivers/LIB/Source/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/LIB/Source/%.o Drivers/LIB/Source/%.su Drivers/LIB/Source/%.cyclo: ../Drivers/LIB/Source/%.c Drivers/LIB/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I../Inc -I"/home/felipe/Documents/Estructuras/ADC_Display/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"/home/felipe/Documents/Estructuras/ADC_Display/Drivers/CMSIS/Include" -I"/home/felipe/Documents/Estructuras/ADC_Display/Drivers/LIB/Include" -I"/home/felipe/Documents/Estructuras/ADC_Display/Drivers/STM32L4xx_LL_Drivers/Inc" -I"/home/felipe/Documents/Estructuras/ADC_Display/Inc" -I"/home/felipe/Documents/Estructuras/ADC_Display/Drivers/STM32L4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-LIB-2f-Source

clean-Drivers-2f-LIB-2f-Source:
	-$(RM) ./Drivers/LIB/Source/keypad.cyclo ./Drivers/LIB/Source/keypad.d ./Drivers/LIB/Source/keypad.o ./Drivers/LIB/Source/keypad.su ./Drivers/LIB/Source/mf_shield.cyclo ./Drivers/LIB/Source/mf_shield.d ./Drivers/LIB/Source/mf_shield.o ./Drivers/LIB/Source/mf_shield.su ./Drivers/LIB/Source/systick.cyclo ./Drivers/LIB/Source/systick.d ./Drivers/LIB/Source/systick.o ./Drivers/LIB/Source/systick.su

.PHONY: clean-Drivers-2f-LIB-2f-Source


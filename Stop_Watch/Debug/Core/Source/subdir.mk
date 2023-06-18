################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Source/main.c 

OBJS += \
./Core/Source/main.o 

C_DEPS += \
./Core/Source/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Source/%.o Core/Source/%.su Core/Source/%.cyclo: ../Core/Source/%.c Core/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I"/home/felipe/Documents/Estructuras/Stop_Watch/Core/Include" -I"/home/felipe/Documents/Estructuras/Stop_Watch/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"/home/felipe/Documents/Estructuras/Stop_Watch/Drivers/CMSIS/Include" -I"/home/felipe/Documents/Estructuras/Stop_Watch/Drivers/STM32L4xx_LL_Drivers/Inc" -I"/home/felipe/Documents/Estructuras/Stop_Watch/Drivers/LIB/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Source

clean-Core-2f-Source:
	-$(RM) ./Core/Source/main.cyclo ./Core/Source/main.d ./Core/Source/main.o ./Core/Source/main.su

.PHONY: clean-Core-2f-Source


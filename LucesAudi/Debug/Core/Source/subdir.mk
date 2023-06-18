################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Source/AUDI_fms.c \
../Core/Source/main.c \
../Core/Source/stm32l4xx_it.c 

OBJS += \
./Core/Source/AUDI_fms.o \
./Core/Source/main.o \
./Core/Source/stm32l4xx_it.o 

C_DEPS += \
./Core/Source/AUDI_fms.d \
./Core/Source/main.d \
./Core/Source/stm32l4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Source/%.o Core/Source/%.su Core/Source/%.cyclo: ../Core/Source/%.c Core/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -DSTM32L476xx -c -I/home/felipe/Documents/Estructuras/LedBLink-C/Core/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/STM32L4xx_HAL_Driver/Inc -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Device/ST/STM32L4xx/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/MFS_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/AUDI_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/STM32L4xx_MSP_Driver/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Source

clean-Core-2f-Source:
	-$(RM) ./Core/Source/AUDI_fms.cyclo ./Core/Source/AUDI_fms.d ./Core/Source/AUDI_fms.o ./Core/Source/AUDI_fms.su ./Core/Source/main.cyclo ./Core/Source/main.d ./Core/Source/main.o ./Core/Source/main.su ./Core/Source/stm32l4xx_it.cyclo ./Core/Source/stm32l4xx_it.d ./Core/Source/stm32l4xx_it.o ./Core/Source/stm32l4xx_it.su

.PHONY: clean-Core-2f-Source


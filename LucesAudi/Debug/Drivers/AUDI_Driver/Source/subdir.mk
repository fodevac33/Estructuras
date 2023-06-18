################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/AUDI_Driver/Source/AUDI_Dx.c \
../Drivers/AUDI_Driver/Source/AUDI_Sx.c 

OBJS += \
./Drivers/AUDI_Driver/Source/AUDI_Dx.o \
./Drivers/AUDI_Driver/Source/AUDI_Sx.o 

C_DEPS += \
./Drivers/AUDI_Driver/Source/AUDI_Dx.d \
./Drivers/AUDI_Driver/Source/AUDI_Sx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/AUDI_Driver/Source/%.o Drivers/AUDI_Driver/Source/%.su Drivers/AUDI_Driver/Source/%.cyclo: ../Drivers/AUDI_Driver/Source/%.c Drivers/AUDI_Driver/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -DSTM32L476xx -c -I/home/felipe/Documents/Estructuras/LedBLink-C/Core/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/STM32L4xx_HAL_Driver/Inc -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Device/ST/STM32L4xx/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/MFS_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/AUDI_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/STM32L4xx_MSP_Driver/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-AUDI_Driver-2f-Source

clean-Drivers-2f-AUDI_Driver-2f-Source:
	-$(RM) ./Drivers/AUDI_Driver/Source/AUDI_Dx.cyclo ./Drivers/AUDI_Driver/Source/AUDI_Dx.d ./Drivers/AUDI_Driver/Source/AUDI_Dx.o ./Drivers/AUDI_Driver/Source/AUDI_Dx.su ./Drivers/AUDI_Driver/Source/AUDI_Sx.cyclo ./Drivers/AUDI_Driver/Source/AUDI_Sx.d ./Drivers/AUDI_Driver/Source/AUDI_Sx.o ./Drivers/AUDI_Driver/Source/AUDI_Sx.su

.PHONY: clean-Drivers-2f-AUDI_Driver-2f-Source


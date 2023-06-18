################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MFS_Driver/Source/MFS_Dx.c \
../Drivers/MFS_Driver/Source/MFS_Sx.c 

OBJS += \
./Drivers/MFS_Driver/Source/MFS_Dx.o \
./Drivers/MFS_Driver/Source/MFS_Sx.o 

C_DEPS += \
./Drivers/MFS_Driver/Source/MFS_Dx.d \
./Drivers/MFS_Driver/Source/MFS_Sx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MFS_Driver/Source/%.o Drivers/MFS_Driver/Source/%.su Drivers/MFS_Driver/Source/%.cyclo: ../Drivers/MFS_Driver/Source/%.c Drivers/MFS_Driver/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -DSTM32L476xx -c -I/home/felipe/Documents/Estructuras/LedBLink-C/Core/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/STM32L4xx_HAL_Driver/Inc -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Include -I/home/felipe/Documents/Estructuras/LedBLink-C/Drivers/CMSIS/Device/ST/STM32L4xx/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/MFS_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/AUDI_Driver/Include -I/home/felipe/Documents/Estructuras/LucesAudi/Drivers/STM32L4xx_MSP_Driver/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-MFS_Driver-2f-Source

clean-Drivers-2f-MFS_Driver-2f-Source:
	-$(RM) ./Drivers/MFS_Driver/Source/MFS_Dx.cyclo ./Drivers/MFS_Driver/Source/MFS_Dx.d ./Drivers/MFS_Driver/Source/MFS_Dx.o ./Drivers/MFS_Driver/Source/MFS_Dx.su ./Drivers/MFS_Driver/Source/MFS_Sx.cyclo ./Drivers/MFS_Driver/Source/MFS_Sx.d ./Drivers/MFS_Driver/Source/MFS_Sx.o ./Drivers/MFS_Driver/Source/MFS_Sx.su

.PHONY: clean-Drivers-2f-MFS_Driver-2f-Source


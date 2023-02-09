################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lan9252/lan9252.c \
../lan9252/lan9252drv.c 

OBJS += \
./lan9252/lan9252.o \
./lan9252/lan9252drv.o 

C_DEPS += \
./lan9252/lan9252.d \
./lan9252/lan9252drv.d 


# Each subdirectory must supply rules for building sources it contributes
lan9252/%.o lan9252/%.su: ../lan9252/%.c lan9252/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lan9252

clean-lan9252:
	-$(RM) ./lan9252/lan9252.d ./lan9252/lan9252.o ./lan9252/lan9252.su ./lan9252/lan9252drv.d ./lan9252/lan9252drv.o ./lan9252/lan9252drv.su

.PHONY: clean-lan9252


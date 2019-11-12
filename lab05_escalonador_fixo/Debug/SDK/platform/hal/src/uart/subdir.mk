################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/hal/src/uart/fsl_uart_hal.c 

OBJS += \
./SDK/platform/hal/src/uart/fsl_uart_hal.o 

C_DEPS += \
./SDK/platform/hal/src/uart/fsl_uart_hal.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/hal/src/uart/%.o: ../SDK/platform/hal/src/uart/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_FREE_RTOS" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/hal/inc" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/hal/src/sim/MKL25Z4" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/system/src/clock/MKL25Z4" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/system/inc" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/osa/inc" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/CMSIS/Include" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/devices" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/devices/MKL25Z4/include" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/utilities/src" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/utilities/inc" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/platform/devices/MKL25Z4/startup" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/Sources" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/Generated_Code" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/rtos/FreeRTOS/include" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/SDK/rtos/FreeRTOS/port/gcc" -I"C:/Users/john/workspace.kds/lab05_escalonador_fixo/Generated_Code/SDK/rtos/FreeRTOS/config" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



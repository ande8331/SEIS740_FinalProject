################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/src/croutine.c \
../freertos/src/list.c \
../freertos/src/queue.c \
../freertos/src/tasks.c 

OBJS += \
./freertos/src/croutine.o \
./freertos/src/list.o \
./freertos/src/queue.o \
./freertos/src/tasks.o 

C_DEPS += \
./freertos/src/croutine.d \
./freertos/src/list.d \
./freertos/src/queue.d \
./freertos/src/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/src/%.o: ../freertos/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC11xx -DDEBUG -D__REDLIB__ -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\CMSISv1p30_LPC11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\lib_small_printf_m0\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\port\lpcxpresso\m0" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\inc" -O2 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



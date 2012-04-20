################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../inc/joystick.c 

OBJS += \
./inc/joystick.o 

C_DEPS += \
./inc/joystick.d 


# Each subdirectory must supply rules for building sources it contributes
inc/%.o: ../inc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC11xx -DDEBUG -D__REDLIB__ -I"C:\Documents and Settings\usb00796\My Documents\Microcontroller\AEU Training\Code\CMSISv1p30_LPC11xx\inc" -I"C:\Documents and Settings\usb00796\My Documents\Microcontroller\AEU Training\Code\lib_small_printf_m0\inc" -I"C:\Documents and Settings\usb00796\My Documents\Microcontroller\AEU Training\Code\freertos_lpc11xx\freertos\port\lpcxpresso\m0" -I"C:\Documents and Settings\usb00796\My Documents\Microcontroller\AEU Training\Code\freertos_lpc11xx\inc" -I"C:\Documents and Settings\usb00796\My Documents\Microcontroller\AEU Training\Code\freertos_lpc11xx\freertos\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



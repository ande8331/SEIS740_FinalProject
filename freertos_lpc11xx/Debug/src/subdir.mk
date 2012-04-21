################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc11.c \
../src/debug.c \
../src/joystick.c \
../src/lcd.c \
../src/main.c \
../src/uart.c 

OBJS += \
./src/cr_startup_lpc11.o \
./src/debug.o \
./src/joystick.o \
./src/lcd.o \
./src/main.o \
./src/uart.o 

C_DEPS += \
./src/cr_startup_lpc11.d \
./src/debug.d \
./src/joystick.d \
./src/lcd.d \
./src/main.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/cr_startup_lpc11.o: ../src/cr_startup_lpc11.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC11xx -DDEBUG -D__REDLIB__ -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\CMSISv1p30_LPC11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\lib_small_printf_m0\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\port\lpcxpresso\m0" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\inc" -O2 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/cr_startup_lpc11.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/debug.o: ../src/debug.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC11xx -DDEBUG -D__REDLIB__ -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\CMSISv1p30_LPC11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\lib_small_printf_m0\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\port\lpcxpresso\m0" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\inc" -O2 -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/debug.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC11xx -DDEBUG -D__REDLIB__ -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\CMSISv1p30_LPC11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\lib_small_printf_m0\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\port\lpcxpresso\m0" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\inc" -I"C:\Users\Ross\Dropbox\SEIS740\FreeRTOSDemo\freertos_lpc11xx\freertos\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



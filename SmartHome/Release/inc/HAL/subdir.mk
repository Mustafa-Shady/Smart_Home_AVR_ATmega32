################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../inc/HAL/EEPROM_Program.c \
../inc/HAL/KEYBAD_prog.c \
../inc/HAL/LCD_Prog.c \
../inc/HAL/LED_prog.c \
../inc/HAL/buzzer.c \
../inc/HAL/servo.c 

OBJS += \
./inc/HAL/EEPROM_Program.o \
./inc/HAL/KEYBAD_prog.o \
./inc/HAL/LCD_Prog.o \
./inc/HAL/LED_prog.o \
./inc/HAL/buzzer.o \
./inc/HAL/servo.o 

C_DEPS += \
./inc/HAL/EEPROM_Program.d \
./inc/HAL/KEYBAD_prog.d \
./inc/HAL/LCD_Prog.d \
./inc/HAL/LED_prog.d \
./inc/HAL/buzzer.d \
./inc/HAL/servo.d 


# Each subdirectory must supply rules for building sources it contributes
inc/HAL/%.o: ../inc/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI\AVR\SmartHome\inc" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



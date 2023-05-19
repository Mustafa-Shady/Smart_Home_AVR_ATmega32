################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../inc/MCAL/ADC_PBCfg.c \
../inc/MCAL/ADC_prog.c \
../inc/MCAL/DIO_program.c \
../inc/MCAL/Extint_prog.c \
../inc/MCAL/GIE_prog.c \
../inc/MCAL/GPT_PBCfg.c \
../inc/MCAL/GPT_program.c \
../inc/MCAL/I2C_Program.c \
../inc/MCAL/PWM_prog.c \
../inc/MCAL/UART_prog.c 

OBJS += \
./inc/MCAL/ADC_PBCfg.o \
./inc/MCAL/ADC_prog.o \
./inc/MCAL/DIO_program.o \
./inc/MCAL/Extint_prog.o \
./inc/MCAL/GIE_prog.o \
./inc/MCAL/GPT_PBCfg.o \
./inc/MCAL/GPT_program.o \
./inc/MCAL/I2C_Program.o \
./inc/MCAL/PWM_prog.o \
./inc/MCAL/UART_prog.o 

C_DEPS += \
./inc/MCAL/ADC_PBCfg.d \
./inc/MCAL/ADC_prog.d \
./inc/MCAL/DIO_program.d \
./inc/MCAL/Extint_prog.d \
./inc/MCAL/GIE_prog.d \
./inc/MCAL/GPT_PBCfg.d \
./inc/MCAL/GPT_program.d \
./inc/MCAL/I2C_Program.d \
./inc/MCAL/PWM_prog.d \
./inc/MCAL/UART_prog.d 


# Each subdirectory must supply rules for building sources it contributes
inc/MCAL/%.o: ../inc/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI\AVR\SmartHome\inc" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



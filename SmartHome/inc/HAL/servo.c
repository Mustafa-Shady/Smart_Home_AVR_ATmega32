/*
 * servo.c
 *
 *  Created on: Apr 15, 2023
 *      Author: 20115
 */
#include <HAL/servo.h>

void SERVO_init(void)
{
    Pwm_Init(PWM_CHANNEL_OC1A,PWM_MODE_FAST_ICR1);
    Pwm_SetICR(20000);

}

void SERVO_SetAngle(u16 angle)
{
    OCR1A = (10 * angle)+750;
    Pwm_Start(PWM_CHANNEL_OC1A,PWM_PRESCALER_8); 
}



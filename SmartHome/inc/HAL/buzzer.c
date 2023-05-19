/*
 * buzzer.c
 *
 *  Created on: May 18, 2023
 *      Author: shady
 */

#include "Buzzer.h"
#include "MCAL/PWM_interface.h"
#include"MCAL/GPT_interface.h"
#include "util/delay.h"

void BuzzerInit(void)
{
	Pwm_Init(PWM_CHANNEL_OC2,PWM_MODE_PHASE_CORRECT);
	Pwm_SetDutyCycle(PWM_CHANNEL_OC2,50);
	
	
	
}
void BuzzerOn(u8 Time)
{
	// Calculate the duration in milliseconds
    u16 duration_ms = (u16)Time * 1000;

    // Enable the PWM output for the duration of the specified time
    Pwm_Start(PWM_CHANNEL_OC2,PWM_PRESCALER_1024);
    _delay_ms(duration_ms);

    // Disable the PWM output and turn off the buzzer
    Pwm_Stop(PWM_CHANNEL_OC2);

}
void BuzzerOff(void)
{
    // Disable the PWM output and turn off the buzzer
    Pwm_Stop(PWM_CHANNEL_OC2);	
	Pwm_SetDutyCycle(PWM_CHANNEL_OC2,0);
	Gpt_Reset(GPT_CHANNEL_TIM2);
}


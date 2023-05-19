/*
 * ADC_prog.c
 *
 *  Created on: Apr 4, 2023
 *      Author: 20115
 */

#include <lib/BIT_MATHS.h>
#include <lib/STD_TYPES.h>
#include <MCAL/ADC_interface.h>
#include <MCAL/ADC_private.h>

void (*Adc_Callback) (u16 data) = NULL_PTR;



ISR(VECTOR_ADC) {
    if (NULL_PTR != Adc_Callback) {
        Adc_Callback(ADCDATA&0x3FF);
    }
}

void Adc_Init(const Adc_ConfigurationType* config) {

    /****************** Reference Selection Bits */
    switch (config->reference)
    {
    case ADC_REF_AREF:
         
        CLR_BIT(ADMUX, 7);
        CLR_BIT(ADMUX, 6);
        break;
    case ADC_REF_AVCC:
        CLR_BIT(ADMUX, 7);
        SET_BIT(ADMUX, 6);
        break;
    case ADC_REF_INTERNAL:
        SET_BIT(ADMUX, 7);
        SET_BIT(ADMUX, 6);
        break;
    default:
        break;
    }

    /****************** ADC Left Adjust Result */
    CLR_BIT(ADMUX, 5); // Right

    /****************** ADC Auto Trigger Enable */
    switch (config->trigger)
    {
    case ADC_AUTO_TRIGGER_OFF:
        CLR_BIT(ADCSRA, 5);
        break;
    case ADC_AUTO_TRIGGER_FREE_RUNNING:
        SET_BIT(ADCSRA, 5);
        CLR_BIT(SFIOR, 5);
        CLR_BIT(SFIOR, 6);
        CLR_BIT(SFIOR, 7);
        break;
    case ADC_AUTO_TRIGGER_ANAL_COMP:
        SET_BIT(ADCSRA, 5);
        SET_BIT(SFIOR,  5);
        CLR_BIT(SFIOR,  6);
        CLR_BIT(SFIOR,  7);
        break; 
    case ADC_AUTO_TRIGGER_EXTI0:
        SET_BIT(ADCSRA, 5);
        CLR_BIT(SFIOR,  5);
        SET_BIT(SFIOR,  6);
        CLR_BIT(SFIOR,  7);
        break;
    case ADC_AUTO_TRIGGER_TIM0_COMP:
        SET_BIT(ADCSRA, 5);
        SET_BIT(SFIOR, 5);
        SET_BIT(SFIOR, 6);
        CLR_BIT(SFIOR, 7);
        break;
    case ADC_AUTO_TRIGGER_TIM0_OVF:
        SET_BIT(ADCSRA, 5);
        CLR_BIT(SFIOR, 5);
        CLR_BIT(SFIOR, 6);
        SET_BIT(SFIOR, 7);
        break;
    case ADC_AUTO_TRIGGER_TIMB_COMP:
        SET_BIT(ADCSRA, 5);
        SET_BIT(SFIOR, 5);
        CLR_BIT(SFIOR, 6);
        SET_BIT(SFIOR, 7);
        break;
    case ADC_AUTO_TRIGGER_TIM1_OVF:
        SET_BIT(ADCSRA, 5);
        CLR_BIT(SFIOR, 5);
        SET_BIT(SFIOR, 6);
        SET_BIT(SFIOR, 7);
        break;
    case ADC_AUTO_TRIGGER_TIM1_CAP:
        SET_BIT(ADCSRA, 5);
        SET_BIT(SFIOR, 5);
        SET_BIT(SFIOR, 6);
        SET_BIT(SFIOR, 7);
        break;
    
    default:
        break;
    }

    /****************** ADC Prescaler Select Bits */
    switch (config->prescaler)
    {
    case ADC_PRESCALER_2:
        CLR_BIT(ADCSRA, 2);
        CLR_BIT(ADCSRA, 1);
        CLR_BIT(ADCSRA, 0);
        break;
    case ADC_PRESCALER_4:
        CLR_BIT(ADCSRA, 2);
        SET_BIT(ADCSRA, 1);
        CLR_BIT(ADCSRA, 0);
        break;
    case ADC_PRESCALER_8:
        CLR_BIT(ADCSRA, 2);
        SET_BIT(ADCSRA, 1);
        SET_BIT(ADCSRA, 0);
        break;
    case ADC_PRESCALER_16:
        SET_BIT(ADCSRA, 2);
        CLR_BIT(ADCSRA, 1);
        CLR_BIT(ADCSRA, 0);
        break;
    case ADC_PRESCALER_32:
        SET_BIT(ADCSRA, 2);
        CLR_BIT(ADCSRA, 1);
        SET_BIT(ADCSRA, 0);
        break;
    case ADC_PRESCALER_64:
        SET_BIT(ADCSRA, 2);
        SET_BIT(ADCSRA, 1);
        CLR_BIT(ADCSRA, 0);
        break;
    case ADC_PRESCALER_128:
        SET_BIT(ADCSRA, 2);
        SET_BIT(ADCSRA, 1);
        SET_BIT(ADCSRA, 0);
        break;    
    default:
        break;
    }

    /****************** ADC Enable */
    SET_BIT(ADCSRA,7);
}



void Adc_StartConversion(Adc_ChannelType channel) {
    /* Wait until current conversion finishes */
    while (GET_BIT(ADCSRA, 6) == 1);
    
    /* Analog Channel and Gain Selection Bits */
    ADMUX &= 0b11100000;
    ADMUX |= channel;

    /* ADC Start Conversion */
    SET_BIT(ADCSRA, 6);
}

u16 Adc_GetResultSync(void) {
    /* Wait until conversion completes */
    while(GET_BIT(ADCSRA, 4) == 0);
    /* Clear flag */
    SET_BIT(ADCSRA, 4);
    /* Return result */
    return (ADCDATA&0x3FF);
}

Adc_StateType Adc_GetResultAsync(u16* result_ref) {
    if (GET_BIT(ADCSRA, 4) == 0) {
        return ADC_NOT_COMPLETE;
    }
    else {
        /* Clear flag */
        SET_BIT(ADCSRA, 4);
        /* Write result in pointer */
        *result_ref = (ADCDATA&0x3FF);
        /* Return result */
        return ADC_COMPLETE;
    }
}

void Adc_EnableNotification(void) {
    SET_BIT(ADCSRA, 3);
}
void Adc_DisableNotification(void) {
    CLR_BIT(ADCSRA, 3);
}
void Adc_SetCallback(void (*funcPtr) (u16 data)) {
    Adc_Callback = funcPtr;
}



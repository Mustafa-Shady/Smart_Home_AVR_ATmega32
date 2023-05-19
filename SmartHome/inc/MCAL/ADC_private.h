/*
 * ADC_private.h
 *
 *  Created on: Apr 4, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_ADC_PRIVATE_H_
#define INC_MCAL_ADC_PRIVATE_H_


/************* ADC Registers *************/
#define ADMUX		*((volatile u8*) 0x27)
#define REFS0               6
#define REFS1               7
#define ADCSRA		*((volatile u8*) 0x26)
#define ADCDATA		*((volatile u16*) 0x24)
#define ADCL		*((volatile u8*) 0x24)
#define ADCH		*((volatile u8*) 0x25)
#define SFIOR		*((volatile u8*) 0x50)


#define VECTOR_ADC              __vector_16

#define ISR(vector)     void vector (void) __attribute__((signal));\
void vector (void)



#endif /* INC_MCAL_ADC_PRIVATE_H_ */

/*
 * GPT_private.h
 *
 *  Created on: Apr 8, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_GPT_PRIVATE_H_
#define INC_MCAL_GPT_PRIVATE_H_

/************* Timer/Counter Iterrupt *************/
#define TIMSK		*((volatile u8*) 0x59)
#define TIFR		*((volatile u8*) 0x58)

/************* Timer/Counter 0 *************/
#define TCCR0		*((volatile u8*) 0x53)
#define TCNT0		*((volatile u8*) 0x52)
#define OCR0		*((volatile u8*) 0x5C)

/************* Timer/Counter 1 *************/
#define TCCR1A		*((volatile u8*) 0x4F)
#define TCCR1B		*((volatile u8*) 0x4E)

#define TCNT1		*((volatile u16*) 0x4C)
#define TCNT1L		*((volatile u8*) 0x4C)
#define TCNT1H		*((volatile u8*) 0x4D)

#define OCR1A		*((volatile u16*) 0x4A)
#define OCR1AL		*((volatile u8*) 0x4A)
#define OCR1AH		*((volatile u8*) 0x4B)

#define OCR1B		*((volatile u16*) 0x48)
#define OCR1BL		*((volatile u8*) 0x48)
#define OCR1BH		*((volatile u8*) 0x49)

#define ICR1		*((volatile u16*) 0x46)
#define ICR1L		*((volatile u8*) 0x46)
#define ICR1H		*((volatile u8*) 0x47)


/************* Timer/Counter 2 *************/
#define TCCR2		*((volatile u8*) 0x45)
#define TCNT2		*((volatile u8*) 0x44)
#define OCR2		*((volatile u8*) 0x43)

#define VECTOR_INT1             __vector_2
#define VECTOR_INT2             __vector_3
#define VECTOR_TIM2_COMP        __vector_4
#define VECTOR_TIM2_OVF         __vector_5
#define VECTOR_TIM1_CAPT        __vector_6
#define VECTOR_TIM1_COMPA       __vector_7
#define VECTOR_TIM1_COMPB       __vector_8
#define VECTOR_TIM1_OVF         __vector_9
#define VECTOR_TIM0_COMP        __vector_10
#define VECTOR_TIM0_OVF         __vector_11

#define ISR_GPT_INT_OFF         0
#define ISR_GPT_INT_ON          1

#define ISR_ENABLE            ISR_GPT_INT_ON

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)


#endif /* INC_MCAL_GPT_PRIVATE_H_ */

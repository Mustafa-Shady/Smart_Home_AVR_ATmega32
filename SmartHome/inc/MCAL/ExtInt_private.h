/*
 * ExtInt_private.h
 *
 *  Created on: Apr 4, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_EXTINT_PRIVATE_H_
#define INC_MCAL_EXTINT_PRIVATE_H_
#include <MCAL/DIO_interface.h>


/************* External Interrupt Registers *************/
#define MCUCR		*((volatile u8*) 0x55)
#define MCUCSR		*((volatile u8*) 0x54)
#define GICR		*((volatile u8*) 0x5B)
#define GIFR		*((volatile u8*) 0x5A)
#define MCUCR_ISC00         0
#define MCUCR_ISC01         1
#define MCUCR_ISC10         2
#define MCUCR_ISC11         3
#define MCUCSR_ISC2         6
#define GICR_INT2           5
#define GICR_INT0           6
#define GICR_INT1           7
#define GIFR_INTF2          5
#define GIFR_INTF0          6
#define GIFR_INTF1          7

#define VECTOR_INT0             __vector_1
#define VECTOR_INT1             __vector_2
#define VECTOR_INT2             __vector_3

#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)

#define EXTINT_ON      1
#define EXTINT_OFF     0

#define EXTINT_PIN_INT0     DIO_PORTD,DIO_PIN2
#define EXTINT_PIN_INT1     DIO_PORTD,DIO_PIN3
#define EXTINT_PIN_INT2     DIO_PORTB,DIO_PIN2


#endif /* INC_MCAL_EXTINT_PRIVATE_H_ */

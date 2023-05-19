/*
 * UART_private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_UART_PRIVATE_H_
#define INC_MCAL_UART_PRIVATE_H_

/************* UART *************/
#define UDR         *((volatile u8*) 0x2C)
#define UCSRA		*((volatile u8*) 0x2B)
#define UCSRB		*((volatile u8*) 0x2A)
#define UCSRC		*((volatile u8*) 0x40)
#define UBRRL		*((volatile u8*) 0x29)
#define UBRRH		*((volatile u8*) 0x40)

#define VECTOR_UART_RX          __vector_13
#define VECTOR_UART_REG_EMPTY   __vector_14
#define VECTOR_UART_TX          __vector_15


#define ISR(vector) void vector (void) __attribute__((signal));\
void vector (void)

#endif /* INC_MCAL_UART_PRIVATE_H_ */

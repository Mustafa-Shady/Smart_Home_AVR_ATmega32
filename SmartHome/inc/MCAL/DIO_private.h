/************************************************************************/
/*Author      : Asmaa Mohsen										    */
/*File Name   : DIO_private.h                                           */
/*Layer       : MCAL												    */
/*Description : This file contains private paremeters of DIO module     */
/*Date        : 22 March 2023                                           */
/************************************************************************/

/*preprocessor header file guard*/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


/************** PORTA Registers **************/
#define DDRA		*((volatile u8*) 0x3A)
#define PORTA		*((volatile u8*) 0x3B)
#define PINA		*((const volatile u8*) 0x39)

/************* PORTB Registers *************/
#define DDRB		*((volatile u8*) 0x37)
#define PORTB		*((volatile u8*) 0x38)
#define PINB		*((const volatile u8*) 0x36)

/************* PORTC Registers *************/
#define DDRC		*((volatile u8*) 0x34)
#define PORTC		*((volatile u8*) 0x35)
#define PINC		*((const volatile u8*) 0x33)

/************* PORTD Registers *************/
#define DDRD		*((volatile u8*) 0x31)
#define PORTD		*((volatile u8*) 0x32)
#define PIND		*((const volatile u8*) 0x30)





/************* I2C *************/
#define TWBR        *((volatile u8*) 0x20)
#define TWCR		*((volatile u8*) 0x56)
#define TWSR		*((volatile u8*) 0x21)
#define TWDR        *((volatile u8*) 0x23)
#define TWAR		*((volatile u8*) 0x22)

#endif /* DIO_PRIVATE_H_ */

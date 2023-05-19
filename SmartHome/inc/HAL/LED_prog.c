/*
 * LED_pog.c
 *
 *  Created on: Mar 25, 2023
 *      Author: 20115
 */
#include <HAL/LED_Cfg.h>
#include <HAL/LED_interface.h>


/*Func to initialize LED*/
void LED_voidInit(u8 Copy_u8PortID,u8 Copy_u8Pin)
{
	DIO_voidSetPinDirection(Copy_u8PortID,Copy_u8Pin,DIO_PORT_OUTPUT);
}

/*Func to turn LED_ON*/
void LED_voidTurnOn(u8 Copy_u8PortID,u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID,Copy_u8Pin,DIO_HIGH_PIN );
}

/*Func to turn LED_OFF*/
void LED_voidTurnOff(u8 Copy_u8PortID,u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID,Copy_u8Pin,DIO_LOW_PIN );

}
/*Func to toggle LED*/
void LED_voidToggle(u8 Copy_u8PortID,u8 Copy_u8Pin)
{
	DIO_voidTogglePin(Copy_u8PortID,Copy_u8Pin);
}


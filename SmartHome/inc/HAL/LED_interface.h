/*
 * LED_interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: 20115
 */

#ifndef INC_HAL_LED_INTERFACE_H_
#define INC_HAL_LED_INTERFACE_H_

#include <HAL/LED_Cfg.h>
#include <MCAL/DIO_interface.h>

/*define LED Status*/
#define LED_ON		1
#define LED_OFF		0

/*Func to initialize LED*/
void LED_voidInit(u8 Copy_u8PortID,u8 Copy_u8Pin);

/*Func to turn LED_ON*/
void LED_voidTurnOn(u8 Copy_u8PortID,u8 Copy_u8Pin);

/*Func to turn LED_OFF*/
void LED_voidTurnOff(u8 Copy_u8PortID,u8 Copy_u8Pin);

/*Func to toggle LED*/
void LED_voidToggle(u8 Copy_u8PortID,u8 Copy_u8Pin);




#endif /* INC_HAL_LED_INTERFACE_H_ */

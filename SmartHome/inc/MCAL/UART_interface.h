/*
 * UART_interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_UART_INTERFACE_H_
#define INC_MCAL_UART_INTERFACE_H_
#include <lib/STD_TYPES.h>
#include <MCAL/UART_Cfg.h>
#include <MCAL/UART_private.h>

typedef enum {
    UART_RX,     
    UART_REG_EMPTY,
    UART_TX       
} Uart_INT_Type;

void Uart_Init(void);
void Uart_Transmit(u8 data);
u8 Uart_Receive(void);
void Uart_SendString(u8*str);
void Uart_ReceiveWord(u8  arr[5]);
void Uart_SetCallBack(Uart_INT_Type type, void (*funcPtr) (void) );


#endif /* INC_MCAL_UART_INTERFACE_H_ */

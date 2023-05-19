/*
 * UART_prog.c
 *
 *  Created on: Apr 10, 2023
 *      Author: 20115
 */

#include <lib/BIT_MATHS.h>
#include <lib/STD_TYPES.h>
#include <MCAL/DIO_interface.h>
#include <MCAL/UART_Cfg.h>
#include <MCAL/UART_interface.h>
#include <MCAL/UART_private.h>


void (*Uart_Callback_EMTY) (void) = NULL_PTR;
void (*Uart_Callback_RX)   (void) = NULL_PTR;
void (*Uart_Callback_TX)   (void) = NULL_PTR;

ISR(VECTOR_UART_REG_EMPTY)
{
    if (NULL_PTR != Uart_Callback_EMTY) {
        Uart_Callback_EMTY();
    }
}

ISR(VECTOR_UART_RX)
{
    if (NULL_PTR != Uart_Callback_RX) {
        Uart_Callback_RX();
    }
}

ISR(VECTOR_UART_TX)
{
    if (NULL_PTR != Uart_Callback_TX) {
        Uart_Callback_TX();
    }
}

void Uart_Init(void) {
    u8 temp = 0;
    u16 baud_register_val = 0;
    /* Receiver Enable */
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT_FLOAT);
    SET_BIT(UCSRB, 4);

/*******************************************************************/

    /* Transmitter Enable */
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
    SET_BIT(UCSRB, 3);
    
/*******************************************************************/


    /* Register Select (UCSRC) */
    SET_BIT(temp, 7);
    
/*******************************************************************/

    /* Character Size (Num bit) */

#if   UART_NUM_OF_DATA_BITS == UART_5_DATA_BITS

    CLR_BIT(temp,1);
    CLR_BIT(temp,2);
    CLR_BIT(UCSRB,2);

#elif UART_NUM_OF_DATA_BITS == UART_6_DATA_BITS

    SET_BIT(temp,1);
    CLR_BIT(temp,2);
    CLR_BIT(UCSRB,2);

#elif UART_NUM_OF_DATA_BITS == UART_7_DATA_BITS

    CLR_BIT(temp,1);
    SET_BIT(temp,2);
    CLR_BIT(UCSRB,2);

#elif UART_NUM_OF_DATA_BITS == UART_8_DATA_BITS

    SET_BIT(temp,1);
    SET_BIT(temp,2);
    CLR_BIT(UCSRB,2);

#elif UART_NUM_OF_DATA_BITS == UART_9_DATA_BITS

    SET_BIT(temp,1);
    SET_BIT(temp,2);
    CLR_BIT(UCSRB,2);

#endif
      
/*******************************************************************/

    /* PARITY Select */

#if UART_NUM_OF_PARITY_BITS == UART_0_PARITY_BITS

    CLR_BIT(temp,4);
    CLR_BIT(temp,5);

#elif UART_NUM_OF_PARITY_BITS == UART_1_PARITY_BITS 

    SET_BIT(temp,4);
    SET_BIT(temp,5);

#elif UART_NUM_OF_PARITY_BITS == UART_2_PARITY_BITS 

    CLR_BIT(temp,4);
    SET_BIT(temp,5);

#endif
    
/*******************************************************************/

    /* INT Select */

#if  UART_INT_RX ==  UART_STATE_OFF

    CLR_BIT(UCSRB,7);

#elif  UART_INT_RX ==  UART_STATE_ON

    SET_BIT(UCSRB,7);

#endif

#if  UART_INT_TX ==  UART_STATE_OFF

    CLR_BIT(UCSRB,6);

#elif  UART_INT_TX ==  UART_STATE_ON

    SET_BIT(UCSRB,6);

#endif

#if  UART_INT_REG_EMPTY == UART_STATE_OFF

    CLR_BIT(UCSRB,5);

#elif  UART_INT_REG_EMPTY == UART_STATE_ON

    SET_BIT(UCSRB,5);
    
#endif
    
/*******************************************************************/

    /* STOP Select */

#if   UART_NUM_OF_STOP_BITS == UART_1_STOP_BITS
    CLR_BIT(temp,3);
#elif UART_NUM_OF_STOP_BITS == UART_2_STOP_BITS
    SET_BIT(temp,3);
#endif
    
/*******************************************************************/

    UCSRC = temp;

/*******************************************************************/

    /* Baud Rate Registers */
    
    baud_register_val = (UART_FREQ_OSC/((u32)16*UART_BAUDRATE)) - 1;
    UBRRL = (u8) baud_register_val;
    UBRRH = (u8) ((baud_register_val>>8)&0x0F);

/*******************************************************************/
}

void Uart_Transmit(u8 data) {
    /* Wait for USART Data Register Empty */
    while (GET_BIT(UCSRA, 5) == 0);
    /* Write Data Register */
    UDR = data;
    /* Wait for USART Transmit Complete */
    while (GET_BIT(UCSRA, 6) == 0);
    /* Clear USART Transmit Complete Flag */
    SET_BIT(UCSRA, 6);
}

u8 Uart_Receive(void) {
    /* Wait for USART Receive Complete */
    while (GET_BIT(UCSRA, 7) == 0);
    return UDR;
}


void Uart_SetCallBack(Uart_INT_Type type, void (*funcPtr) (void) )
{     
    switch (type)
    {
    case UART_REG_EMPTY:
        Uart_Callback_EMTY = funcPtr;
        break;
    case UART_TX:
        Uart_Callback_RX = funcPtr;
        break;
    case UART_RX:
        Uart_Callback_TX = funcPtr;
        break;
    default:
        break;
    }
}

void Uart_SendString(u8*str)
{
    u8 iterator=0;

    while (str[iterator] != '\0')
    {
        Uart_Transmit(str[iterator]);
        iterator++;
    }
    
}

void Uart_ReceiveWord(u8 *arr)
{   

	u8 itirator = 0;
	u8 data;

	do {
		// Wait for incoming data
		while (!(UCSRA  & (1 << 7)));

		// Read the incoming data
		data = UDR;

		// Store the character in the buffer
		arr[itirator++] = data;
	}
	while (data != '+');

	// Add null character to terminate the string
	arr[itirator-1] = '\0';

}

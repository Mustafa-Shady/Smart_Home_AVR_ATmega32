/*
 * UART_Cfg.h
 *
 *  Created on: Apr 10, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_UART_CFG_H_
#define INC_MCAL_UART_CFG_H_


/*Type of States*/

#define UART_STATE_OFF          1
#define UART_STATE_ON           2

/*Number of DATA BITS*/

#define UART_5_DATA_BITS        1
#define UART_6_DATA_BITS        2
#define UART_7_DATA_BITS        3
#define UART_8_DATA_BITS        4
#define UART_9_DATA_BITS        5

/*Select number of DATA BITS*/
#define UART_NUM_OF_DATA_BITS       UART_8_DATA_BITS

/*******************************************************************/

/*Number of PARITY BITS*/

#define UART_0_PARITY_BITS        UART_STATE_OFF
#define UART_1_PARITY_BITS              2
#define UART_2_PARITY_BITS              3



/*Select number of PARITY BITS*/
#define UART_NUM_OF_PARITY_BITS       UART_STATE_OFF

/*******************************************************************/

/*Enable of INT*/

#define UART_INT_RX               UART_STATE_OFF
#define UART_INT_REG_EMPTY        UART_STATE_OFF
#define UART_INT_TX               UART_STATE_OFF   

/*******************************************************************/
/*Number of STOP BITS*/

#define UART_1_STOP_BITS              1
#define UART_2_STOP_BITS              2

/*Select number of STOP BITS*/
#define UART_NUM_OF_STOP_BITS       UART_1_STOP_BITS

/*******************************************************************/

/*Select UART_FREQ_OSC and UART_BAUDRATE */

#define UART_FREQ_OSC       8000000UL
#define UART_BAUDRATE       9600UL


#endif /* INC_MCAL_UART_CFG_H_ */

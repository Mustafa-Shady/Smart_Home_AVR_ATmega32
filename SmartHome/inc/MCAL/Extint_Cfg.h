/*
 * Extint_Cfg.h
 *
 *  Created on: Apr 4, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_EXTINT_CFG_H_
#define INC_MCAL_EXTINT_CFG_H_

/***********************************************************/


#define EXTINT_TRG_LOW_LEVEL        1       
#define EXTINT_TRG_ON_CHANGE        2
#define EXTINT_TRG_FALLING_EDGE     3
#define EXTINT_TRG_RISING_EDGE      4
/***********************************************************/

/*Turn ON/OFF Channels*/

#define EXTINT_INT0     EXTINT_OFF
#define EXTINT_INT1     EXTINT_OFF
#define EXTINT_INT2     EXTINT_OFF


/***********************************************************/

/* Select Type of Trigger edge*/

// #define EXTINT_INT0_TRG_TYPE    EXTINT_TRG_ON_CHANGE
// #define EXTINT_INT1_TRG_TYPE    EXTINT_TRG_ON_CHANGE
// #define EXTINT_INT2_TRG_TYPE    EXTINT_TRG_ON_CHANGE

#endif /* INC_MCAL_EXTINT_CFG_H_ */

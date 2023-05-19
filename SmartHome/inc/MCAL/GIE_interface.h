/*
 * GIE_intefrace.h
 *
 *  Created on: Apr 4, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_GIE_INTERFACE_H_
#define INC_MCAL_GIE_INTERFACE_H_



#include <lib/BIT_MATHS.h>
#include <lib/STD_TYPES.h>
#include <MCAL/GIE_private.h>

inline void Gie_Enable(void) {
    SET_BIT(SREG,SREG_I);
}

inline void Gie_Disable(void) {
    CLR_BIT(SREG,SREG_I);
}

#endif /* INC_MCAL_GIE_INTERFACE_H_ */

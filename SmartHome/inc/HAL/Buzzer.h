/*
 * Buzzer.h
 *
 *  Created on: May 18, 2023
 *      Author: shady
 */

#ifndef INC_HAL_BUZZER_H_
#define INC_HAL_BUZZER_H_

#include "MCAL/PWM_interface.h"


void BuzzerInit(void);
void BuzzerOn(u8 Time);
void BuzzerOff(void);


#endif /* INC_HAL_BUZZER_H_ */

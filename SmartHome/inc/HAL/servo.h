/*
 * servo.h
 *
 *  Created on: Apr 15, 2023
 *      Author: 20115
 */

#ifndef INC_HAL_SERVO_H_
#define INC_HAL_SERVO_H_
#include <lib/STD_TYPES.h>
#include <MCAL/GPT_interface.h>
#include <MCAL/PWM_interface.h>

void SERVO_init(void);
void SERVO_SetAngle(u16 angle);



#endif /* INC_HAL_SERVO_H_ */

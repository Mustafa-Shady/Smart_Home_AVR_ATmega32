/*
 * Extint_interface.h
 *
 *  Created on: Apr 4, 2023
 *      Author: 20115
 */

#ifndef INC_MCAL_EXTINT_INTERFACE_H_
#define INC_MCAL_EXTINT_INTERFACE_H_
#include <MCAL/Extint_Cfg.h>
#include <MCAL/ExtInt_private.h>


#if EXTINT_INT0

void ExtInt0_SetTriggerEdge(u8 edge);
void ExtInt0_EnableNotification(void);
void ExtInt0_DisableNotification(void);
void ExtInt0_ClearFlag(void);
u8   ExtInt0_ReadFlag(void);
void ExInt0_SetCallback(void (*funcPtr) (void));

#endif
#if EXTINT_INT1

void ExtInt1_SetTriggerEdge(u8 edge);
void ExtInt1_EnableNotification(void);
void ExtInt1_DisableNotification(void);
void ExtInt1_ClearFlag(void);
u8   ExtInt1_ReadFlag(void);
void ExInt1_SetCallback(void (*funcPtr) (void));

#endif
#if EXTINT_INT2

void ExtInt2_SetTriggerEdge(u8 edge);
void ExtInt2_EnableNotification(void);
void ExtInt2_DisableNotification(void);
void ExtInt2_ClearFlag(void);
u8   ExtInt2_ReadFlag(void);
void ExInt2_SetCallback(void (*funcPtr) (void));

#endif


#endif /* INC_MCAL_EXTINT_INTERFACE_H_ */

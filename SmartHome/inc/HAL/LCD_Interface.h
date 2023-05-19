/*
 * LCD_Interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: GRAPHICS
 */

#ifndef INC_HAL_LCD_INTERFACE_H_
#define INC_HAL_LCD_INTERFACE_H_
#include <HAL/LCD_Cfg.h>
#include "lib/STD_TYPES.h"

void LCD_voidLCDInit(void);
void LCD_voidLCDSendCom(u8 COMM);
void LCD_voidSendComm_4bit(u8 COMM);
void LCD_charDisplayCharcter(char data);
void LCD_voidLCDSendDATA(u8 DATA);
void LCD_voidClearDisplay(void);
void LCD_voidSendData_4bit(u8 DATA);
void LCD_voidLCDSendString(u8 arr[]);
void LCD_voidSend_NUM(s32 num);
void LCD_voidSetCursor(u8 Row,u8 Col);
void LCD_voidSaveSpecialCharacter(u8 location, u8* pattern);
void LCD_voidShiftCursorLeft(u8 count);
void LCD_voidShiftCursorRight(u8 count);
void LCD_voidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col);
void LCD_u8ShiftDisplayRight(u8 count);
void LCD_u8ShiftDisplayLeft(u8 count);
void LCD_voidReturnHome(void);


#endif /* INC_HAL_LCD_INTERFACE_H_ */

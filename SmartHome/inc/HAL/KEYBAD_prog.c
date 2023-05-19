/*
 * KEYBAD_prog.c
 *
 *  Created on: Apr 1, 2023
 *      Author: shady
 */
#include <HAL/KEYBAD_Cfg.h>
#include <HAL/KEYBAD_interface.h>
#include <lib/STD_TYPES.h>
#include <MCAL/DELAY.h>
#include <MCAL/DIO_interface.h>

static void Keypad_SetColumnLevel(u8 column, u8 level);
static u8 Keypad_GetRowLevel(u8 row);

void Keypad_Init(void) {
    /* Configure all rows to input pull up */
    DIO_voidSetPinDirection(KEYPAD_PIN_R1,DIO_PIN_INPUT_PULLUP);
    DIO_voidSetPinDirection(KEYPAD_PIN_R2,DIO_PIN_INPUT_PULLUP);
    DIO_voidSetPinDirection(KEYPAD_PIN_R3,DIO_PIN_INPUT_PULLUP);
    DIO_voidSetPinDirection(KEYPAD_PIN_R4,DIO_PIN_INPUT_PULLUP);
    /* Configure all columns to output */
    DIO_voidSetPinDirection(KEYPAD_PIN_C1,DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PIN_C2,DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PIN_C3,DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PIN_C4,DIO_PIN_OUTPUT);
    /* Set all columns to high */
    DIO_voidSetPinValue(KEYPAD_PIN_C1,DIO_HIGH_PIN);
    DIO_voidSetPinValue(KEYPAD_PIN_C2,DIO_HIGH_PIN);
    DIO_voidSetPinValue(KEYPAD_PIN_C3,DIO_HIGH_PIN);
    DIO_voidSetPinValue(KEYPAD_PIN_C4,DIO_HIGH_PIN);
}

Keypad_ButtonStateType Keypad_GetButtonState(Keypad_ButtonType button) {
    Keypad_ButtonStateType state = KEYPAD_NOT_PRESSED;
    u8 row = button/4;
    u8 column = button%4;
    /* Set column to low */
    Keypad_SetColumnLevel(column, DIO_LOW_PIN);
    /* Read row and check if low */
    if (Keypad_GetRowLevel(row) == DIO_LOW_PIN) {
        _delay_ms(5);
        if (Keypad_GetRowLevel(row) == DIO_LOW_PIN) {
            state = KEYPAD_PRESSED;
        }
    }
    /* Reset column to high */
    Keypad_SetColumnLevel(column, DIO_HIGH_PIN);
    return state;
}


static void Keypad_SetColumnLevel(u8 column, u8 level) {
    switch (column)
    {
    case 0:
        DIO_voidSetPinValue(KEYPAD_PIN_C1, level);
        break;
    case 1:
        DIO_voidSetPinValue(KEYPAD_PIN_C2, level);
        break;
    case 2:
        DIO_voidSetPinValue(KEYPAD_PIN_C3, level);
        break;
    case 3:
        DIO_voidSetPinValue(KEYPAD_PIN_C4, level);
        break;
    
    default:
        break;
    }
}

static u8 Keypad_GetRowLevel(u8 row) {
    u8 level = DIO_HIGH_PIN;
    switch (row)
    {
    case 0:
        level = DIO_u8GetPinValue(KEYPAD_PIN_R1);
        break;
    case 1:
        level = DIO_u8GetPinValue(KEYPAD_PIN_R2);
        break;
    case 2:
        level = DIO_u8GetPinValue(KEYPAD_PIN_R3);
        break;
    case 3:
        level = DIO_u8GetPinValue(KEYPAD_PIN_R4);
        break;
    default:
        break;
    }
    return level;
}


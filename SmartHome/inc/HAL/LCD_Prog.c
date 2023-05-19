#include <HAL/LCD_Interface.h>
#include <lib/BIT_MATHS.h>
#include <lib/STD_TYPES.h>
#include <stdio.h>
#include <math.h>
#include <MCAL/DIO_interface.h>
#include "util/delay.h"

void LCD_voidLCDInit(void)
{
#if    LCD_MODE == _8_BIT
	DIO_voidSetPortDirection(DATA_PORT,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(E_PIN,DIO_PIN_OUTPUT);
	_delay_ms(30);
	LCD_voidLCDSendCom(0b00111000);
	_delay_us(100);
	LCD_voidLCDSendCom(0b00001100);
	_delay_us(100);
	LCD_voidLCDSendCom(0b00000001);
	_delay_ms(2);

#elif  LCD_MODE == _4_BIT

	DIO_voidSetPortDirection(DATA_PORT,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(E_PIN,DIO_PIN_OUTPUT);
	_delay_ms(30);
	LCD_voidLCDSendCom(0x20);
	_delay_us(100);
	LCD_voidSendComm_4bit(0x28);
	_delay_us(100);
	LCD_voidSendComm_4bit(0x0F);
	_delay_us(100);
	LCD_voidSendComm_4bit(0b00000001);
	_delay_ms(2);

#endif
}

void LCD_voidLCDSendCom(u8 COMM)
{

	DIO_voidSetPinValue(RS_PIN,DIO_LOW_PIN);
	DIO_voidSetPinValue(RW_PIN,DIO_LOW_PIN);
	DIO_u8SetPortValue(DATA_PORT,COMM);
	DIO_voidSetPinValue(E_PIN,DIO_HIGH_PIN);
	_delay_us(1000);
	DIO_voidSetPinValue(E_PIN,DIO_LOW_PIN);
_delay_ms(2);
}
void LCD_voidLCDSendDATA(u8 DATA)
{
#if    LCD_MODE == _8_BIT
	DIO_voidSetPinValue(RS_PIN,DIO_HIGH_PIN);
	DIO_voidSetPinValue(RW_PIN,DIO_LOW_PIN);
	DIO_u8SetPortValue(DATA_PORT,DATA);
	DIO_voidSetPinValue(E_PIN,DIO_HIGH_PIN);
	_delay_ms(2);
	DIO_voidSetPinValue(E_PIN,DIO_LOW_PIN);
	_delay_ms(2);
#elif  LCD_MODE == _4_BIT
	DIO_voidSetPinValue(RS_PIN,DIO_HIGH_PIN);
	DIO_voidSetPinValue(RW_PIN,DIO_LOW_PIN);
	DIO_u8SetPortValue(DATA_PORT,DATA & 0xf0);
	DIO_voidSetPinValue(E_PIN,DIO_HIGH_PIN);
	_delay_us(1000);
	DIO_voidSetPinValue(E_PIN,DIO_LOW_PIN);
	DIO_u8SetPortValue(DATA_PORT,DATA<<4);
	DIO_voidSetPinValue(E_PIN,DIO_HIGH_PIN);
	_delay_us(1000);
	DIO_voidSetPinValue(E_PIN,DIO_LOW_PIN);

#endif
}
void LCD_charDisplayCharcter(char data) {
    LCD_voidLCDSendDATA(data);
}
void LCD_voidReturnHome(void)
{
	LCD_voidLCDSendCom(0b00000010);

}
void LCD_voidLCDSendString(u8 arr[])
{
	u8 local_itirator_variable =0;
	while(arr[local_itirator_variable]!='\0')
	{
		LCD_voidLCDSendDATA(arr[local_itirator_variable]);
		local_itirator_variable ++;
	}
}
void LCD_voidClearDisplay(void)
{
	LCD_voidLCDSendCom(0b00000001);
	LCD_voidSetCursor(0,0);

}

void LCD_voidSaveSpecialCharacter(u8 location, u8* pattern)
{
    u8 i=location;

    if (location < 8) {
        location *= 8;
        SET_BIT(location, 6);
 #if    LCD_MODE == _8_BIT
        LCD_voidLCDSendCom(location);
#elif  LCD_MODE == _4_BIT
        LCD_voidSendComm_4bit(location);
#endif
        for (i=0; i<8; i++) {
        	LCD_voidLCDSendDATA(pattern[i]);

        }

    }
#if    LCD_MODE == _8_BIT
       LCD_voidLCDSendCom(0b10000000);
#elif  LCD_MODE == _4_BIT
       LCD_voidSendComm_4bit(0b10000000);
#endif

}
void LCD_voidSend_NUM(s32 num)
{
	u64 reversed = 0;
    u8 digitsCounter = 0;
    if (num < 0) {
        num = num * -1;
        LCD_voidLCDSendDATA('-');
    }
    do {
        reversed = (reversed*10) + (num%10);
        num /= 10;
        digitsCounter++;
    } while (num > 0);
    while (digitsCounter > 0) {
        LCD_voidLCDSendDATA(reversed%10 + '0');
        reversed /= 10;
        digitsCounter--;
    }
}
void LCD_voidSetCursor(u8 Row,u8 Col)
{
	u8 address = Row*0x40 + Col;
    SET_BIT(address, 7);
    LCD_voidLCDSendCom(address);
}

void LCD_u8ShiftDisplayRight(u8 count)
{
	while (count > 0) {
        LCD_voidLCDSendCom(0b00011100);
        count--;
    }
}
void LCD_u8ShiftDisplayLeft(u8 count)
{
	while (count > 0) {
		LCD_voidLCDSendCom(0b00011000);
        count--;
    }
}

void LCD_voidSendComm_4bit(u8 COMM)
{
	DIO_voidSetPinValue(RS_PIN,DIO_LOW_PIN);
	DIO_voidSetPinValue(RW_PIN,DIO_LOW_PIN);
	DIO_u8SetPortValue(DATA_PORT,COMM & 0xf0);
	DIO_voidSetPinValue(E_PIN,DIO_HIGH_PIN);
	_delay_us(1000);
	DIO_voidSetPinValue(E_PIN,DIO_LOW_PIN);
	DIO_u8SetPortValue(DATA_PORT,COMM<<4);
	DIO_voidSetPinValue(E_PIN,DIO_HIGH_PIN);
	_delay_us(1000);
	DIO_voidSetPinValue(E_PIN,DIO_LOW_PIN);
}

void LCD_voidShiftCursorRight(u8 count) {
    while (count > 0) {
    	LCD_voidLCDSendCom(0b00010100);
        count--;
    }
}

void LCD_voidShiftCursorLeft(u8 count) {
    while (count > 0) {
    	LCD_voidLCDSendCom(0b00010000);
        count--;
    }
}
void LCD_voidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col)
{
	/*Local variable to get the address of the target grid*/
	u8 Local_u8GridAddress = 0 ;

	if(Copy_u8Row == 0 )
		Local_u8GridAddress = Copy_u8Col ;

	else if(Copy_u8Row == 1)
		Local_u8GridAddress = Copy_u8Col + 0x40 ;

	SET_BIT(Local_u8GridAddress , 7) ;

	/*sending Set DDRAM Address command with target address*/
	LCD_voidLCDSendCom(Local_u8GridAddress);

}

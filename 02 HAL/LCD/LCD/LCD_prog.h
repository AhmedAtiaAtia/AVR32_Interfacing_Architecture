#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_int.h"

#include"LCD_int.h"

#include<util/delay.h>



void LCD_Init(void)
{
	/* Delay for VDD = 4.5 Volt		*/
	_delay_ms(35);
	/*Function Set 2lines 5*7 font	*/
	LCD_writeCMD(0b00111000);
	_delay_ms(1);
	/*Display On*/
	LCD_writeCMD(0b00001100);
	_delay_ms(1);
	/*Clear Display*/
	LCD_writeCMD(0b00000001);
	_delay_ms(2);	
	
	/*Cursor increase*/
	LCD_writeCMD(0b00000110);
}
void LCD_writeChar(u8 Data)
{

	DIO_SetPinValue(CONTROL_PORT , RS , HIGH );
	DIO_SetPinValue(CONTROL_PORT , Rw , LOW );
	
	DIO_SetPortValue(DATA_PORT , Data);
	
	DIO_SetPinValue(CONTROL_PORT , EN , HIGH );
	_delay_ms(2);
	
	DIO_SetPinValue(CONTROL_PORT , RS , LOW );
	_delay_ms(2);		
	
}
void LCD_writeCMD(u8 CMD)
{
	DIO_SetPinValue(CONTROL_PORT , RS , LOW );
	DIO_SetPinValue(CONTROL_PORT , Rw , LOW );
	
	DIO_SetPortValue(DATA_PORT , CMD);
	
	DIO_SetPinValue(CONTROL_PORT , EN , HIGH );
	_delay_ms(2);
	
	DIO_SetPinValue(CONTROL_PORT , RS , LOW );
	_delay_ms(2);	
}
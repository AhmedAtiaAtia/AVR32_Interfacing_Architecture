/***************************************************/
/* Author : Ahmed Shaker                           */
/* Date : 9 Mars 2018                              */
/* Version : V01                                   */
/***************************************************/

#include"STD_TYPES.h"
#include"Bit_Math.h"

#include"DIO_int.h"

#include"LCD_PRIV.h"
#include"LCD_CONFIG.h"
#include"LCD_INT.h"

#define F_CPU 8000000UL
#include"util/delay.h"



/* Description : This function Initialize LCD      */
void LCD_voidInitialize(void){
	/*Wait For more 30ms*/
	_delay_ms(35);
	/*Function Set Command*/
	LCD_voidWriteCommand(0b00111000);
	/*Wait For more 39us*/
	_delay_ms(1);
	/* LCD on/off Command */
	LCD_voidWriteCommand(0x0c);
	/*Wait For more 39us*/
	_delay_ms(1);
	/* Display Clear */
	LCD_voidWriteCommand(0b00000001);
	/*Wait For more 1.53 ms*/
	_delay_ms(2);
	/*	Entry Mode SET*/
//	LCD_voidWriteCommand(0b00000110);
	LCD_voidWriteCommand(0b00000110);
	/*Rest Enable */
	DIO_voidSetPinValue(LCD_u8_PIN_E , DIO_u8_LOW);
	/*Wait To Finish */
	_delay_ms(2);
	
	
}

/* Description : This function Write Date To LCD   */
void LCD_voidWriteData(u8 Copy_u8Date){
	/*RS = 1*/
	DIO_voidSetPinValue(LCD_u8_PIN_RS , DIO_u8_HIGH);
	/*Call Execute */
	LCD_voidExecute(Copy_u8Date);
	
}

/* Description : This function Send Command To LCD */
void LCD_voidWriteCommand(u8 Copy_u8Cmd){
	
	/*RS = 0*/
	DIO_voidSetPinValue(LCD_u8_PIN_RS , DIO_u8_LOW);

	/*Call Execute */
	LCD_voidExecute(Copy_u8Cmd);

}



void LCD_voidExecute(u8 Copy_u8DataCmd){
	/*RW = 0*/
	DIO_voidSetPinValue(LCD_u8_PIN_RW , DIO_u8_LOW);
	/*Out The Command Variable On Data Lines          */
	
	/*PIN 0*/
	if(GET_BIT(Copy_u8DataCmd,0)){
		DIO_voidSetPinValue(LCD_u8_PIN_0 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_0 , DIO_u8_LOW);
	}
	
	/*PIN 1*/
	if(GET_BIT(Copy_u8DataCmd,1)){
		DIO_voidSetPinValue(LCD_u8_PIN_1 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_1 , DIO_u8_LOW);
	}
	
	/*PIN 2*/
	if(GET_BIT(Copy_u8DataCmd,2)){
		DIO_voidSetPinValue(LCD_u8_PIN_2 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_2 , DIO_u8_LOW);
	}
	
	/*PIN 3*/
	if(GET_BIT(Copy_u8DataCmd,3)){
		DIO_voidSetPinValue(LCD_u8_PIN_3 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_3 , DIO_u8_LOW);
	}
	
	/*PIN 4*/
	if(GET_BIT(Copy_u8DataCmd,4)){
		DIO_voidSetPinValue(LCD_u8_PIN_4 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_4 , DIO_u8_LOW);
	}
	
	
	/*PIN 5*/
	if(GET_BIT(Copy_u8DataCmd,5)){
		DIO_voidSetPinValue(LCD_u8_PIN_5 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_5 , DIO_u8_LOW);
	}
	
	/*PIN 6*/
	if(GET_BIT(Copy_u8DataCmd,6)){
		DIO_voidSetPinValue(LCD_u8_PIN_6 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_6 , DIO_u8_LOW);
	}
	
	/*PIN 7*/
	if(GET_BIT(Copy_u8DataCmd,7)){
		DIO_voidSetPinValue(LCD_u8_PIN_7 , DIO_u8_HIGH);
	}else{
		DIO_voidSetPinValue(LCD_u8_PIN_7 , DIO_u8_LOW);
	}
	
	/*Enable Puls */
	
	DIO_voidSetPinValue(LCD_u8_PIN_E , DIO_u8_HIGH);
	/* Wait */
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8_PIN_E , DIO_u8_LOW);
	_delay_ms(2);
	
}

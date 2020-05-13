/*
 * main.c
 *
 *  Created on: May 18, 2019
 *      Author: Boon
 */
#include "Std_types.h"

#include "Bit_Math.h"

#include <util/delay.h>

#include "DIO_int.h"
#include "USART_int.h"
#include "LCD_int.h"


int main()
{
	//u8 data = 0 ;
	DIO_voidInitialization();
	USART_Init();
	while(1)
	{
		USART_Transmit('A');
/*
		data = USART_Receive();
		if( data == 'A' )
		{

			DIO_voidSetPinValue(DIO_u8_PIN_0 , DIO_u8_HIGH );
			DIO_voidSetPinValue(DIO_u8_PIN_1 , DIO_u8_LOW );
			_delay_ms(500);
			DIO_voidSetPinValue(DIO_u8_PIN_0 , DIO_u8_LOW );
			_delay_ms(500);
		}
		else
		{
			DIO_voidSetPinValue(DIO_u8_PIN_1 , DIO_u8_HIGH );
			DIO_voidSetPinValue(DIO_u8_PIN_0 , DIO_u8_LOW );
			_delay_ms(500);
		}


*/
	}
	return 0 ;
}
/*

while(1)
{

}

*/

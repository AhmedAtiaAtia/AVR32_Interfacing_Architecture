/*
 * main.c
 *
 *  Created on: Apr 26, 2019
 *      Author: Boon
 */

#include "Lbt_int.h"
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "EXT0_int.h"
#include "GIE_int.h"
#include <util/delay.h>

void Boon(void)
{
	DIO_voidSetPinValue(0 , DIO_u8_HIGH);
	_delay_ms(2000);
	DIO_voidSetPinValue(0 , DIO_u8_LOW);
	_delay_ms(2000);
	DIO_voidSetPinValue(0 , DIO_u8_HIGH);
	_delay_ms(2000);
	DIO_voidSetPinValue(0 , DIO_u8_LOW);
}

int main ()
{

	DIO_voidInitialization();
	EXT0_voidInit();

	//DIO_voidSetPinDirection(DIO_u8_PIN_26 , DIO_u8_OUTPUT);

	DIO_voidSetPinValue(DIO_u8_PIN_26 , DIO_u8_HIGH);
	EXT0_voidCallBack(Boon);
	EXT0_voidEnable();
	GIE_voidEnable();
	while(1);

	return 0 ;
}

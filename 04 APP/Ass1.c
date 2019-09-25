
/*
 * main.c
 *
 *  Created on: Apr 5, 2019
 *      Author: Boon
 */
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "SEV_int.h"
#include <util/delay.h>

int main(void)
{
	DIO_voidInitialization();

	while(1)
	{
		u8 i;
		/*SEV_voidSet7SegmentValue(SEV_LEFT , 0);*/
		for(i=DIO_u8_PIN_0 ; i < DIO_u8_PIN_7 ; i++)
		{
			DIO_voidSetPinValue(i,DIO_u8_HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(i,DIO_u8_LOW);

		}


		for(i=DIO_u8_PIN_7 ; i > DIO_u8_PIN_0 ; i--)
		{
			DIO_voidSetPinValue(i,DIO_u8_HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(i,DIO_u8_LOW);

		}
	}
	return 0;
}

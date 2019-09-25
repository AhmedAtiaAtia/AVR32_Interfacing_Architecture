
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
    //u8 arr[8]=CONC_BIT(7,); //{ DIO_u8_PIN_7 , DIO_u8_PIN_6 , DIO_u8_PIN_5 , DIO_u8_PIN_4 , DIO_u8_PIN_3 , DIO_u8_PIN_2 , DIO_u8_PIN_1 , DIO_u8_PIN_0};
	while(1)
	{
		u8 i , j = 7;

		//SEV_voidSet7SegmentValue(SEV_LEFT , 0);
		//SEV_voidSet7SegmentValue(SEV_RIGHT , 1);
		for( i = 0 ; i < 256 ; i++ )
		{
			DIO_voidSetPortaValue(i);
		    _delay_ms(250);
			DIO_voidSetPortaValue(0);
		}


		/*for(i=DIO_u8_PIN_0 ; i < DIO_u8_PIN_7 ; i++)
		{
			if( i == 4 && j == 3 )
			{
				i = 5 ;
				j = 2 ;
			}

			DIO_voidSetPinValue(i,DIO_u8_HIGH);
			DIO_voidSetPinValue(j,DIO_u8_HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(i,DIO_u8_LOW);
			DIO_voidSetPinValue(j,DIO_u8_LOW);
			j--;

		}
*/

		/*
		j = 7

				for(i=DIO_u8_PIN_7 ; i > DIO_u8_PIN_4 ; i++)
				{
					DIO_voidSetPinValue(i,DIO_u8_HIGH);
					DIO_voidSetPinValue(j,DIO_u8_HIGH);
					_delay_ms(1000);
					DIO_voidSetPinValue(i,DIO_u8_LOW);
					DIO_voidSetPinValue(j,DIO_u8_LOW);
					j--;
				}*/

		/*for(i=DIO_u8_PIN_7 ; i > DIO_u8_PIN_0 ; i--)
		{
			DIO_voidSetPinValue(i,DIO_u8_HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(i,DIO_u8_LOW);

		}*/
	}
	return 0;
}

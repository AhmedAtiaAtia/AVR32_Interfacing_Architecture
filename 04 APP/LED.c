
/*
 * main.c
 *
 *  Created on: Apr 5, 2019
 *      Author: Boon
 */
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include <util/delay.h>

int main(void)
{
	u8 i = 0 ;
	DIO_voidInitialization();
	while(1)
	{

		for(i=DIO_u8_PIN_0 ; i <= DIO_u8_PIN_31 ; i++)
		{
			DIO_voidSetPinValue(i,DIO_u8_HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(i,DIO_u8_LOW);
			switch(i)
			{
			case DIO_u8_PIN_0 : i = DIO_u8_PIN_3;
			break;
			case DIO_u8_PIN_4 : i = DIO_u8_PIN_14;
			break;
			case DIO_u8_PIN_15 : i = DIO_u8_PIN_17;
			break;
			case DIO_u8_PIN_18 : i = DIO_u8_PIN_19;
			break;
			case DIO_u8_PIN_20 : i = DIO_u8_PIN_26;
			break;
			case DIO_u8_PIN_27 : i = DIO_u8_PIN_29;
			break;


			}
		}

			for(i=DIO_u8_PIN_30 ; i > DIO_u8_PIN_0 ; i--)
			{
				DIO_voidSetPinValue(i,DIO_u8_HIGH);
				_delay_ms(1000);
				DIO_voidSetPinValue(i,DIO_u8_LOW);
				switch(i)
				{
				case DIO_u8_PIN_4 : i = DIO_u8_PIN_1;
				break;
				case DIO_u8_PIN_15 : i = DIO_u8_PIN_5;
				break;
				case DIO_u8_PIN_18 : i = DIO_u8_PIN_16;
				break;
				case DIO_u8_PIN_20 : i = DIO_u8_PIN_19;
				break;
				case DIO_u8_PIN_27 : i = DIO_u8_PIN_21;
				break;
				case DIO_u8_PIN_30 : i = DIO_u8_PIN_28;
				break;


				}


			}
		}

		return 0;
	}

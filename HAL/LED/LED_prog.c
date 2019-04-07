/******************************************************/
/* Author  : Ahmed Abo Elnour                         */
/* Date    : 17 FEB 2018                              */
/* Version : 1V                                       */
/******************************************************/
#include "STD_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"


void LED_voidSetLedOn(u8 Copy_u8PinNumber)
{
	switch (Copy_u8PinNumber)
	{
	case LED_PIN_0:
		#if LED_MODE_0 == NORMAL_MODE
			DIO_voidSetPinValue(LED_PIN_0,DIO_u8_HIGH);
		#elif LED_MODE == REVERSE_MODE
			DIO_voidSetPinValue(LED_PIN_0,LED_LOW);
		#endif
			break;
	case LED_PIN_1:
			#if LED_MODE_1 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_1,DIO_u8_HIGH);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_1,LED_LOW);
			#endif
				break;
	case LED_PIN_2:
			#if LED_MODE_2 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_2,DIO_u8_HIGH);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_2,LED_LOW);
			#endif
				break;
		case LED_PIN_3:
				#if LED_MODE_3 == NORMAL_MODE
					DIO_voidSetPinValue(LED_PIN_3,DIO_u8_HIGH);
				#elif LED_MODE == REVERSE_MODE
					DIO_voidSetPinValue(LED_PIN_3,LED_LOW);
				#endif
					break;
		case LED_PIN_4:
			#if LED_MODE_4 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_4,DIO_u8_HIGH);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_4,LED_LOW);
			#endif
				break;
		case LED_PIN_5:
				#if LED_MODE_5 == NORMAL_MODE
					DIO_voidSetPinValue(LED_PIN_5,DIO_u8_HIGH);
				#elif LED_MODE == REVERSE_MODE
					DIO_voidSetPinValue(LED_PIN_5,LED_LOW);
				#endif
					break;
		case LED_PIN_6:
				#if LED_MODE_6 == NORMAL_MODE
					DIO_voidSetPinValue(LED_PIN_6,DIO_u8_HIGH);
				#elif LED_MODE == REVERSE_MODE
					DIO_voidSetPinValue(LED_PIN_6,LED_LOW);
				#endif
					break;
			case LED_PIN_7:
					#if LED_MODE_7 == NORMAL_MODE
						DIO_voidSetPinValue(LED_PIN_7,DIO_u8_HIGH);
					#elif LED_MODE == REVERSE_MODE
						DIO_voidSetPinValue(LED_PIN_7,LED_LOW);
					#endif
						break;
			default:
				break;

	}
}
void LED_voidSetLedOff(u8 Copy_u8PinNumber)
{
	switch (Copy_u8PinNumber)
	{
	case LED_PIN_0:
		#if LED_MODE_0 == NORMAL_MODE
			DIO_voidSetPinValue(LED_PIN_0,DIO_u8_LOW);
		#elif LED_MODE == REVERSE_MODE
			DIO_voidSetPinValue(LED_PIN_0,LED_HIGH);
		#endif
			break;
	case LED_PIN_1:
			#if LED_MODE_1 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_1,DIO_u8_LOW);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_1,LED_HIGH);
			#endif
				break;
	case LED_PIN_2:
			#if LED_MODE_2 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_2,DIO_u8_LOW);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_2,LED_HIGH);
			#endif
				break;
	case LED_PIN_3:
			#if LED_MODE_3 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_3,DIO_u8_LOW);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_4,LED_HIGH);
			#endif
				break;
	case LED_PIN_4:
			#if LED_MODE_4 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_4,DIO_u8_LOW);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_4,LED_HIGH);
			#endif
				break;
	case LED_PIN_5:
			#if LED_MODE_5 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_5,DIO_u8_LOW);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_5,LED_HIGH);
			#endif
				break;
	case LED_PIN_6:
			#if LED_MODE_6 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_6,DIO_u8_LOW);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_6,LED_HIGH);
			#endif
				break;
	case LED_PIN_7:
			#if LED_MODE_7 == NORMAL_MODE
				DIO_voidSetPinValue(LED_PIN_7,DIO_u8_LOW);
			#elif LED_MODE == REVERSE_MODE
				DIO_voidSetPinValue(LED_PIN_7,LED_HIGH);
			#endif
				break;

	}
}


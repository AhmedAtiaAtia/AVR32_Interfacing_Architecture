/**************************************************/
/*   AUTHOR      : AHMED ABO ELNOUR               */
/*   Description : DIO DRIVER                     */
/*   DATE        : 20 FEB 2018                    */
/*   VERSION     : V02                            */
/**************************************************/
/*             Liberary Directives                */
#include "STD_Types.h"
#include "Bit_Math.h"

/*             DIO Directives                     */
#include "DIO_config.h"
#include "DIO_priv.h" 
#include "DIO_int.h"

/**************************************************/
/*             DIO Implementation                 */

/* Description : Initialize PINS Directions       */

void DIO_voidInitialization (void)
{
	DDRA = DIO_u8_PORTA_DIRECTIONS;
	DDRB = DIO_u8_PORTB_DIRECTIONS;
	DDRC = DIO_u8_PORTC_DIRECTIONS;
	DDRD = DIO_u8_PORTD_DIRECTIONS;

}/*END OF Initialization Function                 */

/**************************************************/

/* Description : This Function Set The Pin        */
/*               Value to either High or Low      */

void DIO_voidSetPinValue(u8 Copy_u8PinNumber , u8 Copy_u8PinValue)
{
	
	/*   FIND PORT A PINS                          */
	if (Copy_u8PinNumber >= DIO_u8_PORTA_START && Copy_u8PinNumber <= DIO_u8_PORTA_END)
	{
		/*  Check value passed to fuction HIGH    */
		
		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
		/*   MAKE pin numer Copy_u8PinNumber HIGH */
		
			SET_BIT(PORTA , Copy_u8PinNumber);
		}
		/*  Check value passed to fuction LOW    */
		else 
		{
			/*   MAKE pin numer Copy_u8PinNumber LOW */
			 
			CLEAR_BIT(PORTA, Copy_u8PinNumber);
		}
		
	}
	/*   FIND PORT B PINS                          */
	else if (Copy_u8PinNumber >= DIO_u8_PORTB_START && Copy_u8PinNumber <= DIO_u8_PORTB_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - DIO_u8_PORTA_SIZE ; 
		
		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT (PORTB , Copy_u8PinNumber);
		}
		else 
		{
			CLEAR_BIT(PORTB , Copy_u8PinNumber);
		}
		
	}
	/*   FIND PORT C PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTC_START &&  Copy_u8PinNumber <= DIO_u8_PORTC_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE ) ; 
		
		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT (PORTC , Copy_u8PinNumber);
		}
		else 
		{
			CLEAR_BIT(PORTC , Copy_u8PinNumber);
		}	
	}
	/*   FIND PORT D PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTD_START &&  Copy_u8PinNumber <= DIO_u8_PORTD_END)
	{
		
		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE ) ; 
		
		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT (PORTD , Copy_u8PinNumber);
		}
		else 
		{
			CLEAR_BIT(PORTD , Copy_u8PinNumber);
		}
		
		
	}
}/* END OF  Function Set The Value of a Pin       */

/**************************************************/

/* Description : This Function GET The Pin        */
/*               Value to either High or Low      */

u8 DIO_u8GETPinValue(u8 Copy_u8PinNumber )
{
	u8 LOC_u8ReturnedPinValue;
if (Copy_u8PinNumber >= DIO_u8_PORTA_START && Copy_u8PinNumber <= DIO_u8_PORTA_END)
	{
		LOC_u8ReturnedPinValue = GET_BIT(PINA,Copy_u8PinNumber);
	}
	/*   FIND PORT B PINS                          */
	else if (Copy_u8PinNumber >= DIO_u8_PORTB_START && Copy_u8PinNumber <= DIO_u8_PORTB_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - (DIO_u8_PORTA_SIZE);
		LOC_u8ReturnedPinValue = GET_BIT(PINB , Copy_u8PinNumber);
		
	}
	/*   FIND PORT C PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTC_START &&  Copy_u8PinNumber <= DIO_u8_PORTC_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE);
		LOC_u8ReturnedPinValue = GET_BIT(PINB , Copy_u8PinNumber);
		
	}
	/*   FIND PORT D PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTD_START &&  Copy_u8PinNumber <= DIO_u8_PORTD_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - (DIO_u8_PORTA_SIZE +  DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE);
		LOC_u8ReturnedPinValue = GET_BIT(PINB , Copy_u8PinNumber);
		
	}
	return LOC_u8ReturnedPinValue ;
}/* END OF Function that GET The Value of a Pin     */



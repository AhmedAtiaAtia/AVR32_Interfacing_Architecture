

#include "STD_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"
#include "LCD_INT.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int OVF = 0 ;
int firstReading = 1 ;
int prevState =  0 ;
float ton ,toff ,ttotal;



ISR(TIMER0_OVF_vect)
{
	OVF++;

}

ISR(INT0_vect)
{

	if (firstReading == 1 )
	{
		firstReading = 0 ;
		TCNT0 = 0 ;    // start timer 0
		OVF = 0 ;      // start timer ovf  0
		MCUCR = 0x02;  // sense falling
		prevState = 1;

	}
	else
	{

		if (prevState == 1 ) // falling
		{
			ton = (float)(   (TCNT0 + (OVF * 256) )    * (float)  (  (float) 1024 / 8000000) );
			TCNT0 = 0 ;
			OVF =  0 ;
			prevState = 0;
			MCUCR = 0x03 ; // sense rising


		}
		else // rising
		{
			toff = (float)(   (TCNT0 + (OVF * 256) )    * (float)  (  (float) 1024 / 8000000) );
			TCNT0 = 0 ;
			OVF =  0 ;
			prevState = 1;
			MCUCR = 0x02 ; // sense falling


		}
	}
}

void main (void)
{
	int duty = 0  , f =0;
	float freq = 0  ;
	
	DIO_voidInitialization();
	
	/*DIO_voidInitialization();
	while(1)
	{
		DIO_voidSetPinValue(1,DIO_u8_HIGH);
		_delay_ms(10);
		DIO_voidSetPinValue(1,DIO_u8_LOW);
		_delay_ms(10);
	}*/
	LCD_voidInitialize();
	TCCR0 = 0x05;
	SET_BIT(GICR,6);
	SET_BIT(TIMSK,0);
	SET_BIT(SREG , 7);
	while(1){
		duty =(100 * ton) /(ton+toff);

		freq = 1/(ton + toff );
		f = (int)freq ;
		LCD_voidWriteCommand(0x80);
		LCD_voidWriteData('f');
		LCD_voidWriteData('=');
		LCD_voidWriteData((f/100)+48);
		LCD_voidWriteData(((f/10)%10)+48);
		LCD_voidWriteData((f%10)+48);
		LCD_voidWriteData('h');
		LCD_voidWriteData('z');

		LCD_voidWriteCommand(0xc0);
		LCD_voidWriteData('D');
		LCD_voidWriteData('=');
		LCD_voidWriteData((duty/10)+48);
		LCD_voidWriteData((duty%10)+48);
		LCD_voidWriteData('%');
	}
}

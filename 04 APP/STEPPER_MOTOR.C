/*
 * main.c
 *
 *  Created on: Apr 30, 2019
 *      Author: Boon
 */
#include <util/delay.h>
#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_int.h"

#include "StepperMotor_int.h"

int main()
{
	DIO_voidInitialization();
	StepperMotor_voidInit();
	while(1)
	{
		StepperMotor_voidMove(0 , CLOCKWISE , MAXIMUM_SPEED_MS , FULL_ROTATION_360_DEGREE );
		_delay_ms(200);
		/*
		DIO_voidSetPinValue(DIO_u8_PIN_16 , DIO_u8_HIGH);
		_delay_ms(2500);
		DIO_voidSetPinValue(DIO_u8_PIN_16 , DIO_u8_LOW);
	*/
	}

	return 0 ;
}

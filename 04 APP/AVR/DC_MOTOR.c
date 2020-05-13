/*
 * main.c
 *
 *  Created on: Apr 19, 2019
 *      Author: Boon
 */

#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "DcMotor_int.h"
#include "avr/io.h"


int main() {


	DIO_voidInitialization();
	DcMotor_voidInit();


	while(1)
	{

		DcMotor_voidMove(0,RIGHT);
		//DcMotor_voidMove(0,LEFT);

	}
return 0 ;
}



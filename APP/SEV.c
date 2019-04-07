
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
	u8 i =0 ;
	DIO_voidInitialization();
	while(1)
	{
		SEV_voidSet7SegmentValue(SEV_LEFT ,i);
		_delay_ms(1000);
	i++ ;
	if (i == 10 )i=0;
	}
	return 0;
}

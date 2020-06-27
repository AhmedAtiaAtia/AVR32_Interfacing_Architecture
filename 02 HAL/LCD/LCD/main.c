#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_int.h"

#include"LCD_int.h"

#include<util/delay.h>

int main(void)
{
	DIO_SetPortDirection(PORTA , 0XFF);
	DIO_SetPortDirection(PORTD , 0XFF);
	
	LCD_int();
	
	LCD_writeChar('A');
	
	while(1)
	{
		
	}
}
/******************************************************/
/* Author  : Ahmed Atia Atia                          */
/* Date    : 18 FEB 2018                              */
/* Version : 1V                                       */
/******************************************************/

/*             Liberary Directives                */
#include "STD_Types.h"
#include "Bit_Math.h"

/*             DIO Directives                     */
#include "DIO_int.h"
/*   KEYPAD */
#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_priv.h"

void KEYPAD_voidInit()
{
	/** activate pull up resistor column / inputs 	  */
	DIO_voidSetPinValue(KEYPAD_U8_COLUMN_1 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(KEYPAD_U8_COLUMN_2 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(KEYPAD_U8_COLUMN_3 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(KEYPAD_U8_COLUMN_4 ,DIO_u8_HIGH );
	
	/** OUTPUT		 1	  */
	DIO_voidSetPinValue(KEYPAD_U8_ROW_1 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(KEYPAD_U8_ROW_2 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(KEYPAD_U8_ROW_3 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(KEYPAD_U8_ROW_4 ,DIO_u8_HIGH );
	
}

u8 KEYPAD_u8GetPressedKey(void)
{
	
	u8 LOC_u8preesed = 0XFF;
	u8 LOC_u8ColumnValue ;
	/**   !comment : send row sequence  1  */
	
	DIO_voidSetPinValue(KEYPAD_U8_ROW_1,DIO_u8_LOW);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_2,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_3,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_4,DIO_u8_HIGH);

	/**   !comment : Read columns  */

	LOC_u8ColumnValue  = DIO_u8GETPinValue(KEYPAD_U8_COLUMN_1 );
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_2))<< 1;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_3))<< 2;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_4))<< 3;
	
	switch(LOC_u8ColumnValue)
	{
		case 0b00001110: LOC_u8preesed = 1 ;
		break;                         
		                               
		case 0b00001101: LOC_u8preesed = 2 ;
		break;                          
		                                
		case 0b00001011: LOC_u8preesed = 3 ;
		break;                          
		                                
		case 0b00000111: LOC_u8preesed = '+' ;
		break;
		
		default : LOC_u8preesed = 0XFF ; 
	}
	
	if(LOC_u8preesed == 0XFF)
	{
	/**   !comment : send row sequence  2  */
    
	DIO_voidSetPinValue(KEYPAD_U8_ROW_1,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_2,DIO_u8_LOW);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_3,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_4,DIO_u8_HIGH);

	/**   !comment : Read columns  */

	LOC_u8ColumnValue  = DIO_u8GETPinValue(KEYPAD_U8_COLUMN_1 );
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_2))<< 1;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_3))<< 2;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_4))<< 3;
	
	switch(LOC_u8ColumnValue)
	{
		case 0b00001110: LOC_u8preesed = 4 ;
		break;                         
		                               
		case 0b00001101: LOC_u8preesed = 5 ;
		break;                          
		                                
		case 0b00001011: LOC_u8preesed = 6 ;
		break;                          
		                                
		case 0b00000111: LOC_u8preesed = '-' ;
		break;
		
		default : LOC_u8preesed = 0XFF ; 
	}
	}
	if(LOC_u8preesed == 0XFF)
	{	
	/**   !comment : send row sequence  3  */
	
DIO_voidSetPinValue(KEYPAD_U8_ROW_1,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_2,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_3,DIO_u8_LOW);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_4,DIO_u8_HIGH);

	/**   !comment : Read columns  */

	LOC_u8ColumnValue  = DIO_u8GETPinValue(KEYPAD_U8_COLUMN_1 );
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_2))<< 1;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_3))<< 2;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_4))<< 3;

	switch(LOC_u8ColumnValue)
	{
		case 0b00001110: LOC_u8preesed = 7 ;
		break;                         
		                               
		case 0b00001101: LOC_u8preesed = 8 ;
		break;                          
		                                
		case 0b00001011: LOC_u8preesed = 9 ;
		break;                          
		                                
		case 0b00000111: LOC_u8preesed = '*' ;
		break;
		
		default : LOC_u8preesed = 0XFF ; 
	}
	}
		if(LOC_u8preesed == 0XFF)
	{
	
	/**   !comment : send row sequence  4  */

	DIO_voidSetPinValue(KEYPAD_U8_ROW_1,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_2,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_3,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW_4,DIO_u8_LOW);
	
	/**   !comment : Read columns  */
	
	LOC_u8ColumnValue  = DIO_u8GETPinValue(KEYPAD_U8_COLUMN_1 );
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_2))<< 1;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_3))<< 2;
	LOC_u8ColumnValue |= (DIO_u8GETPinValue(KEYPAD_U8_COLUMN_4))<< 3;
	
		switch(LOC_u8ColumnValue)
	{
		case 0b00001110: LOC_u8preesed = '.' ;
		break;                         
		                               
		case 0b00001101: LOC_u8preesed = 0 ;
		break;                          
		                                
		case 0b00001011: LOC_u8preesed = '=' ;
		break;                          
		                                
		case 0b00000111: LOC_u8preesed = '/' ;
		break;
		
		default : LOC_u8preesed = 0XFF ; 
	}
	}
	
	return LOC_u8preesed ;
}

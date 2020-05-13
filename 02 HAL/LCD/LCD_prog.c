/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 20 April 2019                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : Config.c for LCD		                    */
/************************************************************/

#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "LCD_int.h"
#include "LCD_priv.h"
#include "LCD_config.h"

#include <util/delay.h>


void LCD_vidInit( void )
{
	/* wait 35 */
	_delay_ms(35);

	/*  function set */

	LCD_vidSendCmd(0b00111000);
	/* wait 1 */
	_delay_ms(1);

	/*  function set (on/off) */
	LCD_vidSendCmd(0b00001100);
	/* wait 1 */
	_delay_ms(1);

	/*  function set (Clear  Display) */


	/*****************************/
	/*LCD_vidSendCmd(0b00000001);*/
	/*	 wait 2                  */
	/*_delay_ms(2);	             */
	/*****************************/

	LCD_vidClear();

	/*  function set (Entry mode set - cursor increase or decrease ) */
	LCD_vidSendCmd(0b00000110);
	/* wait 2 */
	_delay_ms(2);

	/* latch = 0 */
	DIO_voidSetPinValue( LCD_u8EN , DIO_u8_LOW );

}

void LCD_vidSendCmd( u8 u8CmdCpy )
{
	/** to send command  ( RS = 0 and R/W = 0 ) =====> (write instruction) */

	/* RS  0 CMD */  
	DIO_voidSetPinValue( LCD_u8RS , DIO_u8_LOW );
	/* write 0 CMD*/
	DIO_voidSetPinValue( LCD_u8RW , DIO_u8_LOW );

	/* take data pass data bu */
	vidPutOnBus(u8CmdCpy);

}

void LCD_vidWriteChar( u8 u8CharCpy )
{
	/** to write command   ( RS = 1 and R/W = 0 ) =====> (write to DR Reg) */

	/* RS  1 CMD */
	DIO_voidSetPinValue( LCD_u8RS , DIO_u8_HIGH );
	/* write 0 CMD*/
	DIO_voidSetPinValue( LCD_u8RW , DIO_u8_LOW );

	/* take data pass data bu */
	vidPutOnBus(u8CharCpy);
}

static void vidPutOnBus( u8 u8CmdDataCpy )
{
	u8 LOC_u8Loop = LCD_DATA_D0_START ;

	DIO_voidSetPinValue( LCD_u8DATA_0 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));
	DIO_voidSetPinValue( LCD_u8DATA_1 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));
	DIO_voidSetPinValue( LCD_u8DATA_2 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));
	DIO_voidSetPinValue( LCD_u8DATA_3 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));
	DIO_voidSetPinValue( LCD_u8DATA_4 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));
	DIO_voidSetPinValue( LCD_u8DATA_5 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));
	DIO_voidSetPinValue( LCD_u8DATA_6 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));
	DIO_voidSetPinValue( LCD_u8DATA_7 , GET_BIT(u8CmdDataCpy , LOC_u8Loop++ ));

	/* lach  */
	DIO_voidSetPinValue( LCD_u8EN , DIO_u8_HIGH );
	_delay_ms(2);
	DIO_voidSetPinValue( LCD_u8EN , DIO_u8_LOW );
	_delay_ms(2);

}

void LCD_vidClear( void )
{
	/*  function set (Clear  Display) */
	LCD_vidSendCmd(0b00000001);
	/* wait 2 */
	_delay_ms(2);
}


void LCD_vidGotoXY( u8 u8LineNbCpy , u8 u8CharNbCpy )
{
 /* switchcase over line */
	if(  u8LineNbCpy == 1 )
	{
		/*  function set (Line1 position " x ") */
		LCD_vidSendCmd( (LCD_BEGINNING_FIRST_LINE + u8CharNbCpy) );
			
	}
	
	else if( u8LineNbCpy == 2 )
	{
		/*  function set (Line1 position " x ") */
		LCD_vidSendCmd( (LCD_BEGINNING_SECOND_LINE + u8CharNbCpy) );
		
	}
	
	
}


/* warnning avoid (u8*)"ahmed" */
void LCD_vidWriteString( u8 * pu8StringCpy )
{
	u8 Loc_u8Counter = 0 ;
	
	while(pu8StringCpy[Loc_u8Counter] !='\0')
	{
		LCD_vidWriteChar(pu8StringCpy[Loc_u8Counter]);
		Loc_u8Counter++;		
	}
	

}

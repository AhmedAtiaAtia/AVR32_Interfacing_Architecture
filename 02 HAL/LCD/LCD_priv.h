/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 20 April 2019                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : Config.c for DC Motor                    */
/************************************************************/

#ifndef _LCD_PRIV_H
#define _LCD_PRIV_H

#define LCD_DATA_D0_START	 0
#define LCD_DATA_D7_END      7

#define LCD_BEGINNING_FIRST_LINE		128 
#define LCD_BEGINNING_SECOND_LINE		192

static void vidPutOnBus( u8 u8CmdDataCpy );

 
#endif 
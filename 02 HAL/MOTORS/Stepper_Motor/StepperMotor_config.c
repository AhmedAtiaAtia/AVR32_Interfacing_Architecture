/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Stepper Motors Pins 		*/
/*									configuration				*/ 
/*							[config.c] Link time configuration	*/
/*									in build process			*/
/****************************************************************/

#include "Std_types.h"
#include "DIO_int.h"
#include "StepperMotor_config.h"
#include "StepperMotor_priv.h"



/*****************************************************************/
/* !comment : Array of struct ( Stepper Motors ) 				 */
/*****************************************************************/

StepperMotor ArrayOfMotor [ NUMBER_OF_MOTORS ] = 
{
	{DIO_u8_PIN_0 ,DIO_u8_PIN_2 , DIO_u8_PIN_4 , DIO_u8_PIN_6 } ,
	{DIO_u8_PIN_1 ,DIO_u8_PIN_3 , DIO_u8_PIN_5 , DIO_u8_PIN_7 } ,
	{DIO_u8_PIN_8 ,DIO_u8_PIN_10 , DIO_u8_PIN_12 , DIO_u8_PIN_14 } , 
	{DIO_u8_PIN_9 ,DIO_u8_PIN_11 , DIO_u8_PIN_13 , DIO_u8_PIN_15 } , 
	{DIO_u8_PIN_16 ,DIO_u8_PIN_18 , DIO_u8_PIN_20 , DIO_u8_PIN_22 }
	
	
};

/***************************************************************************/
/*************************** END OF PROGRAM ********************************/
/***************************************************************************/
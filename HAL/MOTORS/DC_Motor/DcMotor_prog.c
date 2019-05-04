/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Progam algorithm for DC Motor		*/
/*									 [prog.c]				    */
/****************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "STD_Types.h"
#include "Bit_Math.h"

/****************************************************************/
/********************* DIO Component DIRECTIVES *****************/
/****************************************************************/

#include "DIO_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "DcMotor_int.h"
#include "DcMotor_config.h"
#include "DcMotor_priv.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/



/****************************************************************/
/* Description    :  This function used to initialize DC Motor  */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/

void DcMotor_voidInit( void )
{
	
/*****************************************************************/
/* !comment : Loop to initialize all DC Motors				 	 */
/*****************************************************************/
	
	for( u8 i = 0 ; i < NUMBER_OF_MOTORS ; i++ )
	{
		
		/** !comment : Turn off Right wire of current Motor		 */		
		DIO_voidSetPinValue(ArrayOfMotor[i].RightMotorPin ,DIO_u8_LOW );
		/** !comment : Turn off Left wire of current Motor		 */
		DIO_voidSetPinValue(ArrayOfMotor[i].LeftMotorPin ,DIO_u8_LOW );
	}

}


/****************************************************************/
/* Description    :  This function used to show the Direction	*/
/*					 of Moving. 								*/
/*					 Inputs : Motor Number 	 ,  				*/
/*   						  Motor Direction[left ,right,stop] */
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after DC Motor  */
/*     				 initialized								*/
/****************************************************************/

void DcMotor_voidMove( u8 u8MotorNumber , u8 u8Direction  )
{
	
	switch( u8Direction )
	{
		
		case STOP:			
							/** !comment : Turn off all wires			*/
							DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].RightMotorPin ,DIO_u8_LOW );
							DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].LeftMotorPin ,DIO_u8_LOW );
							
		break;
		
		
		case RIGHT:			
							/** !comment : Turn on right Turn off left	*/
						    DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].RightMotorPin ,DIO_u8_HIGH );
							DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].LeftMotorPin ,DIO_u8_LOW );
							
		break;
		
		
		case LEFT:			
							/** !comment : Turn on left Turn off right	*/
						    DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].RightMotorPin ,DIO_u8_LOW );
							DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].LeftMotorPin ,DIO_u8_HIGH );
							
		break;
		
		
		default:			
							/** !comment : Turn off all wires ( STOP )	*/
						    DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].RightMotorPin ,DIO_u8_LOW );
							DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].LeftMotorPin ,DIO_u8_LOW );
							
	}
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
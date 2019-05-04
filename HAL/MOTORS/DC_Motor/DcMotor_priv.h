/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    DC Motor priv [priv.h] contain		*/
/*                           DC Motor Definition and Directions */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _DCMOTOR_PRIV_H
#define _DCMOTOR_PRIV_H





/*****************************************************************/
/*!comment :Define Encabsulated Data type [ DcMotor ] it is a	**/
/*		    Struct contain u8 for Right wire and another u8 Left**/
/*          wire											    **/
/*****************************************************************/

typedef struct dcmotor
{
	
	/** RightMotorPin simulate Right wire for DC Motor			 */
	u8 RightMotorPin;
	
	/** LeftMotorPin simulate Left wire for DC Motor			 */
	u8 LeftMotorPin;

}DcMotor;

/*****************************************************************/
/* !comment : Array of struct ( DC Motors ) from config.c	 	 */
/*****************************************************************/

extern DcMotor ArrayOfMotor [ NUMBER_OF_MOTORS ] ;
  
  
#endif /** !comment  :  End of guard                            **/ 
/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    29 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Stepper Motor priv [priv.h] contain*/
/*                           Stepper Motor Declaration			*/
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _STEPPERMOTOR_PRIV_H
#define _STEPPERMOTOR_PRIV_H




/*****************************************************************/
/*!comment :Define Encabsulated Data type [ StepperMotor ] it	**/
/* 			is a Struct contain u8 for Right wire and another  	**/
/*						u8 Left wire .							**/
/*****************************************************************/

typedef struct steppermotor
{
	/** BlueMotorPin simulate Blue wire for Stepper Motor		 */	
	u8 BlueMotorWire;
	/** pinkMotorPin simulate pink wire for Stepper Motor		 */
	u8 pinkMotorWire;
	/** YellowMotorPin simulate Yellow wire for Stepper Motor	 */
	u8 YellowMotorWire;
	/** OrangeMotorPin simulate Orange wire for Stepper Motor	 */
	u8 OrangeMotorWire;
	
}StepperMotor;

/*****************************************************************/
/* !comment : Array of struct ( Stepper Motors ) 				 */
/*****************************************************************/

extern StepperMotor ArrayOfMotor [ NUMBER_OF_MOTORS ] ;
  
  
#endif /** !comment  :  End of guard                            **/ 
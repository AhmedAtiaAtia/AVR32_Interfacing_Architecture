/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    29 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							for Stepper Motor [int.h] 			*/
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _STEPPERMOTOR_INT_H
#define _STEPPERMOTOR_INT_H

/****************************************************************/	
/** !comment : Stepper Motor Directions Definition	    		*/
/**				[ Clockwise or Anticlockwise or Stop ]			*/
/****************************************************************/

#define CLOCKWISE					1
#define ANTI_CLOCKWISE				3
#define STOP						5


/****************************************************************/	
/** !comment : Stepper Motor Speed : simulate the speed by 	    */
/**				Increasing and Decreasing the Delay time		*/ 
/**				between the Coils in [Milliseconds]				*/
/**				Maximum speed ====> [ Delay = 2 ms ]			*/
/**				minimum speed ====> [ Delay = 800 ms]			*/
/**				and you can choose any number in between		*/
/****************************************************************/

#define MAXIMUM_SPEED_MS			2
#define MINIMUM_SPEED_MS			800

/****************************************************************/	
/** !comment : Stepper Motor Steps : How much degree or step ?	*/
/**				360 degrees = 512 [ one full rotation ].		*/ 
/**				You can choose any number between [ 0 : 512].	*/
/****************************************************************/

#define FULL_ROTATION_360_DEGREE	512
#define HALF_ROTATION_180_DEGREE	256
#define QUARTER_ROTATION_90_DEGREE	128

/****************************************************************/
/* Description    :  This function used to initialize Stepper	*/
/*										Motor				    */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/

void StepperMotor_voidInit( void ); 

/****************************************************************/
/* Description    :  This function used to show the Direction	*/
/*					 of Moving, Speed, and degree. 				*/
/*					 Inputs : Motor Number 	 ,  				*/
/*   						  Motor Direction					*/
/*							  Motor Speed						*/
/*							  Motor Steps						*/
/*					 return : void		 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Stepper	*/
/*					 Motor initialized							*/
/****************************************************************/

void StepperMotor_voidMove( u8 u8MotorNumber , u8 u8Direction , u16 u8Speed ,u16 u16NumberOfSteps );




#endif /**!comment : End of the guard 							**/ 

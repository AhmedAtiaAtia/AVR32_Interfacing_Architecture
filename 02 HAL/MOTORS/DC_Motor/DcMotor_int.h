/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							for DC Motor [int.h] 			    */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _DCMOTOR_INT_H
#define _DCMOTOR_INT_H


/****************************************************************/	
/** !comment : DC Motor Directions Definition	    			*/
/****************************************************************/

#define STOP	1
#define RIGHT	4
#define LEFT	7


/****************************************************************/
/* Description    :  This function used to initialize DC Motor  */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/

void DcMotor_voidInit( void ); 

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

void DcMotor_voidMove( u8 u8MotorNumber , u8 u8Direction  );


#endif /**!comment : End of the guard 							**/ 

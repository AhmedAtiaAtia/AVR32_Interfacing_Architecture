/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    29 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   Progam algorithm for Stepper Motor	*/
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

#include "StepperMotor_int.h"
#include "StepperMotor_config.h"
#include "StepperMotor_priv.h"

/****************************************************************/
/************************* DELAY DIRECTIVES *********************/
/****************************************************************/

#include <util/delay.h>



/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize Stepper	*/
/*										Motor				    */
/*					 Inputs : void			 					*/
/*					 return : void		 						*/
/****************************************************************/

void StepperMotor_voidInit( void )
{
	
/*****************************************************************/
/* !comment : Loop to initialize all Stepper Motors			 	 */
/*****************************************************************/
	
	for( u8 i = 0 ; i < NUMBER_OF_MOTORS ; i++ )
	{
		
		/** !comment : Turn off Blue wire of current Motor		 */		
		DIO_voidSetPinValue(ArrayOfMotor[i].BlueMotorWire ,DIO_u8_LOW );

		/** !comment : Turn off pink wire of current Motor		 */
		DIO_voidSetPinValue(ArrayOfMotor[i].pinkMotorWire ,DIO_u8_LOW );

		/** !comment : Turn off Yellow wire of current Motor	 */		
		DIO_voidSetPinValue(ArrayOfMotor[i].YellowMotorWire ,DIO_u8_LOW );

		/** !comment : Turn off Orange wire of current Motor	 */
		DIO_voidSetPinValue(ArrayOfMotor[i].OrangeMotorWire ,DIO_u8_LOW );

		_delay_ms(MAXIMUM_SPEED_MS);
		
	}

}



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

void StepperMotor_voidMove( u8 u8MotorNumber , u8 u8Direction , u16 u8Speed ,u16 u16NumberOfSteps )
{

	switch( u8Direction )
	{
		
		case STOP:			
					/** !comment : Turn off all wires			*/	
					
					/** !comment : Turn off Blue wire of This Motor		 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
					
					/** !comment : Turn off pink wire of This Motor		 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
					
					/** !comment : Turn off Yellow wire of This Motor	 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );

					/** !comment : Turn off Orange wire of This Motor	 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
					
					_delay_ms(MAXIMUM_SPEED_MS);
					
		break;
		
		
		case CLOCKWISE:			
						for(u16 count = 0 ; count < u16NumberOfSteps ; count++ )
						{
								/* sequnce 1  coil 1 is on ( Orange wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_HIGH );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
								_delay_ms(u8Speed);
					
								/* sequnce 2  coil 2 is on ( Yellow wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_HIGH );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
								_delay_ms(u8Speed);
								
								/* sequnce 3  coil 3 is on ( pink wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_HIGH );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
								_delay_ms(u8Speed);
								
								/* sequnce 4  coil 4 is on ( blue wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_HIGH );
								_delay_ms(u8Speed);
					
						}
						
							
		break;
		
		
		case ANTI_CLOCKWISE:			
							for(u16 count = 0 ; count < u16NumberOfSteps ; count++ )
							{
								/* sequnce 1  coil 1 is on ( blue wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_HIGH );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
								_delay_ms(u8Speed);
								
								/* sequnce 2  coil 2 is on ( pink wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_HIGH );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
								_delay_ms(u8Speed);							

								/* sequnce 3  coil 3 is on ( Yellow wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_HIGH );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
								_delay_ms(u8Speed);									
								
								/* sequnce 4  coil 4 is on ( Orange wire ) */
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );
								DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_HIGH );
								_delay_ms(u8Speed);	
					
							}
						
		break;
		
		
		default:			
						  /** !comment : Turn off all wires			*/		
					
					/** !comment : Turn off Blue wire of This Motor		 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].BlueMotorWire ,DIO_u8_LOW );
					
					/** !comment : Turn off pink wire of This Motor		 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].pinkMotorWire ,DIO_u8_LOW );
					
					/** !comment : Turn off Yellow wire of This Motor	 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].YellowMotorWire ,DIO_u8_LOW );

					/** !comment : Turn off Orange wire of This Motor	 */	
					DIO_voidSetPinValue(ArrayOfMotor[u8MotorNumber].OrangeMotorWire ,DIO_u8_LOW );
					
					_delay_ms(MAXIMUM_SPEED_MS);
								
					
	}
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
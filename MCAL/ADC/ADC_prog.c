/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 2 May 2019	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "STD_Types.h"
#include "Bit_Math.h"
#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_priv.h" 



/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void ADC_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if VOLTAGE_REFERENCE == AREF
	CLEAR_BIT( ADMUX , 6 );
	CLEAR_BIT( ADMUX , 7 );
	
	#elif VOLTAGE_REFERENCE == AVCC
	SET_BIT( ADMUX , 6 );
	CLEAR_BIT( ADMUX , 7 );
	
	#elif VOLTAGE_REFERENCE == INTERNAL
	SET_BIT( ADMUX , 6 );
	SET_BIT( ADMUX , 7 );
	
	#endif
	/* End ( if ) condition for Macros */


	/*  ( if / else if ) condition for Macros */
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT( ADMUX , 5 );
	
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	CLEAR_BIT( ADMUX , 5 );
	
	#endif
	/* End ( if ) condition for Macros */


	/*  ( if / else if ) condition for Macros */
	#if ADC_CHANNEL_NUMBER == DIO_u8_PIN_0
	CLEAR_BIT( ADMUX , 0 );
	CLEAR_BIT( ADMUX , 1 );
	CLEAR_BIT( ADMUX , 2 );
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );
	
	
	#elif ADC_CHANNEL_NUMBER == DIO_u8_PIN_1
	SET_BIT( ADMUX , 0 );
	CLEAR_BIT( ADMUX , 1 );
	CLEAR_BIT( ADMUX , 2 );
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );
	

	#elif ADC_CHANNEL_NUMBER == DIO_u8_PIN_2
	CLEAR_BIT( ADMUX , 0 );
	SET_BIT( ADMUX , 1 );	
	CLEAR_BIT( ADMUX , 2 );
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );
	
	#elif ADC_CHANNEL_NUMBER == DIO_u8_PIN_3
	SET_BIT( ADMUX , 0 );
	SET_BIT( ADMUX , 1 );	
	CLEAR_BIT( ADMUX , 2 );
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );

	#elif ADC_CHANNEL_NUMBER == DIO_u8_PIN_4
	CLEAR_BIT( ADMUX , 0 );
	CLEAR_BIT( ADMUX , 1 );
	SET_BIT( ADMUX , 2 );	
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );

	#elif ADC_CHANNEL_NUMBER == DIO_u8_PIN_5
	SET_BIT( ADMUX , 0 );
	CLEAR_BIT( ADMUX , 1 );
	SET_BIT( ADMUX , 2 );	
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );

	#elif ADC_CHANNEL_NUMBER == DIO_u8_PIN_6
	CLEAR_BIT( ADMUX , 0 );
	SET_BIT( ADMUX , 1 );
	SET_BIT( ADMUX , 2 );	
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );

	
	#elif ADC_CHANNEL_NUMBER == DIO_u8_PIN_7
	SET_BIT( ADMUX , 0 );
	SET_BIT( ADMUX , 1 );
	SET_BIT( ADMUX , 2 );	
	CLEAR_BIT( ADMUX , 3 );
	CLEAR_BIT( ADMUX , 4 );
	
	#endif
	/* End ( if ) condition for Macros */

	
	
	/** disable ADC in initialization function  			   **/
	/** like : void ADC_voidDisable(); 		 				   **/
	CLEAR_BIT( ADCSRA , 7 );

	

	/** disable ADC Auto Trigger in initialization function	   **/
	/** ADATE = 0 =====> 	CLEAR_BIT( ADATE , 5 );			   **/
	CLEAR_BIT( ADCSRA , 5 );


	
	/** ADIF = 1 =====> 	SET_BIT( ADIF , 4 ); 			   **/
	/** ADC Interrupt Flag ( Conversion Complete ) cleared by  **/
	/** set ADIF by Logical 1 .								   **/
    SET_BIT( ADCSRA , 4 );
	
	/** ADIE = 0 =====> 	CLEAR_BIT( ADIF , 4 ); 			   **/
	/** ADC Interrupt Enable is cleared in initialization	   **/
    CLEAR_BIT( ADCSRA , 3 );	
	
	

	/*  ( if / else if ) condition for Macros */
	#if ADC_PRESCALLER == DIVID_BY_2
	SET_BIT( ADCSRA , 0 );
	CLEAR_BIT( ADCSRA , 1 );
	CLEAR_BIT( ADCSRA , 2 );
	
	/*
	||
	(
	CLEAR_BIT( ADCSRA , 0 );
	CLEAR_BIT( ADCSRA , 1 );
	CLEAR_BIT( ADCSRA , 2 );
	
	))
	*/
	
	#elif ADC_PRESCALLER == DIVID_BY_4
	CLEAR_BIT( ADCSRA , 0 );
	SET_BIT( ADCSRA , 1 );
	CLEAR_BIT( ADCSRA , 2 );
	
	
	#elif ADC_PRESCALLER == DIVID_BY_8
	SET_BIT( ADCSRA , 0 );
	SET_BIT( ADCSRA , 1 );
	CLEAR_BIT( ADCSRA , 2 );

	#elif ADC_PRESCALLER == DIVID_BY_16
	CLEAR_BIT( ADCSRA , 0 );
	CLEAR_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 2 );
	
	#elif ADC_PRESCALLER == DIVID_BY_32
	SET_BIT( ADCSRA , 0 );
	CLEAR_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 2 );

	#elif ADC_PRESCALLER == DIVID_BY_64
	CLEAR_BIT( ADCSRA , 0 );
	SET_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 2 );

	#elif ADC_PRESCALLER == DIVID_BY_128
	SET_BIT( ADCSRA , 0 );
	SET_BIT( ADCSRA , 1 );
	SET_BIT( ADCSRA , 2 );	
	
	#endif
	/* End ( if ) condition for Macros */	
	
	
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , 3 );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger()
{
	

	
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    SET_BIT( ADCSRA , 5 );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	CLEAR_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 0 );
	CLEAR_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 0 );
	SET_BIT( SFIOR , 1 );
	SET_BIT( SFIOR , 2 );	
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV()
{
	
	u16 mv_result = 0 ;
	ADC_voidStartConversion();
	while(GET_BIT(ADCSRA , 4) == 0);
	SET_BIT(ADCSRA , 4 );
	
	/*  ( if / else if ) condition for Macros */
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	mv_result = ((ADCH * 5000 )/(256));
	return mv_result;
	
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	
	
	#endif
	
	
	
}


/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
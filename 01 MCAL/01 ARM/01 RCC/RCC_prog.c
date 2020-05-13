/****************************************************************/
/*   Author             :    AHMED ATIA ATIA 				    */
/*	 Date 				:    25 FEB 2020 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    prog.c for RCC					 	*/
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_config.h" 
#include "RCC_reg.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize RCC	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void MRCC_voidInit(void)
{
	
		
		#if 	CLOCK_TYPE == HSI
		/* internal 8 MHZ RC oscillator 			*/
		/*	HSI clock enable						*/
				SET_BIT(MRCC -> CR , 0 );
				/*HSI selected as system clock		*/
				CLR_BIT(MRCC -> CFGR , 0 );
				CLR_BIT(MRCC -> CFGR , 1 );
				
				/*	HSI Ready Flag					*/
				while(!GET_BIT( MRCC -> CR , 1 ) );
		
		#elif	CLOCK_TYPE == HSE
				/*	HSE clock enable				*/
				SET_BIT(MRCC -> CR , 16 );
				
				/*HSE selected as system clock		*/
				SET_BIT(MRCC -> CFGR , 0 );
				CLR_BIT(MRCC -> CFGR , 1 );
				
				/*	HSE Ready Flag					*/
				while(!GET_BIT( MRCC -> CR , 17 ) );
				
		#elif	CLOCK_TYPE == PLL
				/*	The PLL output frequency must not exceed 72 MHz */
				/*PLL selected as system clock		*/
				CLR_BIT(MRCC -> CFGR , 0 );
				SET_BIT(MRCC -> CFGR , 1 );
				
		/*PLL multiplication factor*/		
		#if CLOCK_FACTOR == MULTIPLY_BY_2
		CLR_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_3
		SET_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_4
		CLR_BIT(MRCC -> CFGR , 18 );
		SET_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_5
		SET_BIT(MRCC -> CFGR , 18 );
		SET_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_6
		CLR_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		SET_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_7
		SET_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		SET_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_8
		CLR_BIT(MRCC -> CFGR , 18 );
		SET_BIT(MRCC -> CFGR , 19 );
		SET_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_9
		SET_BIT(MRCC -> CFGR , 18 );
		SET_BIT(MRCC -> CFGR , 19 );
		SET_BIT(MRCC -> CFGR , 20 );
		CLR_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_10
		CLR_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		SET_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_11
		SET_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		SET_BIT(MRCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_12
		CLR_BIT(MRCC -> CFGR , 18 );
		SET_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		SET_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_13
		SET_BIT(MRCC -> CFGR , 18 );
		SET_BIT(MRCC -> CFGR , 19 );
		CLR_BIT(MRCC -> CFGR , 20 );
		SET_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_14
		CLR_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		SET_BIT(MRCC -> CFGR , 20 );
		SET_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_15
		SET_BIT(MRCC -> CFGR , 18 );
		CLR_BIT(MRCC -> CFGR , 19 );
		SET_BIT(MRCC -> CFGR , 20 );
		SET_BIT(MRCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_16
		CLR_BIT(MRCC -> CFGR , 18 );
		SET_BIT(MRCC -> CFGR , 19 );
		SET_BIT(MRCC -> CFGR , 20 );
		SET_BIT(MRCC -> CFGR , 21 );
		
		#else
			#warning	"Wrong Multiplication factor!"
		
		#endif
		
					#if 	PLL_SOURCE	==	PLL_HSI_DIVIDED_BY_2
							/*PLL entry clock source is HSI divdided by 2		*/
							CLR_BIT(MRCC -> CFGR , 16 );
					#elif	PLL_SOURCE	==	PLL_HSE
							/*PLL entry clock source is HSE						*/
							SET_BIT(MRCC -> CFGR , 16 );
							/*HSE divider for PLL entry : clock not divided 	*/
							CLR_BIT(MRCC -> CFGR , 17 );
					#elif	PLL_SOURCE	==	PLL_HSE_DIVIDED_BY_2
							/*PLL entry clock source is HSE						*/
							SET_BIT(MRCC -> CFGR , 16 );
							/*HSE divider for PLL entry : clock divided		 	*/
							SET_BIT(MRCC -> CFGR , 17 );
					#endif
		
				/*	PLL clock enable				*/
				SET_BIT(MRCC -> CR , 24 );
				/*	PLL Ready Flag					*/
				while(!GET_BIT( MRCC -> CR , 25 ) );
				
		#elif	CLOCK_TYPE == HSEPYPASS
				/*The HSEBYP bit can be written only if the HSE oscillator is disabled*/
				/*	HSE clock Disable				*/
				CLR_BIT(MRCC -> CR , 16 );
				
				/*	HSEBYPASS clock Enable			*/
				SET_BIT(MRCC -> CR , 18 );

				/*HSE selected as system clock		*/
				SET_BIT(MRCC -> CFGR , 0 );
				CLR_BIT(MRCC -> CFGR , 1 );
				
				/*	HSE clock Enable				*/
				SET_BIT(MRCC -> CR , 16 );
				
				/*	HSE Ready Flag					*/
				while(!GET_BIT( MRCC -> CR , 17 ) );

		
		#else
			
			#error		"Wrong Clock System type congiguration!"
		
		#endif
		/*FOR Clock Security System				*/
		#if		CLOCK_SECURITY_SYSTEM	==	OFF
				CLR_BIT(MRCC -> CR , 19 );
		
		#elif	CLOCK_SECURITY_SYSTEM	==	ON
				SET_BIT(MRCC -> CR , 19 );
		#else
				#warning	"Wrong clock security system configuration choice!"
		#endif
		
}

ErrorStatus MRCC_enumSetPeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralName , u8 Copy_u8PeripheralState )
{
	ErrorStatus	LOC_enumstate = ES_NOK ;
	switch( Copy_u8PeripheralState )
	{
		case	RCC_ENABLE 	:
							switch( Copy_u8PeripheralBus )
							{	
								case AHB  :	SET_BIT( MRCC -> AHBENR  ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								case APB1 :	SET_BIT( MRCC -> APB1ENR ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								case APB2 : SET_BIT( MRCC -> APB2ENR ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								default	  :	LOC_enumstate = ES_OUT_OF_RANGR;
							}
							break;
		case	RCC_DISABLE :	
							switch( Copy_u8PeripheralBus )
							{	
								case AHB  :	CLR_BIT( MRCC -> AHBENR  ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								case APB1 :	CLR_BIT( MRCC -> APB1ENR ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								case APB2 : CLR_BIT( MRCC -> APB2ENR ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								default	  :	LOC_enumstate = ES_OUT_OF_RANGR;
							}
							break;
		case	RCC_RESET	:	
							switch( Copy_u8PeripheralBus )
							{	
								case APB1 :	SET_BIT( MRCC -> APB1RSTR ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								case APB2 : SET_BIT( MRCC -> APB2RSTR ,  Copy_u8PeripheralName );LOC_enumstate = ES_OK;break;
								default	  :	LOC_enumstate = ES_OUT_OF_RANGR;
							}
							break;
	}
	return	LOC_enumstate ;
}
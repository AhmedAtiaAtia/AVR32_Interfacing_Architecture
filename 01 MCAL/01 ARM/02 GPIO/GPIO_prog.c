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
#include "GPIO_int.h"
#include "GPIO_priv.h"
#include "GPIO_config.h" 
#include "GPIO_reg.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    :  This function used to initialize RCC	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

//void MGPIO_voidInit(void);
ErrorStatus	MGPIO_enumSetPinDirection(u8 copy_u8PortID ,u8 copy_u8PIN_ID ,u8 copy_u8Direction , u8 copy_u8Mode ,u8 copy_u8Speed)
{
	/*	Default Error Status						*/
	ErrorStatus	LOC_enumState = ES_NOK ;
	/*	Range check for PORTS						*/
	
		switch(copy_u8PortID)
		{
			/*	Range check for PINS Of PORT LOW	*/
			case PORTA  : 	if(copy_u8PIN_ID < 8)
							{
								/*check about Direaction Input or Output*/
								switch(copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(copy_u8Speed != SPEED_INPUT)
										{
											/*	output speed Seletion	*/
											switch(copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( MGPIOA -> CRL , (copy_u8PIN_ID * 4) );	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_2MHZ		:	CLR_BIT( MGPIOA -> CRL , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_50MHZ 	:	SET_BIT( MGPIOA -> CRL , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												default				:	LOC_enumState = OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												default						:	LOC_enumState = OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											LOC_enumState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(copy_u8Speed == SPEED_INPUT)
										{
											/* SET INPUT mode */
											CLR_BIT( MGPIOA -> CRL , ( copy_u8PIN_ID * 4) );
											CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );										break;
												case INPUT_FLOATING		:	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );										break;
												case INPUT_PULLDOWN 	:	CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );	CLR_BIT( MGPIOA -> ODR , copy_u8PIN_ID  );	break;
												case INPUT_PULLUP	 	:	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+3) );	SET_BIT( MGPIOA -> ODR , copy_u8PIN_ID  );	break;
												default					:	LOC_enumState = OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	LOC_enumState = OUT_OF_RANGE ;
								}
							}/*	Range check for PINS Of PORT HIGH		*/
							else if(copy_u8PIN_ID < 16)
							{
								/*	modification of Pin Numer of HIGH port with bit number of GPIO_CRH Reg	*/
								copy_u8PIN_ID -= 8 ; 
								
								/*check about Direaction Input or Output*/
								switch(copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(copy_u8Speed != SPEED_INPUT)
										{
											/*	output speed Seletion	*/
											switch(copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( MGPIOA -> CRH , (copy_u8PIN_ID * 4) );	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_2MHZ		:	CLR_BIT( MGPIOA -> CRH , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_50MHZ 	:	SET_BIT( MGPIOA -> CRH , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												default				:	LOC_enumState = OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	CLR_BIT( MGPIOA -> ODR , (copy_u8PIN_ID+8) );	break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	SET_BIT( MGPIOA -> ODR , (copy_u8PIN_ID+8) );	break;
												default						:	LOC_enumState = OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											LOC_enumState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(copy_u8Speed == SPEED_INPUT)
										{
											/* SET INPUT mode */
											CLR_BIT( MGPIOA -> CRL , ( copy_u8PIN_ID * 4) );
											CLR_BIT( MGPIOA -> CRL , ((copy_u8PIN_ID * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case INPUT_FLOATING		:	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case INPUT_PULLDOWN 	:	CLR_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case INPUT_PULLUP	 	:	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOA -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												default					:	LOC_enumState = OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	LOC_enumState = OUT_OF_RANGE ;
								}
							}
							else
							{
								ErrorStatus	LOC_enumState = OUT_OF_RANGE ;
							}
							break;
			/****************************************************************/
			/* End Of PORTA													*/				
			/****************************************************************/
			
			
			/*	Range check for PINS Of PORT LOW	*/				
			case PORTB  :	
							if(copy_u8PIN_ID < 8)
							{
								/*check about Direaction Input or Output*/
								switch(copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(copy_u8Speed != SPEED_INPUT)
										{
											/*	output speed Seletion	*/
											switch(copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( MGPIOB -> CRL , (copy_u8PIN_ID * 4) );	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_2MHZ		:	CLR_BIT( MGPIOB -> CRL , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_50MHZ 	:	SET_BIT( MGPIOB -> CRL , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												default				:	LOC_enumState = OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												default						:	LOC_enumState = OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											LOC_enumState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(copy_u8Speed == SPEED_INPUT)
										{
											/* SET INPUT mode */
											CLR_BIT( MGPIOB -> CRL , ( copy_u8PIN_ID * 4) );
											CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );										break;
												case INPUT_FLOATING		:	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );										break;
												case INPUT_PULLDOWN 	:	CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );	CLR_BIT( MGPIOB -> ODR , copy_u8PIN_ID  );	break;
												case INPUT_PULLUP	 	:	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+3) );	SET_BIT( MGPIOB -> ODR , copy_u8PIN_ID  );	break;
												default					:	LOC_enumState = OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	LOC_enumState = OUT_OF_RANGE ;
								}
							}/*	Range check for PINS Of PORT HIGH		*/
							else if(copy_u8PIN_ID < 16)
							{
								/*	modification of Pin Numer of HIGH port with bit number of GPIO_CRH Reg	*/
								copy_u8PIN_ID -= 8 ; 
								
								/*check about Direaction Input or Output*/
								switch(copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(copy_u8Speed != SPEED_INPUT)
										{
											/*	output speed Seletion	*/
											switch(copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( MGPIOB -> CRH , (copy_u8PIN_ID * 4) );	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_2MHZ		:	CLR_BIT( MGPIOB -> CRH , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_50MHZ 	:	SET_BIT( MGPIOB -> CRH , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												default				:	LOC_enumState = OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	CLR_BIT( MGPIOB -> ODR , (copy_u8PIN_ID+8) );	break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	SET_BIT( MGPIOB -> ODR , (copy_u8PIN_ID+8) );	break;
												default						:	LOC_enumState = OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											LOC_enumState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(copy_u8Speed == SPEED_INPUT)
										{
											/* SET INPUT mode */
											CLR_BIT( MGPIOB -> CRL , ( copy_u8PIN_ID * 4) );
											CLR_BIT( MGPIOB -> CRL , ((copy_u8PIN_ID * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case INPUT_FLOATING		:	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case INPUT_PULLDOWN 	:	CLR_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												case INPUT_PULLUP	 	:	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOB -> CRH , ((copy_u8PIN_ID * 4)+3) );	break;
												default					:	LOC_enumState = OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	LOC_enumState = OUT_OF_RANGE ;
								}
							}
							else
							{
								ErrorStatus	LOC_enumState = OUT_OF_RANGE ;
							}
							break;
			
			/****************************************************************/
			/* The End Of PORTB												*/				
			/****************************************************************/
			
			
								
			case PORTC  : 
							/*	Range check for PINS Of PORT LOW	*/
							if(copy_u8PIN_ID < 8)
							{
								/*check about Direaction Input or Output*/
								switch(copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(copy_u8Speed != SPEED_INPUT)
										{
											/*	output speed Seletion	*/
											switch(copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( MGPIOC -> CRL , (copy_u8PIN_ID * 4) );	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_2MHZ		:	CLR_BIT( MGPIOC -> CRL , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_50MHZ 	:	SET_BIT( MGPIOC -> CRL , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+1) );	break;
												default				:	LOC_enumState = OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );	break;
												default						:	LOC_enumState = OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											LOC_enumState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(copy_u8Speed == SPEED_INPUT)
										{
											/* SET INPUT mode */
											CLR_BIT( MGPIOC -> CRL , ( copy_u8PIN_ID * 4) );
											CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );										break;
												case INPUT_FLOATING		:	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );										break;
												case INPUT_PULLDOWN 	:	CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );	CLR_BIT( MGPIOC -> ODR , copy_u8PIN_ID  );	break;
												case INPUT_PULLUP	 	:	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+3) );	SET_BIT( MGPIOC -> ODR , copy_u8PIN_ID  );	break;
												default					:	LOC_enumState = OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	LOC_enumState = OUT_OF_RANGE ;
								}
							}/*	Range check for PINS Of PORT HIGH		*/
							else if(copy_u8PIN_ID < 16)
							{
								/*	modification of Pin Numer of HIGH port with bit number of GPIO_CRH Reg	*/
								copy_u8PIN_ID -= 8 ; 
								
								/*check about Direaction Input or Output*/
								switch(copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(copy_u8Speed != SPEED_INPUT)
										{
											LOC_enumState = ES_OK;
											/*	output speed Seletion	*/
											switch(copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( MGPIOC -> CRH , (copy_u8PIN_ID * 4) );	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_2MHZ		:	CLR_BIT( MGPIOC -> CRH , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												case SPEED_50MHZ 	:	SET_BIT( MGPIOC -> CRH , (copy_u8PIN_ID * 4) );	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+1) );	break;
												default				:	LOC_enumState = OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	LOC_enumState = ES_OK;	break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	LOC_enumState = ES_OK;	break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	CLR_BIT( MGPIOC -> ODR , (copy_u8PIN_ID+8) );	break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	SET_BIT( MGPIOC -> ODR , (copy_u8PIN_ID+8) );	break;
												default						:	LOC_enumState = OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											LOC_enumState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(copy_u8Speed == SPEED_INPUT)
										{
											LOC_enumState = ES_OK;
											/* SET INPUT mode */
											CLR_BIT( MGPIOC -> CRL , ( copy_u8PIN_ID * 4) );
											CLR_BIT( MGPIOC -> CRL , ((copy_u8PIN_ID * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	LOC_enumState = ES_OK;	break;
												case INPUT_FLOATING		:	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	LOC_enumState = ES_OK;	break;
												case INPUT_PULLDOWN 	:	CLR_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	LOC_enumState = ES_OK;	break;
												case INPUT_PULLUP	 	:	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+2) );	SET_BIT( MGPIOC -> CRH , ((copy_u8PIN_ID * 4)+3) );	LOC_enumState = ES_OK;	break;
												default					:	LOC_enumState = OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	LOC_enumState = OUT_OF_RANGE ;
								}
							}
							else
							{
								ErrorStatus	LOC_enumState = OUT_OF_RANGE ;
							}
							break;
			/*	if not in Range A or B or CLR_BIT			*/				
			default		: LOC_enumState = OUT_OF_RANGE ;
			
		}
	
		return LOC_enumState;
}
ErrorStatus	MGPIO_enumSetPinPinValue(u8 copy_u8PortID ,u8 copy_u8PIN_ID ,u8 copy_u8Value)
{
	ErrorStatus	LOC_enumState = ES_NOK ;
	
	if(copy_u8PIN_ID < 16)
	{
		switch(copy_u8PortID)
		{
			case PORTA	:	
							switch(copy_u8Value)
							{
								case	HIGH	:	SET_BIT(MGPIOA -> ODR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
								case	LOW		:	CLR_BIT(MGPIOA -> ODR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
								default			:	LOC_enumState = OUT_OF_RANGE ;	
							}
							break; /*	The End of PortA	*/
						
			case PORTB	:	
							switch(copy_u8Value)
							{
								case	HIGH	:	SET_BIT(MGPIOB -> ODR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
								case	LOW		:	CLR_BIT(MGPIOB -> ODR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
								default			:	LOC_enumState = OUT_OF_RANGE ;	
							}
							break; /*	The End of PortB	*/
				
			case PORTC	:	
							switch(copy_u8Value)
							{
								case	HIGH	:	SET_BIT(MGPIOC -> ODR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
								case	LOW		:	CLR_BIT(MGPIOC -> ODR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
								default			:	LOC_enumState = OUT_OF_RANGE ;	
							}
							break; /*	The End of PortA	*/
						
			default		:	LOC_enumState = OUT_OF_RANGE ;
		}
	}
	else
	{
		LOC_enumState = OUT_OF_RANGE ;
	}
	
	return LOC_enumState;
	
}
ErrorStatus	MGPIO_enumGetPinValue(u8 copy_u8PortID ,u8 copy_u8PIN_ID , u8 * GPIO_Pu8Value )
{
	ErrorStatus	LOC_enumState = ES_NOK ;
	
	if(copy_u8PIN_ID < 16)
	{
			switch(copy_u8PortID)
		{
			case PORTA 	:	*GPIO_Pu8Value	=	GET_BIT(MGPIOA -> IDR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
			case PORTB 	:	*GPIO_Pu8Value	=	GET_BIT(MGPIOB -> IDR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
			case PORTC 	:	*GPIO_Pu8Value	=	GET_BIT(MGPIOC -> IDR , copy_u8PIN_ID);	LOC_enumState = ES_OK;	break;
			default		:	LOC_enumState = OUT_OF_RANGE ;
		}
	}else
	{
		LOC_enumState = OUT_OF_RANGE ;
	}

	return LOC_enumState;
}
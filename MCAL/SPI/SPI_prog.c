/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 May 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    prog.c for SPI					 	*/
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "Std_types.h"
#include "Bit_Math.h"
#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "SPI_int.h"
#include "SPI_config.h"
#include "SPI_priv.h" 


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize SPI	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void SPI_MasterInit( )
{
	
	/* SPI Enable */
	SET_BIT( SPCR , 6);
	
	/*	Data Order LSB or MSB	*/	
	#if DATA_ORDER	== LSB
		SET_BIT( SPCR , 5);
	
	#elif DATA_ORDER	== MSB
		CLEAR_BIT( SPCR , 5);
		
	#endif	
	
	/* Master Select */
	SET_BIT( SPCR , 4);	
	
	/*	Clock Polarity 	*/	
	#if CLOCK_POLARITY	== RISING_LEADING
		CLEAR_BIT( SPCR , 3);
	
	#elif RISING_LEADING  == FALLING_LEADING
		SET_BIT( SPCR , 3);
		
		
	#endif
	
	
	
	/******************************************************************/
	u16 LOC_baudEquation = 0 ;

	/*	Operation mode Synchronous or Asynchronous	*/	
	#if MODE_OF_OPERATION == ASYNCHRONOUS
		CLEAR_BIT(UCSRC, 6);
	
	#elif MODE_OF_OPERATION == SYNCHRONOUS
		SET_BIT( UCSRC , 6 );
	
	#endif
	
	
	/*	Parity mode Disabled or Odd or Even 	*/	
	#if PARITY_MODE	== DISABLED
		CLEAR_BIT(UCSRC, 4 );
		CLEAR_BIT(UCSRC, 5 );
		
	#elif PARITY_MODE	== EVEN
		CLEAR_BIT(UCSRC, 4 );
		SET_BIT( UCSRC , 5 );

	#elif PARITY_MODE	== ODD
		SET_BIT( UCSRC , 4 );
		SET_BIT( UCSRC , 5 );
		
	#endif
	
	
	/*	Speed mode normal or Double		*/
	#if MODE_OF_OPERATION == ASYNCHRONOUS
	
		if( SPEED_OPERATION	== DOUBLE_SPEED_MODE )    
			SET_BIT(UCSRA, 1);
	
		else if( SPEED_OPERATION == NORMAL_SPEED_MODE )		
			CLEAR_BIT(UCSRA, 1);
	
	#elif MODE_OF_OPERATION == SYNCHRONOUS
		CLEAR_BIT(UCSRA, 1);
	
	#endif
	
	/*  Baud rate Equation	*/
	#if MODE_OF_OPERATION == ASYNCHRONOUS
			if (GET_BIT(UCSRA, 1) == 0) 
			/* Asynchronous Normal Mode */
			LOC_baudEquation = ((F_CPU / (16 * BAUD_RATE)) - 1 );
	
			else if (GET_BIT(UCSRA, 1) == 1)
			/* Asynchronous Double Speed Mode */
			LOC_baudEquation = ((F_CPU / (8 * BAUD_RATE)) - 1 );

	#elif MODE_OF_OPERATION == SYNCHRONOUS
		/* Synchronous Master Mode */
		LOC_baudEquation = ((F_CPU / (2 * BAUD_RATE)) - 1 );
	
	#endif
	
	
	/* Set baud rate */
	UBRRH = (u8)(LOC_baudEquation>>8);
	UBRRL = (u8)LOC_baudEquation;
	

	/*	Stop bit select number One or Two Bits */	
	#if STOP_BIT_SELECT	== TWO_BIT
			SET_BIT( UCSRC , 3 );
	
	#elif STOP_BIT_SELECT	== ONE_BIT
			CLEAR_BIT( UCSRC , 3 );
	
	#endif	



	
/****************************************************************/
/** !comment :Bit 7 – URSEL: Register Select					*/
/** 		  This bit selects between accessing the UCSRC or 	*/
/*							the UBRRH Register.					*/
/*				It is read as one when reading UCSRC.			*/
/*				The URSEL must be one when writing the UCSRC.	*/
/****************************************************************/

	SET_BIT( UCSRC , 7 );



}


void SPI_SlaveInit( )
{
	
	/* SPI Enable */
	SET_BIT( SPCR , 6);
	
	/*	Data Order LSB or MSB	*/	
	#if DATA_ORDER	== LSB
		SET_BIT( SPCR , 5);
	
	#elif DATA_ORDER	== MSB
		CLEAR_BIT( SPCR , 5);
		
	#endif	
		
	/* Slave Select */
	CLEAR_BIT( SPCR , 4);

	/*	Clock Polarity 	*/	
	#if CLOCK_POLARITY	== RISING_LEADING
		CLEAR_BIT( SPCR , 3);
	
	#elif RISING_LEADING  == FALLING_LEADING
		SET_BIT( SPCR , 3);
		
		
	#endif
					
}

/****************************************************************/
/* Description    : This function used to Send Data				*/ 
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void SPI_MasterTransmit( u8 data )
{
	
	/* Wait for empty transmit buffer */
	while( GET_BIT(UCSRA,5) == 0 );
	
	/*	while ( !( UCSRA & (1<<UDRE)) );	*/
	
	/* Put data into buffer, sends the data */
	UDR = data;

}

/****************************************************************/
/* Description    : This function used to Receive Data			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
u8 SPI_SlaveReceive( )
{
	/* Wait for data to be received */
	while( GET_BIT( UCSRA , 7 ) ==0 );
	
	/*while ( !(UCSRA & (1<<RXC)) );*/
	
	/* Get and return received data from buffer */
	return UDR;
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
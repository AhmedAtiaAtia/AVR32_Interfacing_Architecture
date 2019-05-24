/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 May 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure USART Frame [config.h] 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/
#ifndef _USART_CONFIG_H
#define _USART_CONFIG_H


/****************************************************************/
/** !comment : Please Enter the Data Order						*/
/** 		   DATA_ORDER can be : 								*/
/*					    					LSB			 		*/
/*						    				MSB					*/
/****************************************************************/

#define DATA_ORDER					LSB


/****************************************************************/
/*	CPOL = 0 Rising (Leading Edge) and Falling (Trailing Edge)	*/
/*	CPOL = 1 Falling (Leading Edge) and Rising (Trailing Edge)	*/ 
/****************************************************************/
/** !comment : Please Enter the Clock Polarity					*/
/** 		   Speed Operation can be : 						*/
/*					    				RISING_LEADING	 		*/
/*						    			FALLING_LEADING			*/
/****************************************************************/

#define CLOCK_POLARITY				RISING_LEADING
 

/****************************************************************/
/*	CPHA = 0 Sample (Leading Edge) and Setup (Trailing Edge)	*/
/*	CPHA = 1 Setup (Leading Edge) and Sample (Trailing Edge)	*/ 
/****************************************************************/
/** !comment : Please Enter the Clock Phase						*/
/** 		   Speed Operation can be : 						*/
/*					    				SAMPLE_LEADING	 		*/
/*						    			SETUP_LEADING			*/
/****************************************************************/

#define CLOCK_PHASE					SAMPLE_LEADING
  
 
/****************************************************************/
/** !comment : Please Enter the Frame Size						*/
/** 		   FRAME_SIZE can be : 								*/
/*					    			5 Bits				 		*/
/*						    		6 Bits						*/
/*									7 Bits						*/
/*									8 Bits						*/
/*									9 Bits						*/
/****************************************************************/

#define FRAME_SIZE			8


/****************************************************************/
/** !comment : Please Enter the Baud Rate						*/
/****************************************************************/
 
#define BAUD_RATE			9600

/****************************************************************/
/** !comment : Please Enter the Parity Mode						*/
/** 		   PARITY_MODE can be : 							*/
/*					    			DISABLED 					*/
/*						    		EVEN 						*/
/*							    	ODD							*/
/****************************************************************/

#define PARITY_MODE			DISABLED

/****************************************************************/
/** !comment : Please Enter the Number of Stop Bits				*/
/** 		   STOP_BIT_SELECT can be : 						*/
/*					    				ONE_BIT 				*/
/*						    			TWO_BIT					*/
/****************************************************************/

#define STOP_BIT_SELECT		TWO_BIT

/****************************************************************/
/** !comment : For using  Clock Polarity the Mode of Operation	*/
/**							MUST be SYNCHRONOUS					*/
/****************************************************************/
/*	UCPOL = 0 Rising Edge (Transmitted) Falling Edge (Received)	*/
/*	UCPOL = 1 Falling Edge (Transmitted) Rising Edge (Received) */ 
/****************************************************************/
/** !comment : Please Enter the Clock Polarity					*/
/** 		   CLOCK_POLARITY can be : 							*/
/*					    				RISING			 		*/
/*						    			FALLING					*/
/****************************************************************/

#define CLOCK_POLARITY		RISING

#endif	/**!comment : End of the gaurd [_USART_CONFIG_H]	  **/

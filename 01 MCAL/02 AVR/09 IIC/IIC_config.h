/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    25 May 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure IIC [config.h]		 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/
#ifndef _IIC_CONFIG_H
#define _IIC_CONFIG_H

/****************************************************************/
/*   F_CPU = 8000000UL 											*/
/****************************************************************/
/** !comment : Please Enter the Bus Clock						*/
/** 		   BUS_CLOCK can be in (KHZ) : 						*/
/*					    					100 				*/
/*						    				400					*/
/****************************************************************/

#define BUS_CLOCK			100














/****************************************************************/
/*  UMSEL = 1 synchronous 										*/
/*  UMSEL = 0 Asynchronous										*/
/****************************************************************/
/** !comment : Please Enter the Operation Mode					*/
/** 		   MODE_OF_OPERATION can be : 						*/
/*					    					ASYNCHRONOUS 		*/
/*						    				SYNCHRONOUS 		*/
/****************************************************************/

#define MODE_OF_OPERATION	ASYNCHRONOUS


/****************************************************************/
/** !comment : For using  Speed Operation the Mode of Operation	*/
/**							MUST be ASYNCHRONOUS				*/
/****************************************************************/
/*	U2X = 0 normal speed										*/
/*	U2X = 1 double speed										*/ 
/****************************************************************/
/** !comment : Please Enter the Speed Operation					*/
/** 		   Speed Operation can be : 						*/
/*					    				NORMAL_SPEED_MODE 		*/
/*						    			DOUBLE_SPEED_MODE		*/
/****************************************************************/

#define SPEED_OPERATION		DOUBLE_SPEED_MODE
 
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

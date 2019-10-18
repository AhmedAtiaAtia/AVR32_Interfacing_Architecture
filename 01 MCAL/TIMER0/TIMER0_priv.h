/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    26 Sept 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    contain the Memory mapped of		*/	
/*							 [,,,] Registers */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _TIMER0_PRIV_H
#define _TIMER0_PRIV_H


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of ADCSRA    	*/
/**			   Register	is  0X26						    	*/
/****************************************************************/
/**			   ADCSRA : MCU Control Register contains control	*/
/** 		   bits for interrupt sense control and general 	*/
/**            MCU functions.							    	*/
/****************************************************************/

#define TCCR0		*((volatile u8 * ) (0X53))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCSR   	*/
/**			   Register	is  0X54.								*/
/****************************************************************/
/**			   MCUCSR : MCU Control and Status Register			*/
/****************************************************************/

#define TCNT0       *((volatile u8 * ) (0X52))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GICR     	*/
/**			   Register	is  0X5B.								*/
/****************************************************************/
/**			   GICR : General Interrupt Control Register		*/
/****************************************************************/

#define OCR0        *((volatile u8 * ) (0X5C))


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   Register	is  0X5A.						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define TIMSK        *((volatile u8 * ) (0X59))

#define TIFR         *((volatile u8 * ) (0X58))


#endif	/**!comment : End of the guard [_TIMER0_PRIV_H]		   **/
/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    contain the Memory mapped of		*/	
/*							 [MCUCR,MCUCSR,GICR,GIFR] Registers */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _EXT0_PRIV_H
#define _EXT0_PRIV_H


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCR    	*/
/**			   Register	is  0X55						    	*/
/****************************************************************/
/**			   MCUCR : MCU Control Register contains control	*/
/** 		   bits for interrupt sense control and general 	*/
/**            MCU functions.							    	*/
/****************************************************************/

#define MCUCR		*((volatile u8 * ) (0X55))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of MCUCSR   	*/
/**			   Register	is  0X54.								*/
/****************************************************************/
/**			   MCUCSR : MCU Control and Status Register			*/
/****************************************************************/

#define MCUCSR      *((volatile u8 * ) (0X54))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GICR     	*/
/**			   Register	is  0X5B.								*/
/****************************************************************/
/**			   GICR : General Interrupt Control Register		*/
/****************************************************************/

#define GICR        *((volatile u8 * ) (0X5B))


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   Register	is  0X5A.						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define GIFR        *((volatile u8 * ) (0X5A))



#endif	/**!comment : End of the guard [_EXT0_PRIV_H]		   **/
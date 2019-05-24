/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 May 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    contain the Memory mapped Registers*/
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _USART_PRIV_H
#define _USART_PRIV_H





/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UCSRA     	*/
/**			   Register	is  0X2B.						    	*/
/****************************************************************/
/**			   UCSRA : USART Control and Status Register A  	*/
/****************************************************************/

#define UCSRA        *((volatile u8 * ) (0X2B))


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UCSRB    	*/
/**			   Register	is  0X2A						    	*/
/****************************************************************/
/**			   UCSRB : USART Control and Status Register B 	 	*/
/****************************************************************/

#define UCSRB		*((volatile u8 * ) (0X2A))




/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UCSRC     	*/
/**			   Register	is  0X40.								*/
/****************************************************************/
/**			   UCSRC : USART Control and Status Register C		*/
/****************************************************************/

#define UCSRC		*((volatile u8 * ) (0X40))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UBRRH     	*/
/**			   Register	is  0X40.								*/
/****************************************************************/
/**			   UBRRH : USART Baud Rate Register					*/
/****************************************************************/

#define UBRRH      *((volatile u8 * ) (0X40))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UBRRL 	  	*/
/**			   Register	is  0X29.								*/
/****************************************************************/
/**			   UBRRL : USART Baud Rate Register					*/
/****************************************************************/


#define UBRRL        *((volatile u8 * ) (0X29))


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UDR  	   	*/
/**			   Register	is  0X2C.								*/
/****************************************************************/
/**			   UDR : I/O Data Register							*/
/****************************************************************/

#define UDR			*((volatile u8 * ) (0X2C))


#endif	/**!comment : End of the guard [_USART_PRIV_H]		   **/
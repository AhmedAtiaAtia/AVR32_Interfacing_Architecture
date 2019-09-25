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

#ifndef _IIC_PRIV_H
#define _IIC_PRIV_H





/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UCSRA     	*/
/**			   Register	is  0X2B.						    	*/
/****************************************************************/
/**			   UCSRA : USART Control and Status Register A  	*/
/****************************************************************/

#define TWBR        *((volatile u8 * ) (0X20))


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UCSRB    	*/
/**			   Register	is  0X2A						    	*/
/****************************************************************/
/**			   UCSRB : USART Control and Status Register B 	 	*/
/****************************************************************/

#define TWCR		*((volatile u8 * ) (0X56))




/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UCSRC     	*/
/**			   Register	is  0X40.								*/
/****************************************************************/
/**			   UCSRC : USART Control and Status Register C		*/
/****************************************************************/

#define TWSR		*((volatile u8 * ) (0X21))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UBRRH     	*/
/**			   Register	is  0X40.								*/
/****************************************************************/
/**			   UBRRH : USART Baud Rate Register					*/
/****************************************************************/

#define TWDR      *((volatile u8 * ) (0X23))

/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of UBRRL 	  	*/
/**			   Register	is  0X29.								*/
/****************************************************************/
/**			   UBRRL : USART Baud Rate Register					*/
/****************************************************************/


#define TWAR        *((volatile u8 * ) (0X22))




#endif	/**!comment : End of the guard [_IIC_PRIV_H]		   **/
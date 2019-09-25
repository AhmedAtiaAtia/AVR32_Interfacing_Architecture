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

#ifndef _SPI_PRIV_H
#define _SPI_PRIV_H





/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of SPCR     	*/
/**			   Register	is  0X2D.						    	*/
/****************************************************************/
/**			   SPCR : SPI Control Register 					  	*/
/****************************************************************/

#define SPCR        *((volatile u8 * ) (0X2D))







/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of SPSR     	*/
/**			   Register	is  0X2E.								*/
/****************************************************************/
/**			   SPSR : SPI Status Register						*/
/****************************************************************/

#define SPSR		*((volatile u8 * ) (0X2E))



/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of SPDR  	   	*/
/**			   Register	is  0X2F.								*/
/****************************************************************/
/**			   SPDR : SPI Data Register							*/
/****************************************************************/

#define SPDR			*((volatile u8 * ) (0X2F))


#endif	/**!comment : End of the guard [_SPI_PRIV_H]		   **/
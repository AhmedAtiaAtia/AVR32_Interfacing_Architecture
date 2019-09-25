/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    GIE priv [priv.h] contain the 		*/
/*                           Memory mapped of SREG Register    	*/
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _GIE_PRIV_H
#define _GIE_PRIV_H


/****************************************************************/	
/** !comment : From Data Sheet :  Memory mapped of SREG	   		*/
/**			   Register	is  0X5F						   		*/
/****************************************************************/

#define SREG		* ( ( volatile u8 * ) ( 0X5F ) )



#endif	/**!comment : End of the guard [_GIE_PRIV_H]		   **/

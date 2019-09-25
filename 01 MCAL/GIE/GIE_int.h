/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    20 April 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							for GIE [int.h] 				    */
/****************************************************************/


/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _GIE_INT_H
#define _GIE_INT_H


/*****************************************************************/
/* Description    : This function used to Enable GIE			 */ 
/*																 */
/*					Inputs : void					  			 */
/*					Return : void		 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt  */
/*     				 initialized 							     */
/*****************************************************************/

void GIE_voidEnable();

/*****************************************************************/
/* Description    : This function used to Disable GIE			 */ 
/*																 */
/*					Inputs : void					  			 */
/*					Return : void		 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt  */
/*     				 initialized 							     */
/*****************************************************************/

void GIE_voidDisable();



#endif /**!comment : End of the guard [_GIE_INT_H]			   **/

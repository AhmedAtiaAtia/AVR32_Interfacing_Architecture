/***************************************************/
/* Author : Ahmed Shaker                           */
/* Date : 9 Mars 2018                              */
/* Version : V01                                   */
/***************************************************/


#ifndef _LCD_INT_H_
#define _LCD_INT_H_

/* Description : This function Initialize LCD      */
void LCD_voidInitialize(void);

/* Description : This function Write Date To LCD   */
void LCD_voidWriteData(u8 Copy_u8Date);

/* Description : This function Send Command To LCD */
void LCD_voidWriteCommand(u8 Copy_u8Cmd);

#endif

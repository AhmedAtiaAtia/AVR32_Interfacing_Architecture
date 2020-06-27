#ifndef LCD_INT_H
#define LCD_INT_H

void LCD_Init(void);
void LCD_writeChar(u8 Data);
void LCD_writeCMD(u8 CMD);

#define		CONTROL_PORT		PORTA
#define		RS					PIN7
#define		RW					PIN6
#define		EN					PIN5


#define		DATA_PORT			PORTB

#endif
/*
 * Macros.h
 *
 *  Created on: Dec 8, 2017
 *      Author: abo-alnor
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(Byte,Pos) ((Byte) |= (1<<(Pos))) 
#define CLEAR_BIT(Byte,Pos) ((Byte) &= ~(1<<(Pos)))
#define TOGGLE_BIT(Byte,Pos) ((Byte) ^=(1<<(Pos)))

#define SET_BYTE(Byte) (Byte |=(0xFF))
#define CLEAR_BYTE(Byte) (Byte &=(0x00))

#define SET_NIBBLE_HIGH(Byte) (Byte |=(0xF0))
#define SET_NIBBLE_LOW(Byte) (Byte |=(0x0F))
#define CLEAR_NIBBLE_HIGH(Byte) (Byte &=(0x0F))
#define CLEAR_NIBBLE_LOW(Byte) (Byte &=(0xF0))

#define CONC_BIT(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0) CONC_HELP(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)
#define CONC_HELP(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0) 0b##bit7##bit6##bit5##bit4##bit3##bit2##bit1##bit0 

#define GET_BIT(Reg,Bit) (((Reg)>>(Bit))&(0x01))

#endif /* MACROS_H_ */

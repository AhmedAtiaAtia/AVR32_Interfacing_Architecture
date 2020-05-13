
#ifndef _DIO_REG_H
#define _DIO_REG_H

/* Group A Registers */
#define PORTA  *((volatile u8*)0x3B)
#define DDRA   *((volatile u8*)0x3A)
#define PINA   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB  *((volatile u8*)0x38)
#define DDRB   *((volatile u8*)0x37)
#define PINB   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC  *((volatile u8*)0x35)
#define DDRC   *((volatile u8*)0x34)
#define PINC   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD  *((volatile u8*)0x32)
#define DDRD   *((volatile u8*)0x31)
#define PIND   *((volatile u8*)0x30)

///* Group A Registers */
//#define PORTA_Register  *((volatile u8*)0x3B)
//#define DDRA_Register   *((volatile u8*)0x3A)
//#define PINA_Register   *((volatile u8*)0x39)
//
///* Group B Registers */
//#define PORTB_Register  *((volatile u8*)0x38)
//#define DDRB_Register   *((volatile u8*)0x37)
//#define PINB_Register   *((volatile u8*)0x36)
//
///* Group C Registers */
//#define PORTC  *((volatile u8*)0x35)
//#define DDRC   *((volatile u8*)0x34)
//#define PINC   *((volatile u8*)0x33)
//
///* Group D Registers */
//#define PORTD  *((volatile u8*)0x32)
//#define DDRD   *((volatile u8*)0x31)
//#define PIND   *((volatile u8*)0x30)

#endif

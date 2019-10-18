

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF  7
#define WCOL  6
#define SPI2X 0

#define ENABLE_INTERRUPT   5
#define DISABLE_INTERRUPT   9

#define LSB_FIRST    8
#define MSB_FIRST    11

#define MASTER  0
#define SLAVE   3

#define IDLE_LOW   2
#define IDLE_HIGH  5


#define ZERO   0
#define ONE    6


#define QUARTER_FREQ   2
#define HALF_FREQ  6





#define SPCR (*((volatile uint8 *)0x2D ))
#define SPSR (*((volatile uint8 *)0x2E ))
#define SPDR (*((volatile uint8 *)0x2F ))


#endif /* SPI_PRIV_H_ */

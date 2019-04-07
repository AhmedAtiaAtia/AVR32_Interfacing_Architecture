/***************************************************/
/* AUTHOR      : AHMED ABO ELNOUR                  */
/* DISCRIPTION : DIO DRIVER                        */
/* DATE        : 20 FEB 2018                       */
/* VERSION     : V02                               */
/***************************************************/

#ifndef _DIO_CONFIG_H
#define _DIO_CONFIG_H

/***************************************************/
/*  TIPS : IF YOU WANT TO CONFIGURE DIO            */
/*    	   PINS YOU should DETERMINE PIN           */
/*		   INPUT OR OUTPUT BY                      */
/*  	 # DIO_u8_OUTPUT FOR OUTPUT #              */
/*		 # DIO_u8_INPUT FOR INPUT   # 	           */
/***************************************************/


/* DISCRIPTION : PORT A DIRECTIONS INPUT OR OUTPUT  
*                 FROM PIN 0 -> PIN 7              */
#define DIO_u8_PIN_DIR_0    DIO_u8_OUTPUT
#define DIO_u8_PIN_DIR_1    DIO_u8_INPUT
#define DIO_u8_PIN_DIR_2    DIO_u8_INPUT
#define DIO_u8_PIN_DIR_3    DIO_u8_INPUT
#define DIO_u8_PIN_DIR_4    DIO_u8_OUTPUT
#define DIO_u8_PIN_DIR_5    DIO_u8_INPUT
#define DIO_u8_PIN_DIR_6    DIO_u8_INPUT
#define DIO_u8_PIN_DIR_7    DIO_u8_INPUT

/* DISCRIPTION : PORT B DIRECTIONS INPUT OR OUTPUT  
*                 FROM PIN 8 -> PIN 15              */
#define DIO_u8_PIN_DIR_8    DIO_u8_INPUT
#define DIO_u8_PIN_DIR_9    DIO_u8_INPUT
#define DIO_u8_PIN_DIR_10   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_11   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_12   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_13   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_14   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_15   DIO_u8_OUTPUT

/* DISCRIPTION : PORT C DIRECTIONS INPUT OR OUTPUT  
*                 FROM PIN 16 -> PIN 23             */
#define DIO_u8_PIN_DIR_16   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_17   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_18   DIO_u8_OUTPUT
#define DIO_u8_PIN_DIR_19   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_20   DIO_u8_OUTPUT
#define DIO_u8_PIN_DIR_21   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_22   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_23   DIO_u8_INPUT

/* DISCRIPTION : PORT D DIRECTIONS INPUT OR OUTPUT  
*                 FROM PIN 24 -> PIN 31              */
#define DIO_u8_PIN_DIR_24   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_25   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_26   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_27   DIO_u8_OUTPUT
#define DIO_u8_PIN_DIR_28   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_29   DIO_u8_INPUT
#define DIO_u8_PIN_DIR_30   DIO_u8_OUTPUT
#define DIO_u8_PIN_DIR_31   DIO_u8_OUTPUT


#endif

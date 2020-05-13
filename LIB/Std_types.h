/************************************************/
/******** Author      : Ahmed Atia Atia *********/
/******** Date        : 3/8/2019        *********/
/******** version     : 1.0 V           *********/
/******** Description : STD_Lib         *********/ 
/************************************************/


/************************************************/
/* guard of file will call one time in .c      **/
/************************************************/


#ifndef _STD_types_H_
#define _STD_types_H_

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f96;

/******************************************************/
/*pointer to function=>for declarition pf x = & fun();*/
/******************************************************/

typedef void(*pf)(void);

#endif

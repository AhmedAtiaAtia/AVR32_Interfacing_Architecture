/************************************************/
/******** Author      : Ahmed Atia Atia *********/
/******** Date        : 3/8/2019        *********/
/******** version     : 1.0 V           *********/
/******** Description : ERROR_STATUS	*********/ 
/************************************************/


/************************************************/
/* guard of file will call one time in .c      **/
/************************************************/


#ifndef _ERROR_STATUS_H_
#define _ERROR_STATUS_H_

typedef enum Error
{
	
	ES_OK,
	ES_NOK,
	ES_OUT_OF_RANGR,
	ES_NULL_POINTER
	
}ErrorStatus;

#define void(*pf)(void)

#endif




/******************/
/* ErrorStatus errorsta = LBT_OK  */
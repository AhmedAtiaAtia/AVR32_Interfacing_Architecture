/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    2 May 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Configure Sense Mode [config.h] 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/
#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H


/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AREF 				*/
/*						    				AVCC 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define VOLTAGE_REFERENCE		AVCC



/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/** 		   ADJUSTMENT can be : 								*/
/*					    					RIGHT_ADJUSTMENT	*/
/*							    			LEFT_ADJUSTMENT		*/	
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/

#define ADJUSTMENT				LEFT_ADJUSTMENT


/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define ADC_CHANNEL_NUMBER		DIO_U8_PIN_0

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING_MODE

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/	
/****************************************************************/

#define ADC_PRESCALLER			DIVID_BY_2




#endif	/**!comment : End of the guard [_ADC_CONFIG_H]		   **/

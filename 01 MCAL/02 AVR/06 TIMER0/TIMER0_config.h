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
#ifndef _TIMER0_CONFIG_H
#define _TIMER0_CONFIG_H


/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					NORMAL 				*/
/*						    				CTC					*/
/*											FAST_PWM			*/				    			
/*											PWM_PHASECORRECT	*/	
/****************************************************************/

#define WAVEFORM_MODE			NORMAL






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
/*					    					NO_PRESCALLER 		*/
/*						    				DIVID_BY_8			*/
/*							    			DIVID_BY_64			*/
/*											DIVID_BY_256		*/		
/*											DIVID_BY_1024		*/
/*											COUNT_FALLING_EDGES	*/
/*											COUNT_RISING_EDGES	*/	
/****************************************************************/

#define TIMER0_PRESCALLER				DIVID_BY_8


#endif	/**!comment : End of the guard [_TIMER0_CONFIG_H]		   **/

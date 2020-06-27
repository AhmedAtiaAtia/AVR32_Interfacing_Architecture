
#ifndef _TIMER0_CONFIG_H
#define _TIMER0_CONFIG_H

/*Range
#define TIMER0_NORMAL 		
#define TIMER0_CTC 			
#define TIMER0_FAST_PWM 	
#define TIMER0_PHASE_PWM 	
*/

#define TIMER0_MODE 		TIMER0_FAST_PWM
/*Range
//#define		NO_PRESCALLER			0
#define TIMER0_DIV_BY_1			
#define TIMER0_DIV_BY_8			
#define TIMER0_DIV_BY_64		
#define TIMER0_DIV_BY_256		
#define TIMER0_DIV_BY_1024		
*/
#define TIMER0_PRESCALER  	TIMER0_DIV_BY_1024

/*Range
#define TIMER0_NO_ACTION	
#define TIMER0_TOGGLE		
#define TIMER0_SET			
#define TIMER0_CLEAR		
*/

#define TIMER0_COM_EVENT   TIMER0_CLEAR


#endif

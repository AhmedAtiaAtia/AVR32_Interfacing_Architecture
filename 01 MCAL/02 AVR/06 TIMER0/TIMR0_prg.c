
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer0_int.h"
#include "Timer0_priv.h"
#include "Timer0_config.h"

void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;

void TIMER0_void_Init(void)
{
	#if(TIMER0_MODE == TIMER0_NORMAL)
		CLEAR_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_CTC)
		CLEAR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER0_FAST_PWM )
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER0_PHASE_PWM )
		SET_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
		
	#endif
	
	#if(TIMER0_PRESCALER == TIMER0_DIV_BY_1)
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_8)
		CLEAR_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_64 )
		SET_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_256 )
		CLEAR_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_1024 )
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
		
	#endif
	
	#if(TIMER0_COM_EVENT == TIMER0_NO_ACTION)
		CLEAR_BIT(TCCR0 , 4);
		CLEAR_BIT(TCCR0 , 5);
		
	
	#elif(TIMER0_COM_EVENT == TIMER0_TOGGLE)
		SET_BIT(TCCR0 , 4)
		CLEAR_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_CLEAR )
		CLEAR_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_SET )
		SET_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);

		
	#endif
	/*Disable Interrupts*/
	CLEAR_BIT(TIMSK , 0);	
	CLEAR_BIT(TIMSK , 1);
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , 0);	
	SET_BIT(TIFR , 1);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
	
	
}

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT0 = Copy_uint8Val ;
}

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = Copy_uint8Val ;
}

void TIMER0_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 0);
}

void TIMER0_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 0);
}

void TIMER0_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 1);
}

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	
	TIMER0_CTC_CallBack();
}

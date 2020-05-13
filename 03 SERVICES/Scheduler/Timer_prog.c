
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_int.h"
#include "Timer_reg.h"
#include "Timer_int.h"





//Init global pointer to function

static void(*Gptrtofunc)(void);

void __vector_7(void)        __attribute__((signal));



void Timer1_Init(void)
{
	//CTC MODE , Enable INT of compare match for channel A
	TCCR1A = 0x00;

	OCR1A = 1000;

	TCNT1 = 0;
	//	Enable Global INT
	SET_BIT(SREG,7);

	// Enable Compare match INT Channel A
	SET_BIT(TIMSK,4);

	TCCR1B = 0b00001010;

}




void Timer_set_callback( void(*localPfunc)(void))
{
	//set global pointer to function
	Gptrtofunc = localPfunc;
}



void __vector_7(void)
{
	Gptrtofunc();
}



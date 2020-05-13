#ifndef		RCC_INT_H
#define		RCC_INT_H

void MRCC_voidInit(void);
ErrorStatus MRCC_enumSetPeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralName , u8 Copy_u8PeripheralState );

#define		AHB										1
#define		APB1									2
#define		APB2									3

#define		RCC_ENABLE								1
#define		RCC_DISABLE								2
#define		RCC_RESET								3

#define		GPIOA									2
#define		GPIOB									3
#define		GPIOC									4

#define		HSI										1										
#define		HSE										2										
#define		PLL_HSI_DIVIDED_BY_2					3							
#define		PLL_HSE									4		
#define		PLL_HSE_DIVIDED_BY_2					5
#define		HSEPYPASS								6
#define		PLL										7


#define		NO_CLOCK_FACTOR							0  
#define		DIVIDED_BY_2							1 	
#define		MULTIPLY_BY_2							2		
#define		MULTIPLY_BY_3							3		
#define		MULTIPLY_BY_4							4		
#define		MULTIPLY_BY_5							5
#define		MULTIPLY_BY_6							6	
#define		MULTIPLY_BY_7							7		
#define		MULTIPLY_BY_8							8								
#define		MULTIPLY_BY_9							9							
#define		MULTIPLY_BY_10							10							
#define		MULTIPLY_BY_11							11							
#define		MULTIPLY_BY_12							12							
#define		MULTIPLY_BY_13							13							
#define		MULTIPLY_BY_14							14							
#define		MULTIPLY_BY_15							15							
#define		MULTIPLY_BY_16							16	

#endif

#define		OUTPUT							1
#define		INPUT							3
/**************************************************************/
#define		HIGH							1
#define		LOW								0
/**************************************************************/
#define		OUTPUT_PUSHPULL					1
#define		OUTPUT_OPEN_DRAIN				3
#define		AF_OUTPUT_PUSHPULL				5
#define		AF_OUTPUT_OPEN_DRAIN			7
/**************************************************************/

#define		SPEED_INPUT						1
#define		SPEED_10MHZ						3
#define		SPEED_2MHZ						7
#define		SPEED_50MHZ						5

/*************************************************************/

#define		INPUT_ANALOG					13
#define		INPUT_FLOATING					14
#define		INPUT_PULLDOWN					15
#define		INPUT_PULLUP					16


/*************************************************************/

#define		PORTA							1
#define		PORTB							3
#define		PORTC							5


/*************************************************************/
#define		PIN0							0
#define		PIN1							1
#define		PIN2							2
#define		PIN3							3
#define		PIN4							4
#define		PIN5							5
#define		PIN6							6
#define		PIN7							7
#define		PIN8							8
#define		PIN9							9
#define		PIN10							10
#define		PIN11							11
#define		PIN12							12
#define		PIN13							13
#define		PIN14							14
#define		PIN15							15

//void MGPIO_voidInit(void);
ErrorStatus	MGPIO_enumSetPinDirection(u8 copy_u8PortID ,u8 copy_u8PIN_ID ,u8 copy_u8Direction ,u8 copy_u8Mode ,u8 copy_u8Speed);
ErrorStatus	MGPIO_enumSetPinPinValue(u8 copy_u8PortID ,u8 copy_u8PIN_ID ,u8 copy_u8Value);
ErrorStatus	MGPIO_enumGetPinValue(u8 copy_u8PortID ,u8 copy_u8PIN_ID , u8 * GPIO_Pu8Value );
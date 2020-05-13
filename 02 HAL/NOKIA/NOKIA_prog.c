
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "GPIO_int.h"
#include "SPI_int.h"
void NOKIA_voidInit(void)
{
		/*Reset Pulse high 2m low 2m then high*/
		DIO_SETpinvalue(A , 2 , 1 );
		/*Delay 2 msec*/
		STK_voidBusyDelay(2000);

		/*	low	 2 msec		*/
		DIO_SETpinvalue(A , 2 , 0 );
		/*Delay 2 msec*/
		STK_voidBusyDelay(2000);
		
		/*High*/
		DIO_SETpinvalue(A , 2 , 1 );
		
		/*Init Extended Mode*/
		NOKIA_voidWriteCMD(0b00100001);
		/*Temp Typical curve*/
		NOKIA_voidWriteCMD(0b00100110);
			/*Baise system	1:48	*/
		NOKIA_voidWriteCMD(0b00010011);	
				/*Set Contrast Vop BF or BE*/
		NOKIA_voidWriteCMD(0XBF);
		
		
		/*Normal mode*/
			/*Init Extended Mode*/
		NOKIA_voidWriteCMD(0b00100000);
		
		/*Display controll cmd*/
		NOKIA_voidWriteCMD(0b00001100);

}
void NOKIA_voidDisplayData(u8 * copy_DataArray)
{
	/* x add =0 y add = 0*/
	
	for(u16 i = 0 ; i < 504 ; i++)
	{
		NOKIA_voidWriteData(copy_DataArray[i]);
	}
}
static void NOKIA_voidWriteData(u8 copy_u8Data)
{
	/*Clear CE PIN*/
	DIO_SETpinvalue(A , 3 , 0 );
	/*DC = 1  for data and 0 for CMD*/
	DIO_SETpinvalue(A , 1 , 1 );
	/*Send Data over SPI*/
	SPI_SendData(copy_u8Data);
	/*SET CE PIN*/
	DIO_SETpinvalue(A , 3 , 1 );
}
static void NOKIA_voidWriteCMD(u8 copy_u8CMD)
{
	/*Clear CE PIN*/
	DIO_SETpinvalue(A , 3 , 0 );
	/*DC = 1  for data and 0 for CMD*/
	DIO_SETpinvalue(A , 1 , 0 );
	/*Send Data over SPI*/
	SPI_SendData(copy_u8CMD);
	/*SET CE PIN*/
	DIO_SETpinvalue(A , 3 , 1 );	
}
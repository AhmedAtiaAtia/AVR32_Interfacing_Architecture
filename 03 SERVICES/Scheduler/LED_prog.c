
#include "LIB/STD_TYPES.h"
#include "DIO_int.h"

#define LED_PORT   PORT_A

#define LED_G_PIN  PIN0
#define LED_Y_PIN  PIN1
#define LED_R_PIN  PIN2


void LED_Init(void)
{
	//Confg LED PINS -> Output
	DIO_SetPinDirection(LED_PORT,LED_G_PIN,OUTPUT);
	DIO_SetPinDirection(LED_PORT,LED_R_PIN,OUTPUT);
	DIO_SetPinDirection(LED_PORT,LED_Y_PIN,OUTPUT);

}

void LED_R_Tog(void)
{
	static u8 flag = 0;
	if(flag == 0)
	{
		DIO_SetPinValue(LED_PORT,LED_R_PIN,HIGH);
		flag = 1;
	}
	else if(flag == 1)
	{
		DIO_SetPinValue(LED_PORT,LED_R_PIN,LOW);
		flag = 0;
	}
}
void LED_Y_Tog(void)
{
	static u8 flag = 0;
	if(flag == 0)
	{
		DIO_SetPinValue(LED_PORT,LED_Y_PIN,HIGH);
		flag = 1;
	}
	else if(flag == 1)
	{
		DIO_SetPinValue(LED_PORT,LED_Y_PIN,LOW);
		flag = 0;
	}
}
void LED_G_Tog(void){
	static u8 flag = 0;
	if(flag == 0)
	{
		DIO_SetPinValue(LED_PORT,LED_G_PIN,HIGH);
		flag = 1;
	}
	else if(flag == 1)
	{
		DIO_SetPinValue(LED_PORT,LED_G_PIN,LOW);
		flag = 0;
	}
}

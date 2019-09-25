/******************************************************/
/* Author  : Ahmed Abo Elnour                         */
/* Date    : 17 FEB 2018                              */
/* Version : 1V                                       */
/******************************************************/
#include "STD_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SEV_int.h"
#include "SEV_config.h"
#include "SEV_priv.h"






void SEV_voidSet7SegmentValue(u8 Copy_u8SevenSegmentNumber , u8 Copy_u8SevenSegmentValue )
{
	u8 seg [10]= {0xC0 , 0xF9 , 0xA4 , 0xB0 , 0x99 , 0x92 , 0x82,0xf8, 0x80,0x90};
	u8 LOC_u8Loop=SEV_START;
	if (Copy_u8SevenSegmentNumber ==SEV_LEFT )
	{
		
		DIO_voidSetPinValue (SEV_0_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_0_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_0_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_0_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_0_u8_E ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_0_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_0_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_0_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
	}
	else if (Copy_u8SevenSegmentNumber ==SEV_RIGHT)
	{
		LOC_u8Loop=SEV_START;
		DIO_voidSetPinValue (SEV_1_u8_A ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_1_u8_B ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_1_u8_C ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_1_u8_D ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_1_u8_E ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_1_u8_F ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_1_u8_G ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
		DIO_voidSetPinValue (SEV_1_u8_H ,GET_BIT(seg[Copy_u8SevenSegmentValue],(LOC_u8Loop++)));
	}		
	
}

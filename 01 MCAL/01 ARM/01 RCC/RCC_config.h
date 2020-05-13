#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

/*clockType may be :											*/
/*					1-HSI										*/
/*					2-HSE										*/
/*					3-PLL										*/
/*					4-HSEPYPASS									*/
#define 	CLOCK_TYPE 					HSI			

/*PLL_SOURCE may be :											*/
/*					1-PLL_HSI_DIVIDED_BY_2						*/
/*					2-PLL_HSE									*/
/*					3-PLL_HSE_DIVIDED_BY_2						*/
#define		PLL_SOURCE					PLL_HSI_DIVIDED_BY_2			

/*clockFactor may be :												*/
/*					1-	NO_CLOCK_FACTOR  For HSI or HSE  			*/
/*					2-	DIVIDED_BY_2 	For HSE						*/
/*					3-	MULTIPLY_BY_2	For PLL						*/
/*					4-	MULTIPLY_BY_3	For PLL						*/
/*					5-	MULTIPLY_BY_4	For PLL						*/
/*					6-	MULTIPLY_BY_5	For PLL						*/
/*					7-	MULTIPLY_BY_6	For PLL						*/
/*					8-	MULTIPLY_BY_7	For PLL						*/
/*					9-	MULTIPLY_BY_8	For PLL						*/
/*					10-	MULTIPLY_BY_9	For PLL						*/
/*					11-	MULTIPLY_BY_10	For PLL						*/
/*					12-	MULTIPLY_BY_11	For PLL						*/
/*					13-	MULTIPLY_BY_12	For PLL						*/
/*					14-	MULTIPLY_BY_13	For PLL						*/
/*					15-	MULTIPLY_BY_14	For PLL						*/
/*					16-	MULTIPLY_BY_15	For PLL						*/
/*					17-	MULTIPLY_BY_16	For PLL						*/

#define 	CLOCK_FACTOR				NO_CLOCK_FACTOR 

/*  clock security system Enable and Disable		*/
/*	may be ON or OFF								*/

#define 	CLOCK_SECURITY_SYSTEM		OFF

/****************************************************/
/*	MicroController output clock may be :			*/
/*					1-	NO_CLOCK					*/
/*					2-	SYSTEM_CLOCK				*/
/*					3-	HSI							*/
/*					4-	HSE							*/
/*					5-	PLL_DIVIDED_BY_2			*/
/****************************************************/
/*	When the System Clock is selected to output to	*/ 
/*	the MCO pin, make sure that this clock 			*/
/*	does not exceed 50 MHz (the maximum IO speed).	*/
/****************************************************/

#define 	MC_OUT_CLOCK				NO_CLOCK

#define		USBPRESCALLER					1

#define		APB1_prescaller					1
#define		APB2_prescaller					1
#define		AHB_prescaller					1

#endif		/*RCC_CONFIG_H*/
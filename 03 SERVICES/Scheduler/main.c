
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "Timer_int.h"

/* HAL */
#include "LED_int.h"

/* OS */
#include "RTO_interface.h"




int main(void)
{


	LED_Init();

	RTO_voidInit();

	/* Global Interrupt enable */

	/* Create tasks */

	RTO_voidCreateTask(0,1000,0,&LED_G_Tog);
	RTO_voidCreateTask(1,2000,1,&LED_Y_Tog);
	RTO_voidCreateTask(2,5000,2,&LED_R_Tog);

/* start scheduler */
	RTO_voidStartScheduler();


	while(1);



	return 0;
}



#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_int.h"
#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_config.h"

#if INTERRUPT_MODE == ENABLE_INTERRUPT

void (*CallBack) (void);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
{
	CallBack = PtrToFunc ;
}

void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{

	CallBack();

}

void SPI_voidSendDataISR(u8 Copy_Data)
{
	SPDR = Copy_Data ;
}

u8 SPI_u8ReadDataISR(void)
{
	return SPDR ;
}

#elif INTERRUPT_MODE == DISABLE_INTERRUPT

u8 SPI_u8Transfer(u8 Copy_Data)
{
	SPDR = Copy_Data ;
	while(GET_BIT(SPSR , SPIF) == 0);

	return SPDR ;
}

#endif

#if MASTER_SLAVE_MODE == MASTER
void SPI_voidMasterInit(void)
{
	SET_BIT(SPCR , SPE);
#if INTERRUPT_MODE == ENABLE_INTERRUPT
	SET_BIT(SPCR , SPIE);
#elif INTERRUPT_MODE == DISABLE_INTERRUPT
	CLEAR_BIT(SPCR , SPIE);
#endif

	SET_BIT(SPCR , MSTR);

#if DATA_ORDER == MSB_FIRST
	CLEAR_BIT(SPCR , DORD);
#elif DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR , DORD);
#endif
#if CLOCK_POLARITY == IDLE_LOW
	CLEAR_BIT(SPCR , CPOL);
#elif CLOCK_POLARITY == IDLE_HIGH
	SET_BIT(SPCR , CPOL);
#endif
#if CLOCK_PHASE == ZERO
	CLEAR_BIT(SPCR , CPHA);
#elif CLOCK_PHASE == ONE
	SET_BIT(SPCR , CPHA);
#endif

#if SPI_FREQUENCY == QUARTER_FREQ
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPSR , SPI2X);
#elif SPI_FREQUENCY == HALF_FREQ
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	SET_BIT(SPSR , SPI2X);

#endif

}

#elif MASTER_SLAVE_MODE == SLAVE

void SPI_voidSlaveInit(void)
{
	SET_BIT(SPCR , SPE);

#if INTERRUPT_MODE == ENABLE_INTERRUPT
	SET_BIT(SPCR , SPIE);
#elif INTERRUPT_MODE == DISABLE_INTERRUPT
	CLEAR_BIT(SPCR , SPIE);
#endif

	CLEAR_BIT(SPCR , MSTR);
#if DATA_ORDER == MSB_FIRST
	CLEAR_BIT(SPCR , DORD);
#elif DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR , DORD);
#endif
#if CLOCK_POLARITY == IDLE_LOW
	CLEAR_BIT(SPCR , CPOL);
#elif CLOCK_POLARITY == IDLE_HIGH
	SET_BIT(SPCR , CPOL);
#endif
#if CLOCK_PHASE == ZERO
	CLEAR_BIT(SPCR , CPHA);
#elif CLOCK_PHASE == ONE
	SET_BIT(SPCR , CPHA);
#endif

#if SPI_FREQUENCY == QUARTER_FREQ
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPSR , SPI2X);
#elif SPI_FREQUENCY == HALF_FREQ
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	SET_BIT(SPSR , SPI2X);

#endif
}


#endif


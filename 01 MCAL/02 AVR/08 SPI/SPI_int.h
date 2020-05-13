

#ifndef SPI_INT_H_
#define SPI_INT_H_

#define DUMMY 0xFF

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_Data);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );

u8 SPI_u8ReadDataISR(void);

void SPI_voidSendDataISR(u8 Copy_Data);


#endif /* SPI_INT_H_ */

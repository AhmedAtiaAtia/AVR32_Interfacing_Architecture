

#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_


void RTO_voidInit(void);

void RTO_voidStartScheduler(void);


void RTO_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity , u16 Copy_u16Firstdelay,void(*Copy_ptrtofun)(void));

#endif /* RTO_INTERFACE_H_ */

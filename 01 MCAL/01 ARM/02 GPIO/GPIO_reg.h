#ifndef	GPIO_REG_H
#define	GPIO_REG_H

typedef struct
{
	volatile u32 CRL 	;
	volatile u32 CRH 	;
	volatile u32 IDR 	;
	volatile u32 ODR 	;
	volatile u32 BSRR 	;
	volatile u32 BRR 	;
	volatile u32 LCKR 	;
	
}GPIO;

#define		MGPIOA		((volatile  GPIO *)0x40010800)

#define		MGPIOB		((volatile  GPIO *)0x40010C00)

#define		MGPIOC		((volatile  GPIO *)0x40011000)

#endif
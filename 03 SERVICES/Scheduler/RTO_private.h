

#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct
{
	/* periodicity*/
	u16 u16Periodicity;
	/* FirstDleay */
	u16 u16FirstDelay;

	/* pointer to function */
	void(*pfun)(void);
}Task_TCB;



static void RTO_voidScheduler(void);

#endif /* RTO_PRIVATE_H_ */

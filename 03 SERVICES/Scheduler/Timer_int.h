
#ifndef TIMER_INT_H_
#define TIMER_INT_H_


#define NORMAL_MODE     1
#define CTC_MODE        5
#define FAST_PWM_MODE   2

#define INDEX_OF_TIMER0_OVERFLOW_INT             0
#define INDEX_OF_TIMER0_COMPARE_MATCH_INT        1
#define INDEX_OF_TIMER1_ICU_INT                  2
#define INDEX_OF_TIMER1_INT_CTC                  3


void Timer_set_callback(void(*ptr)(void));
void Timer1_Init(void);




#endif /* TIMER_INT_H_ */

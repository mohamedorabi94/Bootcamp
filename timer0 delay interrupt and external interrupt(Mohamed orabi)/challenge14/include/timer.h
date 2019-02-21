/*
 * timer.h
 *
 * Created: 2/14/2019 9:08:17 AM
 *  Author: AVE-LAP-025
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include <AVR/interrupt.h>
#include "type.h"

extern uint32 volatile flag;

#define _TCCR0	(0x53)
#define _TCNT0	(0x52)
#define _OCR0	(0x5c)
#define _TIFR	(0x58)

#define _TIMSK  (0x59)
#define _SREG   (0x5f)


#define PIN_0	0
#define PIN_1	1
#define PIN_2	2
#define PIN_3	3
#define PIN_4	4
#define PIN_5	5
#define PIN_6	6
#define PIN_7	7

#define INTERRUPT_EN 1	/*if one enable interrupt pin*/

#define RESET	0
#define SET		1



void timer_init(uint32 prescaller);
void timer_delay(uint32 n);




#endif /* TIMER_H_ */
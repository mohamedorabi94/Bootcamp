/*
 * timer.h
 *
 * Created: 2/14/2019 9:08:17 AM
 *  Author: AVE-LAP-025
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "type.h"

#define _TCCR0	(0x53)
#define _TCNT0	(0x52)
#define _OCR0	(0x5c)
#define _TIFR	(0x58)


#define RESET	0
#define SET		1
void timer_init();
void timer_delay(uint32 n);




#endif /* TIMER_H_ */
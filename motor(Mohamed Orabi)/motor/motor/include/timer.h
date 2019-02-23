/*
 * timer.h
 *
 * Created: 2/14/2019 9:08:17 AM
 *  Author: AVE-LAP-025
 */ 
/*Function Name: timer_init
*parameter:
*	I/P:
*		-prescaller choose the CLK HZ you required
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-initialize timer0 according to your Cristal and if required active interrupt active it from .h
*/


/*Function Name: timer_delay(uint32 n)
*parameter:
*	I/P:
*		-n choose delay you required by ms
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-determine the time you required by mille sec
*/


/*Function Name: Timer1_INIt_PWM
*parameter:
*	I/P:
*		-channel choose you required work MOTOR1(OC1A) or MOTOR2(OC1B)
*		-MODE	choose mode you required in PWM if FAST_PWM or PHASE_CORRECT_PWM
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this func i initialize PWM in timer 1
*/


#ifndef TIMER_H_
#define TIMER_H_
/*#include <AVR/interrupt.h>*/
#include "type.h"
#include "DIO_Serialized.h"
extern uint32 volatile flag;

#define _TCCR0		(0x53)
#define _TCNT0		(0x52)
#define _OCR0		(0x5c)
#define _TIFR		(0x58)

#define _TIMSK		(0x59)
#define _SREG		(0x5f)

#define _TCCR1A		(0x4f)
#define _TCCR1B		(0x4E)
#define _TCNT1H		(0x4D)
#define _TCNT1L		(0x4C)
#define _OCR1AH		(0x4B)
#define _OCR1AL		(0x4A)
#define _OCR1BH		(0x49)
#define _OCR1BL		(0x48)
#define _ICR1H		(0x47)
#define _ICR1L		(0x46)



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


#define PHASE_CORRECT_PWM	0
#define FAST_PWM			1

#define MOTOR2			0
#define MOTOR1			1

#define CLOCK_WISE			0
#define UN_CLOCK_WISE			1


#define TOP_PHASE_CORRECT	0x0640
#define TOP_FAST			0x0C7f


void timer_init(uint32 prescaller);
void timer_delay(uint32 n);

void Timer1_INIt_PWM(uint8 channel,uint8 MODE);


#endif /* TIMER_H_ */
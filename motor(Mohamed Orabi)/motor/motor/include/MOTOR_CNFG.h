/*
 * MOTOR.h
 *
 * Created: 2/23/2019 10:38:11 AM
 *  Author: AVE-LAP-025
 */ 


/*Function Name: SPead direction
*parameter:
*	I/P:
*		-channel choose you required work MOTOR1(OC1A) or MOTOR2(OC1B)
*		-volt	inter the volt you required out on motor
*		-MODE	choose mode you required in PWM if FAST_PWM or PHASE_CORRECT_PWM
*		-direction	direction of rotating of motor	CLOCK_WISE or UN_CLOCK_WISE
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this func i control in motor
*/



#ifndef MOTOR_H_
#define MOTOR_H_
#include "timer.h"

#define PHASE_CORRECT_PWM	0
#define FAST_PWM			1

#define MOTOR2				0
#define MOTOR1				1

#define CLOCK_WISE			0
#define UN_CLOCK_WISE		1


void SPead(uint8 channel,uint8 volt,uint8 MODE,uint8 direction);
#endif /* MOTOR_H_ */
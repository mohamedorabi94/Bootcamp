/*
 * challenge14.c
 *
 * Created: 2/20/2019 6:17:19 PM
 * Author : AVE-LAP-025
 */ 
#include "type.h"
#include "DIO_Serialized.h"
#include "timer.h"
/*#include <AVR/interrupt.h>*/

#define GO		B5		/*LED1 IS SIMULATE GO SIGN*/
#define STOP	B7		/*LED3 IS SIMULATE stop sign*/
#define READY	B6		/*LED2 IS SIMULATE READY SIGN*/
#define  F_CPU 8000000
 uint8 f=0;

ISR(INT2_vect)
{
	flag=ONE_SECOUND_ms;	/*if press on button ONE GO to STOP */
	f=1;
}


int main(void)
{
    timer_init(F_CPU);/*initialize timer with clk 8000000 HZ*/
	init_DIO_INTERRUPT();/*active rising edge interrupt push button*/	
	DIO_SetPinDirection(GO,OUTPUT); /*detect direction of LED OUTPUT*/
	DIO_SetPinDirection(STOP,OUTPUT);
	DIO_SetPinDirection(READY,OUTPUT);
    
	
	while (1) 
    {
				
		if (flag==ONE_SECOUND_ms && f==ZERO)			/*to wait 1 sec and enter the 1st state*/ 
		{
			DIO_WritePin(STOP,RESET);
			DIO_WritePin(READY,RESET);
			DIO_WritePin(GO,SET);
			f=ONE;						/*prepare 2nd state*/
			flag=ZERO;	
		}
		else if (flag==ONE_SECOUND_ms && f==ONE)		/*to wait 1 sec and enter the 2nd state*/
		{
			DIO_WritePin(READY,RESET);
			DIO_WritePin(GO,RESET);
			DIO_WritePin(STOP,SET);
			f=TWO;							/*prepare 3rd state*/
			flag=ZERO;
		}
		else if (flag==ONE_SECOUND_ms && f==TWO)	/*to wait 1 sec and enter the 3rd state*/
		{
			DIO_WritePin(READY,SET);
			DIO_WritePin(GO,RESET);
			DIO_WritePin(STOP,RESET);
			f=ZERO;						/*prepare 1st state*/
			flag=ZERO;
		}
    }
}


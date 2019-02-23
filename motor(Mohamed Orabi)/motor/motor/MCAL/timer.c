/*
 * timer.c
 *
 * Created: 2/14/2019 9:08:44 AM
 *  Author: AVE-LAP-025
 */

#include "timer.h"
uint32 volatile flag=0;
/*Function Name:Write_pin
*parameter:
*	I/P:
*		-reg	is register take from timer 
*		-Pin	select  bit in register
*		-PinValue	the value that required out in pin
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-put output in spicific pin in register
*/

/*Function Name: Write_Register
*parameter:
*	I/P:
*		-reg	is register take from timer
*		-Val	the value of register
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-put output in specific pin in register
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
static void Write_pin(uint8 reg,uint8 pin,uint8 val)/*write to any pin*/
{
	if (val==SET)
	{
		(*((volatile uint8*)(reg)))|=(1<<pin);
	}
	else if (val==RESET)
	{
		(*((volatile uint8*)(reg)))&=~(1<<pin);
	}
}

static void  Write_Register(uint8 reg,uint8 val)/*write to any register*/
{
	if (val==SET)
	{
		(*((volatile uint8*)(reg)))=0xff;
	}
	else if (val==RESET)
	{
		(*((volatile uint8*)(reg)))=0x00;
	}
	else
	{
		(*((volatile uint8*)(reg)))=val;
	}
}
static uint8 Read_pin(uint8 reg,uint8 pin)/*read from any pin*/
{
	uint8 val;
	val=(*((volatile uint8*)(reg))&(1<<pin));
	return val;
}
void timer_init(uint32 prescaller)	/*timer0*/
{
	
	Write_Register(_TCNT0,0); /*put zero in counter register*/
	
	
	Write_pin(_TCCR0,PIN_3,SET); /*mode CTC*/
	Write_pin(_TCCR0,PIN_1,SET);/*64 prescaler*/
	Write_pin(_TCCR0,PIN_0,SET);
	
	if (prescaller==16000000)	
	{
		Write_Register(_OCR0,249);/*put on ocr */
	}
	else if (prescaller==8000000)
	{
		Write_Register(_OCR0,124);
	}
	
	if (INTERRUPT_EN==1)
	{
		Write_pin(_SREG,PIN_7,SET);

		Write_pin(_TIMSK,PIN_1,SET);
		
	}
	
}
void timer_delay(uint32 n) //int time with ms
/*timer0*/
{
	uint32 i=0;
	Write_Register(_TCNT0,0);
	for(i=0;i<n;i++)
	{
		while(!Read_pin(_TIFR,1));/*waiting until flag set*/
		Write_pin(_TIFR,1,SET);/*clear flag*/
	
	}	
}


void Timer1_INIt_PWM(uint8 channel,uint8 MODE)
{
	if(channel==MOTOR2)
	{
		
		
		DIO_SetPinDirection(D5,OUTPUT);/*oc1a*/
		
		if (MODE==PHASE_CORRECT_PWM)
		{
			Write_pin(_TCCR1A,PIN_7,SET);	/*COM1A1=1 non inverting */
			Write_pin(_TCCR1A,PIN_6,RESET);	/*COM1A0=0 */
			
			Write_pin(_TCCR1A,PIN_0,RESET);	/*PHASE CORRECT PWM	WGM10=0*/
			Write_pin(_TCCR1A,PIN_1,SET);	/*PHASE CORRECT PWM	WGM11=1*/
			Write_pin(_TCCR1B,PIN_3,RESET);	/*PHASE CORRECT PWM	WGM12=0*/
			Write_pin(_TCCR1B,PIN_4,SET);	/*PHASE CORRECT PWM	WGM13=1*/
			
			Write_Register(_ICR1H,0x06);	/*max value is 1600*/
			Write_Register(_ICR1L,0x40);	/*max value is 1600*/
			
		}
		else if (MODE==FAST_PWM )
		{
			Write_pin(_TCCR1A,PIN_7,SET);	/*COM1A1=1 non inverting */
			Write_pin(_TCCR1A,PIN_6,RESET);	/*COM1A0=0 */
			
			Write_pin(_TCCR1A,PIN_0,RESET);	/*fast PWM	WGM10=0*/
			Write_pin(_TCCR1A,PIN_1,SET);	/*fast PWM	WGM11=1*/
			Write_pin(_TCCR1B,PIN_3,SET);	/*fast PWM	WGM12=1*/
			Write_pin(_TCCR1B,PIN_4,SET);	/*fast PWM	WGM13=1*/

			Write_Register(_ICR1H,0x0c);	/*max value is 1600*/
			Write_Register(_ICR1L,0x7f);	/*max value is 1600*/
			
		}
		
		//DIO_WritePin(D5,0);
	}
	
	if(channel==MOTOR1)
	{
		
		
		DIO_SetPinDirection(D4,OUTPUT);/*OC1B*/
		
		
		if (MODE==PHASE_CORRECT_PWM)
		{
			Write_pin(_TCCR1A,PIN_5,SET);	/*COM1B1=1 non inverting */
			Write_pin(_TCCR1A,PIN_4,RESET);	/*COM1B0=0 */
			
			Write_pin(_TCCR1A,PIN_0,RESET);	/*PHASE CORRECT PWM	WGM10=0*/
			Write_pin(_TCCR1A,PIN_1,SET);	/*PHASE CORRECT PWM	WGM11=1*/
			Write_pin(_TCCR1B,PIN_3,RESET);	/*PHASE CORRECT PWM	WGM12=0*/
			Write_pin(_TCCR1B,PIN_4,SET);	/*PHASE CORRECT PWM	WGM13=1*/
			
			Write_Register(_ICR1H,0x06);	/*max value is 1600*/
			Write_Register(_ICR1L,0x40);	/*max value is 1600*/
			
		}
		else if (MODE==FAST_PWM )
		{
			
			Write_pin(_TCCR1A,PIN_5,SET);	/*COM1B1=1 non inverting */
			Write_pin(_TCCR1A,PIN_4,RESET);	/*COM1B0=0 */
			
			Write_pin(_TCCR1A,PIN_0,RESET);	/*fast PWM	WGM10=0*/
			Write_pin(_TCCR1A,PIN_1,SET);	/*fast PWM	WGM11=1*/
			Write_pin(_TCCR1B,PIN_3,SET);	/*fast PWM	WGM12=1*/
			Write_pin(_TCCR1B,PIN_4,SET);	/*fast PWM	WGM13=1*/
			
			Write_Register(_ICR1H,0x0C);	/*max value is 3199*/
			Write_Register(_ICR1L,0x7f);	/*max value is 3199*/
			
		}
	}
	
	Write_pin(_TCCR1B,PIN_0,RESET);	/*no prescaller CS10=1*/
	Write_pin(_TCCR1B,PIN_1,SET);	/*no prescaller CS11=0*/
	Write_pin(_TCCR1B,PIN_2,RESET);	/*no prescaller CS12=0*/
	
	Write_Register(_TCNT1H,0x00);
	Write_Register(_TCNT1L,0x00);	
}

/*

ISR(TIMER0_COMP_vect)
{
	flag++;
}*/
/*
 * timer.c
 *
 * Created: 2/14/2019 9:08:44 AM
 *  Author: AVE-LAP-025
 */

#include "timer.h"
uint32 volatile flag=0;

static void Write_pin(uint8 reg,uint8 pin,uint8 val)/*write to any pin*/
{
	if (val==SET)
	{
		*((volatile uint8*)(reg))|=(1<<pin);
	}
	else if (val==RESET)
	{
		*((volatile uint8*)(reg))&=~(1<<pin);
	}
}

static void  Write_Register(uint8 reg,uint8 val)/*write to any register*/
{
	if (val==SET)
	{
		*((volatile uint8*)(reg))=0xff;
	}
	else if (val==RESET)
	{
		*((volatile uint8*)(reg))=0x00;
	}
	else
	{
		*((volatile uint8*)(reg))=val;
	}
}
static uint8 Read_pin(uint8 reg,uint8 pin)/*read from any pin*/
{
	uint8 val;
	val=(*((volatile uint8*)(reg))&(1<<pin));
	return val;
}
void timer_init(uint32 prescaller)
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
{
	uint32 i=0;
	Write_Register(_TCNT0,0);
	for(i=0;i<n;i++)
	{
		while(!Read_pin(_TIFR,1));/*waiting until flag set*/
		Write_pin(_TIFR,1,SET);/*clear flag*/
	
	}	
}

ISR(TIMER0_COMP_vect)
{
	flag++;
}
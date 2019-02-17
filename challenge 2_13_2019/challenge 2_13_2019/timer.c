/*
 * timer.c
 *
 * Created: 2/14/2019 9:08:44 AM
 *  Author: AVE-LAP-025
 */

#include "timer.h"

static void Write_pin(uint8 reg,uint8 pin,uint8 val)
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

static void  Write_Register(uint8 reg,uint8 val)
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
static uint8 Read_pin(uint8 reg,uint8 pin)
{
	uint8 val;
	val=(*((volatile uint8*)(reg))&(1<<pin));
	return val;
}
void timer_init()
{
	
	Write_pin(_TIFR,1,SET);
	Write_Register(_TCNT0,0);
	Write_Register(_OCR0,249);
	
	Write_pin(_TCCR0,3,SET); //mode CTC
	Write_pin(_TCCR0,1,SET);//64 prescaler
	Write_pin(_TCCR0,0,SET);

	
}
void timer_delay(uint32 n) //int time with ms
{
	uint32 i=0;
	Write_Register(_TCNT0,0);
	for(i=0;i<n;i++)
	{
		while(Read_pin(_TIFR,1)==0);
		Write_pin(_TIFR,1,SET);
	
	}	
}
/*
 * DIO_Serialized.c
 *
 * Created: 2/13/2019 3:25:25 PM
 *  Author: AVE-LAP-025
 */ 

#include "DIO_Serialized.h"


/*Function Name:DIO_WritePin
*parameter:
*	I/P:
*		-PinNum		enter the number of pin in data sheet or A0-A7 or B0-B7...
*		-PinValue	the value that required out in pin
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-put output in spicific pin
*/


/*Function Name:DIO_ReadPin
*parameter:
*	I/P:
*		-PinNum		enter the number of pin in data sheet or A0-A7 or B0-B7...
*	O/P:NULL
*	I/O:NULL
*	return: the value of pin
*
*description:
*			-read value from pin
*/





/*Function Name:DIO_SetPinDirection
*parameter:
*	I/P:
*		-PinNum		enter the number of pin in data sheet or A0-A7 or B0-B7...
*		-PinValue	OUTPUT or INPUT
*	O/P:NULL
*	I/O:NULL
*	return: void
*
*description:
*			-determine the direction of bin 
*/


void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if(PinNum>=A0 && PinNum<=A7)
	{
		switch(PinValue)
		{
			case SET:
			*((volatile uint8*)(A+2))|=(1<<PinNum);
			break;
			case RESET:
				*((volatile uint8*)(A+2))&=~(1<<PinNum);
				break;
		}	
	}
	else if(PinNum>=B0 && PinNum<=B7)
	{
	 	switch(PinValue)
		{
			case SET:
				*((volatile uint8*)(B+2))|=(1<<(PinNum%8));
				break;
			case RESET:
				*((volatile uint8*)(B+2))&=~(1<<(PinNum%8));
				break;
		}
	}
	else if(PinNum>=C0 && PinNum<=C7)
	{
		switch(PinValue)
		{
			case SET:
				*((volatile uint8*)(C+2))|=(1<<(PinNum%8));
				break;
			case RESET:
				*((volatile uint8*)(C+2))&=~(1<<(PinNum%8));
				break;
		}
	}
	else if(PinNum>=D0 && PinNum<=D7)
	{
		switch(PinValue)
		{
			case SET:
				*((volatile uint8*)(D+2))|=(1<<(PinNum%8));
				break;
			case RESET:
				*((volatile uint8*)(D+2))&=~(1<<(PinNum%8));
				break;
		}
	}
	
}


uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 val=0;
	
	if(PinNum>=A0 && PinNum<=A7)
	{
		val=(uint8)(*((volatile uint8*)(A))&(1<<PinNum))>>PinNum;
	}
	else if(PinNum>=B0 && PinNum<=B7)
	{
		val=(uint8)(*((volatile uint8*)(B))&(1<<(PinNum%8)))>>(PinNum%8);
	}
	else if(PinNum>=C0 && PinNum<=C7)
	{
		val=(uint8)(*((volatile uint8*)(C))&(1<<(PinNum%8)))>>(PinNum%8);
	}
	else if(PinNum>=D0 && PinNum<=D7)
	{
		val=(uint8)(*((volatile uint8*)(D))&(1<<(PinNum%8)))>>(PinNum%8);
	}
	return val;
}



void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinNum>=A0 && PinNum<=A7)
	{
		switch(PinDirection)
		{
			case OUTPUT:
			*((volatile uint8*)(A+1))|=(1<<PinNum);
			break;
			case INPUT:
			*((volatile uint8*)(A+1))&=~(1<<PinNum);
			break;
		}
	}
	else if(PinNum>=B0 && PinNum<=B7)
	{
		switch(PinDirection)
		{
			case OUTPUT:
			*((volatile uint8*)(B+1))|=(1<<(PinNum%8));
			break;
			case INPUT:
			*((volatile uint8*)(B+1))&=~(1<<(PinNum%8));
			break;
		}
	}
	else if(PinNum>=C0 && PinNum<=C7)
	{
		switch(PinDirection)
		{
			case OUTPUT:
			*((volatile uint8*)(C+1))|=(1<<(PinNum%8));
			break;
			case INPUT:
			*((volatile uint8*)(C+1))&=~(1<<(PinNum%8));
			break;
		}
	}
	else if(PinNum>=D0 && PinNum<=D7)
	{
		switch(PinDirection)
		{
			case OUTPUT:
			*((volatile uint8*)(D+1))|=(1<<(PinNum%8));
			break;
			case INPUT:
			*((volatile uint8*)(D+1))&=~(1<<(PinNum%8));
			break;
		}
	}
	
}


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


void init_DIO_INTERRUPT()
{
	Write_pin(_SREG,7,1);
	DIO_SetPinDirection(B2,INPUT);
	Write_pin(_MCUCSR,6,SET);
	Write_pin(_GICR,5,SET);	
}



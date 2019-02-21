/*
 * DIO_Serialized.c
 *
 * Created: 2/13/2019 3:25:25 PM
 *  Author: AVE-LAP-025
 */ 

#include "DIO_Serialized.h"



void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if(PinNum>=0 && PinNum<=7)
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
	else if(PinNum>=8 && PinNum<=15)
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
	else if(PinNum>=16 && PinNum<=23)
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
	else if(PinNum>=23 && PinNum<=31)
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
	
	if(PinNum>=0 && PinNum<=7)
	{
		val=(uint8)(*((volatile uint8*)(A))&(1<<PinNum))>>PinNum;
	}
	else if(PinNum>=8 && PinNum<=15)
	{
		val=(uint8)(*((volatile uint8*)(B))&(1<<(PinNum%8)))>>(PinNum%8);
	}
	else if(PinNum>=16 && PinNum<=23)
	{
		val=(uint8)(*((volatile uint8*)(C))&(1<<(PinNum%8)))>>(PinNum%8);
	}
	else if(PinNum>=23 && PinNum<=31)
	{
		val=(uint8)(*((volatile uint8*)(D))&(1<<(PinNum%8)))>>(PinNum%8);
	}
	return val;
}



void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinNum>=0 && PinNum<=7)
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
	else if(PinNum>=8 && PinNum<=15)
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
	else if(PinNum>=16 && PinNum<=23)
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
	else if(PinNum>=23 && PinNum<=31)
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


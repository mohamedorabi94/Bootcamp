/*

 * challenge 2_13_2019.c
 *
 * Created: 2/13/2019 10:50:29 AM
 * Author : AVE-LAP-025
 */ 


#include "type.h"
#include "BitwiseOperation.h"
#include "DIO_Serialized.h"
#include "timer.h"

int main(void)
{
	uint8 i=0,f=0;
	timer_init();

	DIO_SetPinDirection(10,INPUT);
	DIO_SetPinDirection(13,OUTPUT);
	DIO_SetPinDirection(14,OUTPUT);
	DIO_SetPinDirection(15,OUTPUT);
	while (1)
	{
		
		f=0;
		DIO_WritePin(13,SET);
		for (i=0;i<20;i++)
		{
			if(DIO_ReadPin(10)==1 && f==0)
			{
				f=1;
				while(DIO_ReadPin(10))
				{
					DIO_WritePin(15,SET);
					DIO_WritePin(13,RESET);
				}
			}
			timer_delay(50);
			if(DIO_ReadPin(10)==0 && f==1)
			{
				DIO_WritePin(13,RESET);
				DIO_WritePin(14,RESET);
				DIO_WritePin(15,SET);
				f=0;
				timer_delay(1000);
				DIO_WritePin(13,SET);
				DIO_WritePin(15,RESET);
			}
			if(DIO_ReadPin(10)==1 && f==1)
			{
				f=0;
				while(DIO_ReadPin(10))
				{
					DIO_WritePin(15,SET);
					DIO_WritePin(13,RESET);
				}
			}
			DIO_WritePin(13,SET);
		}
		f=0;
		DIO_WritePin(13,RESET);
		DIO_WritePin(15,SET);
		for (i=0;i<20;i++)
		{
			if(DIO_ReadPin(10) && f==0)
			{
				f=1;
				while(DIO_ReadPin(10));
			}
			timer_delay(50);
			if(DIO_ReadPin(10)==0 && f==1)
			{
				DIO_WritePin(13,RESET);
				DIO_WritePin(14,RESET);
				DIO_WritePin(15,SET);
				f=0;
				timer_delay(1000);
			}
			if(DIO_ReadPin(10)==1 && f==1)
			{
				f=0;
				while(DIO_ReadPin(10));
			}
		}
		f=0;
		DIO_WritePin(15,RESET);
		DIO_WritePin(14,SET);
		for (i=0;i<20;i++)
		{
			if(DIO_ReadPin(10) && f==0)
			{
				f=1;
				while(DIO_ReadPin(10))
				{
					DIO_WritePin(15,SET);
					DIO_WritePin(14,RESET);
				}
			}
			timer_delay(50);
			if(DIO_ReadPin(10)==0 && f==1)
			{
				DIO_WritePin(13,RESET);
				DIO_WritePin(14,RESET);
				DIO_WritePin(15,SET);
				f=0;
				timer_delay(1000);
				DIO_WritePin(14,SET);
				DIO_WritePin(15,RESET);
			}
			if(DIO_ReadPin(10)==1 && f==1)
			{
				f=0;
				while(DIO_ReadPin(10))
				{
					DIO_WritePin(15,SET);
					DIO_WritePin(14,RESET);
				}
			}
			DIO_WritePin(14,SET);
		}
		DIO_WritePin(14,RESET);		
	}
		
}


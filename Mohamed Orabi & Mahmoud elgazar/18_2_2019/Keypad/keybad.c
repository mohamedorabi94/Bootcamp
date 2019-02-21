/*
 * keybad.c
 *
 * Created: 2/18/2019 4:58:18 PM
 *  Author: AVE-LAP-025
 */ 
#include "keybad.h"
void Keypad_init()
{
	DIO_SetPinDirection(C_0,OUTPUT);/*determine direction of bin*/
	DIO_SetPinDirection(C_1,OUTPUT);
	DIO_SetPinDirection(C_2,OUTPUT);
	
	DIO_SetPinDirection(R_0,INPUT);
	DIO_SetPinDirection(R_1,INPUT);
	DIO_SetPinDirection(R_2,INPUT);
	
	DIO_WritePin(C_0,SET);/*OUTPUT on pin 1*/
	DIO_WritePin(C_1,SET);
	DIO_WritePin(C_2,SET);
	
	DIO_WritePin(R_0,SET);/*pull up*/
	DIO_WritePin(R_1,SET);
	DIO_WritePin(R_2,SET);
}
uint8 Keypad_getPressedKey()
{
	uint8 row[no_row]={R_0,R_1,R_2};
	uint8 col[no_col]={C_0,C_1,C_2};
	uint8 i,j;
	uint8 val =ZERO;
	for(i=0;i<no_col;i++)/*check Rows and column */
	{	
		DIO_WritePin(col[ZERO],SET);/*set all pin*/
		DIO_WritePin(col[ONE],SET);
		DIO_WritePin(col[TWO],SET);
		
		DIO_WritePin(col[i],RESET);/*reset one pin only*/
		
		for (j=0;j<no_row;j++)
		{
			if(!DIO_ReadPin(row[j]))
			{
				
				while(!DIO_ReadPin(row[j]));
				switch(i)
				{
					case ZERO:
						if(j==ZERO){
							val= ONE;
							
						}
						else if (j==ONE)
						{
							val= FOUR;
						}
						else if (j==TWO)
						{
							val= SEVEN;
						}
						break;
					case 1:
						if(j==ZERO){
							val= TWO;
						}
						else if (j==ONE)
						{
							val= FIVE;
						}
						else if (j==TWO)
						{
							val= EIGHT;
						}
						break;
					case 2:
						if(j==ZERO){
							val= THREE;
						}
						else if (j==ONE)
						{
							val= SIX;
						}
						else if (j==TWO)
						{
							val= NINE;
						}
						break;
				}
			}
		}
	}
	return val;
	
}
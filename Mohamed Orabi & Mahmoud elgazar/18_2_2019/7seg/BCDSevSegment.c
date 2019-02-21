/*
 * _7seg.c
 *
 * Created: 2/18/2019 11:42:40 AM
 *  Author: AVE-LAP-025
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "BCDSevSegment.h"

void BCDSevegments_init(){
	timer_init();
	DIO_SetPinDirection(P0,OUTPUT);
	DIO_SetPinDirection(P1,OUTPUT);
	DIO_SetPinDirection(P2,OUTPUT);
	DIO_SetPinDirection(P3,OUTPUT);

	switch(NO_work_seg)
	{
		case 1:
			DIO_SetPinDirection(SEG_EN1,OUTPUT);
			break;
		case 2:
			DIO_SetPinDirection(SEG_EN1,OUTPUT);
			DIO_SetPinDirection(SEG_EN2,OUTPUT);
			break;
		case 3:
			DIO_SetPinDirection(SEG_EN1,OUTPUT);
			DIO_SetPinDirection(SEG_EN2,OUTPUT);
			DIO_SetPinDirection(SEG_EN3,OUTPUT);
			break;
		case 4:
			DIO_SetPinDirection(SEG_EN1,OUTPUT);
			DIO_SetPinDirection(SEG_EN2,OUTPUT);
			DIO_SetPinDirection(SEG_EN3,OUTPUT);
			DIO_SetPinDirection(SEG_EN4,OUTPUT);
			break;
	}
	

}


void BCDSevegments_enable (uint8 no_seg)
{
			
	DIO_WritePin(no_seg,SET);
}
void BCDSevegments_disable(uint8 no_seg)
{
	DIO_WritePin(no_seg,RESET);
}


void BCDSevegments_displayNo(uint16 num1)
{

	
	uint16 disp_num=num1,num,i,x[4]={0,0,0,0};
	for (i=0;i<10;i++)
	{
		num=num1;
	
		BCDSevegments_enable (SEG_EN1);
		BCDSevegments_disable(SEG_EN2);
		BCDSevegments_disable(SEG_EN3);
		BCDSevegments_disable(SEG_EN4);
		disp_num=num%10;
		num=num/10;
		x[0]=disp_num & 0b00000001;
		x[1]=(char)((disp_num & 0b00000010)>>1);
		x[2]=(char)((disp_num & 0b00000100)>>2);
		x[3]=(char)((disp_num & 0b00001000)>>3);
		DIO_WritePin(P0,x[0]);//((char)(disp_num	& 1)));
		DIO_WritePin(P1,x[1]);//((char)(disp_num	& 2)>>1));
		DIO_WritePin(P2,x[2]);//((char)(disp_num	& 4)>>2));
		DIO_WritePin(P3,x[3]);//((char)(disp_num	& 8)>>3));
		timer_delay(1);
		
		/*
		BCDSevegments_enable (SEG_EN2);
		BCDSevegments_disable(SEG_EN1);
		BCDSevegments_disable(SEG_EN3);
		BCDSevegments_disable(SEG_EN4);
		disp_num=num%10;
		num=num/10;
		x[0]=disp_num & 0b00000001;
		x[1]=(char)((disp_num & 0b00000010)>>1);
		x[2]=(char)((disp_num & 0b00000100)>>2);
		x[3]=(char)((disp_num & 0b00001000)>>3);
		DIO_WritePin(P0,x[0]);
		DIO_WritePin(P1,x[1]);
		DIO_WritePin(P2,x[2]);
		DIO_WritePin(P3,x[3]);
		timer_delay(1);
		
		BCDSevegments_enable (SEG_EN3);
		BCDSevegments_disable(SEG_EN1);
		BCDSevegments_disable(SEG_EN2);
		BCDSevegments_disable(SEG_EN4);
		disp_num=num%10;
		num=num/10;
		x[0]=disp_num & 0b00000001;
		x[1]=(char)((disp_num & 0b00000010)>>1);
		x[2]=(char)((disp_num & 0b00000100)>>2);
		x[3]=(char)((disp_num & 0b00001000)>>3);
		DIO_WritePin(P0,x[0]);
		DIO_WritePin(P1,x[1]);
		DIO_WritePin(P2,x[2]);
		DIO_WritePin(P3,x[3]);
		timer_delay(1);

		BCDSevegments_enable (SEG_EN4);
		BCDSevegments_disable(SEG_EN1);
		BCDSevegments_disable(SEG_EN2);
		BCDSevegments_disable(SEG_EN3);
		disp_num=num%10;
		num=num/10;
		x[0]=disp_num & 0b00000001;
		x[1]=(char)((disp_num & 0b00000010)>>1);
		x[2]=(char)((disp_num & 0b00000100)>>2);
		x[3]=(char)((disp_num & 0b00001000)>>3);
		DIO_WritePin(P0,x[0]);
		DIO_WritePin(P1,x[1]);
		DIO_WritePin(P2,x[2]);
		DIO_WritePin(P3,x[3]);
		timer_delay(1);*/
	}
	
}
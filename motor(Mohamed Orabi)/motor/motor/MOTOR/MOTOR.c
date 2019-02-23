/*
 * MOTOR.c
 *
 * Created: 2/23/2019 10:37:24 AM
 *  Author: AVE-LAP-025
 */ 
#include "MOTOR_CNFG.h"

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




void SPead(uint8 channel,uint8 volt,uint8 MODE,uint8 direction)
{
	uint32 OCR_VAl;
	
	if(channel==MOTOR2)
	{
		DIO_SetPinDirection(D7,OUTPUT);/*DIR1*/
		DIO_SetPinDirection(D6,OUTPUT);/*DIR2*/
		if (MODE==PHASE_CORRECT_PWM)
		{
			OCR_VAl=(1600*volt)/5;
			Write_Register(_OCR1AH,((uint8)((OCR_VAl & 0xff00)>>8)));
			Write_Register(_OCR1AL,((uint8)(OCR_VAl & 0x00ff)));
		}
		else if (MODE==FAST_PWM )
		{
			OCR_VAl=(3200*volt)/5;
			Write_Register(_OCR1AH,((uint8)((OCR_VAl & 0xff00)>>8)));
			Write_Register(_OCR1AL,((uint8)(OCR_VAl & 0x00ff)));
		}
		if(direction==CLOCK_WISE)
		{
			DIO_WritePin(D6,SET);
			DIO_WritePin(D7,RESET);
		}
		else if(direction==UN_CLOCK_WISE)
		{
			DIO_WritePin(D6,RESET);
			DIO_WritePin(D7,SET);
		}
	}
	else if(channel==MOTOR1)
	{
		DIO_SetPinDirection(D2,OUTPUT);/*DIR1*/
		DIO_SetPinDirection(D3,OUTPUT);/*DIR2*/
		if (MODE==PHASE_CORRECT_PWM)
		{
			OCR_VAl=(1600*volt)/5;
			Write_Register(_OCR1BH,((char)((OCR_VAl & 0xff00)>>8)));
			Write_Register(_OCR1BL,((char)(OCR_VAl & 0x00ff)));
		}
		else if (MODE==FAST_PWM )
		{
			OCR_VAl=(3200*volt)/5;
			Write_Register(_OCR1BH,((char)((OCR_VAl & 0xff00)>>8)));
			Write_Register(_OCR1BL,((char)(OCR_VAl & 0x00ff)));
		}
		if(direction==CLOCK_WISE)
		{
			DIO_WritePin(D2,SET);
			DIO_WritePin(D3,RESET);
		}
		else if(direction==UN_CLOCK_WISE)
		{
			DIO_WritePin(D2,RESET);
			DIO_WritePin(D3,SET);
		}
	}
	
}
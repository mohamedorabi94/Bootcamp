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
#include "BCDSevSegment.h"
#include "keybad.h"
#include "LCD.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	LCD_init(FOUR_BIT_MODE);/* initialize the LCD*/
	Keypad_init();			/*KEYPAD initialize*/
	uint8 i=ZERO,count =ZERO;
	for (i=ZERO;i<FOUR;i++)/*Blinking welcome word on LCD*/
	{
		LCD_displayStringRowColumn(FOUR_BIT_MODE,"***WELCOME***",LCD_CMD_1ST_LINE,1);
		_delay_ms(ONE_SECOUND_ms);
		LCD_clear(FOUR_BIT_MODE);
		_delay_ms(ONE_SECOUND_ms);
	}
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"lets start !",LCD_CMD_1ST_LINE,2);/*print lets start ! word on LCD*/
	_delay_ms(2*ONE_SECOUND_ms);
	
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"Your score will",LCD_CMD_1ST_LINE,1);/*thats notes to the reader*/
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"appear on 7 seg",LCD_CMD_2ND_LINE,1);	
	_delay_ms(2*ONE_SECOUND_ms);
	BCDSevegments_init();						/*initialize seven segment*/
	BCDSevegments_displayNo(ZERO);					/*print on seven segment zero*/
	
	LCD_clear(FOUR_BIT_MODE);					/*clear LCD*/
	
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"num of country  ",LCD_CMD_1ST_LINE,ZERO);/*1st question*/
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"in Europe is 44?",LCD_CMD_2ND_LINE,ZERO);
	while(1)
	{
		if(Keypad_getPressedKey()==ONE)/*print happy face*/
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_happy(FOUR_BIT_MODE);
			count++;									/*increase result*/
			BCDSevegments_displayNo(count);
			break;
		
		}
		else if(Keypad_getPressedKey()==TWO)/*print sad face*/
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_SAD(FOUR_BIT_MODE);
			break;
		}	
	}
	
	_delay_ms(3*ONE_SECOUND_ms);
	
	LCD_clear(FOUR_BIT_MODE);										/*clear LCD*/
	
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"The Capital of",LCD_CMD_1ST_LINE,0);/*2nd question*/
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"Estonia is SAKU?",LCD_CMD_2ND_LINE,0);
	while(1)
	{
		if(Keypad_getPressedKey()==TWO)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_happy(FOUR_BIT_MODE);
			count++;											/*increase result*/
			BCDSevegments_displayNo(count);
			break;
			
		}
		else if(Keypad_getPressedKey()==ONE)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_SAD(FOUR_BIT_MODE);
			break 
		}
	}
	
	
	_delay_ms(3*ONE_SECOUND_ms);
	
	LCD_clear(FOUR_BIT_MODE);									/*clear LCD*/
	
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"Area of Egypt is",LCD_CMD_1ST_LINE,0);/*3rd question*/
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"1.02million KM2?",LCD_CMD_2ND_LINE,0);
	while(1)
	{
		if(Keypad_getPressedKey()==TWO)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_happy(FOUR_BIT_MODE);
			count++;										/*increase result*/
			BCDSevegments_displayNo(count);
			break;
			
		}
		else if(Keypad_getPressedKey()==ONE)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_SAD(FOUR_BIT_MODE);
			break;
		}
	}
	
	_delay_ms(3*ONE_SECOUND_ms);
	
	LCD_clear(FOUR_BIT_MODE);										/*clear LCD*/
	
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"The Suez channel",LCD_CMD_1ST_LINE,0);/*4th question*/
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"opened in 1869?",LCD_CMD_2ND_LINE,0);
	while(1)
	{
		if(Keypad_getPressedKey()==ONE)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_happy(FOUR_BIT_MODE);
			count++;											/*increase result*/
			BCDSevegments_displayNo(count);
			break;
			
		}
		else if(Keypad_getPressedKey()==TWO)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_SAD(FOUR_BIT_MODE);
			break;
		}
	}
	
	_delay_ms(3*ONE_SECOUND_ms);
	
	LCD_clear(FOUR_BIT_MODE);										/*clear LCD*/
	
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"The Num of German",LCD_CMD_1ST_LINE,0);/*5th question*/
	LCD_displayStringRowColumn(FOUR_BIT_MODE,"letters is 29?",LCD_CMD_2ND_LINE,0);
	while(1)
	{
		if(Keypad_getPressedKey()==TWO)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_happy(FOUR_BIT_MODE);
			count++;											/*increase result*/
			BCDSevegments_displayNo(count);
			break;
			
		}
		else if(Keypad_getPressedKey()==ONE)
		{
			LCD_clear(FOUR_BIT_MODE);
			DISP_SAD(FOUR_BIT_MODE);
			break;
		}
	}
	
	
	_delay_ms(3*ONE_SECOUND_ms);
	
	LCD_clear(FOUR_BIT_MODE);							/*clear LCD*/
	
	if (count==FIVE)
	{
		LCD_displayStringRowColumn(FOUR_BIT_MODE,"WOW ",LCD_CMD_1ST_LINE,6);
		LCD_displayStringRowColumn(FOUR_BIT_MODE,"you are genius",LCD_CMD_2ND_LINE,0);
	}
	else if (count>=THREE)
	{
		LCD_displayStringRowColumn(FOUR_BIT_MODE,"YOU PASSED",LCD_CMD_1ST_LINE,2);
	}
	
	else if (count<THREE)
	{
		LCD_displayStringRowColumn(FOUR_BIT_MODE,"YOU FAILED",LCD_CMD_1ST_LINE,2);
	}
	while (1)
	{
		;
	}
}

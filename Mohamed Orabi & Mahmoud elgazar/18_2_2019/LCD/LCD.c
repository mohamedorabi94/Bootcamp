/*
 * LCD.c
 *
 * Created: 2/19/2019 11:40:02 AM
 *  Author: AVE-LAP-025
 */ 
#include "LCD.h"

/*Function Name:LCD_init
*parameter:
*	I/P:	
*		-mode	mode you use choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function only determine direction of pins and initialize the mode 
*/

/*Function Name:LCD_sendCommand
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*		-command enter the command you required 
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function only enter the command to made some thing in lcd
*/

/*Function Name:LCD_displayChar
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*		-Data enter the data you required to disp on seven segmant
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function only enter the data that appear on  LCD
*/

/*Function Name:LCD_gotoRowColumn
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*		-row	if want to write in first line inter "LCD_CMD_1ST_LINE" if second line inter "LCD_CMD_2ND_LINE"
		-column	inter from ZERO to FIFteen
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function only enter the string that appear on  LCD
*/

/*Function Name:LCD_displayStringRowColumn
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*		-str	string that want to appear on LCD
*		-Row	if want to write in first line inter "LCD_CMD_1ST_LINE" if second line inter "LCD_CMD_2ND_LINE"
*		-column	inter from ZERO to FIFteen
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function only enter the string that appear on  LCD on specific position
*/

/*Function Name:LCD_clear
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function clear LCD
*/


/*Function Name:DRow_Custom_char
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*		-str	is the array that output from LED MATRIX studio
*		-num_of_char that allowed only save 8 character so you should enter ZERO-SEVEN 
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function save strange char in CGROM
*/

/*Function Name:Disp_Custom_char  
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*		-Row	if want to write in first line inter "LCD_CMD_1ST_LINE" if second line inter "LCD_CMD_2ND_LINE"
*		-column	inter from ZERO to FIFteen 
*		-num_of_char that allowed only save 8 character so you should enter ZERO-SEVEN as you saved 
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-in this function print strange char in CGROM in LCD
*/

/*Function Name:HAPPY
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-save shape of smile on CGRAM
*/

/*Function Name:DISP_happy
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-print saves shape of smile on LCD
*/

/*Function Name:SAD
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-save shape of sad on CGRAM
*/

/*Function Name:DISP_SAD
*parameter:
*	I/P:
*		-mode	mode you choose one of FOUR_BIT_MODE or EIGHT_BIT_MODE
*	O/P:NULL
*	I/O:NULL
*	return:void
*
*description:
*			-print saves shape of SAD on LCD
*/



void LCD_init(uint8 mode)
{
	
	DIO_SetPinDirection(LCD_RS,OUTPUT);/*detect direction of control pin*/
	DIO_SetPinDirection(LCD_RW,OUTPUT);
	DIO_SetPinDirection(LCD_E,OUTPUT);
	
	if(mode==EIGHT_BIT_MODE)/*detect direction of data bit*/
	{
		/*//define direction of 1st 4 bit*/
	}
	DIO_SetPinDirection(LCD_DATA_PIN4,OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PIN5,OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PIN6,OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PIN7,OUTPUT);

	
	
	DIO_WritePin(LCD_E,RESET);
	
	LCD_sendCommand(mode,LCD_CMD_CLR);					/*initialization of LCD */
	LCD_sendCommand(mode,LCD_CMD_DISP_ON_CURSOR_BLINK);
	if(mode==EIGHT_BIT_MODE)
	{
		/*define direction of 1st 4 bit*/
	}
	else if (mode==FOUR_BIT_MODE)
	{
		LCD_sendCommand(mode,LCD_CMD_INIT1_4_BIT);
		LCD_sendCommand(mode,LCD_CMD_INIT2_4_BIT);
		LCD_sendCommand(mode,LCD_CMD_4_BIT_MODE);
	}
	LCD_sendCommand(mode,LCD_CMD_INCREMNT_CURSER);
}
void LCD_sendCommand(uint8 mode,uint8 command)
{
	DIO_WritePin(LCD_RS,RESET);/*detect command mode*/
	DIO_WritePin(LCD_RW,RESET);/*write command*/
	if (mode==EIGHT_BIT_MODE)
	{
		//write in all port directly
	}
	else if(mode==FOUR_BIT_MODE)
	{
																		/*send 4 high nibble pin*/
		DIO_WritePin(LCD_DATA_PIN4,(char)((command & SET_4)>>SHIFT_4));
		DIO_WritePin(LCD_DATA_PIN5,(char)((command & SET_5)>>SHIFT_5));
		DIO_WritePin(LCD_DATA_PIN6,(char)((command & SET_6)>>SHIFT_6));
		DIO_WritePin(LCD_DATA_PIN7,(char)((command & SET_7)>>SHIFT_7));
		
		DIO_WritePin(LCD_E,SET);	/*send latch*/
		_delay_ms(2*ONE_MILE_SECOUND_ms);
		DIO_WritePin(LCD_E,RESET);
		_delay_us(100*ONE_MICRO_SECOUND);
		
		command=(char)((command&0x0f)<<SHIFT_4);	/*send 4 low nibble pin*/
		
		DIO_WritePin(LCD_DATA_PIN4,(char)((command & SET_4)>>SHIFT_4));
		DIO_WritePin(LCD_DATA_PIN5,(char)((command & SET_5)>>SHIFT_5));
		DIO_WritePin(LCD_DATA_PIN6,(char)((command & SET_6)>>SHIFT_6));
		DIO_WritePin(LCD_DATA_PIN7,(char)((command & SET_7)>>SHIFT_7));
		
	}
	DIO_WritePin(LCD_E,SET);		/*send latch*/
	_delay_ms(2*ONE_MILE_SECOUND_ms);
	DIO_WritePin(LCD_E,RESET);
	_delay_us(100*ONE_MICRO_SECOUND);
}
void LCD_displayChar(uint8 mode,uint8 Data)
{
	DIO_WritePin(LCD_RS,SET);/*data mode*/
	DIO_WritePin(LCD_RW,RESET);/*write only*/
	if (mode==EIGHT_BIT_MODE)
	{
		/*write in all port directly*/
	}
	else if(mode==FOUR_BIT_MODE)/*send 4 high nibble bit*/
	{
		DIO_WritePin(LCD_DATA_PIN4,(char)((Data & SET_4)>>SHIFT_4));
		DIO_WritePin(LCD_DATA_PIN5,(char)((Data & SET_5)>>SHIFT_5));
		DIO_WritePin(LCD_DATA_PIN6,(char)((Data & SET_6)>>SHIFT_6));
		DIO_WritePin(LCD_DATA_PIN7,(char)((Data & SET_7)>>SHIFT_7));
		
		DIO_WritePin(LCD_E,SET);
		_delay_ms(2*ONE_MILE_SECOUND_ms);
		DIO_WritePin(LCD_E,RESET);
	
		
		Data=(char)((Data&0x0f)<<SHIFT_4);
																	/*send low nibble bit*/										
		DIO_WritePin(LCD_DATA_PIN4,(char)((Data & SET_4)>>SHIFT_4));
		DIO_WritePin(LCD_DATA_PIN5,(char)((Data & SET_5)>>SHIFT_5));
		DIO_WritePin(LCD_DATA_PIN6,(char)((Data & SET_6)>>SHIFT_6));
		DIO_WritePin(LCD_DATA_PIN7,(char)((Data & SET_7)>>SHIFT_7));
		
	}
	DIO_WritePin(LCD_E,SET); /*latch*/
	_delay_ms(2*ONE_MILE_SECOUND_ms);
	DIO_WritePin(LCD_E,RESET);
	_delay_us(100*ONE_MICRO_SECOUND);
}
void LCD_displayString(uint8 mode,uint8 str[])
{
	while (*str!=0)		/*send string until find NULL*/
	{	
		LCD_displayChar(mode,*str);
		str++;
	}
	
}
void LCD_gotoRowColumn(uint8 mode,uint8 Row,uint8 Column)/*row=LCD_CMD_1ST_LINE or LCD_CMD_2ND_LINE*/
{
	
	LCD_sendCommand(mode,Row+Column);
	
}
void LCD_displayStringRowColumn(uint8 mode,uint8 *str,uint8 Row,uint8 Column)/*row=LCD_CMD_1ST_LINE or LCD_CMD_2ND_LINE*/
{
	LCD_gotoRowColumn(mode,Row,Column);
	LCD_displayString(mode,str);
}
void LCD_clear(uint8 mode)
{
	LCD_sendCommand(mode,LCD_CMD_CLR);
}

void DRow_Custom_char(uint8 mode,uint8 * str,uint8 num_of_char)
{
	uint8 i;
	LCD_sendCommand(mode,(LCD_CMD_CGRAM_ADDRESS+EIGHT*num_of_char));
	for (i=0;i<8;i++)
	{
		LCD_displayChar(mode,str[i]);
	}
}
void Disp_Custom_char(uint8 mode,uint8 Row,uint8 Column,uint8 num_of_char)
{
	LCD_gotoRowColumn(mode,Row,Column);
	LCD_displayChar(mode,num_of_char);
}

void HAPPY(uint8 mode)
{
	const uint8 Emotion0[8]={3,4,8,16,17,18,16,16};
	const uint8 Emotion1[8]={31,0,0,0,0,16,0,0};
	const uint8 Emotion2[8]={31,0,0,0,0,1,0,0};
	const uint8 Emotion3[8]={24,4,2,1,17,9,1,1};
	const uint8 Emotion4[8]={16,16,16,16,16,8,4,3};
	const uint8 Emotion5[8]={0,0,8,4,3,0,0,31};
	const uint8 Emotion6[8]={0,0,0,2,4,24,0,31};
	const uint8 Emotion7[8]={1,1,1,1,1,2,4,24};
	DRow_Custom_char(mode,Emotion0,ZERO);
	DRow_Custom_char(mode,Emotion1,ONE);
	DRow_Custom_char(mode,Emotion2,TWO);
	DRow_Custom_char(mode,Emotion3,THREE);
	DRow_Custom_char(mode,Emotion4,FOUR);
	DRow_Custom_char(mode,Emotion5,FIVE);
	DRow_Custom_char(mode,Emotion6,SIX);
	DRow_Custom_char(mode,Emotion7,SEVEN);
}
void DISP_happy(uint8 mode)
{
	HAPPY(mode);
	_delay_ms(5);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,SIX,ZERO);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,SEVEN,ONE);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,EIGHT,TWO);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,NINE,THREE);
	
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,SIX,FOUR);
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,SEVEN,FIVE);
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,EIGHT,SIX);
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,NINE,SEVEN);
}


void SAD(uint8 mode)
{
	const uint8 Emotion0[EIGHT]={3,4,8,16,17,18,16,16};
	const uint8 Emotion1[EIGHT]={31,0,0,0,0,16,0,0};
	const uint8 Emotion2[EIGHT]={31,0,0,0,0,1,0,0};
	const uint8 Emotion3[EIGHT]={24,4,2,1,17,9,1,1};
	const uint8 Emotion4[EIGHT]={16,16,16,16,16,8,4,3};
	const uint8 Emotion5[EIGHT]={0,0,1,2,4,0,0,31};
	const uint8 Emotion6[EIGHT]={0,0,16,8,4,0,0,31};
	const uint8 Emotion7[EIGHT]={1,1,1,1,1,2,4,24};
	DRow_Custom_char(mode,Emotion0,ZERO);
	DRow_Custom_char(mode,Emotion1,ONE);
	DRow_Custom_char(mode,Emotion2,TWO);
	DRow_Custom_char(mode,Emotion3,THREE);
	DRow_Custom_char(mode,Emotion4,FOUR);
	DRow_Custom_char(mode,Emotion5,FIVE);
	DRow_Custom_char(mode,Emotion6,SIX);
	DRow_Custom_char(mode,Emotion7,SEVEN);
}
void DISP_SAD(uint8 mode)
{
	SAD(mode);
	_delay_ms(5*ONE_MILE_SECOUND_ms);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,SIX,ZERO);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,SEVEN,ONE);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,EIGHT,TWO);
	Disp_Custom_char(mode,LCD_CMD_1ST_LINE,NINE,THREE);
	
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,SIX,FOUR);
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,SEVEN,FIVE);
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,EIGHT,SIX);
	Disp_Custom_char(mode,LCD_CMD_2ND_LINE,NINE,SEVEN);
}
/*/////////////////////////////////////////////////TEST CASES//////////////////////////////////////*/

	void test_print_char()
	{
		LCD_displayChar(FOUR_BIT_MODE,'M');
	}
	void test_print_string()
	{
		LCD_displayString(FOUR_BIT_MODE,"mohamed orabi");
	}
	void test_go_to_string()
	{
		LCD_displayStringRowColumn(FOUR_BIT_MODE,"mohamed orabi",LCD_CMD_2ND_LINE,TWO);
	}
	
	void test_clear()
	{
		LCD_clear(FOUR_BIT_MODE);
	}
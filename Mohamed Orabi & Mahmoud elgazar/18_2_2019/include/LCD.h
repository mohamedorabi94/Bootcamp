/*
 * LCD.h
 *
 * Created: 2/19/2019 11:38:17 AM
 *  Author: AVE-LAP-025
 */ 
#ifndef LCD_H_
#define LCD_H_
#include "DIO_Serialized.h"
#include "type.h"
#ifndef F_CPU
#define F_CPU	8000000UL
#endif
#include <util/delay.h>
#include "LCD_config.h"




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




/*command*/ 
#define LCD_CMD_CLR						0x01
#define LCD_CMD_DISP_ON_CURSOR_BLINK	0x0E
#define LCD_CMD_8_BIT_MODE				0x38
#define	LCD_CMD_4_BIT_MODE				0x28
#define LCD_CMD_INIT1_4_BIT				0x33
#define LCD_CMD_INIT2_4_BIT				0x32
#define LCD_CMD_1ST_LINE				0x80
#define LCD_CMD_2ND_LINE				0xC0
#define LCD_CMD_INCREMNT_CURSER			0x06
#define LCD_CMD_CGRAM_ADDRESS			0x40



#define SHIFT_4							4
#define SHIFT_5							5
#define SHIFT_6							6
#define SHIFT_7							7


#define SET_0							0b00000001
#define SET_1							0b00000010
#define SET_2							0b00000100
#define SET_3							0b00001000
#define SET_4							0b00010000
#define SET_5							0b00100000
#define SET_6							0b01000000
#define SET_7							0b10000000

#define ZERO							0
#define ONE								1
#define TWO								2
#define THREE							3
#define FOUR							4
#define FIVE							5
#define SIX								6
#define SEVEN							7
#define EIGHT							8
#define NINE							9
#define TEN								10
#define ELEVEN							11
#define TWELVE							12
#define THIRTEEN						13
#define FOURTEEN						14
#define FIFTEEN							15
#define SIXTEEN							16

void LCD_init(uint8 mode);
void LCD_sendCommand(uint8 mode,uint8 command);
void LCD_displayChar(uint8 mode,uint8 Data);
void LCD_displayString(uint8 mode,uint8 str[]);
void LCD_displayStringRowColumn(uint8 mode,uint8 *str,uint8 Row,uint8 Column);/*row=LCD_CMD_1ST_LINE or LCD_CMD_2ND_LINE*/
void LCD_gotoRowColumn(uint8 mode,uint8 Row,uint8 Column);/*row=LCD_CMD_1ST_LINE or LCD_CMD_2ND_LINE*/
void LCD_clear(uint8 mode);
void DRow_Custom_char(uint8 mode,uint8 * str,uint8 num_of_char);
void Disp_Custom_char(uint8 mode,uint8 Row,uint8 Column,uint8 num_of_char);
void HAPPY(uint8 mode);
void DISP_happy(uint8 mode);

void SAD(uint8 mode);
void DISP_SAD(uint8 mode);

/*/////////////////////////////////////////////////TEST CASES//////////////////////////////////////*/



void test_print_char();
void test_print_string();
void test_go_to_string();
void test_clear();


#endif /* LCD_H_ */
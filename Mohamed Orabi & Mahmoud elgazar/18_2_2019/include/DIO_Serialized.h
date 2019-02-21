/*
 * DIO_Serialized.h
 *
 * Created: 2/13/2019 3:25:39 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef DIO_SERIALIZED_H_
#define DIO_SERIALIZED_H_
#include"type.h"

#define A 0x39 //PINA ,DDRA+=1,PORTA+=2
#define B 0x36 //PINB ,DDRB+=1,PORTB+=2
#define C 0x33 //PINC ,DDRC+=1,PORTC+=2
#define D 0x30 //PIND ,DDRD+=1,PORTD+=2

#define OUTPUT 1
#define INPUT  0

#define SET	   1
#define RESET  0

#define A0	0
#define A1	1
#define A2	2
#define A3	3
#define A4	4
#define A5	5
#define A6	6
#define A7	7	

#define B0	8
#define B1	9
#define B2	10
#define B3	11
#define B4	12
#define B5	13
#define B6	14
#define B7	15

#define C0	16
#define C1	17
#define C2	18
#define C3	19
#define C4	20
#define C5	21
#define C6	22
#define C7	23

#define D0	24
#define D1	25
#define D2	26
#define D3	27
#define D4	28
#define D5	29
#define D6	30
#define D7	31

#define ONE_SECOUND_ms 1000			/*	by ms */
#define ONE_SECOUND_us 1000000		/* by Us	*/

#define ONE_MILE_SECOUND_ms 1			/* by ms */
#define ONE_MILE_SECOUND_us 1000		/* by Us */



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



#define ONE_MICRO_SECOUND	1
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);



#endif /* DIO_SERIALIZED_H_ */
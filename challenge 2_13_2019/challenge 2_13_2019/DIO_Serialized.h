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



void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);



#endif /* DIO_SERIALIZED_H_ */
/*
 * challenge14.c
 *
 * Created: 2/20/2019 6:17:19 PM
 * Author : AVE-LAP-025
 */ 
#include "type.h"
#include "DIO_Serialized.h"
#include "timer.h"
#include "MOTOR_CNFG.h"
#include <AVR/io.h>

int main(void)
{
    Timer1_INIt_PWM(MOTOR2,PHASE_CORRECT_PWM);
    SPead(MOTOR2,5,PHASE_CORRECT_PWM,UN_CLOCK_WISE);
	while (1) 
    {
		;
	}
}


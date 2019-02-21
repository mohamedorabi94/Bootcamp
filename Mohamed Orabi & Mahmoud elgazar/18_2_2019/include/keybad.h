/*
 * keybad.h
 *
 * Created: 2/18/2019 4:58:04 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_
#include "type.h"
#include "keypad_config.h"
#include "timer.h"


void Keypad_init();
uint8 Keypad_getPressedKey();

#endif /* KEYBAD_H_ */
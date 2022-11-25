/*
 * button.h
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

void getKeyInput();
unsigned char is_button_pressed(unsigned char button_number);
unsigned char is_button_pressed_1s(unsigned char button_number);


#endif /* INC_BUTTON_H_ */

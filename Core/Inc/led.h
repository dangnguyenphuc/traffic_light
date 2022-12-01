/*
 * led.h
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

/*	setRed using to turn on RED LED of traffic light 1 or 2 depend on index.
 * index = 0 or index = 1
 * if index = 0 then turn on RED LED and turn off all LEDs of traffic light 1
 *
 * if index = 1 then turn on RED LED and turn off all LEDs of traffic light 2
 */
void setRed(int index);


/*
 * Same as setRed but turn Yellow on
 */
void setYellow(int index);

/*
 * Same as setRed but turn Yellow on
 */
void setGreen(int index);


/*
 * set Pedestrian light on or off depend on value:
 * 		if value == 0 then off otherwise on.
 */
void setPedestrian(int value);

void clearLED(int index);

#endif /* INC_LED_H_ */

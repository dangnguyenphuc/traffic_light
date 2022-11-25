/*
 * global.h
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "scheduler.h"
#include "button.h"
#include "software_timer.h"
#include "led.h"


extern int status;

// define all status of automatic FSM:
#define AUTO_INIT		0
#define AUTO_RED		1
#define AUTO_YELLOW 	2
#define AUTO_GREEN		3

#endif /* INC_GLOBAL_H_ */

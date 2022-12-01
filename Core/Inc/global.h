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
#define AUTO_INIT		255

#define AUTO_GREEN1		1
#define AUTO_YELLOW1 	2

#define AUTO_GREEN2		11
#define AUTO_YELLOW2 	12

// states of MANUAL FSM:
#define MAN_RED			21
#define MAN_GREEN		22
#define MAN_YELLOW		23

// states of TUNING FSM
#define TUNING_RED			31
#define TUNING_GREEN		32
#define TUNING_YELLOW		33

// TIME of LIGHTs TIMER VALUE:
#define RED_TIME		20
#define GREEN_TIME		15
#define YELLOW_TIME		5

#define MANUAL_TIME		10
#define TUNING_TIME		10


extern int red_time;
extern int yellow_time;
extern int green_time;

#endif /* INC_GLOBAL_H_ */

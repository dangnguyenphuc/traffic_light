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
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_pedestrian.h"
#include "fsm_tuning.h"
#include "perihersal.h"
#include <stdio.h>

extern int counter;

extern int status;
extern int status_pedestrian;

// define all status of automatic FSM:
#define AUTO_INIT			255

#define AUTO_GREEN1			1
#define AUTO_YELLOW1 		2

#define AUTO_GREEN2			11
#define AUTO_YELLOW2 		12

// states of MANUAL FSM:
#define MAN_GREEN1			21
#define MAN_YELLOW1			22

#define MAN_GREEN2			23
#define MAN_YELLOW2			24

// states of TUNING FSM
#define TUNING_RED			31
#define TUNING_GREEN		32
#define TUNING_YELLOW		33

// states of PEDESTRIAN
#define STOP_LIGHT			45
#define	WALK_LIGHT			46

// TIME of LIGHTs TIMER VALUE:
#define RED_TIME			10000
#define GREEN_TIME			7000
#define YELLOW_TIME			3000

#define MANUAL_TIME			10000
#define TUNING_TIME			10000
#define PEDESTRIAN_TIME		20000
#define BUZZER_CYCLE		1300
#define BUZZER_FREQ_START	50

extern int red_time;
extern int yellow_time;
extern int green_time;

extern int red_time_2;
extern int yellow_time_2;
extern int green_time_2;

extern int buzzer_time;
extern int buzzer_freq;

// UART communiation
#define MAX_SIZE_FOR_UART	30
extern char buffer_rx[MAX_SIZE_FOR_UART];
extern char buffer_tx[MAX_SIZE_FOR_UART];

#endif /* INC_GLOBAL_H_ */

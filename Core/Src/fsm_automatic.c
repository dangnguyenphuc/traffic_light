/*
 * fsm_automatic.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#include "fsm_automatic.h"


void fsm_automatic_run(){
	switch(status){
		case INIT:
			// TODO:
			clearLED(3);	// clear 2 traffic Lights

			//SWITCH CASE
			setTimer3(green_time);
			status = AUTO_GREEN1;
			break;
		case AUTO_GREEN1:
			// TODO:
				// RED2 on, GREEN1 on
			setRed(1);
			setGreen(0);

			//SWITCH CASE
			if(timer3_flag){
				setTimer3(yellow_time);
				status = AUTO_YELLOW1;
			}
			break;
		case AUTO_YELLOW1:
			// TODO:
				// RED2 still on, YELLOW1 on
			setRed(1);
			setYellow(0);

			//SWITCH CASE
			if(timer3_flag){
				setTimer3(green_time);
				status = AUTO_GREEN2;
			}

			break;
		case AUTO_GREEN2:
			// TODO:
				// RED2 off, GREEN2 on, RED1 on
			setRed(0);
			setGreen(1);

			//SWITCH CASE
			if(timer3_flag){
				setTimer3(yellow_time);
				status = AUTO_YELLOW2;
			}

			break;
		case AUTO_YELLOW2:
			// TODO:
				// RED1 still on, YELLOW2 on
			setRed(0);
			setYellow(1);

			//SWITCH CASE
			if(timer3_flag){
				setTimer3(green_time);
				status = AUTO_GREEN1;
			}

			break;
		default:
			break;
	}
}

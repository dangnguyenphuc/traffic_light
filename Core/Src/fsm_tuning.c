/*
 * fsm_tunning.c
 *
 *  Created on: Dec 1, 2022
 *      Author: phucd
 */


#include "fsm_tuning.h"


void fsm_tuning_run(){
	switch(status){
		case TUNING_RED:
			// TODO:
			if(is_button_pressed(3)){
				red_time += 1;
			}
			if(is_button_pressed_1s(3)){
				red_time -= 1;
			}
			// display time by uart

			// toogle LED

			//SWITCH CASE
			if(timer3_flag){
				status = AUTO_INIT;
			}
			else if(is_button_pressed(2)){
				status = TUNING_YELLOW;
				setTimer3(TUNING_TIME);
			}

			break;
		case TUNING_YELLOW:
			// TODO:
			if(is_button_pressed(3)){
				yellow_time += 1;
			}
			if(is_button_pressed_1s(3)){
				yellow_time -= 1;
			}
			// display time by uart

			// toogle LED

			//SWITCH CASE
			if(timer3_flag){
				setTimer3(green_time);
				status = AUTO_GREEN2;
			}
			else if(is_button_pressed(2)){
				status = TUNING_GREEN;
				setTimer3(TUNING_TIME);
			}

			break;
		case TUNING_GREEN:
			// TODO:
			if(is_button_pressed(3)){
				green_time += 1;
			}
			if(is_button_pressed_1s(3)){
				green_time -= 1;
			}
			// display time by uart

			// toogle LED

			//SWITCH CASE
			if(timer3_flag){
				setTimer3(yellow_time);
				status = AUTO_YELLOW2;
			}
			else if(is_button_pressed(2)){
				status = TUNING_RED;
				setTimer3(TUNING_TIME);
			}

			break;
		default:
			break;
	}
}

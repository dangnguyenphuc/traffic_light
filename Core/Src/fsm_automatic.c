/*
 * fsm_automatic.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd, ngocvy
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
		case AUTO_INIT:
			// TODO:
			clearLED(3);	// clear 2 traffic Lights

			//SWITCH CASE
			setTimer3(green_time);		// set green1 time
			setTimer4(red_time_2);		// set red2 time
			timer2_flag = 1;
			status = AUTO_GREEN1;

			break;
		case AUTO_GREEN1:
			// TODO:
				// RED2 on, GREEN1 on
			setRed(1);
			setGreen(0);
				// if PEDESTRIAN PRESSED:
			if(is_button_pressed(0)){
				status_pedestrian = STOP_LIGHT;
				setTimer1(PEDESTRIAN_TIME);
				buzzer_freq = BUZZER_FREQ_START;
				buzzer_time = BUZZER_CYCLE;
			}

			//SWITCH CASE
			if(timer3_flag){
				setTimer3(yellow_time);
				status = AUTO_YELLOW1;
			}

			if (is_button_pressed(1)) {
				status = MAN_GREEN1;
				setTimer3(MANUAL_TIME);
			}

			if (is_button_pressed(2)) {
				status = TUNING_RED;
				setTimer3(TUNING_TIME);
			}


			break;
		case AUTO_YELLOW1:
			// TODO:
				// RED2 still on, YELLOW1 on
			setRed(1);
			setYellow(0);
				// if PEDESTRIAN PRESSED:
			if(is_button_pressed(0)){
				status_pedestrian =	STOP_LIGHT;
				setTimer1(PEDESTRIAN_TIME);
				buzzer_freq = BUZZER_FREQ_START;
				buzzer_time = BUZZER_CYCLE;
			}

			//SWITCH CASE
			if(timer3_flag && timer4_flag){
				setTimer3(red_time);
				setTimer4(green_time_2);
				status = AUTO_GREEN2;
			}

			if (is_button_pressed(1)) {
				status = MAN_YELLOW1;
				setTimer3(MANUAL_TIME);
			}

			if (is_button_pressed(2)) {
				status = TUNING_RED;
				setTimer3(TUNING_TIME);
			}


			break;
		case AUTO_GREEN2:
			// TODO:
				// RED2 off, GREEN2 on, RED1 on
			setRed(0);
			setGreen(1);
				// if PEDESTRIAN PRESSED:
			if(is_button_pressed(0)){
				status_pedestrian = WALK_LIGHT;
				setTimer1(PEDESTRIAN_TIME);
				buzzer_freq = BUZZER_FREQ_START;
				buzzer_time = BUZZER_CYCLE;
			}

			//SWITCH CASE
			if(timer4_flag){
				setTimer4(yellow_time_2);
				status = AUTO_YELLOW2;
			}

			if (is_button_pressed(1)) {
				status = MAN_GREEN2;
				setTimer3(MANUAL_TIME);
			}

			if (is_button_pressed(2)) {
				status = TUNING_RED;
				setTimer3(TUNING_TIME);
			}



			break;
		case AUTO_YELLOW2:
			// TODO:
				// RED1 still on, YELLOW2 on
			setRed(0);
			setYellow(1);
				// if PEDESTRIAN PRESSED:
			if(is_button_pressed(0)){
				status_pedestrian = WALK_LIGHT;
				setTimer1(PEDESTRIAN_TIME);
				buzzer_freq = BUZZER_FREQ_START;
				buzzer_time = BUZZER_CYCLE;
			}

			//SWITCH CASE
			if(timer4_flag && timer3_flag){
				setTimer3(green_time);
				setTimer4(red_time_2);
				status = AUTO_GREEN1;
			}

			if (is_button_pressed(1)) {
				status = MAN_YELLOW2;
				setTimer3(MANUAL_TIME);
			}

			if (is_button_pressed(2)) {
				status = TUNING_RED;
				setTimer3(TUNING_TIME);
			}

			break;
		default:
			break;
	}
}

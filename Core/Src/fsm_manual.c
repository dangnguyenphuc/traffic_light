/*
 * fsm_manual.c
 *
 *  Created on: Dec 1, 2022
 *      Author: phucd
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_GREEN1:
		// TODO:
			// RED2 on, GREEN1 on
		setRed(1);
		setGreen(0);

			// display value by UART
		sendingUART_MANUAL();


			// if PEDESTRIAN PRESSED:
		if(is_button_pressed(0)){
			status_pedestrian = STOP_LIGHT;
			buzzer_freq = BUZZER_FREQ_START;
			buzzer_time = BUZZER_CYCLE;
		}

		//SWITCH CASE
		if(is_button_pressed(1)){
			setTimer8(MANUAL_TIME);
			status = MAN_YELLOW1;
		}

		if (timer8_flag) {
			status = AUTO_YELLOW1;
			setTimer3(yellow_time);
			setTimer4(yellow_time);
		}

		if (is_button_pressed(2)) {
			status = TUNING_RED;

			temp_red = red_time;
			temp_yellow = yellow_time;
			temp_green = green_time;

			setTimer8(TUNING_TIME);
			setTimer9(10);
		}

		break;
	case MAN_YELLOW1:
		// TODO:
			// RED2 still on, YELLOW1 on
		setRed(1);
		setYellow(0);

			// display value by UART
		sendingUART_MANUAL();

			// if PEDESTRIAN PRESSED:
		if(is_button_pressed(0)){
			status_pedestrian =	STOP_LIGHT;
			setTimer1(PEDESTRIAN_TIME);
			buzzer_freq = BUZZER_FREQ_START;
			buzzer_time = BUZZER_CYCLE;
		}
		//SWITCH CASE
		if(is_button_pressed(1)){
			setTimer8(MANUAL_TIME);
			status = MAN_GREEN2;
		}

		if (timer8_flag) {
			status = AUTO_GREEN2;
			setTimer3(red_time);
			setTimer4(green_time_2);
		}

		if (is_button_pressed(2)) {
			status = TUNING_RED;

			temp_red = red_time;
			temp_yellow = yellow_time;
			temp_green = green_time;

			setTimer8(TUNING_TIME);
			setTimer9(10);
		}

		break;
	case MAN_GREEN2:
		// TODO:
			// RED2 off, GREEN2 on, RED1 on
		setRed(0);
		setGreen(1);

			// display value by UART
		sendingUART_MANUAL();

			// if PEDESTRIAN PRESSED:
		if(is_button_pressed(0)){
			status_pedestrian = WALK_LIGHT;
			setTimer1(PEDESTRIAN_TIME);
			buzzer_freq = BUZZER_FREQ_START;
			buzzer_time = BUZZER_CYCLE;
		}

		//SWITCH CASE
		if(is_button_pressed(1)){
			setTimer8(MANUAL_TIME);
			status = MAN_YELLOW2;
		}

		if (timer8_flag) {
			status = AUTO_YELLOW2;
			setTimer3(yellow_time_2);
			setTimer3(yellow_time_2);
		}

		if (is_button_pressed(2)) {
			status = TUNING_RED;

			temp_red = red_time;
			temp_yellow = yellow_time;
			temp_green = green_time;

			setTimer8(TUNING_TIME);
			setTimer9(10);
		}

		break;
	case MAN_YELLOW2:
		// TODO:
			// RED1 still on, YELLOW2 on
		setRed(0);
		setYellow(1);

			// display value by UART
		sendingUART_MANUAL();

			// if PEDESTRIAN PRESSED:
		if(is_button_pressed(0)){
			status_pedestrian = WALK_LIGHT;
			setTimer1(PEDESTRIAN_TIME);
			buzzer_freq = BUZZER_FREQ_START;
			buzzer_time = BUZZER_CYCLE;
		}

		//SWITCH CASE
		if(is_button_pressed(1)){
			setTimer8(MANUAL_TIME);
			status = MAN_GREEN1;
		}

		if (timer8_flag) {
			setTimer3(green_time);
			setTimer4(red_time_2);
			status = AUTO_GREEN1;
		}

		if (is_button_pressed(2)) {
			status = TUNING_RED;

			temp_red = red_time;
			temp_yellow = yellow_time;
			temp_green = green_time;

			setTimer8(TUNING_TIME);
			setTimer9(10);
		}

		break;

	default:
		break;
	}
}

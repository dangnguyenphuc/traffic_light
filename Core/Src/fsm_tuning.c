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
				red_time += 500;
				sendingUART_SETTING();
			}
			if(is_button_pressed_1s(3)){
				red_time -= 500;
				sendingUART_SETTING();
			}

			red_time_2 = red_time;

			// toogle LED and send Setting informations
			if(timer9_flag){
				setRed(0);
				setRed(1);
				setTimer9(2000);
				setTimer7(1000);
			}
			if(timer7_flag){
				setRed(2);	// Turn off
			}

			//SWITCH CASE
			if(timer3_flag){
				status = AUTO_INIT;
			}
			else if(is_button_pressed(2)){
				status = TUNING_YELLOW;
				setTimer3(TUNING_TIME);
				setTimer9(10);
			}
			else if(is_button_pressed(1)){
				status = AUTO_INIT;
			}


			break;
		case TUNING_YELLOW:
			// TODO:
			if(is_button_pressed(3)){
				yellow_time += 500;
				sendingUART_SETTING();
			}
			if(is_button_pressed_1s(3)){
				yellow_time -= 500;
				sendingUART_SETTING();
			}

			yellow_time_2 = yellow_time;

			// toogle LED and send Setting informations
			if(timer9_flag){
				setYellow(0);
				setYellow(1);
				setTimer9(2000);
				setTimer7(1000);
			}
			if(timer7_flag){
				setRed(2);	// Turn off
			}

			//SWITCH CASE
			if(timer3_flag){
				status = AUTO_INIT;
			}
			else if(is_button_pressed(2)){
				status = TUNING_GREEN;
				setTimer3(TUNING_TIME);
				setTimer9(10);
			}
			else if(is_button_pressed(1)){
				status = AUTO_INIT;
			}

			break;

		case TUNING_GREEN:
			// TODO:
			if(is_button_pressed(3)){
				green_time += 500;
				sendingUART_SETTING();
			}
			if(is_button_pressed_1s(3)){
				green_time -= 500;
				sendingUART_SETTING();
			}

			green_time_2 = green_time;

			// toogle LED and send Setting informations
			if(timer9_flag){
				setGreen(0);
				setGreen(1);
				setTimer9(2000);
				setTimer7(1000);
			}
			if(timer7_flag){
				setRed(2);	// Turn off
			}

			//SWITCH CASE
			if(timer3_flag){
				status = AUTO_INIT;
			}
			else if(is_button_pressed(2)){
				status = TUNING_RED;
				setTimer3(TUNING_TIME);
				setTimer9(10);
			}
			else if(is_button_pressed(1)){
				status = AUTO_INIT;
			}

			break;
		default:
			break;
	}
}

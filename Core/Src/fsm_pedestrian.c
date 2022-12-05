/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 5, 2022
 *      Author: phucd, ngocvy
 */
#include "fsm_pedestrian.h"

void fsm_pedestrian_run(){
	switch(status_pedestrian){
		case STOP_LIGHT:
			//TODO:
			setPedestrian(0);


			//SWITCH CASE
			if(timer1_flag){
				status_pedestrian = -1;
				setPedestrian(3); // turn off light
				buzzer_freq = 0;
				buzzer_time = 0;
			}
			if(status == AUTO_GREEN2 || status == AUTO_YELLOW2){
				status_pedestrian = WALK_LIGHT;
			}

			break;
		case WALK_LIGHT:
			//TODO:
			setPedestrian(1);

			//SWITCH CASE
			if(timer1_flag){
				status_pedestrian = -1;
				setPedestrian(3); // turn off light
				buzzer_freq = 0;
				buzzer_time = 0;
			}
			if(status == AUTO_GREEN1 || status == AUTO_YELLOW1){
				status_pedestrian = STOP_LIGHT;
			}

			break;
		default:

			break;
	}
}


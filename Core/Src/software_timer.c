/*
 * software_timer.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#include "software_timer.h"

int timer1_flag = 0;
int timer1_counter = 0;

int timer2_flag = 0;
int timer2_counter = 0;

int timer3_flag = 0;
int timer3_counter = 0;

int timer4_flag = 0;
int timer4_counter = 0;

int timer5_flag = 0;
int timer5_counter = 0;


void setTimer1(int time){

}

void clearTimer1(){

}

void setTimer2(int time){

}
void clearTimer2(){

}

void setTimer3(int time){

}
void clearTimer3(){

}

void setTimer4(int time){

}
void clearTimer4(){

}

void setTimer5(int time){

}
void clearTimer5(){

}

void TimerRun(){
	if(timer1_counter > 0){
		timer1_counter -= 1;
	}
	else{
		timer1_flag = 1;
	}

	if(timer2_counter > 0){
		timer2_counter -= 1;
	}
	else{
		timer2_flag = 1;
	}
	if(timer3_counter > 0){
		timer3_counter -= 1;
	}
	else{
		timer3_flag = 1;
	}

	if(timer4_counter > 0){
		timer4_counter -= 1;
	}
	else{
		timer4_flag = 1;
	}

	if(timer5_counter > 0){
		timer5_counter -= 1;
	}
	else{
		timer5_flag = 1;
	}
}

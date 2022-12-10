/*
 * software_timer.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#include "software_timer.h"

#define TICK 10

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

int timer6_flag = 0;
int timer6_counter = 0;

int timer7_flag = 0;
int timer7_counter = 0;

int timer8_flag = 0;
int timer8_counter = 0;

int timer9_flag = 0;
int timer9_counter = 0;

void setTimer1(int time){
	timer1_counter = time/10;
	timer1_flag = 0;
}

void clearTimer1(){
	timer1_counter = 0;
	timer1_flag = 0;
}

void setTimer2(int time){
	timer2_counter = time/10;
	timer2_flag = 0;
}

void clearTimer2(){
	timer2_counter = 0;
	timer2_flag = 0;
}

void setTimer3(int time){
	timer3_counter = time/10;
	timer3_flag = 0;
}

void clearTimer3(){
	timer3_counter = 0;
	timer3_flag = 0;
}

void setTimer4(int time){
	timer4_counter = time/10;
	timer4_flag = 0;
}

void clearTimer4(){
	timer4_counter = 0;
	timer4_flag = 0;
}

void setTimer5(int time){
	timer5_counter = time/10;
	timer5_flag = 0;
}

void clearTimer5(){
	timer5_counter = 0;
	timer5_flag = 0;
}

void setTimer6(int time){
	timer6_counter = time/10;
	timer6_flag = 0;
}

void clearTimer6(){
	timer6_counter = 0;
	timer6_flag = 0;
}

void setTimer7(int time){
	timer7_counter = time/10;
	timer7_flag = 0;
}

void clearTimer7(){
	timer7_counter = 0;
	timer7_flag = 0;
}

void setTimer8(int time){
	timer8_counter = time/10;
	timer8_flag = 0;
}

void clearTimer8(){
	timer8_counter = 0;
	timer8_flag = 0;
}

void setTimer9(int time){
	timer9_counter = time/10;
	timer9_flag = 0;
}

void clearTimer9(){
	timer9_counter = 0;
	timer9_flag = 0;
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

	if(timer6_counter > 0){
		timer6_counter -= 1;
	}
	else{
		timer6_flag = 1;
	}

	if(timer7_counter > 0){
		timer7_counter -= 1;
	}
	else{
		timer7_flag = 1;
	}

	if(timer8_counter > 0){
		timer8_counter -= 1;
	}
	else{
		timer8_flag = 1;
	}

	if(timer9_counter > 0){
		timer9_counter -= 1;
	}
	else{
		timer9_flag = 1;
	}
}

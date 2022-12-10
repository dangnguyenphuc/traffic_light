/*
 * global.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */


#include "global.h"

int counter = 0;

int status = AUTO_INIT;
int status_pedestrian = -1;

int red_time = RED_TIME;
int yellow_time = YELLOW_TIME;
int green_time = GREEN_TIME;

int red_time_2 = RED_TIME;
int yellow_time_2 = YELLOW_TIME;
int green_time_2 = GREEN_TIME;

char buffer_rx[MAX_SIZE_FOR_UART] = {0,0,0,0,0,0,0,0,0,0};
char buffer_tx[MAX_SIZE_FOR_UART] = {0,0,0,0,0,0,0,0,0,0};


int buzzer_time = 0;
int buzzer_freq = 0;

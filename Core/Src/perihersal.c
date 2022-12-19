/*
 * perihersal.c
 *
 *  Created on: Dec 6, 2022
 *      Author: PC
 */

#include "perihersal.h"

void sendingUART_RUN(){
	if(timer2_flag){
		if(!timer3_flag){
			HAL_UART_Transmit(&huart2, (void *)buffer_tx, sprintf (buffer_tx,"!7SEG:%d:LIGHT1#\r\n", timer3_counter/100), 1000);
		}else{
			HAL_UART_Transmit(&huart2, (void *)buffer_tx, sprintf (buffer_tx,"!7SEG:DELAY:LIGHT1#\r\n"), 1000);
		}

		if(!timer4_flag){
			HAL_UART_Transmit(&huart2, (void *)buffer_tx, sprintf (buffer_tx,"!7SEG:%d:LIGHT2#\r\n", timer4_counter/100), 1000);
		}else{
			HAL_UART_Transmit(&huart2, (void *)buffer_tx, sprintf (buffer_tx,"!7SEG:DELAY:LIGHT2#\r\n"), 1000);
		}
		setTimer2(1000);
	}
}

void sendingUART_SETTING(){
		HAL_UART_Transmit(&huart2, (void *)buffer_tx, sprintf (buffer_tx,"!RED:%d:YELLOW:%d:GREEN:%d#\r\n", temp_red/1000, temp_yellow/1000, temp_green/1000), 1000);
}

void Buzzer(){
	if(timer5_flag){
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, buzzer_freq);
		setTimer6(buzzer_time/2);
		if(timer3_counter<2000){
			buzzer_freq *= 3;
			buzzer_time = (timer3_counter>0)? timer3_counter/4 : buzzer_time/3;
		}else{
			buzzer_freq += 100;
			buzzer_time -= 100;
		}


		if(buzzer_freq >= 1000) buzzer_freq = 1000;
		if(buzzer_time <= 100)	buzzer_time = 100;
		setTimer5(buzzer_time);
	}
	if(timer6_flag){
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	}
}

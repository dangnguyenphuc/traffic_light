/*
 * led.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#include "led.h"

/*
 * Traffic light 1:
 * 		Pin 1: D2 – PA10
 * 		Pin 2: D3 – PB3
 */

/*
 * Traffic light 2:
 *		Pin 1: D4 – PB5
 *		Pin 2: D5 – PB4
 */

void setRed(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_RESET);
			break;
		default:

			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_RESET);

			break;
	}
}

void setYellow(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_SET);
			break;
		default:

			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_RESET);

			break;
	}
}

void setGreen(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_SET);
			break;
		default:

			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_RESET);

			break;
	}
}

void setPedestrian(int value){
	switch(value){
		case 0:

			break;
		case 1:

			break;
		default:


			break;
	}
}

void clearLED(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_RESET);
			break;
		default:

			HAL_GPIO_WritePin(D2_LED_RED1_GPIO_Port, D2_LED_RED1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D3_LED_GREEN1_GPIO_Port, D3_LED_GREEN1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D4_LED_RED2_GPIO_Port, D4_LED_RED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(D5_LED_GREEN2_GPIO_Port, D5_LED_GREEN2_Pin, GPIO_PIN_RESET);


			break;
	}
}

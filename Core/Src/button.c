/*
 * button.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#include "button.h"

#define NO_OF_BUTTONS						4
#define DURATION_FOR_AUTO_INCREASING		100
#define PRESSED_STATE						GPIO_PIN_RESET
#define NORMAL_STATE						GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS];


static int flagForButtonPressed[NO_OF_BUTTONS] = 		{0,0,0,0};
static int flagForButtonPressed1s[NO_OF_BUTTONS]= 		{0,0,0,0};
static int counterForButtonPressed1s[NO_OF_BUTTONS]= 	{0,0,0,0};


GPIO_PinState iKeyInput(int index){
	switch(index){
	case 0:
		return HAL_GPIO_ReadPin(A0_GPIO_Port,A0_Pin);
	case 1:
		return HAL_GPIO_ReadPin(A1_GPIO_Port,A1_Pin);
	case 2:
		return HAL_GPIO_ReadPin(A2_GPIO_Port,A2_Pin);
	case 3:
		return HAL_GPIO_ReadPin(A3_GPIO_Port, A3_Pin);
	default:
		return NORMAL_STATE;
	}
}

void subKeyProcess1(int index){
	flagForButtonPressed[index] = 1;
}

void subKeyProcess2(int index){
	flagForButtonPressed1s[index] = 1;
}

void getKeyInput(){
	for(int i = 0; i < NO_OF_BUTTONS; ++i){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer0[i];
		debounceButtonBuffer0[i] = iKeyInput(i);

		if(debounceButtonBuffer2[i] == debounceButtonBuffer1[i] &&
		   debounceButtonBuffer0[i] == debounceButtonBuffer1[i])
		{
			if(buttonBuffer[i] != debounceButtonBuffer2[i]){
				buttonBuffer[i] = debounceButtonBuffer2[i];
				if(debounceButtonBuffer2[i]==PRESSED_STATE){
					subKeyProcess1(i);
					counterForButtonPressed1s[i] = DURATION_FOR_AUTO_INCREASING;
				}
			}else{
				counterForButtonPressed1s[i]--;
				if(counterForButtonPressed1s[i] <= 0){
					if(debounceButtonBuffer2[i]==PRESSED_STATE){
						subKeyProcess2(i);
					}
				counterForButtonPressed1s[i] = DURATION_FOR_AUTO_INCREASING;
				}
			}
		}
	}
}

unsigned char is_button_pressed(unsigned char button_number){
	if(button_number >= NO_OF_BUTTONS) return 0;
	else {
		if(flagForButtonPressed[button_number] == 1){
			flagForButtonPressed[button_number] = 0;
			return 1;
		}
		return 0;
	}
}
unsigned char is_button_pressed_1s(unsigned char button_number){
	if(button_number >= NO_OF_BUTTONS) return 0xff;
	else {
		if(flagForButtonPressed1s[button_number] == 1){
			flagForButtonPressed1s[button_number] = 0;
			return 1;
		}
		return 0;
	}
}






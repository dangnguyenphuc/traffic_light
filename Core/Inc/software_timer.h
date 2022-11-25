/*
 * software_timer.h
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
void setTimer1(int time);
void clearTimer1();

extern int timer2_flag;
void setTimer2(int time);
void clearTimer2();

extern int timer3_flag;
void setTimer3(int time);
void clearTimer3();

extern int timer4_flag;
void setTimer4(int time);
void clearTimer4();

extern int timer5_flag;
void setTimer5(int time);
void clearTimer5();

void TimerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */

/*
 * scheduler.c
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#include "scheduler.h"


#define TICK			10

//  ======================
Task sTask[SCH_MAX_TASKS];
int len;
int head;
int tail;
int cur_index;
//  ======================

void SCH_Init(){

	cur_index = 0;
	len = 0;
	head = 0;
	cur_index = 0;
	tail = 0;

	clearLED(0);
	clearLED(1);

}

void SCH_Add_Task( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){

	if(len<SCH_MAX_TASKS){

        if(len == 0){

            sTask[0].pTask = pFunction;
            sTask[0].Delay = DELAY/TICK;
            sTask[0].Period = PERIOD/TICK;
            sTask[0].RunMe = 0;

            cur_index = 0;

        }else{
            //counter
            int i, j;

    	    if(DELAY >= sTask[cur_index].Delay){

                for(i=cur_index;i<tail && DELAY/TICK >= sTask[i].Delay;i+=1);

                //new tail
                if( i==tail && DELAY >= sTask[i].Delay ){
                    sTask[i+1].pTask = pFunction;
                    sTask[i+1].Delay = DELAY/TICK;
                    sTask[i+1].Period = PERIOD/TICK;
                    sTask[i+1].RunMe = 0;
                    cur_index = tail;

                }
                else{
                    for(j = len; j>i ; j-=1){
                        sTask[j] = sTask[j-1];
                    }

                    sTask[i].pTask = pFunction;
                    sTask[i].Delay = DELAY/TICK;
                    sTask[i].Period = PERIOD/TICK;
                    sTask[i].RunMe = 0;
                    cur_index = i;
                }

    	    }else{
                // printf("dang");
    	        for(i=cur_index; i>head && DELAY/TICK < sTask[i].Delay; i-=1);

                //new head
                if( i==head && DELAY/TICK < sTask[i].Delay ){

                    for(j = len; j>head ; j-=1){
                        sTask[j] = sTask[j-1];
                    }

                    sTask[0].pTask = pFunction;
                    sTask[0].Delay = DELAY/TICK;
                    sTask[0].Period = PERIOD/TICK;
                    sTask[0].RunMe = 0;
                    cur_index = 0;
                }
                else{
                    for(j = len; j>i+1 ; j-=1){
                        sTask[j] = sTask[j-1];
                    }

                    i += 1;

                    sTask[i].pTask = pFunction;
                    sTask[i].Delay = DELAY/TICK;
                    sTask[i].Period = PERIOD/TICK;
                    sTask[i].RunMe = 0;
                    cur_index =i;
                }

    	    }
        }

        tail = len;
	    // Adding len
        len += 1;

	}

}

void SCH_Delete_Then_Add_Task(){

		Task temp = sTask[0];
		for(int i = 0; i<len-1; i+=1){
		    sTask[i] = sTask[i+1];
		}
		len -= 1;
		tail -= 1;

		SCH_Add_Task(temp.pTask, temp.Delay + temp.Period, temp.Period);

}


void SCH_Update(void) {

	int head_index_update = 0;
	while(counter >= sTask[head_index_update].Delay){
		sTask[head_index_update].RunMe += 1;
		head_index_update += 1;
	}

	counter+=1;
}
//
void SCH_Dispatch_Tasks(void) {
	while(sTask[0].RunMe){
	    sTask[0].RunMe -= 1;
	    (*sTask[0].pTask)();
	    SCH_Delete_Then_Add_Task();
	}
//	SCH_Report_Status();
//	SCH_Go_to_Sleep();
}
//
void SCH_Go_to_Sleep(){
	// TODO: none
	// It do nothing until the next task executed

	char flag = 0;
	while(!flag){
		for (int i = 0; i < len; i+=1 ) {
				if (sTask[i].RunMe) {
					flag = 1;
					break;
				}
		}
	}
}

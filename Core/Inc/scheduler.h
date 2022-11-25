/*
 * scheduler.h
 *
 *  Created on: Nov 25, 2022
 *      Author: phucd
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>


typedef struct{
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t 	RunMe;
	uint32_t 	TaskID;
}sTasks;

#define SCH_MAX_TASKS	30

void SCH_Init(void);

void SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(uint32_t task_ID);

void SCH_Go_to_Sleep();

void SCH_Report_Status(void);

#endif /* INC_SCHEDULER_H_ */

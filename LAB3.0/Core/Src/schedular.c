/*
 * schedular.c
 *
 *  Created on: Dec 11, 2024
 *      Author: Dell
 */


#include "schedular.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void) {

}

void SCH_Update(void) {
	uint32_t Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].pTask) {
			if (SCH_tasks_G[Index].Delay == 0) {
				// The task is due to run
				SCH_tasks_G[Index].RunMe += 1; // Inc. the 'RunMe' flag
				if (SCH_tasks_G[Index].Period) {
					// Schedule periodic tasks to run again
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			}
			else
			{
				// Not yet ready to run: just decrement the delay
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
}

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD){
	uint32_t Index = 0;
	// First find a gap in the array (if there is one)
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
	{
		Index++;
	}
	if (Index == SCH_MAX_TASKS) {
		return SCH_MAX_TASKS; // Also return an error code
	}
	// If we're here, there is a space in the task array
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	return Index; // return position of task (to allow later deletion)
}

void SCH_Dispatch_Task(void) {
	uint32_t Index;
	// Dispatches (runs) the next task (if one is ready)
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].RunMe > 0) {
			(*SCH_tasks_G[Index].pTask)(); // Run the task
			SCH_tasks_G[Index].RunMe -= 1; // Reset / reduce RunMe flag
			if (SCH_tasks_G[Index].Period == 0) {
				SCH_Delete_Task(Index);
			}
		}
	}
}
unsigned char SCH_Delete_Task(const uint32_t TASK_INDEX) {
	int Return_code;
	if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
		Return_code = 1;
	}
	else {
		Return_code = 0;
	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	return Return_code; // return status
}

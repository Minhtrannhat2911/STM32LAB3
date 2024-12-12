/*
 * schedular.c
 *
 *  Created on: Dec 11, 2024
 *      Author: Dell
 */


#include "schedular.h"

sTask SCH_tasks[SCH_MAX_TASKS];

void SCH_Init(void) {

}

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD){
	uint32_t Index = 0;
	// Find empty slot in the array
	while ((SCH_tasks[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
	{
		Index++;
	}
	if (Index == SCH_MAX_TASKS) {
		return SCH_MAX_TASKS;
	}
	// initialize new task
	SCH_tasks[Index].pTask = pFunction;
	SCH_tasks[Index].Delay = DELAY;
	SCH_tasks[Index].Period = PERIOD;
	SCH_tasks[Index].RunMe = 0;
	return Index; // return position of task (to allow later deletion)
}

void SCH_Update(void) {
	uint32_t Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		// If there is a task at this location
		if (SCH_tasks[Index].pTask) {
			if (SCH_tasks[Index].Delay == 0) {
				// And if the task is due to run
				SCH_tasks[Index].RunMe += 1;
				if (SCH_tasks[Index].Period) {
					// Schedule periodic tasks to run again
					SCH_tasks[Index].Delay = SCH_tasks[Index].Period;
				}
			}
			else
			{
				// Else the task is not due to run => Delay--
				SCH_tasks[Index].Delay -= 1;
			}
		}
	}
}

void SCH_Dispatch_Task(void) {
	uint32_t Index;
	// runs the next task
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks[Index].RunMe > 0) {
			(*SCH_tasks[Index].pTask)(); // Run the task
			SCH_tasks[Index].RunMe -= 1; // Reset the flag
			if (SCH_tasks[Index].Period == 0) {
				SCH_Delete_Task(Index);
			}
		}
	}
}
unsigned char SCH_Delete_Task(const uint32_t TASK_INDEX) {
	int Return_code;
	if (SCH_tasks[TASK_INDEX].pTask == 0) {
		Return_code = 1;
	}
	else {
		Return_code = 0;
	}
	SCH_tasks[TASK_INDEX].pTask = NULL;
	SCH_tasks[TASK_INDEX].Delay = 0;
	SCH_tasks[TASK_INDEX].Period = 0;
	SCH_tasks[TASK_INDEX].RunMe = 0;
	return Return_code; // return status
}



/*
 * schedular.h
 *
 *  Created on: Dec 11, 2024
 *      Author: Dell
 */

#ifndef INC_SCHEDULAR_H_
#define INC_SCHEDULAR_H_

#include <stdint.h> // Thêm để định nghĩa uint32_t, uint8_t

typedef struct {
    void (*funcPtr)(void);
    uint32_t delay; // đơn vị: tick
    uint32_t period; // đơn vị: tick
    uint8_t run_me;
    uint32_t taskId;
} task_struct;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
task_struct taskArr[SCH_MAX_TASKS];

#define ERROR_SCH_TOO_MANY_TASKS 1
#define ERROR_SCH_CANNOT_DELETE_TASK 2
#define RETURN_CODE_ERROR_DELETE 3
#define RETURN_CODE_SUCCESS_DELETE 4

extern unsigned char ERROR_CODE;

void SCH_Init(void);
unsigned char SCH_Add_Task(void (*funcPtr)(void), unsigned int delay, unsigned int period);
void SCH_Dispatch_Task(void);
void SCH_Update(void);
void SCH_UpdateDueTime(void);
void SCH_Dispatch_Task(void);
unsigned char SCH_Delete_Task(const uint8_t TASK_IDX); // Sửa tByte thành uint8_t
void SCH_Sleep(void);
void SCH_Report_Status(void);
void SCH_Update(void); // Thêm khai báo hàm SCH_Update

#endif /* INC_SCHEDULAR_H_ */


/*
 * fsm_manual.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "main.h"
#include "global.h"

// Các biến toàn cục
extern int mode;
extern int redValue;
extern int yellowValue;
extern int greenValue;

// Khai báo hàm FSM manual
void fsm_manual_run();

// Khai báo các hàm hỗ trợ
void updateBufferAndClear(int newMode, int value);
void handleButtonPressed(int nextStatus, int newMode, void (*updateFunc)(void), int value);

#endif /* INC_FSM_MANUAL_H_ */

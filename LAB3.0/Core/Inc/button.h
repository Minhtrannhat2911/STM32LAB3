/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: DELL
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE RESET
#define PRESSED_STATE SET
#define NUM_BUTTONS 10

#define MODE_BUTTON 	0
#define ADD_BUTTON		1
#define CONFIRM_BUTTON	2
#define RESET_BUTTON	3

extern int KeyReg0[NUM_BUTTONS];
extern int KeyReg1[NUM_BUTTONS];
extern int KeyReg2[NUM_BUTTONS];
extern int KeyReg3[NUM_BUTTONS];

extern int TimeOutForKeyPress[NUM_BUTTONS];
extern int button_pressed[NUM_BUTTONS];
extern int button_long_pressed[NUM_BUTTONS];
extern int button_flag[NUM_BUTTONS];

void initButtons(void);
int isButtonPressed(int buttonIndex);
int isButtonLongPressed(int buttonIndex);
void subKeyProcess(int buttonIndex);
void getKeyInput();

#endif /* INC_BUTTON_H_ */


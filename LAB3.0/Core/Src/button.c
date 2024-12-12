#include "button.h"

int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE};


int TimerForkeyPress[NUM_BUTTONS] = {500};
int button_pressed[NUM_BUTTONS];
int button_long_pressed[NUM_BUTTONS];
int button_flag[NUM_BUTTONS];


/*
int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(){
	if(button1_long_pressed == 1){
		button1_long_pressed = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}
int isButton4Pressed(){
	if(button4_flag == 1){
		button4_flag = 0;
		return 1;
	}
	return 0;
}


void subKeyProcess(int buttonIndex) {
    switch (buttonIndex) {
        case 0:
            button1_flag = 1;
            break;
        case 1:
            button2_flag = 1;
            break;
        case 2:
            button3_flag = 1;
            break;
        case 3:
            button4_flag = 1;
            break;
        default:
            break;
    }
}
*/
int isButtonPressed(int buttonIndex) {
    if (button_flag[buttonIndex] == 1) {
        button_flag[buttonIndex] = 0;
        return 1;
    }
    return 0;
}

int isButtonLongPressed(int buttonIndex) {
    if (button_long_pressed[buttonIndex] == 1) {
        button_long_pressed[buttonIndex] = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess(int buttonIndex) {
    button_flag[buttonIndex] = 1;
}

void getKeyInput() {
    for (int i = 0; i < NUM_BUTTONS; i++) {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];
        switch (i) {
            case MODE_BUTTON:
                KeyReg2[i] = HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);
                break;
            case ADD_BUTTON:
                KeyReg2[i] = HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin);
                break;
            case CONFIRM_BUTTON:
                KeyReg2[i] = HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin);
                break;
            case RESET_BUTTON:
                KeyReg2[i] = HAL_GPIO_ReadPin(BUT4_GPIO_Port, BUT4_Pin);
                break;
            default:
                break;
        }


        if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
            if (KeyReg3[i] != KeyReg2[i]) {
                KeyReg3[i] = KeyReg2[i];
                if (KeyReg3[i] == PRESSED_STATE) {
                    button_flag[i] = 1;
                    TimerForkeyPress[i] = 500;
                }
            } else {
                if (KeyReg3[i] == PRESSED_STATE) {
                    TimerForkeyPress[i]--;
                    if (TimerForkeyPress[i] == 0) {
                        button_long_pressed[i] = 1;
                        TimerForkeyPress[i] = 500;
                    }
                }
            }
        }
    }
}


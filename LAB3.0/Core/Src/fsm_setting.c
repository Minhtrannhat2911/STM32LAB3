/*
 * fsm_setting.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */


#include "global.h"
#include "fsm_setting.h"
int status = INIT;
void fsm_setting_run() {
    switch(status) {
        case INIT: {
            status = AUTO;  // Chuyển trực tiếp sang AUTO
            break;
        }
        case AUTO: {
            if (isButtonPressed(0)) {
                status = MAN;
                setTimer(2, 10000); // Timer 3
                setTimer(3, 500); // Timer 4
                clearTrafficLight();
            }
            break;
        }
        case MAN: {
            if (isButtonPressed(2) || timer_flag[2] == 1) {
                status = AUTO;
            }
            break;
        }
        default: {
            break;
        }
    }
}

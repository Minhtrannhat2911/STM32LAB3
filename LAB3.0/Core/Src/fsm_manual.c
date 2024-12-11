/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */

#include "fsm_manual.h"
#include "light.h"

int mode = 0;
int redValue = 0;
int yellowValue = 0;
int greenValue = 0;

/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */

#include "fsm_manual.h"
#include "light.h"

int mode = 0;
int redValue = 0;
int yellowValue = 0;
int greenValue = 0;


void updateBufferAndClear(int newMode, int value) {
    mode = newMode;
    BufferHorizontal(mode);
    BufferVertical(value);
    clearTrafficLight();
}

void handleButtonPressed(int nextStatus, int newMode, void (*updateFunc)(void), int value) {
    if (isButtonPressed(0)) {
        status = nextStatus;
        updateBufferAndClear(newMode, value);
    } else if (isButtonPressed(1) && updateFunc) {
        updateFunc();
        BufferVertical(value);
    } else if (isButtonPressed(2)) {
        status = MAN;
        setTimer(2, 10000); // Timer 3
        clearTrafficLight();
        mode = 0;
    }
}

void fsm_manual_run() {
    if (timer_flag[3] == 1) {
        setTimer(3, 500); // Timer 4
        switch (status) {
            case MAN: blinkAllLed(); break;
            case MODE2: blinkRedLed(); break;
            case MODE3: blinkYellowLed(); break;
            case MODE4: blinkGreenLed(); break;
        }
    }

    switch (status) {
        case MAN: {
            BufferHorizontal(mode);
            BufferVertical(0);
            if (isButtonPressed(0)) {
                status = MODE2;
                redValue = redTime;
                yellowValue = yellowTime;
                greenValue = greenTime;
                updateBufferAndClear(2, redTime);
            }
            break;
        }
        case MODE2: {
            handleButtonPressed(MODE3, 3, timeredupdate, redTime);
            break;
        }
        case MODE3: {
            handleButtonPressed(MODE4, 4, timeyellowupdate, yellowTime);
            break;
        }
        case MODE4: {
            handleButtonPressed(MAN, 0, timegreenupdate, greenTime);
            break;
        }
        default: {
            break;
        }
    }
}






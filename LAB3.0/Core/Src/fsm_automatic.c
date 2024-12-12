/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */

#include "fsm_automatic.h"


int countdownX = 0;
int countdownY = 0;

void updateBuffer(int x, int y) {
    // cập nhậthai buffer cùng một lúc
    BufferHorizontal(x);
    BufferVertical(y);
}

void updateCountdownAndResetTimer() {
    updateBuffer(countdownX, countdownY); // Cập nhật lại buffer hiển thị
    countdownX--;
    countdownY--;
    setTimer(1, 1000); // Timer 2
}

void switchToManualMode() {
    status = MAN;
    setTimer(2, 10000); // Timer 3
    clearTrafficLight();
}

void fsm_automatic_run() {
    switch (status) {
        case AUTO: {
            status = GREEN_RED;
            countdownX = greenTime - 1;
            countdownY = redTime - 1;
            updateBuffer(countdownX, countdownY);
            setTimer(0, greenTime * 1500); // Timer 1
            setTimer(1, 1000);
            break;
        }
        case GREEN_RED: {
        	Green_Red();
            if (timer_flag[0] == 1) {
                status = YELLOW_RED;
                setTimer(0, yellowTime * 1000); // Timer 1
                countdownX = yellowTime - 1;
            }
            if (timer_flag[1] == 1) {
                updateCountdownAndResetTimer();
            }
            if (isButtonPressed(0)) {
                switchToManualMode();
            }
            break;
        }
        case YELLOW_RED: {
            Yellow_Red();
            // Kiểm tra nếu timer_flag[0] đã kích hoạt (kết thúc đèn vàng)
            if (timer_flag[0] == 1) {
                status = RED_GREEN;
                setTimer(0, greenTime * 1000); // Chuyển sang RED_GREEN
                countdownX = redTime - 1;
                countdownY = greenTime - 1;
            }
            // Giảm thời gian hiển thị nếu timer_flag[1] kích hoạt
            if (timer_flag[1] == 1) {
                updateCountdownAndResetTimer();
            }
            // Kiểm tra nếu nút nhấn để chuyển chế độ
            if (isButtonPressed(0)) {
                switchToManualMode();
            }
            break;
        }

        case RED_GREEN: {
        	Red_Green();
            if (timer_flag[0] == 1) {
                status = RED_YELLOW;
                setTimer(0, yellowTime * 1000); // Timer 1
                countdownY = yellowTime - 1;
            }
            if (timer_flag[1] == 1) {
                updateCountdownAndResetTimer();
            }
            if (isButtonPressed(0)) {
                switchToManualMode();
            }
            break;
        }
        case RED_YELLOW: {
        	Red_Yellow();
            if (timer_flag[0] == 1) {
                status = GREEN_RED;
                setTimer(0, greenTime * 1000); // Timer 1
                countdownX = greenTime - 1;
                countdownY = redTime - 1;
            }
            if (timer_flag[1] == 1) {
                updateCountdownAndResetTimer();
            }
            if (isButtonPressed(0)) {
                switchToManualMode();
            }
            break;
        }
        default: {
            break;
        }
    }
}



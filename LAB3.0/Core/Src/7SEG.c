/*
 * 7LED.C
 *
 *  Created on: Nov 13, 2024
 *      Author: Dell
 */


#include <7SEG.h>
#include "global.h"


void resetAllDigits(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
}

void setDigit(int digitSerial){
	resetAllDigits();
	switch(digitSerial) {
		case 0: {
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			break;
		}
		case 1: {
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			break;
		}
		case 2: {
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			break;
		}
		case 3: {
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			break;
		}
		default: {
			break;
		}
	}
}

void setNum2Digit(int a, int b, int c, int d, int e, int f, int g){
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, a);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, b);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, c);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, d);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, e);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, f);
	HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, g);
}

void display7SEG(int num){
    switch(num) {
		case 0: {
			setNum2Digit(0,0,0,0,0,0,1);
			break;
		}
		case 1: {
			setNum2Digit(1,0,0,1,1,1,1);
			break;
		}
		case 2: {
			setNum2Digit(0,0,1,0,0,1,0);
			break;
		}
		case 3: {
			setNum2Digit(0,0,0,0,1,1,0);
			break;
		}
		case 4: {
			setNum2Digit(1,0,0,1,1,0,0);
			break;
		}
		case 5: {
			setNum2Digit(0,1,0,0,1,0,0);
			break;
		}
		case 6: {
			setNum2Digit(0,1,0,0,0,0,0);
			break;
		}
		case 7: {
			setNum2Digit(0,0,0,1,1,1,1);
			break;
		}
		case 8: {
			setNum2Digit(0,0,0,0,0,0,0);
			break;
		}
		case 9: {
			setNum2Digit(0,0,0,0,1,0,0);
			break;
		}
		default: {
			break;
		}
    }
}

int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index) {
	resetAllDigits();
    switch (index) {
        case 0:{
            // Display the first 7 SEG with led_buffer[0]
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
        	display7SEG(led_buffer[0]);
            break;
        }
        case 1:{
            // Display the second 7 SEG with led_buffer[1]
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
        	display7SEG(led_buffer[1]);
            break;
        }
        case 2:{
            // Display the third 7 SEG with led_buffer[2]
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
        	display7SEG(led_buffer[2]);
            break;
        }
        case 3:{
            // Display the fourth 7 SEG with led_buffer[3]
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
        	display7SEG(led_buffer[3]);
            break;
        }
        default:{
            break;
        }
    }
}

void BufferHorizontal(int value) {
	led_buffer[0] = (value / 10) % 10;
	led_buffer[1]= value % 10;
}
void BufferVertical(int value) {
	led_buffer[2] = (value / 10) % 10;
	led_buffer[3]= value % 10;
}

int idx = 0;
void autoUpdate7Seg() {
	update7SEG(idx++);
	if (idx >= 4){
		idx = 0;
	}
}

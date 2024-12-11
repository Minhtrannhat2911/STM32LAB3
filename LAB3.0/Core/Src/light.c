/*
 * light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */
#include "light.h"
#include "main.h"
int redTime = 5;
int yellowTime = 2;
int greenTime = 3;



void Green_Red() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
}
void Yellow_Red() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
}
void Red_Green() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
}
void Red_Yellow() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
}

void timeredupdate() {
	if (redTime < 99) {
		redTime++;
	}
}
void timegreenupdate() {
	if (redTime < 99) {
		greenTime++;

	}
}
void timeyellowupdate() {
	if (yellowTime < 99) {
		yellowTime++;

	}
}

void setRedTime(int redValue) {
	redTime = redValue;
}
void setYellowTime(int yellowValue) {
	yellowTime = yellowValue;
}
void setGreenTime(int greenValue) {
	greenTime = greenValue;
}

void clearTrafficLight() {
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
}

void blinkRedLed() {
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_TogglePin(D1_GPIO_Port, D1_Pin);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
}
void blinkYellowLed() {
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
}
void blinkGreenLed() {
	HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
}

void blinkAllLed() {
	HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
	HAL_GPIO_TogglePin(D1_GPIO_Port, D1_Pin);
	HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
	HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
	HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
	HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
}

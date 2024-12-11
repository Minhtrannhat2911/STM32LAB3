/*
 * 7LED.h
 *
 *  Created on: Nov 13, 2024
 *      Author: Dell
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include "main.h"

void resetAllDigits();
void setDigit(int digitSerial);
void setNum2Digit(int a, int b, int c, int d, int e, int f, int g);
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int hour, int minute);
void BufferHorizontal(int value);
void BufferVertical(int value);
void autoUpdate7Seg();

#endif /* INC_7SEG_H_ */

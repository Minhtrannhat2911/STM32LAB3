/*
 * light.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */

#ifndef INC_LIGHT_H_
#define INC_LIGHT_H_

#include "main.h"

extern int redTime;
extern int yellowTime;
extern int greenTime;

void Green_Red();
void Yellow_Red();
void Red_Green();
void Red_Yellow();

void setRedTime(int redValue);
void setYellowTime(int yellowValue);
void setGreenTime(int greenValue);

void timeredupdate();
void timegreenupdate();
void timeyellowupdate();

void blinkRedLed();
void blinkYellowLed();
void blinkGreenLed();

void blinkAllLed();

void clearTrafficLight();

#endif /* INC_LIGHT_H_ */

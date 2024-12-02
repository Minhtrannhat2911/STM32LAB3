/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <7SEG.h>
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "light.h"

extern int status;

#define INIT 1
#define AUTO 2
#define MAN 3

#define	RED_GREEN 11
#define GREEN_RED 12
#define	YELLOW_RED 13
#define	RED_YELLOW 14

extern int red_duration;
extern int amber_duration;
extern int green_duration;

#define MODE2 18
#define MODE3 19
#define MODE4 20

#endif /* INC_GLOBAL_H_ */

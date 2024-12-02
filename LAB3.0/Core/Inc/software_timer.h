/*
 * software_timer.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

/*
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;

void settimer1(int duration);
void settimer2(int duration);
void settimer3(int duration);
void settimer4(int duration);
void timerun();
*/
extern int timer_flag[];
extern int timer_counter[];
extern int TIMER_CYCLE;
void setTimer(int index, int counter);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */

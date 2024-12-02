/*
 * software_timer.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Dell
 */


/*
 * timer.c
 *
 *  Created on: Oct 2, 2024
 *      Author: Dell
 */
#include "software_timer.h"

/*
int time_cycle = 10;
int time_counter1 = 0;
int time_counter2 = 0;
int time_counter3 = 0;
int time_counter4 = 0;
int timer1_flag = 0;
int timer2_flag = 0;
int timer3_flag = 0;
int timer4_flag = 0;

void settimer1(int duration){
	time_counter1 = duration/time_cycle;
	timer1_flag = 0;
}
void settimer2(int duration){
	time_counter2 = duration;
	timer2_flag = 0;
}
void settimer3(int duration){
	time_counter3 = duration;
	timer3_flag = 0;
}
void settimer4(int duration){
	time_counter4 = duration/time_cycle;
	timer4_flag = 0;
}
void timerun(){
	if(time_counter1 > 0){
		time_counter1--;
		if(time_counter1 <= 0){
			timer1_flag=1;
		}
	}
	if(time_counter2 > 0){
		time_counter2--;
		if(time_counter2 <= 0){
			timer2_flag = 1;
		}
	}
	if(time_counter3 > 0){
		time_counter3--;
		if(time_counter3 <= 0){
			timer3_flag = 1;
		}
	}
	if(time_counter4 > 0){
		time_counter4--;
		if(time_counter4 <= 0){
			timer4_flag = 1;
		}
	}
}
*/

int TIMER_CYCLE = 10;
void setTimer(int index, int counter){
	timer_flag[index] = 0;
	timer_counter[index] = counter / TIMER_CYCLE;
}

int timer_flag[10];
int timer_counter[10];
void timerRun(){
	for (int i = 0; i < 10; i++) {
		if (timer_counter[i] >= 0) {
			timer_counter[i]--;
			if (timer_counter[i] <= 0) {
				timer_flag[i] = 1;
			}
		}
	}
}

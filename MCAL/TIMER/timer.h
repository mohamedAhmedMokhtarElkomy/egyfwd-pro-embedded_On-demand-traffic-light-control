/*
 * timer.h
 *
 * Created: 9/12/2022 7:32:49 PM
 *  Author: admin
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

void TIMER0_init();
void TIMER0_start();
void TIMER0_wait();
void TIMER0_clearOverFlow();
void TIMER0_stop();



#endif /* TIMER_H_ */
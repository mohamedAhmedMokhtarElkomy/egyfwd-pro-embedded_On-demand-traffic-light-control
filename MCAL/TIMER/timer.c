/*
 * timer.c
 *
 * Created: 9/12/2022 7:32:37 PM
 *  Author: admin
 */ 

#include "timer.h"

void TIMER0_init()
{
	//Timer choose timer mode
	TCCR0 = 0x00;
	//TIMER set initial value
	TCNT0 = 0x00;
	
	
}
void TIMER0_start()
{
	//Timer start by setting prescaler -> timer start one prescaler is set to 1
	TCCR0 |= (1<<0); //No prescaler
	//TCCR0 |= (1<<2); //No prescaler
}
void TIMER0_wait()
{
	//wait until overflow
	while((TIFR & (1<<0)) == 0);
}

void TIMER0_clearOverFlow()
{
	TIFR |= (1<<0);
}
void TIMER0_stop()
{
	TCCR0 = 0x00;
}
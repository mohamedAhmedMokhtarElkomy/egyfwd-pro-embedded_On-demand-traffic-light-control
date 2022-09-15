/*
 * On-demand-traffic-light-control.c
 *
 * Created: 9/12/2022 10:37:56 AM
 * Author : admin
 */ 

#include "Application/application.h"
#include "MCAL/TIMER/timer.h"
EN_DIO_STATUS status;


int currentLed = 2;

int tempCount = 0;


int main(void)
{
	APP_init();
	APP_start();

}


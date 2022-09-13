/*
 * On-demand-traffic-light-control.c
 *
 * Created: 9/12/2022 10:37:56 AM
 * Author : admin
 */ 

#include "Application/application.h"

EN_DIO_STATUS status;
int main(void)
{
	//APP_init();
	
	status = LED_init(PORT_A, 0);
	status = LED_on(PORT_A, 0);
	status = LED_off(PORT_A, 0);
	
	
	//while (1) 
    //{
		//APP_start();
    //}
}


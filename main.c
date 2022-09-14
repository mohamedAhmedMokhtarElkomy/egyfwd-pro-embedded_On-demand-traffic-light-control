/*
 * On-demand-traffic-light-control.c
 *
 * Created: 9/12/2022 10:37:56 AM
 * Author : admin
 */ 

#include "Application/application.h"
#include "MCAL/TIMER/timer.h"
EN_DIO_STATUS status;

unsigned long long nOfOverflow = 1;

int main(void)
{
	APP_init();
	APP_start();
	/**
	status = LED_init(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	status = LED_init(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
	status = LED_init(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
	
	status = LED_on(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	status = LED_on(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
	
	status = BUTTON_init(BUTTON_PEDESTRIAN_PORT, BUTTON_PEDESTRIAN_PIN);
	
	uint8_t buttonValue = 0;
	
	TIMER0_init();
	while (1) 
    {
		//APP_start();
		
		//status = BUTTON_read(PORT_C, 0, &buttonValue);
		//if(buttonValue == HIGH)
			//status = LED_on(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
		//else 
			//status - LED_off(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
		
		
		PORTA ^= (1<<LED_TRAFFIC_GREEN_PIN);
		
		nOfOverflow = 11961;
		while(nOfOverflow > 0)
		{
			TIMER0_start();
			TIMER0_wait();
			TIMER0_clearOverFlow();
			TIMER0_stop();			
			nOfOverflow--;
		}
		

		LED_off(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
		nOfOverflow = 14285;
		while(nOfOverflow > 0)
		{
			TIMER0_start();
			TIMER0_wait();
			TIMER0_clearOverFlow();
			TIMER0_stop();			
			nOfOverflow--;
		}
		
    }
	**/
}


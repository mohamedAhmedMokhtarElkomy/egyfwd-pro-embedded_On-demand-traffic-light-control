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
	
	status = LED_init(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	status = LED_init(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
	status = LED_init(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
	
	status = LED_on(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	status = LED_on(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
	
	status = BUTTON_init(BUTTON_PEDESTRIAN_PORT, BUTTON_PEDESTRIAN_PIN);
	
	uint8_t buttonValue = 0;
	
	while (1) 
    {
		//APP_start();
		
		status = BUTTON_read(PORT_C, 0, &buttonValue);
		if(buttonValue == HIGH)
			status = LED_on(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
		else 
			status - LED_off(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);

    }
}


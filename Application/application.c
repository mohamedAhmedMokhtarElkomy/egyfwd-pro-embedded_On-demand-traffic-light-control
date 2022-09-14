/*
 * application.c
 *
 * Created: 9/12/2022 10:53:40 AM
 *  Author: admin
 */ 

#include "application.h"

#define NUMBER_OF_LEDS 3
uint8_t led_number = 0;

void APP_init()
{
	BUTTON_init(BUTTON_PEDESTRIAN_PORT, BUTTON_PEDESTRIAN_PIN);
	
	LED_init(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	LED_init(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
	LED_init(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
	
	//Enable global interrupts - setting bit 7 in the status register to 1
	sei();
	
	// Choose the external interrupt sense - sense on rising edge
	MCUCR |= (1<<0) | (1<<1);
	
	
	// Enable External interrupt 0 - INT0
	GICR |= (1<<6);
	
}
void APP_start()
{
	while(1)
	{
		switch(led_number)
		{
			case 0:
				LED_off(LEDS_PORT, LED_TRAFFIC_RED_PIN);
				LED_off(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
				LED_off(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
			break;
			case 1:
				LED_on(LEDS_PORT, LED_TRAFFIC_RED_PIN);
			break;
			case 2:
				LED_on(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
			break;
			case 3:
				LED_on(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
			break;
		}
	}
}

ISR(EXT_INT_0)
{
	if(led_number < NUMBER_OF_LEDS)
	{
		led_number++;
	}
	else
	{
		led_number = 0;
	}
}
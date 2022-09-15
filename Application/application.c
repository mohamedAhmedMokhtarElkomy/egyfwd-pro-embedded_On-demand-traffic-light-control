/*
 * application.c
 *
 * Created: 9/12/2022 10:53:40 AM
 *  Author: admin
 */ 

#include "application.h"

//#define NUMBER_OF_LEDS 3

int pedestrianStatus = 0;		//it show status of pedestrian light is is changed in ISE
int currentTrafficLed = 0;		//current traffic led
unsigned int nOfOverflow = 18000;

inline void PedestrianMode()
{
	//If traffic light is red don't change in traffic lights
//	if(currentTrafficLed == LED_PEDESTRIAN_RED_PIN)
	//	LED_off(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_RED_PIN);
	//else if(currentTrafficLed == 2)
		//LED_off(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
	
	switch(currentTrafficLed)
	{
		case 0:
			LED_off(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
			LED_on(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
		break;
		
		case 1:
		break;
		
		case 2:
			
		break;
	}
	
	//TURN off pedestrian red light off and yellow on
	LED_off(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_RED_PIN);
	LED_on(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_YELLOW_PIN);
	
	
	//used to iterate timer 0 overflow many times until time = 5 sec
	nOfOverflow = 18000;
	
	//Start timer 0 and iterate number of overflows until time = 5 seconds
	while(nOfOverflow--)
	{
		TIMER0_start();
		TIMER0_wait();
		TIMER0_clearOverFlow();
		TIMER0_stop();
	}
	
	//TURN off pedestrian yellow light off and green on
	LED_off(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_YELLOW_PIN);
	LED_on(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_GREEN_PIN);
	
	//TURN off traffic yellow and on the red traffic
	LED_off(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
	LED_on(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	
	//used to iterate timer 0 overflow many times until time = 5 sec
	nOfOverflow = 18000;
	
	//Start timer 0 and iterate number of overflows until time = 5 seconds
	while(nOfOverflow--)
	{
		TIMER0_start();
		TIMER0_wait();
		TIMER0_clearOverFlow();
		TIMER0_stop();
	}
	
	//TURN OFF pedestrian green and turn on red led
	LED_off(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_GREEN_PIN);
	LED_on(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_RED_PIN);
	
	//TURN off traffic yellow and on the green traffic
	LED_off(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	LED_on(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);
	
	//TODO re open interrupt and remove pedestrian status
	pedestrianStatus = 0;
	nOfOverflow = -1;
	return;
}

void APP_init()
{
	// INIT Traffic LEDS as output
	LED_init(LEDS_PORT, LED_TRAFFIC_RED_PIN);
	LED_init(LEDS_PORT, LED_TRAFFIC_YELLOW_PIN);
	LED_init(LEDS_PORT, LED_TRAFFIC_GREEN_PIN);

	// INIT Pedestrian LEDS as output
	LED_init(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_RED_PIN);
	LED_init(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_YELLOW_PIN);
	LED_init(LEDS_PEDESTRIAN_PORT, LED_PEDESTRIAN_GREEN_PIN);
	
	// INIT button pin as input
	BUTTON_init(BUTTON_PEDESTRIAN_PORT, BUTTON_PEDESTRIAN_PIN);

	//Enable global interrupts - setting bit 7 in the status register to 1
	sei();
	
	// Choose the external interrupt sense - sense on rising edge
	MCUCR |= (1<<0) | (1<<1);
	
	
	// Enable External interrupt 0 - INT0
	GICR |= (1<<6);
	
	// INIT timer 0 registers
	TIMER0_init();
	
}
void APP_start()
{
	while(1)
	{
		//Always start the cycle with green led on
		LED_on(LEDS_PORT, currentTrafficLed);
		LED_on(LEDS_PEDESTRIAN_PORT, LED_TRAFFIC_RED_PIN);
		
		//used to iterate timer 0 overflow many times until time = 5 sec
		nOfOverflow = 18000;	
		
		//Start timer 0 and iterate number of overflows until time = 5 seconds
		while(nOfOverflow > 0)
		{
			TIMER0_start();
			TIMER0_wait();
			TIMER0_clearOverFlow();
			TIMER0_stop();
			nOfOverflow--;
		}
		//Turn off current traffic led
		LED_off(LEDS_PORT, currentTrafficLed);
		
		//increment current traffic led between 0 -> 2
		currentTrafficLed = ((currentTrafficLed + 1) % 3);
	}
}

//Create Interrupt Service Routine for PEDESTRIAN button
ISR(EXT_INT_0)
{
	if(pedestrianStatus == 0){	
		pedestrianStatus = 1;
		
		//TODO close interrupt
		PedestrianMode();
	
	}
	
}
/*
 * LED.h
 *
 * Created: 9/12/2022 10:47:49 AM
 *  Author: admin
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"	//Upper layer include lower layer

#define LEDS_PORT PORT_A
#define LED_TRAFFIC_RED_PIN		2
#define LED_TRAFFIC_YELLOW_PIN	1
#define LED_TRAFFIC_GREEN_PIN	0

#define LEDS_PEDESTRIAN_PORT PORT_B
#define LED_PEDESTRIAN_RED_PIN		2
#define LED_PEDESTRIAN_YELLOW_PIN	1
#define LED_PEDESTRIAN_GREEN_PIN	0



typedef enum EN_LED_STATUS
{
	LED_INIT_OK,
	LED_INIT_FAILED,
	LED_ON_OK,
	LED_ON_FAILED,
	LED_OFF_OK,
	LED_OFF_FAILED,
	
}EN_LED_STATUS;

EN_LED_STATUS LED_init(uint8_t ledPort, uint8_t ledPin);
EN_LED_STATUS LED_on(uint8_t ledPort, uint8_t ledPin);
EN_LED_STATUS LED_off(uint8_t ledPort, uint8_t ledPin);

void LED_toggle(uint8_t ledPort, uint8_t ledPin);



#endif /* LED_H_ */
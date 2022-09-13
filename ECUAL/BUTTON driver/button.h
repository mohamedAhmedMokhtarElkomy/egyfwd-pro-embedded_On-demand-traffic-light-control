/*
 * button.h
 *
 * Created: 9/12/2022 10:48:14 AM
 *  Author: admin
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"	//Upper layer include lower layer


#define PEDESTRIAN_BUTTON_PORT PORT_C
#define PEDESTRIAN_BUTTON_PIN 0

typedef enum EN_BUTTON_STATUS
{
	BUTTON_INIT_OK,
	BUTTON_INIT_FAILED,
	
	BUTTON_READ_OK,
	BUTTON_READ_FAILED,
	
}EN_BUTTON_STATUS;

EN_BUTTON_STATUS BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
EN_BUTTON_STATUS BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);



#endif /* BUTTON_H_ */
/*
 * button.c
 *
 * Created: 9/12/2022 10:48:26 AM
 *  Author: admin
 */ 

#include "button.h"

EN_BUTTON_STATUS BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	if(DIO_init(buttonPin, buttonPort, INPUT) == DIO_INIT_OK)
		return BUTTON_INIT_OK;
	return BUTTON_INIT_FAILED;
}
EN_BUTTON_STATUS BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	if(DIO_read(buttonPin, buttonPort, value) == DIO_READ_OK)
		return BUTTON_READ_OK;
	return BUTTON_READ_FAILED;

}
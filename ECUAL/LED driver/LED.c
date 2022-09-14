/*
 * LED.c
 *
 * Created: 9/12/2022 10:47:40 AM
 *  Author: admin
 */ 

#include "led.h"

EN_LED_STATUS LED_init(uint8_t ledPort, uint8_t ledPin)
{
	if(DIO_init(ledPin, ledPort, OUTPUT) == DIO_INIT_OK)
		return LED_INIT_OK;
	return LED_INIT_FAILED;
}
EN_LED_STATUS LED_on(uint8_t ledPort, uint8_t ledPin)
{
	if(DIO_write(ledPin, ledPort, HIGH) == DIO_WRITE_OK)
		return LED_ON_OK;
	return LED_ON_FAILED;
}
EN_LED_STATUS LED_off(uint8_t ledPort, uint8_t ledPin)
{
	if(DIO_write(ledPin, ledPort, LOW) == DIO_WRITE_OK)
		return LED_OFF_OK;
	return LED_OFF_FAILED;
}

void LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	ledPort ^= (1<<ledPin);
}
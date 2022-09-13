/*
 * dio.c
 *
 * Created: 9/12/2022 10:46:48 AM
 *  Author: admin
 */ 

#include "dio.h"

EN_DIO_STATUS checkDir(uint8_t *pinRegister, uint8_t direction, uint8_t pinNumber)
{
	if(direction == INPUT){
		CLEAR_BIT(*pinRegister, pinNumber);	//SET PIN NUMBER AS INPUT
	}
	else if(direction == OUTPUT){		
		SET_BIT(*pinRegister, pinNumber);	//SET PIN NUMBER AS OUTPUT
	}
	else
		return DIO_WRONG_PORT_DIRECTION;
	
	return DIO_RIGHT_PORT_DIRECTION;
		
}

EN_DIO_STATUS checkValue(uint8_t *pinRegister, uint8_t value, uint8_t pinNumber)
{
	if(value == LOW)
		CLEAR_BIT(*pinRegister, pinNumber);	//SET PIN NUMBER AS INPUT
	else if(value == HIGH)
		SET_BIT(*pinRegister, pinNumber);	//SET PIN NUMBER AS OUTPUT
	else
		return DIO_WRONG_WRITE_VALUE;
	
	return DIO_RIGHT_WRITE_VALUE;
	
}


EN_DIO_STATUS DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	EN_DIO_STATUS dirStatus = DIO_INIT_FAILED;
	
	if (pinNumber > 7)
		return DIO_WRONG_PIN_NUMBER;
	
	switch (portNumber)
	{
		case PORT_A:
			dirStatus = checkDir(&DDRA, direction, pinNumber);
		break;
		
		case PORT_B:
			dirStatus = checkDir(&DDRB, direction, pinNumber);
		break;
		
		case PORT_C:
			dirStatus = checkDir(&DDRC, direction, pinNumber);
		break;
		
		case PORT_D:
			dirStatus = checkDir(&DDRD, direction, pinNumber);
		break;
		
		default:
			return DIO_WRONG_PORT_NUMBER;
		break;
	}
	
	if(dirStatus == DIO_WRONG_PORT_DIRECTION)
		return dirStatus;
	
	return DIO_INIT_OK;
}

EN_DIO_STATUS DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	if (pinNumber > 7)
		return DIO_WRONG_PIN_NUMBER;
		
	EN_DIO_STATUS valueStatus;
	
	switch (portNumber)
	{
		case PORT_A:
			valueStatus = checkValue(&PORTA, value, pinNumber);
		break;
		
		case PORT_B:
			valueStatus = checkValue(&PORTA, value, pinNumber);
		break;
		
		case PORT_C:
			valueStatus = checkValue(&PORTA, value, pinNumber);
		break;
		
		case PORT_D:
			valueStatus = checkValue(&PORTA, value, pinNumber);
		break;
		
		default:
			return DIO_WRONG_PORT_NUMBER;
		break;
	}
	
	if(valueStatus == DIO_WRONG_WRITE_VALUE)
		return valueStatus;
	
	return DIO_WRITE_OK;
}
EN_DIO_STATUS DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	if (pinNumber > 7)
		return DIO_WRONG_PIN_NUMBER;
		
	switch(portNumber)
	{
		case PORT_A:
			*value = READ_BIT(PINA, pinNumber);
		break;
		case PORT_B:
			*value = READ_BIT(PINB, pinNumber);
		break;
		case PORT_C:
			*value = READ_BIT(PINC, pinNumber);
		break;
		case PORT_D:
			*value = READ_BIT(PIND, pinNumber);
		break;
		default:
			return DIO_WRONG_PORT_NUMBER;
		break;
	}
	
	return DIO_READ_OK;
}


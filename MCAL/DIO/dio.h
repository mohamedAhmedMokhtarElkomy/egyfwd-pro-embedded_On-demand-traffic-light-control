/*
 * dio.h
 *
 * Created: 9/12/2022 10:46:58 AM
 *  Author: admin
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/typedef.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

typedef enum EN_DIO_STATUS 
{
	DIO_INIT_OK ,
	DIO_INIT_FAILED,
	DIO_WRITE_OK,
	DIO_WRITE_FAILED,
	DIO_READ_OK,
	DIO_READ_FAILED,
	DIO_RIGHT_PORT_NUMBER,
	DIO_WRONG_PORT_NUMBER,
	DIO_RIGHT_PORT_DIRECTION,
	DIO_WRONG_PORT_DIRECTION,
	DIO_RIGHT_WRITE_VALUE,
	DIO_WRONG_WRITE_VALUE,
	DIO_RIGHT_READ_VALUE,
	DIO_WRONG_READ_VALUE,
	DIO_WRONG_PIN_NUMBER
}EN_DIO_STATUS;

//define macros for easily readable

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define INPUT	0
#define OUTPUT	1

#define LOW		0
#define HIGH	1

//initialize DIO PIN
EN_DIO_STATUS DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);

//write on DIO PIN
EN_DIO_STATUS DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

//read from DIO PIN
//*value to return value in pointer and function return error handling
EN_DIO_STATUS DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);




#endif /* DIO_H_ */
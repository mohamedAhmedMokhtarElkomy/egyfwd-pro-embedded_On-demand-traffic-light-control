/*
 * registers.h
 *
 * Created: 9/12/2022 10:49:53 AM
 *  Author: admin
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "typedef.h"

//PORTX	=====> used to write data on pin
//DDRX	=====> used to set direction for pins as input or output
//PINX	=====> used to read data from pin
//TIFR	=====> Timer/Counter Interrupt Flag Register, it hold timer interrupt flag
//TCCR0	=====> Timer/Counter control register
//TCNT0	=====> Timer/Counter Register that counts from 0 to FF or 0 to FFFF

//PORTA REGISTERS
#define PORTA *((volatile uint8_t*) 0x3B)	//8-bit register
#define DDRA *((volatile uint8_t*) 0x3A)	//8-bit register
#define PINA *((volatile uint8_t*) 0x39)	//8-bit register

//PORTB REGISTERS
#define PORTB *((volatile uint8_t*) 0x38)	//8-bit register
#define DDRB *((volatile uint8_t*) 0x37)	//8-bit register
#define PINB *((volatile uint8_t*) 0x36)	//8-bit register

//PORTC REGISTERS
#define PORTC *((volatile uint8_t*) 0x35)	//8-bit register
#define DDRC *((volatile uint8_t*) 0x34)	//8-bit register
#define PINC *((volatile uint8_t*) 0x33)	//8-bit register

//PORTD REGISTERS
#define PORTD *((volatile uint8_t*) 0x32)	//8-bit register
#define DDRD *((volatile uint8_t*) 0x31)	//8-bit register
#define PIND *((volatile uint8_t*) 0x30)	//8-bit register

//TIMER0 REGISTERS
#define TIFR *((volatile uint8_t*) 0x58)	//8-bit register
#define TCCR0 *((volatile uint8_t*) 0x53)	//8-bit register
#define TCNT0 *((volatile uint8_t*) 0x52)	//8-bit register



#endif /* REGISTERS_H_ */
/*
 * bit_manipulation.h
 *
 * Created: 9/12/2022 10:52:56 AM
 *  Author: admin
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_


#define CLEAR_BIT(reg, pinNumber) reg &= ~(1<<pinNumber)
#define SET_BIT(reg, pinNimber) reg |= (1<<pinNumber)
#define READ_BIT(reg, pinNumber) ({ (reg & (1<<pinNumber))>>pinNumber; })


#endif /* BIT_MANIPULATION_H_ */
/*
 * interrupt.h
 *
 * Created: 9/14/2022 10:21:49 AM
 *  Author: admin
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/* External Interrupt Vectors */
/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1

// External Interrupt Request 1
#define EXT_INT_1 __vector_2

// External Interrupt Request 2
#define EXT_INT_2 __vector_3

// Set Global Interrupts, Set the I-bit in status register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// Clear Global Interrupts, Set the I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


#endif /* INTERRUPT_H_ */
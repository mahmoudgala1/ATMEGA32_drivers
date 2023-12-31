/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define GICR *((volatile u8 *)0x5B)
#define GIFR *((volatile u8 *)0x5A)
#define MCUCR *((volatile u8 *)0x55)
#define MCUCSR *((volatile u8 *)0x54)

#endif /* _EXTI_PRIVATE_H_ */

/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GPIO_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : GPIO/GPIO
 *
 */

#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#define F_CPU 8000000UL

// Port Defines
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3

// PIN Defines
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7

// PIN Directions
#define GPIO_PIN_OUTPUT 0x01
#define GPIO_PIN_INPUT 0x00

// PIN Value Options
#define GPIO_PIN_HIGH 0x01
#define GPIO_PIN_LOW 0x00

// PORT Directions
#define GPIO_PORT_OUTPUT 0xFF
#define GPIO_PORT_INPUT 0

// PORT Value Options
#define GPIO_PORT_HIGH 0xFF
#define GPIO_PORT_LOW 0

typedef enum
{
	GPIO_NOK,
	GPIO_OK
} GPIO_ErrorStatus;

GPIO_ErrorStatus GPIO_enumSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PInDirection);
GPIO_ErrorStatus GPIO_enumSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);
GPIO_ErrorStatus GPIO_enumGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Ptr_u8PinValue);
GPIO_ErrorStatus GPIO_enumTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

GPIO_ErrorStatus GPIO_enumSetPortDirection(u8 Copy_u8Port, u8 Copy_u8PrtDirection);
GPIO_ErrorStatus GPIO_enumSetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue);
GPIO_ErrorStatus GPIO_enumGetPortValue(u8 Copy_u8Port, u8 *Ptr_u8PortValue);
GPIO_ErrorStatus GPIO_enumTogglePortValue(u8 Copy_u8Port);

GPIO_ErrorStatus GPIO_enumWriteHighNibbles(u8 Copy_u8Port, u8 Copy_u8Value);
GPIO_ErrorStatus GPIO_enumWriteLowNibbles(u8 Copy_u8Port, u8 Copy_u8Value);

#endif /* _GPIO_INTERFACE_H_ */

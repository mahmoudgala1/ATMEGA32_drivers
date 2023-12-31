/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LED_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : LED
 *
 */

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#define ACTIVE_HIGH 0x01
#define ACTIVE_lOW 0x00

typedef struct
{
    u8 Port;
    u8 Pin;
    u8 Active_State;
} LED_type;

void LED_voidInit(LED_type LED_Configuration);
void LED_voidOn(LED_type LED_Configuration);
void LED_voidOff(LED_type LED_Configuration);
void LED_voidToggle(LED_type LED_Configuration);

#endif /* _LED_INTERFACE_H_ */

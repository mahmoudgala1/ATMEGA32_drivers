/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BUZ_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : BUZ
 *
 */

#ifndef _BUZ_INTERFACE_H_
#define _BUZ_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#define ACTIVE_HIGH 0x01
#define ACTIVE_lOW 0x00

typedef struct
{
    u8 Port;
    u8 Pin;
    u8 Active_State;
} BUZ_type;

void BUZ_voidInit(BUZ_type BUZ_Configuration);
void BUZ_voidOn(BUZ_type BUZ_Configuration);
void BUZ_voidOff(BUZ_type BUZ_Configuration);
void BUZ_voidToggle(BUZ_type BUZ_Configuration);

#endif /* _BUZ_INTERFACE_H_ */

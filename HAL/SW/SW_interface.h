/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : SW
 *
 */

#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_

#include "../../lib/STD_TYPES.h"

#define SW_PULL_UP 0x00
#define SW_PULL_DOWN 0x01

#define SW_PRESSED 0x01
#define SW_RELESED 0x00

typedef struct
{
    u8 Port;
    u8 Pin;
    u8 PullState;
} SW_Type;

void SW_voidInit(SW_Type SW_Config);
u8 SW_u8GetPressed(SW_Type SW_Config);

#endif /* _SW_INTERFACE_H_ */
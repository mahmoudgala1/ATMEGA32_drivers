/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define EXTI_0 0x06
#define EXTI_1 0x07
#define EXTI_2 0x05

#define EXTI_FALLING_EDGE 0
#define EXTI_RISING_EDGE 1
#define EXTI_LOW_LEVEL 2
#define EXTI_ON_CHANGE 3

void EXTI_voidInit(u8 Copy_u8Line, u8 Copy_u8SenseMode, void (*Copy_pvoidCallBack)(void));
void EXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8SenseMode);
void EXTI_voidDisableInterrupt(u8 Copy_u8Line);
void EXTI_voidEnableInterrupt(u8 Copy_u8Line);
void EXTI_voidClearFlag(u8 Copy_u8Line);
void EXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*Copy_pvoidCallBack)(void));

#endif /* _EXTI_INTERFACE_H_ */

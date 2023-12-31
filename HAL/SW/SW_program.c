/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : SW
 *
 */

#include "SW_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SW_voidInit(SW_Type SW_Config)
{
    GPIO_enumSetPinDirection(SW_Config.Port, SW_Config.Pin, GPIO_PIN_INPUT);
}

u8 SW_u8GetPressed(SW_Type SW_Config)
{
    u8 LOC_u8PinValue = SW_RELESED;
    u8 LOC_u8Result = SW_RELESED;
    GPIO_enumGetPinValue(SW_Config.Port, SW_Config.Pin, &LOC_u8PinValue);
    if (SW_Config.PullState == SW_PULL_UP)
    {
        if (LOC_u8PinValue == 0)
        {
            LOC_u8Result = SW_PRESSED;
        }
        else if (LOC_u8PinValue == 1)
        {
            LOC_u8Result = SW_RELESED;
        }
    }
    else if (SW_Config.PullState == SW_PULL_DOWN)
    {
        if (LOC_u8PinValue == 0)
        {
            LOC_u8Result = SW_RELESED;
        }
        else if (LOC_u8PinValue == 1)
        {
            LOC_u8Result = SW_PRESSED;
        }
    }
    return LOC_u8Result;
}

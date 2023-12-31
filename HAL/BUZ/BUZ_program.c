/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BUZ_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : BUZ
 *
 */

#include "BUZ_config.h"
#include "BUZ_private.h"
#include "BUZ_interface.h"


void BUZ_voidInit(BUZ_type BUZ_Configuration)
{
    GPIO_enumSetPinDirection(BUZ_Configuration.Port, BUZ_Configuration.Pin, GPIO_PIN_OUTPUT);
}

void BUZ_voidOn(BUZ_type BUZ_Configuration)
{
    if (BUZ_Configuration.Active_State == ACTIVE_HIGH)
    {
        GPIO_enumSetPinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin, GPIO_PIN_HIGH);
    }
    else if (BUZ_Configuration.Active_State == ACTIVE_lOW)
    {
        GPIO_enumSetPinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin, GPIO_PIN_LOW);
    }
}

void BUZ_voidOff(BUZ_type BUZ_Configuration)
{
    if (BUZ_Configuration.Active_State == ACTIVE_HIGH)
    {
        GPIO_enumSetPinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin, GPIO_PIN_LOW);
    }
    else if (BUZ_Configuration.Active_State == ACTIVE_lOW)
    {
        GPIO_enumSetPinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin, GPIO_PIN_HIGH);
    }
}

void BUZ_voidToggle(BUZ_type BUZ_Configuration)
{
    GPIO_enumTogglePinValue(BUZ_Configuration.Port, BUZ_Configuration.Pin);
}
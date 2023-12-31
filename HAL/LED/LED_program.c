/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LED_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : LED
 *
 */

#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"


void LED_voidInit(LED_type LED_Configuration)
{
    GPIO_enumSetPinDirection(LED_Configuration.Port, LED_Configuration.Pin, GPIO_PIN_OUTPUT);
}

void LED_voidOn(LED_type LED_Configuration)
{
    if (LED_Configuration.Active_State == ACTIVE_HIGH)
    {
        GPIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, GPIO_PIN_HIGH);
    }
    else if (LED_Configuration.Active_State == ACTIVE_lOW)
    {
        GPIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, GPIO_PIN_LOW);
    }
}

void LED_voidOff(LED_type LED_Configuration)
{
    if (LED_Configuration.Active_State == ACTIVE_HIGH)
    {
        GPIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, GPIO_PIN_LOW);
    }
    else if (LED_Configuration.Active_State == ACTIVE_lOW)
    {
        GPIO_enumSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, GPIO_PIN_HIGH);
    }
}

void LED_voidToggle(LED_type LED_Configuration)
{
    GPIO_enumTogglePinValue(LED_Configuration.Port, LED_Configuration.Pin);
}
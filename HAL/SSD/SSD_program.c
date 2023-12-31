/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : SSD
 *
 */

#include "SSD_interface.h"
#include "SSD_private.h"

static u8 Local_u8SSDNumbers[10] = SSD_NMUBER_ARR;

void SSD_voidInitDataPort(SSD_Type Copy_structConfig)
{
    GPIO_enumSetPortDirection(Copy_structConfig.DataPort, GPIO_PORT_OUTPUT);
}

void SSD_voidEnable(SSD_Type Copy_structConfig)
{
    if (Copy_structConfig.Type == COMMON_ANODE)
    {
        GPIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_OUTPUT);
        GPIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_HIGH);
    }
    else if (Copy_structConfig.Type == COMMON_CATHOD)
    {
        GPIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_OUTPUT);
        GPIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_LOW);
    }
}

void SSD_voidInitDisable(SSD_Type Copy_structConfig)
{
    if (Copy_structConfig.Type == COMMON_ANODE)
    {
        GPIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_OUTPUT);
        GPIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_LOW);
    }
    else if (Copy_structConfig.Type == COMMON_CATHOD)
    {
        GPIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_OUTPUT);
        GPIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, GPIO_PIN_HIGH);
    }
}

void SSD_voidSendNumber(SSD_Type Copy_structConfig, u8 Copy_u8Number)
{
    if (Copy_structConfig.Type == COMMON_ANODE)
    {
        GPIO_enumSetPortValue(Copy_structConfig.DataPort, ~(Local_u8SSDNumbers[Copy_u8Number]));
    }
    else if (Copy_structConfig.Type == COMMON_CATHOD)
    {
        GPIO_enumSetPortValue(Copy_structConfig.DataPort, Local_u8SSDNumbers[Copy_u8Number]);
    }
}

void SSD_voidWithDecoder(u8 Copy_u8Port, u8 Copy_u8Number, u8 PinOrder)
{
    if (PinOrder == LOW_NIBBLES)
    {
        GPIO_enumWriteLowNibbles(Copy_u8Port, Copy_u8Number);
    }
    else if (PinOrder == HIGH_NIBBLES)
    {
        GPIO_enumWriteHighNibbles(Copy_u8Port, Copy_u8Number);
    }
}
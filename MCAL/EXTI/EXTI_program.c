/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_progrem.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */

#include "../../LIB/BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void (*EXTI_CallBack[3])(void) = {NULL};

void EXTI_voidInit(u8 Copy_u8Line, u8 Copy_u8SenseMode, void (*Copy_pvoidCallBack)(void))
{
    if ((Copy_u8Line >= EXTI_2) && (Copy_u8Line <= EXTI_1) && (Copy_pvoidCallBack != NULL))
    {
        GPIO_enumSetPinDirection(GPIO_PORTD, GPIO_PIN2, GPIO_PIN_INPUT);
        EXTI_voidDisableInterrupt(Copy_u8Line);
        EXTI_voidClearFlag(Copy_u8Line);
        EXTI_voidSetSignalLatch(Copy_u8Line, Copy_u8SenseMode);
        EXTI_voidSetCallBack(Copy_u8Line, Copy_pvoidCallBack);
        EXTI_voidEnableInterrupt(Copy_u8Line);
    }
}

void EXTI_voidDisableInterrupt(u8 Copy_u8Line)
{
    if ((Copy_u8Line >= EXTI_2) && (Copy_u8Line <= EXTI_1))
    {
        CLEAR_BIT(GICR, Copy_u8Line);
    }
}

void EXTI_voidEnableInterrupt(u8 Copy_u8Line)
{
    if ((Copy_u8Line >= EXTI_2) && (Copy_u8Line <= EXTI_1))
    {
        SET_BIT(GICR, Copy_u8Line);
    }
}

void EXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8SenseMode)
{
    if ((Copy_u8Line >= EXTI_0) && (Copy_u8Line <= EXTI_1))
    {
        Copy_u8Line = (6 - Copy_u8Line) * -2;
        switch (Copy_u8SenseMode)
        {
        case EXTI_LOW_LEVEL:
            CLEAR_BIT(MCUCR, Copy_u8Line);
            CLEAR_BIT(MCUCR, Copy_u8Line + 1);
            break;
        case EXTI_ON_CHANGE:
            SET_BIT(MCUCR, Copy_u8Line);
            CLEAR_BIT(MCUCR, Copy_u8Line + 1);
            break;
        case EXTI_FALLING_EDGE:
            CLEAR_BIT(MCUCR, Copy_u8Line);
            SET_BIT(MCUCR, Copy_u8Line + 1);
            break;
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR, Copy_u8Line);
            SET_BIT(MCUCR, Copy_u8Line + 1);
            break;
        default:
            break;
        }
    }
    else if (Copy_u8Line == EXTI_2)
    {
        switch (Copy_u8SenseMode)
        {
        case EXTI_FALLING_EDGE:
            CLEAR_BIT(MCUCSR, 6);
            break;
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCSR, 6);
            break;
        default:
            break;
        }
    }
}

void EXTI_voidClearFlag(u8 Copy_u8Line)
{
    if ((Copy_u8Line >= EXTI_2) && (Copy_u8Line <= EXTI_1))
    {
        SET_BIT(GIFR, Copy_u8Line);
    }
}

void EXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*Copy_pvoidCallBack)(void))
{
    if ((Copy_u8EXTILine >= EXTI_2) && (Copy_u8EXTILine <= EXTI_1) && (Copy_pvoidCallBack != NULL))
    {
        switch (Copy_u8EXTILine)
        {
        case EXTI_0:
            EXTI_CallBack[0] = Copy_pvoidCallBack;
            break;
        case EXTI_1:
            EXTI_CallBack[1] = Copy_pvoidCallBack;
            break;
        case EXTI_2:
            EXTI_CallBack[2] = Copy_pvoidCallBack;
            break;
        default:
            break;
        }
    }
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_CallBack[0] != NULL)
    {
        EXTI_CallBack[0](); /*  Call The Global Pointer to Func   */
        EXTI_voidClearFlag(EXTI_0);
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (EXTI_CallBack[1] != NULL)
    {
        EXTI_CallBack[1]();
        EXTI_voidClearFlag(EXTI_1);
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (EXTI_CallBack[2] != NULL)
    {
        EXTI_CallBack[2]();
        EXTI_voidClearFlag(EXTI_2);
    }
}
/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    CLCD_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : CLCD
 *
 */

#include "CLCD_config.h"
#include "CLCD_private.h"
#include "CLCD_interface.h"
#include "CLCD_extrachar.h"

void CLCD_voidInit(void)
{
#if CLCD_MODE == 0x08
    _delay_ms(50);
    GPIO_enumSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN, GPIO_PIN_OUTPUT);
    GPIO_enumSetPortDirection(CLCD_DATA_PORT, GPIO_PORT_OUTPUT);
    CLCD_voidSendCommand(CLCD_RETURN_HOME);
    _delay_ms(1);
    CLCD_voidSendCommand(CLCD_8BIT_MODE_2_LINE);
    _delay_ms(1);
    CLCD_voidSendCommand(CLCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
    _delay_ms(1);
    CLCD_voidClearScreen();
    CLCD_voidSendCommand(CLCD_ENTRY_MODE_INC_SHIFT_OFF);
    _delay_ms(1);
#elif CLCD_MODE == 0x04
    _delay_ms(50);
    GPIO_enumSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(CLCD_DATA_PORT, GPIO_PIN0, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(CLCD_DATA_PORT, GPIO_PIN1, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(CLCD_DATA_PORT, GPIO_PIN2, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(CLCD_DATA_PORT, GPIO_PIN4, GPIO_PIN_OUTPUT);
    CLCD_voidSendCommand(CLCD_RETURN_HOME);
    _delay_ms(1);
    CLCD_voidSendCommand(CLCD_4BIT_MODE_2_LINE);
    _delay_ms(1);
    CLCD_voidSendCommand(CLCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
    _delay_ms(1);
    CLCD_voidClearScreen();
    CLCD_voidSendCommand(CLCD_ENTRY_MODE_INC_SHIFT_OFF);
    _delay_ms(1);
#endif
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
#if CLCD_MODE == 0x08
    GPIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, GPIO_PIN_HIGH);
    GPIO_enumSetPortValue(CLCD_DATA_PORT, Copy_u8Data);
    CLCD_voidSendFallingEdge();
#elif CLCD_MODE == 0x04
    GPIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, GPIO_PIN_HIGH);
    GPIO_enumWriteLowNibbles(CLCD_DATA_PORT, Copy_u8Data >> 4);
    CLCD_voidSendFallingEdge();
    GPIO_enumWriteLowNibbles(CLCD_DATA_PORT, Copy_u8Data);
    CLCD_voidSendFallingEdge();
#endif
    _delay_ms(1);
}

void CLCD_voidSendString(const u8 *Copy_u8ptrString)
{
    while (*Copy_u8ptrString)
    {
        CLCD_voidSendData(*Copy_u8ptrString++);
    }
}

void CLCD_voidSendNumber(u64 Copy_u64Number)
{
    u64 LOC_u64Reversed = 1;
    if (Copy_u64Number == 0)
    {
        CLCD_voidSendData('0');
    }
    else
    {
        while (Copy_u64Number != 0)
        {
            LOC_u64Reversed = (LOC_u64Reversed * 10) + (Copy_u64Number % 10);
            Copy_u64Number /= 10;
        }
        while (LOC_u64Reversed != 1)
        {
            CLCD_voidSendData((LOC_u64Reversed % 10) + 48);
            LOC_u64Reversed /= 10;
        }
    }
}

void CLCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Col)
{

    u8 LOC_u8Iterator = 0;
    CLCD_voidSendCommand(CLCD_CGRAM_START);
    for (LOC_u8Iterator = 0; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]); LOC_u8Iterator++)
    {
        CLCD_voidSendData(CLCD_u8ExtraChar[LOC_u8Iterator]);
    }
    CLCD_voidSetPosition(Copy_u8Row, Copy_u8Col);
    for (LOC_u8Iterator = 0; LOC_u8Iterator < 8; LOC_u8Iterator++)
    {
        CLCD_voidSendData(LOC_u8Iterator);
    }
}

void CLCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col)
{
    Copy_u8Col -= 1;
    switch (Copy_u8Row)
    {
    case CLCD_ROW1:
        CLCD_voidSendCommand((0x80 + Copy_u8Col));
        break;
    case CLCD_ROW2:
        CLCD_voidSendCommand((0xC0 + Copy_u8Col));
        break;
    case CLCD_ROW3:
        CLCD_voidSendCommand((0x94 + Copy_u8Col));
        break;
    case CLCD_ROW4:
        CLCD_voidSendCommand((0xD4 + Copy_u8Col));
        break;
    default:
        break;
    }
}

void CLCD_voidSendCommand(u8 Copy_u8Commend)
{
#if CLCD_MODE == 0x08
    GPIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, GPIO_PIN_LOW);
    GPIO_enumSetPortValue(CLCD_DATA_PORT, Copy_u8Commend);
    CLCD_voidSendFallingEdge();
#elif CLCD_MODE == 0x04
    GPIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, GPIO_PIN_LOW);
    GPIO_enumWriteLowNibbles(CLCD_DATA_PORT, Copy_u8Commend >> 4);
    CLCD_voidSendFallingEdge();
    GPIO_enumWriteLowNibbles(CLCD_DATA_PORT, Copy_u8Commend);
    CLCD_voidSendFallingEdge();
#endif
    _delay_ms(1);
}

void CLCD_voidClearScreen(void)
{
    CLCD_voidSendCommand(CLCD_CLEAR);
    _delay_ms(10);
}

static void CLCD_voidSendFallingEdge(void)
{
    GPIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, GPIO_PIN_HIGH);
    _delay_ms(1);
    GPIO_enumSetPinValue(CLCD_CONTROL_PORT, CLCD_EN, GPIO_PIN_LOW);
    _delay_ms(1);
}
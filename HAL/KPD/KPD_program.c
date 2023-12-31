/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#include "KPD_interface.h"
#include "KPD_config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void KPD_Init(void)
{
    GPIO_enumSetPinDirection(KPD_PORT, KPD_R0, GPIO_PIN_INPUT);
    GPIO_enumSetPinDirection(KPD_PORT, KPD_R1, GPIO_PIN_INPUT);
    GPIO_enumSetPinDirection(KPD_PORT, KPD_R2, GPIO_PIN_INPUT);
    GPIO_enumSetPinDirection(KPD_PORT, KPD_R3, GPIO_PIN_INPUT);

    GPIO_enumSetPinValue(KPD_PORT, KPD_R0, GPIO_PIN_HIGH);
    GPIO_enumSetPinValue(KPD_PORT, KPD_R1, GPIO_PIN_HIGH);
    GPIO_enumSetPinValue(KPD_PORT, KPD_R2, GPIO_PIN_HIGH);
    GPIO_enumSetPinValue(KPD_PORT, KPD_R3, GPIO_PIN_HIGH);

    GPIO_enumSetPinDirection(KPD_PORT, KPD_C0, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(KPD_PORT, KPD_C1, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(KPD_PORT, KPD_C2, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(KPD_PORT, KPD_C3, GPIO_PIN_OUTPUT);

    GPIO_enumSetPinValue(KPD_PORT, KPD_C0, GPIO_PIN_LOW);
    GPIO_enumSetPinValue(KPD_PORT, KPD_C1, GPIO_PIN_LOW);
    GPIO_enumSetPinValue(KPD_PORT, KPD_C2, GPIO_PIN_LOW);
    GPIO_enumSetPinValue(KPD_PORT, KPD_C3, GPIO_PIN_LOW);
}

u8 KPD_u8GetPressed(void)
{
    u8 LOC_u8ReturnData = NOTPRESSED;
    u8 LOC_u8GetPressed;
    u8 LOC_u8Row;
    u8 LOC_u8Col;
    for (LOC_u8Col = 0 + KPD_COL_INIT; LOC_u8Col < KPD_COL_END + 1; LOC_u8Col++)
    {
        GPIO_enumSetPinValue(KPD_PORT, LOC_u8Col, GPIO_PIN_LOW);
        for (LOC_u8Row = 0 + KPD_ROW_INIT; LOC_u8Row < KPD_ROW_END + 1; LOC_u8Row++)
        {
            GPIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
            if (LOC_u8GetPressed == 0)
            {
                _delay_ms(50);
                GPIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
                if (LOC_u8GetPressed == 0)
                {
                    LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT];
                }
                GPIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
                while (GPIO_PIN_LOW == LOC_u8GetPressed)
                {
                    GPIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
                }
                break;
            }
        }
        GPIO_enumSetPinValue(KPD_PORT, LOC_u8Col, GPIO_PIN_HIGH);
    }
    return LOC_u8ReturnData;
}
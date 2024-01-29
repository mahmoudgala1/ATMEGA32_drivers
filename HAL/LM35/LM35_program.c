/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_program.C    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : LM35
 *
 */

#include "LM35_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

u8 LM35_u8GetTemp(LM35_CONFIG *lm35, u8 *Copy_u8TempValue)
{
    u8 Local_u8ErrorState = OK;
    u16 Local_u16ADCResult;
    u16 Local_u16AnalogValue;
    if ((NULL != lm35) && (NULL != Copy_u8TempValue))
    {
        u16 Local_u8ADCReference = (lm35->Copy_u8ADCVoltageReference) * 1000;
        ADC_u8GetResultSync(lm35->Copy_u8LM35Channel, &Local_u16ADCResult);
        if (lm35->Copy_u8ADCResolution == ADC_RESOLUTION_10_BIT)
        {
            Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * (u32)Local_u8ADCReference) / 1024UL);
        }
        else if (lm35->Copy_u8ADCResolution == ADC_RESOLUTION_8_BIT)
        {
            Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * (u32)Local_u8ADCReference) / 256UL);
        }
        *Copy_u8TempValue = Local_u16AnalogValue / 10;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}

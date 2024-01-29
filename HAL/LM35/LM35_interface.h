/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : LM35
 *
 */

#ifndef _LM35_INTERFACE_H_
#define _LM35_INTERFACE_H_

#include"../../LIB/STD_TYPES.h"

#define ADC_RESOLUTION_10_BIT 0
#define ADC_RESOLUTION_8_BIT 1

typedef struct
{
    u8 Copy_u8LM35Channel;
    u8 Copy_u8ADCVoltageReference;
    u8 Copy_u8ADCResolution;
} LM35_CONFIG;

u8 LM35_u8GetTemp(LM35_CONFIG *lm35, u8 *Copy_u8TempValue);

#endif /* _LM35_INTERFACE_H_ */
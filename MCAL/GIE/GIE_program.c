/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GIE_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */

#include "GIE_interface.h"
#include "GIE_register.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void GIE_VoidEnable(void)
{
    SET_BIT(SREG, SREG_I);
}
void GIE_VoidDisable(void)
{
    CLEAR_BIT(SREG, SREG_I);
}
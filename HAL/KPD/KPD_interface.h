/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef _KPD_INTERFACE_H_
#define _KPD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define NOTPRESSED 0xFF

void KPD_Init(void);
u8 KPD_u8GetPressed(void);

#endif /* _KPD_INTERFACE_H_ */
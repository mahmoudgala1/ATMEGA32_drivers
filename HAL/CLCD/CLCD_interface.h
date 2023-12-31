/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    CLCD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : CLCD
 *
 */

#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#define CLCD_CLEAR 0X01
#define CLCD_RETURN_HOME 0x02
#define CLCD_ENTRY_MODE_DEC_SHIFT_OFF 0x04
#define CLCD_ENTRY_MODE_DEC_SHIFT_ON 0x05
#define CLCD_ENTRY_MODE_INC_SHIFT_OFF 0x06
#define CLCD_ENTRY_MODE_INC_SHIFT_ON 0x07
#define CLCD_CURSOR_MOVE_SHIFT_LEFT 0x10
#define CLCD_CURSOR_MOVE_SHIFT_RIGHT 0x14
#define CLCD_DISPLAY_SHIFT_LEFT 0x18
#define CLCD_DISPLAY_SHIFT_RIGHT 0x1C
#define CLCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define CLCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON 0x0D
#define CLCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF 0x0E
#define CLCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON 0x0F
#define CLCD_DISPLAY_OFF_CURSOR_OFF 0x08
#define CLCD_8BIT_MODE_2_LINE 0x38
#define CLCD_4BIT_MODE_2_LINE 0x28

#define CLCD_CGRAM_START 0x40
#define CLCD_DDRAM_START 0x80

#define CLCD_ROW1 0x01
#define CLCD_ROW2 0x02
#define CLCD_ROW3 0x03
#define CLCD_ROW4 0x04

#define CLCD_COL_1 0x1
#define CLCD_COL_2 0x2
#define CLCD_COL_3 0x3
#define CLCD_COL_4 0x4
#define CLCD_COL_5 0x5
#define CLCD_COL_6 0x6
#define CLCD_COL_7 0x7
#define CLCD_COL_8 0x8
#define CLCD_COL_9 0x9
#define CLCD_COL_10 0x0A
#define CLCD_COL_11 0x0B
#define CLCD_COL_12 0x0C
#define CLCD_COL_13 0x0D
#define CLCD_COL_14 0x0E
#define CLCD_COL_15 0x0F
#define CLCD_COL_16 0x10

void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Commend);
void CLCD_voidSendString(const u8 *Copy_u8ptrString);
void CLCD_voidSendNumber(u64 Copy_u64Number);
void CLCD_voidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col);
void CLCD_voidSendExtraChar(u8 Copy_u8Row, u8 Copy_u8Col);
void CLCD_voidClearScreen(void);

#endif /* _CLCD_INTERFACE_H_ */
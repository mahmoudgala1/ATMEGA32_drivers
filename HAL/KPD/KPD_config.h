/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_config.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef _KPD_CONFIG_H_
#define _KPD_CONFIG_H_

#define KPD_ROW_INIT GPIO_PIN0
#define KPD_ROW_END GPIO_PIN3

#define KPD_COL_INIT GPIO_PIN4
#define KPD_COL_END GPIO_PIN7

u8 KPD_u8Buttons[4][4] = {{'7', '8', '9', '/'},
                          {'4', '5', '6', '*'},
                          {'1', '2', '3', '-'},
                          {'#', '0', '=', '+'}};

#define KPD_PORT GPIO_PORTB

#define KPD_R0 GPIO_PIN0
#define KPD_R1 GPIO_PIN1
#define KPD_R2 GPIO_PIN2
#define KPD_R3 GPIO_PIN3

#define KPD_C0 GPIO_PIN4
#define KPD_C1 GPIO_PIN5
#define KPD_C2 GPIO_PIN6
#define KPD_C3 GPIO_PIN7

#endif /* _KPD_CONFIG_H_ */
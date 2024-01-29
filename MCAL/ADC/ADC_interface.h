/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "ADC_config.h"

#define ADC_DISABLE 0x00
#define ADC_ENABLE 0x01

#define INT_DISABLE 0x00
#define INT_ENABLE 0x01

#define AREF 0x00
#define AVCC 0x01
#define INTERNAL_2_56 0x03

#define ADC0 0x00
#define ADC1 0x01
#define ADC2 0x02
#define ADC3 0x03
#define ADC4 0x04
#define ADC5 0x05
#define ADC6 0x06
#define ADC7 0x07

#define ADC_Right_Adjust_Result 0x00
#define ADC_Left_Adjust_Result 0x01

#define ADC_PS_2 0X01
#define ADC_PS_4 0X02
#define ADC_PS_8 0X03
#define ADC_PS_16 0X04
#define ADC_PS_32 0X05
#define ADC_PS_64 0X06
#define ADC_PS_128 0X07

#define ADC_SINGLE_CONVERSION 0x00
#define ADC_FREE_RUNNING 0x01
#define ADC_ANALOG_COMPARATOR 0x02
#define ADC_EXTI0 0x03
#define ADC_TIM0_CTC 0x04
#define ADC_TIM0_OVF 0x05
#define ADC_TIM1_CTC_CHANNEL_B 0x06
#define ADC_TIM1_OVF 0x07
#define ADC_TIM1_ICU 0x08

typedef struct
{
    u8 *Channel;
    u16 *Result;
    u8 Size;
    void (*NotificationFunc)(void);
} Chain_t;

void ADC_voidInit(void);
u8 ADC_u8GetResultSync(u8 Copy_u8Channel, u16 *Copy_pu16Result);
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_pu16Reading, void (*Copy_pvNotificationFunc)(void));
u8 ADC_u8StartChainAsynch(Chain_t *Copy_Chain);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
u8 ADC_u8SetPrescaler(u8 Copy_u8Prescaler);
u8 ADC_u8SetChannel(u8 Copy_u8Channel);
void ADC_voidSetRefranceVoltage(u8 Copy_u8RefranceVoltage);
void ADC_voidSetAdjustResult(u8 Copy_u8AdjustResult);
u16 ADC_u16GetResult(u8 Copy_u8AdjustResult);

#endif /* _ADC_INTERFACE_H_ */
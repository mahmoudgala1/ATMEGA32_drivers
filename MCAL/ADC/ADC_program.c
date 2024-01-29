/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */

#include "ADC_interface.h"
#include "ADC_private.h"
#include "../../LIB/BIT_MATH.h"

static u8 ADC_u8State = IDLE;

static u16 *ADC_pu16AsynchConversionResult = NULL;
static void (*ADC_pvNotificationFunc)(void) = NULL;

static u8 ADC_u8ISRState;
static u8 *ADC_pu8ChainChannel;
static u8 ADC_u8ChainSize;
static u8 ADC_u8Index;

void ADC_voidInit(void)
{
#if ADC_STATUS == ADC_ENABLE
    ADC_voidDisable();
    ADC_voidSetRefranceVoltage(ADC_VREF);
    ADC_u8SetPrescaler(ADC_PS);
    ADC_voidSetAdjustResult(ADC_Adjust_Result);
#if INT_STATUS == INT_ENABLE
    ADC_voidInterruptEnable();
#else INT_STATUS == INT_DISABLE
    ADC_voidInterruptDisable();
#endif
    ADC_voidEnable();
#else
    ADC_voidDisable();
#endif
}

u8 ADC_u8GetResultSync(u8 Copy_u8Channel, u16 *Copy_pu16Result)
{
    u8 Local_u8ErrorState = OK;
    u32 Local_u32TimeoutCounter = 0;
    if (NULL != Copy_pu16Result)
    {
        if (IDLE == ADC_u8State)
        {
            ADC_u8State = BUSY;
            ADC_u8SetChannel(Copy_u8Channel);
            SET_BIT(ADCSRA, ADSC);
            while (((GET_BIT(ADCSRA, ADIF)) == 0x00) && (Local_u32TimeoutCounter < ADC_TIMEOUT))
            {
                Local_u32TimeoutCounter++;
            }
            if (Local_u32TimeoutCounter == ADC_TIMEOUT)
            {
                Local_u8ErrorState = TIMEOUT_STATE;
            }
            else
            {
                SET_BIT(ADCSRA, ADIF);
                *Copy_pu16Result = ADC_u16GetResult(ADC_Adjust_Result);
            }
            ADC_u8State = IDLE;
        }
        else
        {
            Local_u8ErrorState = BUSY_STATE;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_pu16Reading, void (*Copy_pvNotificationFunc)(void))
{
    u8 Local_u8ErrorState = OK;
    if ((NULL != Copy_pu16Reading) && (NULL != Copy_pvNotificationFunc))
    {
        if (ADC_u8State == IDLE)
        {
            ADC_u8State = BUSY;
            ADC_u8ISRState = SINGLE_CHANNEL_ASYNCH;
            ADC_u8SetChannel(ADC_CHANNEL);
            ADC_pu16AsynchConversionResult = Copy_pu16Reading;
            ADC_pvNotificationFunc = Copy_pvNotificationFunc;
            SET_BIT(ADCSRA, ADSC);
        }
        else
        {
            Local_u8ErrorState = BUSY_STATE;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}

u8 ADC_u8StartChainAsynch(Chain_t *Copy_Chain)
{
    u8 Local_u8ErrorState = OK;
    if ((Copy_Chain != NULL) && (Copy_Chain->Channel != NULL) && (Copy_Chain->NotificationFunc != NULL) && (Copy_Chain->Result != NULL))
    {
        if (ADC_u8State == IDLE)
        {
            ADC_u8State = BUSY;
            ADC_u8ISRState = CHAIN_CHANNEL_ASYNCH;
            ADC_pu8ChainChannel = Copy_Chain->Channel;
            ADC_u8ChainSize = Copy_Chain->Size;
            ADC_pvNotificationFunc = Copy_Chain->NotificationFunc;
            ADC_pu16AsynchConversionResult = Copy_Chain->Result;
            ADC_u8Index = 0;
            ADC_u8SetChannel(ADC_pu8ChainChannel[ADC_u8Index]);
            SET_BIT(ADCSRA, ADSC);
        }
        else
        {
            Local_u8ErrorState = BUSY_STATE;
        }
    }
    else
    {
        Local_u8ErrorState = NULL;
    }
    return Local_u8ErrorState;
}

void ADC_voidEnable(void)
{
    SET_BIT(ADCSRA, ADEN);
}

void ADC_voidDisable(void)
{
    CLEAR_BIT(ADCSRA, ADEN);
}

void ADC_voidInterruptEnable(void)
{
    SET_BIT(ADCSRA, ADIE);
}

void ADC_voidInterruptDisable(void)
{
    CLEAR_BIT(ADCSRA, ADIE);
}

u8 ADC_u8SetPrescaler(u8 Copy_u8Prescaler)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Prescaler < 0x08)
    {
        ADCSRA &= ADC_PRE_MASK;
        ADCSRA |= Copy_u8Prescaler;
    }
    return Local_u8ErrorState;
}

u8 ADC_u8SetChannel(u8 Copy_u8Channel)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Channel < 33)
    {
        ADMUX &= ADC_CH_MASK;
        ADMUX |= Copy_u8Channel;
    }
    return Local_u8ErrorState;
}

void ADC_voidSetRefranceVoltage(u8 Copy_u8RefranceVoltage)
{
    switch (Copy_u8RefranceVoltage)
    {
    case AREF:
        CLEAR_BIT(ADMUX, REFS0);
        CLEAR_BIT(ADMUX, REFS1);
        break;
    case AVCC:
        SET_BIT(ADMUX, REFS0);
        CLEAR_BIT(ADMUX, REFS1);
        break;
    case INTERNAL_2_56:
        SET_BIT(ADMUX, REFS0);
        SET_BIT(ADMUX, REFS1);
        break;
    default:
        break;
    }
}

void ADC_voidSetAdjustResult(u8 Copy_u8AdjustResult)
{
    switch (Copy_u8AdjustResult)
    {
    case ADC_Right_Adjust_Result:
        CLEAR_BIT(ADMUX, ADLAR);
        break;
    case ADC_Left_Adjust_Result:
        SET_BIT(ADMUX, ADLAR);
        break;
    default:
        break;
    }
}

u16 ADC_u16GetResult(u8 Copy_u8AdjustResult)
{
    u16 Local_u16Result = 0x00;
    switch (Copy_u8AdjustResult)
    {
    case ADC_Right_Adjust_Result:
        Local_u16Result = (ADCL | (ADCH << 8));
        break;
    case ADC_Left_Adjust_Result:
        Local_u16Result = ADCH;
        break;
    default:
        break;
    }
    return Local_u16Result;
}

void __vector_16(void) __attribute((signal));
void __vector_16(void)
{
    if (ADC_u8ISRState == SINGLE_CHANNEL_ASYNCH)
    {
        *ADC_pu16AsynchConversionResult = ADC_u16GetResult(ADC_Adjust_Result);
        ADC_u8State = IDLE;
        ADC_pvNotificationFunc();
    }
    else
    {
        *(ADC_pu16AsynchConversionResult + ADC_u8Index) = ADC_u16GetResult(ADC_Adjust_Result);
        ADC_u8Index++;
        if (ADC_u8Index == ADC_u8ChainSize)
        {
            ADC_u8State = IDLE;
            ADC_pvNotificationFunc();
        }
        else
        {
            ADC_u8SetChannel(ADC_pu8ChainChannel[ADC_u8Index]);
            SET_BIT(ADCSRA, ADSC);
        }
    }
}
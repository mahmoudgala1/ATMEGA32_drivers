/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */

#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#define ADC_PRE_MASK 0b11111000
#define ADC_CH_MASK 0b11100000

#define ADMUX *((volatile u8 *)0x27)
#define REFS1 0x07
#define REFS0 0x06
#define ADLAR 0x05

#define ADCSRA *((volatile u8 *)0x26)
#define ADEN 0x07
#define ADSC 0x06
#define ADATE 0x05
#define ADIF 0x04
#define ADIE 0x03
#define ADPS2 0x02
#define ADPS1 0x01
#define ADPS0 0x00

#define SFIOR *((volatile u8 *)0x50)
#define ADTS2 0x07
#define ADTS1 0x06
#define ADTS0 0x05

#define ADCH *((volatile u8 *)0x25)
#define ADCL *((volatile u8 *)0x24)

#define SINGLE_CHANNEL_ASYNCH 0x00
#define CHAIN_CHANNEL_ASYNCH  0x01

#endif /* _ADC_PRIVATE_H_ */
/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GPIO_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */

#include "../../LIB/BIT_MATH.h"

#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

GPIO_ErrorStatus GPIO_enumSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PInDirection)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if ((Copy_u8Port <= GPIO_PORTD) && (Copy_u8Pin <= GPIO_PIN7))
	{
		if (Copy_u8PInDirection == GPIO_PIN_OUTPUT)
		{
			switch (Copy_u8Port)
			{
			case GPIO_PORTA:
				SET_BIT(DDRA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				SET_BIT(DDRB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				SET_BIT(DDRC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				SET_BIT(DDRD, Copy_u8Pin);
				break;
			default:
				break;
			}
		}
		else if (Copy_u8PInDirection == GPIO_PIN_INPUT)
		{
			switch (Copy_u8Port)
			{
			case GPIO_PORTA:
				CLEAR_BIT(DDRA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				CLEAR_BIT(DDRB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				CLEAR_BIT(DDRC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				CLEAR_BIT(DDRD, Copy_u8Pin);
				break;
			default:
				break;
			}
		}
		else
		{
			LOC_enumState = GPIO_NOK;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if ((Copy_u8Port <= GPIO_PORTD) && (Copy_u8Pin <= GPIO_PIN7))
	{
		if (Copy_u8PinValue == GPIO_PIN_HIGH)
		{
			switch (Copy_u8Port)
			{
			case GPIO_PORTA:
				SET_BIT(PORTA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				SET_BIT(PORTB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				SET_BIT(PORTC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				SET_BIT(PORTD, Copy_u8Pin);
				break;
			default:
				break;
			}
		}
		else if (Copy_u8PinValue == GPIO_PIN_LOW)
		{
			switch (Copy_u8Port)
			{
			case GPIO_PORTA:
				CLEAR_BIT(PORTA, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				CLEAR_BIT(PORTB, Copy_u8Pin);
				break;
			case GPIO_PORTC:
				CLEAR_BIT(PORTC, Copy_u8Pin);
				break;
			case GPIO_PORTD:
				CLEAR_BIT(PORTD, Copy_u8Pin);
				break;
			default:
				break;
			}
		}
		else
		{
			LOC_enumState = GPIO_NOK;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Ptr_u8PinValue)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if ((Copy_u8Port <= GPIO_PORTD) && (Copy_u8Pin <= GPIO_PIN7) && (Ptr_u8PinValue != NULL))
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			*Ptr_u8PinValue = GET_BIT(PINA, Copy_u8Pin);
			break;
		case GPIO_PORTB:
			*Ptr_u8PinValue = GET_BIT(PINB, Copy_u8Pin);
			break;
		case GPIO_PORTC:
			*Ptr_u8PinValue = GET_BIT(PINC, Copy_u8Pin);
			break;
		case GPIO_PORTD:
			*Ptr_u8PinValue = GET_BIT(PIND, Copy_u8Pin);
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if ((Copy_u8Port <= GPIO_PORTD) && (Copy_u8Pin <= GPIO_PIN7))
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			TOGGLE_BIT(PORTA, Copy_u8Pin);
			break;
		case GPIO_PORTB:
			TOGGLE_BIT(PORTB, Copy_u8Pin);
			break;
		case GPIO_PORTC:
			TOGGLE_BIT(PORTC, Copy_u8Pin);
			break;
		case GPIO_PORTD:
			TOGGLE_BIT(PORTD, Copy_u8Pin);
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumSetPortDirection(u8 Copy_u8Port, u8 Copy_u8PrtDirection)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if ((Copy_u8Port <= GPIO_PORTD) && (Copy_u8PrtDirection <= 0xFF))
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			DDRA = Copy_u8PrtDirection;
			break;
		case GPIO_PORTB:
			DDRB = Copy_u8PrtDirection;
			break;
		case GPIO_PORTC:
			DDRC = Copy_u8PrtDirection;
			break;
		case GPIO_PORTD:
			DDRD = Copy_u8PrtDirection;
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumSetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if ((Copy_u8Port <= GPIO_PORTD) && (Copy_u8PortValue <= 0xFF))
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			PORTA = Copy_u8PortValue;
			break;
		case GPIO_PORTB:
			PORTB = Copy_u8PortValue;
			break;
		case GPIO_PORTC:
			PORTC = Copy_u8PortValue;
			break;
		case GPIO_PORTD:
			PORTD = Copy_u8PortValue;
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumGetPortValue(u8 Copy_u8Port, u8 *Ptr_u8PortValue)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if ((Copy_u8Port <= GPIO_PORTD) && (Ptr_u8PortValue != NULL))
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			*Ptr_u8PortValue = PINA;
			break;
		case GPIO_PORTB:
			*Ptr_u8PortValue = PINB;
			break;
		case GPIO_PORTC:
			*Ptr_u8PortValue = PINC;
			break;
		case GPIO_PORTD:
			*Ptr_u8PortValue = PIND;
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumTogglePortValue(u8 Copy_u8Port)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if (Copy_u8Port <= GPIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			PORTA ^= 0xFF;
			break;
		case GPIO_PORTB:
			PORTB ^= 0xFF;
			break;
		case GPIO_PORTC:
			PORTC ^= 0xFF;
			break;
		case GPIO_PORTD:
			PORTD ^= 0xFF;
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumWriteHighNibbles(u8 Copy_u8Port, u8 Copy_u8Value)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;

	if (Copy_u8Port <= GPIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			DDRA |= 0xF0;
			PORTA = ((PORTA & 0x0F) | (Copy_u8Value << 4));
			break;
		case GPIO_PORTB:
			DDRB |= 0xF0;
			PORTB = ((PORTB & 0x0F) | (Copy_u8Value << 4));
			break;
		case GPIO_PORTC:
			DDRC |= 0xF0;
			PORTC = ((PORTC & 0x0F) | (Copy_u8Value << 4));
			break;
		case GPIO_PORTD:
			DDRD |= 0xF0;
			PORTD = ((PORTD & 0x0F) | (Copy_u8Value << 4));
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}

GPIO_ErrorStatus GPIO_enumWriteLowNibbles(u8 Copy_u8Port, u8 Copy_u8Value)
{
	GPIO_ErrorStatus LOC_enumState = GPIO_OK;
	if (Copy_u8Port <= GPIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			DDRA |= 0x0F;
			PORTA = ((PORTA & 0xF0) | (Copy_u8Value &= 0x0F));
			break;
		case GPIO_PORTB:
			DDRB |= 0x0F;
			PORTB = ((PORTB & 0xF0) | (Copy_u8Value &= 0x0F));
			break;
		case GPIO_PORTC:
			DDRC |= 0x0F;
			PORTC = ((PORTC & 0xF0) | (Copy_u8Value &= 0x0F));
			break;
		case GPIO_PORTD:
			DDRB |= 0x0F;
			PORTD = ((PORTD & 0xF0) | (Copy_u8Value &= 0x0F));
			break;
		default:
			break;
		}
	}
	else
	{
		LOC_enumState = GPIO_NOK;
	}
	return LOC_enumState;
}
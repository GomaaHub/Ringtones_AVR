#include "Library/types.h"
#include "TMR_Private.h"
#include "TMR_Interface.h"

void TMR0_Init(u8 MODE, u8 OC0_MODE, u8 CLOCK_SELECT)
{
	MODE &= 0x03;
	OC0_MODE &= 0x03;
	CLOCK_SELECT &= 0x07;

	if(MODE==0)
	{
		TIMSK_REG &= ~(1 << OCIE0);
		TIMSK_REG |= (1 << TOIE0);
	}

	else if(MODE > 0)
	{
		TIMSK_REG &= ~(1 << TOIE0);
		TIMSK_REG |= (1 << OCIE0);
	}

	switch(MODE)
	{
		case 0:
		{
			TCCR0_REG &= ~(1 << WGM00);
			TCCR0_REG &= ~(1 << WGM01);
			break;
		}
		case 1:
		{
			TCCR0_REG |=  (1 << WGM00);
			TCCR0_REG &= ~(1 << WGM01);
			break;
		}
		case 2:
		{
			TCCR0_REG &= ~(1 << WGM00);
			TCCR0_REG |=  (1 << WGM01);
			break;
		}
		case 3:
		{
			TCCR0_REG |= (1 << WGM00);
			TCCR0_REG |= (1 << WGM01);
			break;
		}
	}

		TCCR0_REG &= 0b11001111;
		TCCR0_REG |= (OC0_MODE << COM00);

		TCCR0_REG &= 0b11111000;
		TCCR0_REG |= CLOCK_SELECT;
}

void TMR0_TCNTSet(u8 start)
{
	TCNT0_REG = start;
}

void TMR0_OCRSet(u8 ocr0)
{
	OCR0_REG = ocr0;
}

/********************************************TIMER 2 DRIVERS********************************************/

void TMR2_Init(u8 MODE, u8 OC0_MODE, u8 CLOCK_SELECT)
{
	MODE &= 0x03;
	OC0_MODE &= 0x03;
	CLOCK_SELECT &= 0x07;

	if(MODE==0)
	{
		TIMSK_REG &= ~(1 << OCIE2);
		TIMSK_REG |= (1 << TOIE2);
	}

	else if(MODE > 0)
	{
		TIMSK_REG &= ~(1 << TOIE2);
		TIMSK_REG |= (1 << OCIE2);
	}

	switch(MODE)
	{
		case 0:
		{
			TCCR2_REG &= ~(1 << WGM20);
			TCCR2_REG &= ~(1 << WGM21);
			break;
		}
		case 1:
		{
			TCCR2_REG |=  (1 << WGM20);
			TCCR2_REG &= ~(1 << WGM21);
			break;
		}
		case 2:
		{
			TCCR2_REG &= ~(1 << WGM20);
			TCCR2_REG |=  (1 << WGM21);
			break;
		}
		case 3:
		{
			TCCR2_REG |= (1 << WGM20);
			TCCR2_REG |= (1 << WGM21);
			break;
		}
	}

		TCCR2_REG &= 0b11001111;
		TCCR2_REG |= (OC0_MODE << COM20);

		TCCR2_REG &= 0b11111000;
		TCCR2_REG |= CLOCK_SELECT;
}

void TMR2_TCNTSet(u8 start)
{
	TCNT2_REG = start;
}

void TMR2_OCRSet(u8 ocr2)
{
	OCR2_REG = ocr2;
}

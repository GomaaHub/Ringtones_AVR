#include "Library/types.h"
#include "Library/bit_math.h"
#include "include/DIO_Interface.h"
#include "include/LCD_Interface.h"
#include "include/EXTI_Interface.h"
#include "include/BUZ_Interface.h"
#include "include/TMR_Interface.h"
#include "avr/delay.h"
#include "avr/interrupt.h"



u16 OF_COUNTS=0;
u16 OV_COUNTS=0;

void main(void)
{

	DIO_SetPortDirection(DIO_PORTA,DIO_PORT_OUTPUT);

	DIO_SetPortDirection(DIO_PORTD,0xFF);
	DIO_SetPortDirection(DIO_PORTB,0xFF);

	GLOBAL_INTERRUPT_ENABLE();

	LCD_Init();
	LCD_DISPLAY_CONTROL(1,0,0);
	TMR2_Init(CTC,TOGGLE_OC0,TMR2_CLOCK_32);
	TMR2_OCRSet(0);


	while(1)
	{

		LCD_CLEAR();
		LCD_GoToXY(0,0);
		LCD_Print_String("Samsung Ringtone");
		TONE_samsung_tone();
		LCD_CLEAR();
		LCD_GoToXY(0,0);
		LCD_Print_String("iPhone Ringtone");
		TONE_iphone_tone();
		LCD_CLEAR();
		LCD_GoToXY(0,0);
		LCD_Print_String("If you're Happy and you know it");
		TONE_IfYourHappyAndYouKnowIt();
		LCD_CLEAR();
		LCD_GoToXY(0,0);
		LCD_Print_String("Coffin Dance");
		TONE_coffin_dance();
		LCD_CLEAR();
		LCD_GoToXY(0,0);
		LCD_Print_String("He is a Pirate");
		TONE_HeIsAPirate();
	}

}



ISR(TIMER2_COMP_vect)
{

}



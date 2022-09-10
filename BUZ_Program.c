#include "Library/types.h"
#include "BUZ_Interface.h"
#include "TMR_Interface.h"
#include "avr/delay.h"

void TONE_HeIsAPirate(void)
{
	u8 pirates[]={NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 1,
			   NOTE_A4, NOTE_G4, NOTE_A4, 1,

			   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 1,
			   NOTE_A4, NOTE_G4, NOTE_A4, 1,

			   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 1,
			   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 1,
			   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 1,

			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_D5, NOTE_E5, NOTE_A4, 1,
			   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 1,
			   NOTE_C5, NOTE_A4, NOTE_B4, 1,

			   NOTE_A4, NOTE_A4,

			   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 1,
			   NOTE_A4, NOTE_G4, NOTE_A4, 1,

			   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 1,
			   NOTE_A4, NOTE_G4, NOTE_A4, 1,

			   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 1,
			   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 1,
			   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 1,

			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_D5, NOTE_E5, NOTE_A4, 1,
			   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 1,
			   NOTE_C5, NOTE_A4, NOTE_B4, 1,
			   //Repeat of first part
			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 1,
			   NOTE_A4, NOTE_G4, NOTE_A4, 1,

			   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 1,
			   NOTE_A4, NOTE_G4, NOTE_A4, 1,

			   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 1,
			   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 1,
			   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 1,
			   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 1,

			   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 1,
			   NOTE_D5, NOTE_E5, NOTE_A4, 1,
			   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 1,
			   NOTE_C5, NOTE_A4, NOTE_B4, 1,
			   //End of Repeat

			   NOTE_E5, 1, 1, NOTE_F5, 1, 1,
			   NOTE_E5, NOTE_E5, 1, NOTE_G5, 1, NOTE_E5, NOTE_D5, 1, 1,
			   NOTE_D5, 1, 1, NOTE_C5, 1, 1,
			   NOTE_B4, NOTE_C5, 1, NOTE_B4, 1, NOTE_A4,

			   NOTE_E5, 1, 1, NOTE_F5, 1, 1,
			   NOTE_E5, NOTE_E5, 1, NOTE_G5, 1, NOTE_E5, NOTE_D5, 1, 1,
			   NOTE_D5, 1, 1, NOTE_C5, 1, 1,
			   NOTE_B4, NOTE_C5, 1, NOTE_B4, 1, NOTE_A4};

	u8 pirates_delay[]={125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 375, 125,

			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 375, 125,

			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 125, 250, 125,

			  125, 125, 250, 125, 125,
			  250, 125, 250, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 375, 375,

			  250, 125,
			  125, 125, 250, 125, 125,
			  			  125, 125, 250, 125, 125,
			  			  125, 125, 250, 125, 125,
			  			  125, 125, 375, 125,

						  125, 125, 250, 125, 125,
						 			  125, 125, 250, 125, 125,
						 			  125, 125, 250, 125, 125,
						 			  125, 125, 375, 125,

						 			  125, 125, 250, 125, 125,
						 			  125, 125, 250, 125, 125,
						 			  125, 125, 250, 125, 125,
						 			  125, 125, 125, 250, 125,

						 			  125, 125, 250, 125, 125,
						 			  250, 125, 250, 125,
						 			  125, 125, 250, 125, 125,
						 			  125, 125, 375, 375,
			  //Repeat of First Part
			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 375, 125,

			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 375, 125,

			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 125, 250, 125,

			  125, 125, 250, 125, 125,
			  250, 125, 250, 125,
			  125, 125, 250, 125, 125,
			  125, 125, 375, 375,

			  //End of Repeat

			  250, 125, 375, 250, 125, 375,
			  125, 125, 125, 125, 125, 125, 125, 125, 375,
			  250, 125, 375, 250, 125, 375,
			  125, 125, 125, 125, 125, 500,

			  250, 125, 375, 250, 125, 375,
			  125, 125, 125, 125, 125, 125, 125, 125, 375,
			  250, 125, 375, 250, 125, 375,
			  125, 125, 125, 125, 125, 500};




	for(u16 i=0;i<280;i++)
	{
		//u8 wait = pirates_delay[i];
		u16 wait1 = pirates_delay[i];
		TMR2_OCRSet(pirates[i]);
		_delay_ms(wait1);


	}
}

void TONE_IfYourHappyAndYouKnowIt(void)
{
	u8 clap0[11]={D4,D4,G4,G4,G4,G4,G4,G4,F4_,G4,A4};
	u8 clap1[11]={D4,D4,A4,A4,A4,A4,A4,A4,G4,A4,B4};
	u8 clap2[14]={B4,B4,C5,C5,C5,C5,E4,C5,C5,B4,B4,A4,G4,G4};
	u8 clap3[11]={B4,B4,A4,A4,A4,G4,F4_,F4_,E4,F4_,G4};

	for(u8 i=0;i<11;i++)
			{
				TMR2_OCRSet(clap0[i]);
				_delay_ms(200);
			}

			TMR2_OCRSet(1);
			_delay_ms(500);

			for(u8 i=0;i<11;i++)
			{
				TMR2_OCRSet(clap1[i]);
				_delay_ms(200);
			}

			TMR2_OCRSet(1);
				_delay_ms(500);

			for(u8 i=0;i<14;i++)
			{
				TMR2_OCRSet(clap2[i]);
				_delay_ms(200);
			}


			for(u8 i=0;i<11;i++)
			{
				TMR2_OCRSet(clap3[i]);
				_delay_ms(200);
			}

			TMR2_OCRSet(1);
			_delay_ms(500);
}

void TONE_iphone_tone(void)
{
	u8 iphone_tone0[9]={C5,A4_,G4,C5,F4,C5,A4_,C5,G4};
	u8 iphone_tone0_delay[9]={80,50,50,120,110,110,120,120,180};
	u8 iphone_tone0_delay1[9]={10,35,80,20,30,30,30,70,180};

	u8 iphone_tone1[13]={G4,G4,A4_,C5,C5,A4_,G4,C5,F4,C5,A4_,C5,G4};
	u16 iphone_tone1_delay[13]={180,110,110,110,60,60,110,110,110,110,110,110,180};
	u16 iphone_tone1_delay1[13]={80,50,40,20,20,20,50,50,50,50,50,50,50};

	for(u8 i=0;i<9;i++)
			{
				TMR2_OCRSet(iphone_tone0[i]);
				_delay_ms(iphone_tone0_delay[i]);
				TMR2_OCRSet(1);
				_delay_ms(50);
			}

			TMR2_OCRSet(1);

			_delay_ms(500);


			for(u8 i=0;i<13;i++)
			{
				TMR2_OCRSet(iphone_tone1[i]);
				_delay_ms(iphone_tone1_delay[i]);
				TMR2_OCRSet(1);
				_delay_ms(iphone_tone1_delay1[i]);
			}

			TMR2_OCRSet(1);
			_delay_ms(500);

			for(u8 i=0;i<13;i++)
			{
				TMR2_OCRSet(iphone_tone1[i]);
				_delay_ms(iphone_tone1_delay[i]);
				TMR2_OCRSet(1);
				_delay_ms(iphone_tone1_delay1[i]);
			}

			TMR2_OCRSet(1);
			_delay_ms(500);

			for(u8 i=0;i<13;i++)
			{
				TMR2_OCRSet(iphone_tone1[i]);
				_delay_ms(iphone_tone1_delay[i]);
				TMR2_OCRSet(1);
				_delay_ms(iphone_tone1_delay1[i]);
			}

			TMR2_OCRSet(1);
			_delay_ms(500);


}

void TONE_samsung_tone(void)
{
	u8 samsung_tone0[15]={A4,A4,G4,G4,F4,C4,D4,G4,F4,C4,E4,F4,F5,F5,F5};
	u16 samsung_tone0_delay[15]={250,170,170,170,170,170,170,150,150,150,150,300,200,200,200};
	u16 samsung_tone0_delay1[15]={650,200,400,60,60,60,550,60,60,60,200,250,120,120,120};

	for(u8 i=0;i<15;i++)
	{
		TMR2_OCRSet(samsung_tone0[i]);
		_delay_ms(samsung_tone0_delay[i]);
		TMR2_OCRSet(1);
		_delay_ms(samsung_tone0_delay1[i]);
	}

	TMR2_OCRSet(1);
	_delay_ms(1000);

}

void TONE_coffin_dance(void)
{

	u8 coffin0[28]={C5,C5,C5,C5,E5,E5,E5,E5,D5,D5,D5,D5,G5,G5,G5,G5,A5,A5,A5,A5,A5,A5,A5,A5,A5,A5,A5,A5};
	u8 coffin1[29]={D5,C5,B4,G4,A4,A4,E5,D5,C5,B4,B4,B4,D5,C5,B4,A4,A4,C6,B5,C6,B5,C6,A4,A4,C6,B5,C6,B5,C6};
	u16 coffin1_delay[29]={60,60,60,60,150,60,60,150,150,150,60,60,150,60,60,150,60,60,60,60,60,60,150,60,60,60,60,60};
	u8 coffin2[29]={A4,A4,E5,D5,C5,B4,B4,B4,D5,C5,B4,A4,A4,C6,B5,C6,B5,C6,A4,A4,C6,B5,C6,B5,C6};
	u16 coffin2_delay[29]={150,60,60,150,150,150,60,60,150,60,60,150,60,60,60,60,60,60,150,60,60,60,60,60};

	for(u8 i=0;i<28;i++)
	{
		TMR2_OCRSet(coffin0[i]);
		_delay_ms(150);
		TMR2_OCRSet(1);
		_delay_ms(60);
	}

	for(u8 i=0;i<29;i++)
	{
		TMR2_OCRSet(coffin1[i]);
		_delay_ms(150);

		if(i==4||i==7||i==8||i==9||i==12 ||i==15||i==22)
			_delay_ms(70);

		TMR2_OCRSet(1);
		_delay_ms(coffin1_delay[i]);
	}

	TMR2_OCRSet(1);
	_delay_ms(60);

	for(u8 i=0;i<25;i++)
	{
		TMR2_OCRSet(coffin2[i]);
		_delay_ms(150);

		if(i==0||i==3||i==4||i==5||i==8 ||i==11||i==18)
					_delay_ms(70);

		TMR2_OCRSet(1);
		_delay_ms(coffin2_delay[i]);
	}

	TMR2_OCRSet(1);
	_delay_ms(50);
}

/*
 * main.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_int.h"
#include "LCD_config.h"


#include "init.h"
#include "config.h"
#include "register.h"

#include "util/delay.h"

int main(void)
{
	u8int_t customChar1[] = {
			0b00000000,
			0b00001110,
			0b00001110,
			0b00000100,
			0b00001110,
			0b00010101,
			0b00000100,
			0b00001010
	};

	u8int_t customchar2[]={
			0b00000000,
			0b00000000,
			0b00001110,
			0b00000000,
			0b00001110,
			0b00011111,
			0b00010001,
			0b00000000
	};

	u8int_t customchar3[]={
			0b00000000,
			0b00011111,
			0b00011111,
			0b00011111,
			0b00011111,
			0b00011111,
			0b00011111,
			0b00000000
	};
	u8int_t customchar4[]={
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00011111,
			0b00011111,
			0b00000000,
			0b00000000
	};
	u8int_t customchar5[]={
				0b00000000,
				0b00000000,
				0b00011011,
				0b00010101,
				0b00001010,
				0b00000100,
				0b00000000,
				0b00000000
		};
	CLCD_voidInit();

	CLCD_GoTOXY(0,1);
	CLCD_voidSendString("Hi This is bing !");
	_delay_ms(20);
	write_special_character(customChar1,0,1,8);
	_delay_ms(100);

	CLCD_Void_LCDClear();
	_delay_ms(100);

	CLCD_GoTOXY(0,1);
	CLCD_voidSendString("bing had a dream to be ");
	CLCD_voidSendString("a singer ");
	write_special_character(customchar2,1,2,14);
	_delay_ms(100);


	CLCD_Void_LCDClear();
	_delay_ms(100);


	CLCD_GoTOXY(1,8);
	CLCD_voidSendString("so he went");
	CLCD_GoTOXY(2,5);
	CLCD_voidSendString("to an audition");
	_delay_ms(20);


	write_special_character(customChar1,0,0,1);
	write_special_character(customchar4,3,0,1);
	write_special_character(customChar1,0,0,2);
	write_special_character(customchar4,3,0,2);
	write_special_character(customChar1,0,0,3);
	write_special_character(customchar4,3,0,3);


	_delay_ms(20);

	write_special_character(customchar3,2,1,0);
	write_special_character(customchar3,2,1,1);
	write_special_character(customchar3,2,1,2);
	write_special_character(customchar3,2,2,0);
	write_special_character(customchar3,2,2,1);
	write_special_character(customchar3,2,2,2);
	write_special_character(customchar3,2,3,0);
	write_special_character(customchar3,2,3,1);
	write_special_character(customchar3,2,3,2);



	CLCD_Void_LCDClear();
	_delay_ms(100);


	CLCD_GoTOXY(0,1);
	CLCD_voidSendString("and fortunately");
	CLCD_GoTOXY(1,1);
	CLCD_voidSendString("he got accepted");
	CLCD_GoTOXY(2,1);
	CLCD_voidSendString("now he becomes a ");
	CLCD_GoTOXY(3,1);
		CLCD_voidSendString("famous singer ");
	_delay_ms(20);
	write_special_character(customchar5,4,3,16);




	while(1)
	{
		//				for(u8int_t count=0; count!=2 ;count++)
		//				{
		//					write_special_character(customchar4,1,0,count);
		//					write_special_character(customChar1,0,0,count+1);
		//					_delay_ms(200);
		//
		//
		//				}
		//				CLCD_Void_LCDClear();

	}


	return 0;
}

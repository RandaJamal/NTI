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
#include "KYP_int.h"
#include "KYP_config.h"

#include "init.h"
#include "config.h"
#include "register.h"

#include "util/delay.h"
static u8int_t i=1;
static u8int_t j=1;
static u8int_t r=1;
static u8int_t c=1;
static u8int_t score1= 1;
static u8int_t score2= 1;





int main(void)
{
	u8int_t Local_key;
	// dash pos in ram=0
	u8int_t customChar1[] = {
			0b00000011,
			0b00000011,
			0b00000011,
			0b00000011,
			0b00000011,
			0b00000011,
			0b00000011,
			0b00000011
	};
	//ball,pos ina ram=1
	u8int_t customchar2[]={
			0b00000000,
			0b00000000,
			0b00001110,
			0b00011111,
			0b00011111,
			0b00001110,
			0b00000000,
			0b00000000
	};
	//space, pos in ram=2
	u8int_t customchar3[]={
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000
	};


	CLCD_voidInit();

	KYP_Init();


	CLCD_GoTOXY(1,1);
	CLCD_voidSendString("WELCOME !");
	_delay_ms(500);
	CLCD_Void_LCDClear();
	_delay_ms(20);
	write_special_character(customChar1,0,i,0);
	write_special_character(customChar1,0,j,19);
	CLCD_GoTOXY(0,2);
	CLCD_voidSendString("P1:");
	CLCD_GoTOXY(0,10);
	CLCD_voidSendString("P2: ");





	while(1)
	{

		write_special_character(customChar1,0,j,19);
		write_special_character(customChar1,0,i,0);

		write_special_character(customchar3,2,1,c);


		for(c=1;c<20 ;c++)
		{

			do{

				Local_key=KYP_u8GetPressed();
			}
			while (Local_key == KYP_NO_PRESSED);

			if(Local_key == '9')
			{
				break;
			}

			if(Local_key == '3')
			{
				break;
			}
			if(Local_key == '7')
			{
				break;
			}

			if(Local_key == '1')
			{
				break;
			}

			else
			{

				write_special_character(customchar3,2,1,c);
				write_special_character(customchar2,1,1,c+1);
				//				c=c+1 ;
			}

			if(c == 18)
			{
				write_special_character(customchar3,2,1,c);
				write_special_character(customchar3,2,1,c+1);


				CLCD_GoTOXY(0,5);
				CLCD_voidWriteNumber(score1);
				score1 ++ ;
				break;


			}

			if((score1 > 2) || (score2 > 2) )
			{
				CLCD_Void_LCDClear();
				CLCD_GoTOXY(1,2);
				CLCD_voidSendString("The winner is:");
				if(score1 > score2)
				{
					CLCD_GoTOXY(2,2);
					CLCD_voidSendString("Player1");
				}
				else
				{
					CLCD_GoTOXY(2,2);
					CLCD_voidSendString("Player2");
				}
			}


		}


		if(Local_key == '9')

		{
			write_special_character(customchar3,2,j,19);

			write_special_character(customChar1,0,j-1,19);

			_delay_ms(20);
			j=j-1 ;


		}




		if(Local_key == '3')
		{
			write_special_character(customchar3,2,j,19);

			write_special_character(customChar1,0,j+1,19);

			_delay_ms(20);
			j=j+1 ;
		}

		if(Local_key == '7')

		{
			write_special_character(customchar3,2,i,0);

			write_special_character(customChar1,0,i-1,0);

			_delay_ms(20);
			i=i-1 ;

		}

		if(Local_key == '1')
		{
			write_special_character(customchar3,2,i,0);

			write_special_character(customChar1,0,i+1,0);

			_delay_ms(20);
			i=i+1 ;
		}



	}
	return 0;
}





//for(c=18;c>0;c--)
//		{
//			if(Local_key == '7')
//			{
//				break;
//			}
//
//			if(Local_key == '1')
//			{
//				break;
//			}
//			else
//			{
//
//				write_special_character(customchar3,2,1,c);
//				write_special_character(customchar2,1,1,c-1);
//			}
//
//			if(c == 1)
//			{
//				write_special_character(customchar3,2,1,c);
//				CLCD_GoTOXY(0,15);
//				CLCD_voidWriteNumber(score2);
//				score2 ++ ;
//				break;
//
//
//			}
//
//			if((score1 > 2) || (score2 > 2) )
//			{
//				CLCD_Void_LCDClear();
//				CLCD_GoTOXY(1,2);
//				CLCD_voidSendString("The winner is:");
//				if(score1 > score2)
//				{
//					CLCD_GoTOXY(2,2);
//					CLCD_voidSendString("Player1");
//				}
//				else
//				{
//					CLCD_GoTOXY(2,2);
//					CLCD_voidSendString("Player2");
//				}
//			}

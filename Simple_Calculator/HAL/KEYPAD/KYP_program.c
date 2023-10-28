/*
 * KYP_program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Lenovo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "register.h"
#include "config.h"
#include "init.h"

#include "KYP_config.h"
#include "KYP_int.h"

void KYP_Init(void)
{
	/*set rows pins as input pull up from 0->3*/
	DIO_INIT(KYP_PORT,PIN_0,PIN_INPUT);
	DIO_SetPinValue(KYP_PORT,PIN_0,PIN_HIGH);

	DIO_INIT(KYP_PORT,PIN_1,PIN_INPUT);
	DIO_SetPinValue(KYP_PORT,PIN_1,PIN_HIGH);

	DIO_INIT(KYP_PORT,PIN_2,PIN_INPUT);
	DIO_SetPinValue(KYP_PORT,PIN_2,PIN_HIGH);

	DIO_INIT(KYP_PORT,PIN_3,PIN_INPUT);
	DIO_SetPinValue(KYP_PORT,PIN_3,PIN_HIGH);
	/*set col pins as ouput and initially high 4->7*/
	DIO_INIT(KYP_PORT,PIN_4,PIN_OUTPUT);
	DIO_SetPinValue(KYP_PORT,PIN_4,PIN_HIGH);

	DIO_INIT(KYP_PORT,PIN_5,PIN_OUTPUT);
	DIO_SetPinValue(KYP_PORT,PIN_5,PIN_HIGH);

	DIO_INIT(KYP_PORT,PIN_6,PIN_OUTPUT);
	DIO_SetPinValue(KYP_PORT,PIN_6,PIN_HIGH);

	DIO_INIT(KYP_PORT,PIN_7,PIN_OUTPUT);
	DIO_SetPinValue(KYP_PORT,PIN_7,PIN_HIGH);

}
u8int_t KYP_u8GetPressed(void)
{
	u8int_t pressed_key= KYP_NO_PRESSED;
	static u8int_t KYP_ARR[4][4]=KYP_ARR_VAL ;
	u8int_t button;

	for(u8int_t col=4; col<8;col++)
	{
		/*activate current col  */
		DIO_SetPinValue(KYP_PORT,col,PIN_LOW);
		for(u8int_t row=0; row<4; row++)
		{
			DIO_ReadPin(KYP_PORT,row,&button);

			/*check if a sietch is pressed*/
			if(PIN_LOW == button)
			{
				//pressed_key=KYP_ARR[col][row];
				pressed_key= KYP_ARR[row][col-4];
				while (PIN_LOW == button)
				{
					DIO_ReadPin(KYP_PORT,row,&button);


				}
				_delay_ms(20);

				return pressed_key ;
			}


		}

		/*deactivate the current col*/
		DIO_SetPinValue(KYP_PORT,col,PIN_HIGH);

	}

	return pressed_key;
}

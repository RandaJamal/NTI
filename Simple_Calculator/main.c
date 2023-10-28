/*
 * main.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <ctype.h>
#include "util/delay.h"

#include "LCD_config.h"
#include "LCD_int.h"
#include "KYP_int.h"
#include "KYP_config.h"


#include "init.h"
#include "config.h"

#define  MAX_UNUSED     1000

int main(void)
{
	label : CLCD_voidInit();
	KYP_Init();

	u8int_t arr[6]={KYP_NO_PRESSED,KYP_NO_PRESSED,KYP_NO_PRESSED,KYP_NO_PRESSED,KYP_NO_PRESSED,KYP_NO_PRESSED} ;
	u16 res ;
	u8int_t counter=0 ;
	while(1)
	{
		do
		{
			arr[counter]=KYP_u8GetPressed();

		} while(arr[counter]==KYP_NO_PRESSED);
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_Void_LCDClear();
			goto label ;
		}
		else
		{
			CLCD_voidSendData(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=KYP_u8GetPressed();

		}while(arr[counter]==KYP_NO_PRESSED);
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_Void_LCDClear();
			goto label ;
		}
		else
		{
			CLCD_voidSendData(arr[counter]);
		}
		counter++;
		_delay_ms(300);

		do
		{
			arr[counter]=KYP_u8GetPressed();

		}while(arr[counter]==KYP_NO_PRESSED);

		if(arr[counter]=='A'||arr[counter]=='=')
		{
			CLCD_Void_LCDClear();
			goto label ;
		}
		else
		{
			CLCD_voidSendData(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=KYP_u8GetPressed();

		}while(arr[counter]==KYP_NO_PRESSED);

		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_Void_LCDClear();
			goto label ;
		}
		else
		{
			CLCD_voidSendData(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=KYP_u8GetPressed();

		}while(arr[counter]==KYP_NO_PRESSED);

		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_Void_LCDClear();
			goto label ;
		}
		else
		{
			CLCD_voidSendData(arr[counter]);
		}
		counter++;
		_delay_ms(300);


		do
		{
			arr[counter]=KYP_u8GetPressed();

		}while(arr[counter]==KYP_NO_PRESSED);

		if(arr[counter]=='=')
		{
			CLCD_voidSendData(arr[counter]);


			switch(arr[counter-3])
			{
			case '+':
				res=(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
				if(res>=100&&res<1000)
				{
					CLCD_voidSendData((res/100)+48);
					CLCD_voidSendData(((res/10)%10)+48);
					CLCD_voidSendData((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					CLCD_voidSendData((res/10)+48);
					CLCD_voidSendData((res%10)+48);


				}
				else if(res<10)
				{
					CLCD_voidSendData(res+48);

				}
				break;
			case '-' :
				res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(res>=100&&res<1000)
				{

					CLCD_voidSendData((res/100)+48);
					CLCD_voidSendData(((res/10)%10)+48);
					CLCD_voidSendData((res%10)+48);

				}
				else if (res>=10&&res<100)
				{
					CLCD_voidSendData((res/10)+48);
					CLCD_voidSendData((res%10)+48);
				}
				else if(res<10)
				{
					CLCD_voidSendData(res+48);
				}
				break;
			case '*':
				res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(res>=1000&&res<10000)
				{


					CLCD_voidSendData((res/100)+48);
					CLCD_voidSendData(((res/10)%10)+48);
					CLCD_voidSendData(((res/10)%10)+48);

					CLCD_voidSendData((res%10)+48);

				}
				else if(res>=100&&res<1000)
				{

					CLCD_voidSendData((res/100)+48);
					CLCD_voidSendData(((res/10)%10)+48);
					CLCD_voidSendData((res%10)+48);


				}
				else if (res>=10&&res<100)
				{


					CLCD_voidSendData((res/10)+48);
					CLCD_voidSendData((res%10)+48);


				}
				else if(res<10)
				{
					CLCD_voidSendData(res+48);
				}
				break;
			case '/':
				res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(res>=100&&res<1000)
				{


					CLCD_voidSendData((res/100)+48);
					CLCD_voidSendData(((res/10)%10)+48);
					CLCD_voidSendData((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					CLCD_voidSendData((res/10)+48);
					CLCD_voidSendData((res%10)+48);
				}
				else if(res<10)
				{
					CLCD_voidSendData(res+48);
				}
				break;
			default : break;

			}
		}
		else
		{
			CLCD_Void_LCDClear();
			goto label ;
		}
		_delay_ms(200);
	}
	return 0;
}

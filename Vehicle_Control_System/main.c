/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Lenovo
 */

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define ON  1
#define OFF 0
int Engine_State =OFF ;
int AC;
int engine_temp_controller ;

int speed ;
int room_temp ;
int engine_temp ;

void vehicle_state(void);
void menu_set (void);
void SensorsSetMenu(void);
void Traffic_Light_Color(void);
void room_temperature(void);
void engine_temperature(void);
void vehicle_state(void);







int main(void)
{




	return 0;
}
void menu_set (void)
{
	int option;
	printf("please select on of the following option \n");
	printf("press 1 to Turn on the vehicle engine \n");
	printf("press 2 to Turn off the vehicle engine \n");
	printf("please 3 to quit the system  \n");
	fflush(stdin);fflush(stdout);
	scanf("%d", &option);

	switch(option){

	case 3:printf("*****Quit program****\n"); break;
	case 2: printf("The system will turn off \n") ;menu_set(); break;
	case 1: printf("The system will turn on \n"); SensorsSetMenu();break;
	default:printf("Wrong input try again\n"); break;
	}

}
void SensorsSetMenu(void)
{
	int option;
	Engine_State=ON;
		printf("please select on of the following option \n");
		printf("press 1 to Turn off the  engine \n");
		printf("press 2 to set the traffic light color \n");
		printf("please 3 to set the room temperature  \n");
		printf("please 4 to set the engine temperature  \n");
		fflush(stdin);fflush(stdout);
		scanf("%d", &option);

		switch(option){
		case 1: printf("The Engine will be turned off \n");break;
		case 2: printf(" traffic light color mode \n"); Traffic_Light_Color();break;
		case 3: printf(" room temperature mode \n"); room_temperature();break;
		case 4: printf(" engine temperature  mode \n"); engine_temperature();break;
		default:break;

		}

		if(speed == 30)
		{
			AC=ON;
			room_temp= room_temp *(5/4) +1 ;
			engine_temp_controller =ON;
			engine_temp=engine_temp *(5/4)+1 ;
		}

		vehicle_state();
}
 void Traffic_Light_Color(void)
 {
	 char color ;
	 printf("Please enter the traffic light color: \n");
	 fflush(stdin);fflush(stdout);
	 scanf("%c", &color);

	 switch(color){
	 case 'G': printf("set vehicle speed to 100km/hr\n"); speed=100;break;
	 case 'O': printf("set vehicle speed to 30km/hr\n");speed=30 ;break;
	 case 'R': printf("set vehicle speed to 0km/hr\n");speed=0;break;
	 default:break;

	 }

	 vehicle_state();
 }

 void room_temperature(void)
 {
	 int temperature ;
	 	 printf("Please enter the room temperature: \n");
	 	 fflush(stdin);fflush(stdout);
	 	 scanf("%d", &temperature);

	 	 if(temperature <10 && temperature >30)
	 	 {
	 		 AC=ON;
	 		 room_temp=20;
	 	 }

	 	 else
	 	 {
	 		 AC=OFF;
	 	 }


 }
void engine_temperature(void)
{
	 int temperature ;
		 	 printf("Please enter the engine  temperature: \n");
		 	 fflush(stdin);fflush(stdout);
		 	 scanf("%d", &temperature);

		 	 if(temperature <100 && temperature >150)
		 	 {
		 		 engine_temp_controller=ON;
		 		 engine_temp=125;
		 	 }

		 	 else
		 	 {
		 		 engine_temp=OFF;
		 	 }

}

void vehicle_state(void)
{
	if(Engine_State == OFF) printf("The Engine state is off\n");
	else if(Engine_State ==ON) printf("The Engine State is on\n");
	else
	{
		// do nothing
	}

	if(AC == OFF) printf("AC is off\n");
		else if(AC ==ON) printf("AC is on\n");
		else
		{
			// do nothing
		}
	printf("The vehicle speed is %d", speed);
	printf("The Room Temperature  is %d", room_temp);
	printf("The engine  is %d", engine_temp);
	printf("The engine temperature controller state  is %d", engine_temp_controller);



}

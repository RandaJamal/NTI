/*
 * main.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Lenovo
 */


/*
 * main.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Lenovo
 */

#include<stdio.h>
#include <string.h>
typedef struct{
	char Book_Title [100];
	char Author_Name [100];
	int Publication_Year ;
	float Price ;
	char 		NumberOfCopies;
	char 		Status[50];


}Book;


Book BookArr[100];

int BookCounter =0;
int LibraryCounter =0;



void Add_Book(Book Library[]) ;
void Borrow(Book library[]);
void PrintBook(Book library[]);
void Delete_Book(Book library[]) ;
void Buy_Book(Book library[]);




int main (void )
{
	int options=0;


	while(1)
	{

			printf("please select one of the following option \n");
			printf("Press 1 to add a book\n");
			printf("Press 2 to borrow a book\n");
			printf("Press 3 to print books info \n");
			printf("Press 4 to delete a book\n");
			printf("Press 5 to buy a book\n");
			printf("Press 6 to exit the system\n");
			fflush(stdin);fflush(stdout);
			scanf("%d", &options);

			switch(options){

			case 1: Add_Book(BookArr); break;
			case 2: Borrow(BookArr); break ;
			case 3: PrintBook(BookArr); break ;
			case 4: Delete_Book(BookArr); break;
			case 5: Buy_Book(BookArr); break ;
			case 6 :printf("the system will exist \n"); break;
			default: break;
			}
	}

	return 0;
}
void Add_Book(Book Library[])
{

	int flag ;

	if (LibraryCounter < 100){

		printf("please enter the book title : \n");
		fflush(stdout);fflush(stdin);
		gets(Library[LibraryCounter].Book_Title);
		fflush(stdout);fflush(stdin);


		printf("please enter the author name  :  \n");
		fflush(stdout);fflush(stdin);
		gets(Library[LibraryCounter].Author_Name);
		fflush(stdout);fflush(stdin);


		printf("enter publish year:\n");
		fflush(stdout);fflush(stdin);
		scanf("%d", &(Library[LibraryCounter].Publication_Year));
		fflush(stdout);fflush(stdin);


		printf("enter price:\n");
		fflush(stdout);fflush(stdin);
		scanf("%f", &(Library[LibraryCounter].Price));
		fflush(stdout);fflush(stdin);


		flag=0;
		for (int i = 0; i < LibraryCounter; i++)
		{

			// Convert both strings to uppercase before comparing
			strupr(Library[i].Book_Title);
			strupr(Library[LibraryCounter].Book_Title);

			strupr(Library[i].Author_Name);
			strupr(Library[LibraryCounter].Author_Name);

			// Compare book title and author name
			if (strcmp(Library[i].Book_Title, Library[LibraryCounter].Book_Title) == 0 &&
					strcmp(Library[i].Author_Name, Library[LibraryCounter].Author_Name) == 0)
			{
				// Set flag variable to one
				flag = 1;

				// Increment the number of copies of existing book by one
				Library->NumberOfCopies ++;
				LibraryCounter++ ;


				// Print message that book already exists and copies have been increased
				printf("This book already exists in the library. The number of copies has been increased by one.\n");

				// Break out of loop
				break;
			}

		}
		// Check if found variable is still zero
		if (flag == 0)
		{
			// Set number of copies of new book to one
			Library[LibraryCounter].NumberOfCopies = 1;
			LibraryCounter++ ;
			printf("This book has been added to the library.\n");
		}


	}

	else
	{
		printf("the library is full now \n");
	}



}








void Borrow(Book library[])
{
	Book check ;
	printf("please enter the book title : \n");
	fflush(stdout);fflush(stdin);
	gets(check.Book_Title);
	fflush(stdout);fflush(stdin);




	for(int i=0; i<100; i++)
	{
		// Convert both strings to uppercase before comparing
		strupr(library[i].Book_Title);
		strupr(check.Book_Title);

		if (strcmp(library[i].Book_Title, check.Book_Title) == 0)
		{
			// Check if there are any copies left
			if (library[i].NumberOfCopies > 0)
			{
				// Decrement the number of copies by one
				library[i].NumberOfCopies --;
				printf("here we go \n");
				LibraryCounter--;
				break;
			}
			else
			{
				// Print message that book is out of stock
				printf("Sorry, this book is out of stock.\n");
				break;
			}

		}
		else
		{
			printf("not found \n");
			break;
		}
	}

}

void PrintBook(Book library[])
{
	for(int i=0; i<LibraryCounter ;i++){

		printf("The book title is : %s\n", library[i].Book_Title);
		printf("The author name  is : %s\n", library[i].Author_Name);
		printf("The publication year is : %d\n",(library[i].Publication_Year));
		printf("The book price is : %f\n",(library[i].Price));


	}
}


void Delete_Book(Book library[])
{
	char name[100];
	printf("enter the book title you want to delete from the library:\n");
	fflush(stdout);fflush(stdin);
	gets(name);
	fflush(stdout);fflush(stdin);

	for(int i=0;i<LibraryCounter; i++)
	{
		strupr(library[i].Book_Title);
		strupr(name);

		if(stricmp(library[i].Book_Title,name) == 0 )
		{
			library[i]=library[LibraryCounter -1];
			LibraryCounter -- ;
			printf("hi \n");

			break;
		}

		else
		{

		}
	}
}

void Buy_Book(Book library[])
{
	char title[100]; // Declare a variable for book title
	int found = 0; // Declare and initialize a flag variable
	int i = 0; // Declare and initialize an index variable

	printf("Enter the book title you want to buy from the library:\n");
	fflush(stdin); fflush(stdout);
	gets(title);// Read the book title from input
	fflush(stdin); fflush(stdout);


	// Loop through the library array
	for (i = 0; i < LibraryCounter; i++)
	{
		// Convert both strings to uppercase before comparing
		strupr(library[i].Book_Title);
		strupr(title);

		// Compare book titles
		if (stricmp(library[i].Book_Title, title) == 0)
		{
			// Set found variable to one
			found = 1 ;

			printf("the price of the book is %f:\n",library[i].Price);
			LibraryCounter --;
			library[i].NumberOfCopies -- ;





			// Break out of loop
			break;
		}
	}

	// Check if found variable is still zero
	if (found == 0)
	{
		// Print message that book is not available
		printf("This book is not available in the library.\n");

		// Return from function
		return;
	}


	else
	{
		// Print message that input is invalid
	}
}



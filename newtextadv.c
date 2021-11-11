#include <stdint.h>
#include <stdio.h>
#include <conio.h>
#include "textadv_images.h"
void room();
void kitchen();
void outside();
void bathroom();
void printfile(char* my_filename);

int showerconfirm;


int main()
{
	showerconfirm = 0;
	
	printf("Welcome to the text adventure game!\n");
	room();
	
	printf("Thanks for playing!!!!!! Press any key to exit.\n");
	
	getch();
	return 0;
}

void room(){
	char choice;
	printf("%s", room_pic);
	printf("Rise and shine, motherfucker. Do you want to go to the bathroom, or the kitchen? \nb for bathroom, k for kitchen: \n");
	scanf(" %c", &choice);
	
	if (choice == 'b')
	{
	bathroom();
	}
	else if (choice == 'k')
	{
	kitchen();
	}
	else
	{
	printf("Please enter a valid number. \n");	
	room();
	}
}

void bathroom(){
	
	char choice;
	
	printfile("bathroom.txt");
	printf("\nWould you like to take a shower, go back to your room, or to the kitchen? \ns for shower, r for room, k for kitchen \n");
	scanf(" %c", &choice);
	
	if (choice == 's')
	{		
		if (showerconfirm == 0)
		{
			printfile("shower.txt");
			printf("\nYou take a shower. You feel refreshed and ready to head out. \n");
			showerconfirm = 1;
		}
		
		else
		{
			printf("\nThere's no other reason to be here. \n");
		}
		bathroom();
	}	
	
	else if (choice == 'r')
	{
		room();
	}
	
	else if (choice == 'k')
	{
		kitchen();
	}
	
	else
	{
	printf("Please enter a valid option. \n");	
	bathroom();
	}
	
}

void kitchen(){
	
	char choice;
	
	printfile("kitchen.txt");
	printf("\nYou are in the kitchen. Would you like to go outside, the room, or bathroom? \no for outside, r for room, b for bathroom \n");
	scanf(" %c", &choice);
	
	if (choice == 'o')
	{
		if (showerconfirm == 1)
		{
			printfile("house.txt");
			printf("\nYou feel clean and ready to head out. \n");
			outside();
		}
		else
		{
			printf("\nYou don't feel very clean, why not take a shower? \n");
			kitchen();
		}
	}
	else if (choice == 'r')
	{
		room();
	}
	else if (choice == 'b')
	{
		bathroom();
	}
	else
	{
		printf("\nPlease enter a valid option. \n");
		kitchen();
	}

}

void printfile(char* my_filename){
	
	FILE* file_pointer;
	
	char c;
	
	file_pointer = fopen(my_filename, "r");
	
	c = fgetc(file_pointer);
	
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(file_pointer);
	}
	
	fclose(file_pointer);
}
	
void outside(){
	
	printf("\nYou head out and now you feel ready to start the day! \n");
		
}
	


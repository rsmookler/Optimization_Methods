// Rob Smookler, Sean Flaherty
// Project 2A

//This file contains the main function for part A of project 2.

#include "stdafx.h"
#include "card.h"
#include "deck.h"
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
//Create a deck using the default constructor, 
//and print out the deck using the defined print operators
//for card and deck.
{
	//Create deck
	deck d;

	//Print out the deck
	cout << d;

	//Wait for character press by user before terminating program
	getch();

	return 0;
}//end main

//End of source file.


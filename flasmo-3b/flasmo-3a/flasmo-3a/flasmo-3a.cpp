// Rob Smookler, Sean Flaherty
// Project 3A

//This file contains the main function for part A of project 3,
//as well as global functions findMatches and testSearch.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "dictionary.h"
#include "d_matrix.h"
#include "grid.h"

using namespace std;

void findMatches(dictionary dict, grid gr)
//Global function that produces all candidate strings in the grid,
//from all eight possible directions. If a candidate string is at 
//least 5 characters long, checkDictionary is called which will
//print the string if it exists in the dictionary.
{
	//Store the grid
	matrix<char> g = gr.getMatrix();

	//String for word found in dictionary
	string result;
	
	//Starting character for candidate strings
	char startingLetter;

	//Starting row and column for candidate strings
	int startingRow, startingCol;

	//Incrementors to get next characters in a candidate string
	int nextRow, nextCol;

	//Iterate through each character in the grid, first by column and then by row.
	for (int i = 0; i < g.rows(); i++) 
	{

		for (int j = 0; j < g.cols(); j++) 
		{
			//Store starting letter for candidate strings
			startingLetter = g[i][j];
			
			//Store the initial row and column
			startingRow = i; 
			startingCol = j;  

			//Declare the candidate string that will be built
			string candidateString = "";

			//Add the first letter to candidate string
			candidateString += startingLetter;
			
			//Search up: decrement row until arriving at the initial row (accounting for wrap-around)
			nextRow = startingRow - 1;

			//Wrap-around condition
			if(nextRow == -1)      
			{
				nextRow = g.rows() - 1; 
			}//end if
			
			//While there are existing candidate strings
			while(nextRow != startingRow) 
			{
				//Add the next character to the candidate string
				candidateString += g[nextRow][startingCol];

				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5) 
				{
				  if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
					
				}//end if
				nextRow = nextRow - 1; //Go to the next character

				if(nextRow == -1)      //Wrap-around condition
				{
					nextRow = g.rows() - 1; 
				}//end if
			}//end while: UP

			//Reset candidate string to just the starting letter
			candidateString = startingLetter; 

			//Search down: increment row until arriving at the initial row (accounting for wrap-around)
			nextRow = startingRow + 1; 

			//Wrap-around condition
			if(nextRow == g.rows())  
			{
				nextRow = 0; 
			}//end if

			//While there are existing candidate strings
			while(nextRow != startingRow)
			{
				//Add the next character to the candidate string
				candidateString += g[nextRow][startingCol];

				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5)
				{
				  if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
				}//end if
				nextRow = nextRow + 1;       //Go to the next character

				if(nextRow == g.rows())      //Wrap-around condition
				{
					nextRow = 0; 
				}//end if
			}//end while: DOWN

			//Reset candidate string to just the starting letter
			candidateString = startingLetter; 

			//Search left: decrement column until arriving at the initial column (accounting for wrap-around)
			nextCol = startingCol - 1; 

			//Wrap-around condition
			if(nextCol == -1)     
			{
				nextCol = g.cols() - 1; 
			}//end if

			//While there are existing candidate strings
			while(nextCol != startingCol) 
			{
				//Add the next character to the candidate string
				candidateString += g[startingRow][nextCol];

				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5) 
				{
					 if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
				}//end if
				nextCol = nextCol - 1;   //Go to the next character

				if(nextCol == -1)        //Wrap-around condition
				{
					nextCol = g.cols() - 1; 
				}//end if
			}//end while: LEFT
			
			//Reset candidate string to just the starting letter
			candidateString = startingLetter; 

			//Search right: increment column until arriving at the initial column (accounting for wrap-around)
			nextCol = startingCol + 1; 

			//Wrap-around condition
			if(nextCol == g.cols())     
			{
				nextCol = 0; 
			}//end if

			//While there are existing candidate strings
			while(nextCol != startingCol)
			{
				//Add the next character to the candidate string
				candidateString += g[startingRow][nextCol];

				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5)
				{
					 if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
				}//end if
				nextCol = nextCol + 1;       //Go to the next character

				if(nextCol == g.cols())      //Wrap-around condition
				{
					nextCol = 0; 
				}//end if
			}//end while: RIGHT

			//Reset candidate string to just the starting letter
			candidateString = startingLetter; 

			//Search up-left: decrement column & row until arriving at the initial column & row (accounting for wrap-around)
			nextRow = startingRow - 1;
			nextCol = startingCol - 1; 

			//Wrap around conditions
			if(nextCol == -1)    
			{
				nextCol = g.cols() - 1; 
			}//end if

			if(nextRow == -1)  
			{
				nextRow = g.rows() - 1;
			}//end if

			//While there are existing candidate strings
			while(nextRow != startingRow && nextCol != startingCol) 
			{
				//Add the next character to the candidate string
				candidateString += g[nextRow][nextCol];

				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5) 
				{
					 if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
				}//end if

				//Go to the next character
				nextRow = nextRow - 1;
				nextCol = nextCol - 1; 

				//Wrap around conditions
				if(nextCol == -1)     
				{
					nextCol = g.cols() - 1; 
				}//end if

				if(nextRow == -1)   
				{
					nextRow = g.rows() - 1;
				}//end if
			}//end while: UP-LEFT

			//Reset candidate string to just the starting letter
			candidateString = startingLetter; 

			//Search up-right: decrement row, increment column until arriving at the initial column & row (accounting for wrap-around)
			nextRow = startingRow - 1;
			nextCol = startingCol + 1; 

			//Wrap-around conditions
			if(nextCol == g.cols())    
			{
				nextCol = 0; 
			}//end if

			if(nextRow == -1) 
			{
				nextRow = g.rows() - 1;
			}//end if

			//While there are existing candidate strings
			while(nextRow != startingRow && nextCol != startingCol) 
			{
				//Add the next character to the candidate string
				candidateString += g[nextRow][nextCol];
			
				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5)
				{
					  if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
				}//end if
				
				//Go to the next character
				nextRow = nextRow - 1;
				nextCol = nextCol + 1; //Decrement

				//Wrap-around conditions
				if(nextCol == g.cols())     
				{
					nextCol = 0; 
				}//end if

				if(nextRow == -1)    
				{
					nextRow = g.rows() - 1;
				}//end if
			}//end while: UP-RIGHT

			//Reset candidate string to just the starting letter
			candidateString = startingLetter; 

			//Search down-left: increment row, decrement column until arriving at the initial column & row (accounting for wrap-around)
			nextRow = startingRow + 1;
			nextCol = startingCol - 1; 

			//Wrap-around conditions
			if(nextCol == -1)     
			{
				nextCol = g.cols() - 1; 
			}//end if

			if(nextRow == g.rows())   
			{
				nextRow = 0;
			}//end if

			//While there are existing candidate strings
			while(nextRow != startingRow && nextCol != startingCol)
			{
				//Add the next character to the candidate string
				candidateString += g[nextRow][nextCol];

				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5)
				{
					 if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
				}//end if

				//Go to the next character
				nextRow = nextRow + 1;
				nextCol = nextCol - 1;

				//Wrap-around conditions
				if(nextCol == -1)     
				{
					nextCol = g.cols() - 1; 
				}//end if

				if(nextRow == g.rows())  
				{
					nextRow = 0;
				}//end if
			}//end while: DOWN-LEFT

			//Reset candidate string to just the starting letter
			candidateString = startingLetter; 

			//Search down-right: increment row, increment column until arriving at the initial column & row (accounting for wrap-around)
			nextRow = startingRow + 1;
			nextCol = startingCol + 1;

			//Wrap-around conditions
			if(nextCol == g.cols())  
			{
				nextCol = 0; 
			}//end if

			if(nextRow == g.rows())  
			{
				nextRow = 0;
			}//end if

			//While there are existing candidate strings
			while(nextRow != startingRow && nextCol != startingCol) 
			{
				//Add the next character to the candidate string
				candidateString += g[nextRow][nextCol];

				//If the candidate string is at least 5 characters, check the dictionary.
				if(candidateString.length() >= 5) 
				{
					 if(dict.checkDictionaryBinary(candidateString, 0, dict.getWords().size()-1)) cout << candidateString << "\n";
				}//end if

				//Go to the next character
				nextRow = nextRow + 1;
				nextCol = nextCol + 1;

				//Wrap-around conditions
				if(nextCol == g.cols())     
				{
					nextCol = 0; 
				}//end if

				if(nextRow == g.rows())    
				{
					nextRow = 0;
				}//end if
			}//end while: DOWN-RIGHT
		}//end inner for: columns
	}//end outer for: rows
}//end findMatches

void testSearch()
//Opens a dictionary, but prompts the user to enter the name of
//the grid file to use. Following this, it will call findMatches
//to print all words found in the grid.
{
	//Create a grid from the filename supplied by the user
	string filename;
	cout << "Enter name of grid file (including file type): ";
	cin >> filename;
	grid g(filename.c_str());
	cout << "-------------------------------------------------------------";
	cout << "\nWords found in the grid will be displayed below.\n";
	cout << "-------------------------------------------------------------\n";

	//Create a dictionary 
	dictionary d("dictionary.txt");
	d.dQuickSort(0, d.getWords().size()-1);
	//Call findMatches to print all words from the dictionary in the grid
//	d.printDictionary();
	findMatches(d, g);
}//end testSearch


int _tmain(int argc, _TCHAR* argv[])
//The main function calls testSearch, where the user is prompted to enter a grid filename.
{
	//Call testSearch, which calls findMatches and then returns here
	testSearch();

	//Wait for a character press by user before terminating program
	cout << "\nPress any key to continue...";
	getch();

	return 0;
}//end main


//End of source file.

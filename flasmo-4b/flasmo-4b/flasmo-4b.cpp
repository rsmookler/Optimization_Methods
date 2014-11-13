// Rob Smookler, Sean Flaherty
// Project 4B

//This file contains the main function for part B of project 4.

#include "stdafx.h"
#include "board.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
//The function initializes a board for each sudoku text file.
//The board and conflict vectors are printed, as well as
//whether the board is solved or not.
{
   //Define three input streams to read from the text files.
   ifstream fin1, fin2, fin3;
   string fileName1 = "sudoku1.txt";
   string fileName2 = "sudoku2.txt";
   string fileName3 = "sudoku3.txt";

   //Open file 1
   fin1.open(fileName1.c_str());

   if (!fin1)
   {
      cerr << "Cannot open " << fileName1 << endl;
      exit(1);
   }//end if

   //Open file 2
   fin2.open(fileName2.c_str());

   if (!fin2)
   {
      cerr << "Cannot open " << fileName2 << endl;
      exit(1);
   }//end if

   //Open file 3 
   fin3.open(fileName3.c_str());

   if (!fin3)
   {
      cerr << "Cannot open " << fileName3 << endl;
      exit(1);
   }//end if

   //Boolean variables to determine if puzzle is solved
   bool puzzle_solved1, puzzle_solved2, puzzle_solved3;

   //Print out the boards, conflicts, and whether the board is solved
   //using the functions defined in the board class.

   //Board 1
   try
   {
      board b1(SquareSize);				   //Board declaration

      while (fin1 && fin1.peek() != 'Z')   //The character z terminates a puzzle file
      {
			
		  b1.initialize(fin1);             //Initialize board
		  b1.printBoard();				   //Print out the board values
		  b1.printConflicts();			   //Print out the row, column, and square conflict vectors

		  //Determine if the puzzle is solved, and print out the result.
		  puzzle_solved1 = b1.solvePuzzle();

		  if(puzzle_solved1)
		  {
			  cout << "\n---------------------------\n";
			  cout << "Puzzle is solved.\n";
			  cout << "---------------------------\n\n";
		  }
		  else
		  {
			  cout << "\n---------------------------\n";
			  cout << "Puzzle is not solved.\n";
			  cout << "---------------------------\n\n";
		  }//end if
      }//end while
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }//end try-catch

   //Board 2
   try
   {
      board b2(SquareSize);				   //Board declaration

      while (fin2 && fin2.peek() != 'Z')   //The character z terminates a puzzle file
      {
			
		  b2.initialize(fin2);			   //Initialize board
		  b2.printBoard();				   //Print out the board values
		  b2.printConflicts();			   //Print out the row, column, and square conflict vectors

		  //Determine if the puzzle is solved, and print out the result.
		  puzzle_solved2 = b2.solvePuzzle();
	  
		  if(puzzle_solved2)
		  {
			  cout << "\n---------------------------\n";
			  cout << "Puzzle is solved.\n";
			  cout << "---------------------------\n\n";
		  }
		  else
		  {
			  cout << "\n---------------------------\n";
			  cout << "Puzzle is not solved.\n";
			  cout << "---------------------------\n\n";
		  }//end if
      }//end while
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }//end try-catch

   //Board 3
   try
   {
      board b3(SquareSize);				   //Board declaration

      while (fin3 && fin3.peek() != 'Z')   //The character z terminates a puzzle file
      {
			
		  b3.initialize(fin3);			   //Initialize board
		  b3.printBoard();				   //Print out the board values
		  b3.printConflicts();			   //Print out the row, column, and square conflict vectors

		  //Determine if the puzzle is solved, and print out the result.
		  puzzle_solved3 = b3.solvePuzzle();

		  if(puzzle_solved3)
		  {
			  cout << "\n---------------------------\n";
			  cout << "Puzzle is solved.\n";
			  cout << "---------------------------\n\n";
			  b3.printBoard();
		  }
		  else
		  {
			  cout << "\n---------------------------\n";
			  cout << "Puzzle is not solved.\n";
			  cout << "---------------------------\n\n";
		  }//end if
      }//end while
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }//end try-catch

   //Wait for character input by user before terminating program
   cout << "Press any key to continue...";
   getch();

   return 0;
}//end main

//End of source file.


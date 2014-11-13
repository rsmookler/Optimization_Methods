// Rob Smookler, Sean Flaherty
// Project 4B

//This file contains the board class, including functions to 
//initialize, clear, or print a board, set/get functions for
//cells, boolean functions for blank cells and a solved puzzle,
//and a function to print the three conflict vectors.

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>

using namespace std;

typedef int ValueType; // The type of the value in a cell
const int Blank = -1;  // Indicates that a cell is blank
 
const int SquareSize = 3;  //  The number of cells in a small square
                           //  (usually 3).  The board has
                           //  SquareSize^2 rows and SquareSize^2
                           //  columns.

const int BoardSize = SquareSize * SquareSize;

const int MinValue = 1;
const int MaxValue = 9;

int numSolutions = 0;

class board
// Stores the entire Sudoku board
{
   public:
      board(int);						     //Constructor
      void clear();						     //Clear board
	  void clearCell(int i, int j, int val); //Clear a cell
      void initialize(ifstream &fin);        //Initialize a board
	  void  setCell(int i, int j, int val);  //Set cell value
	  ValueType getCell(int, int);			 //Return cell value
      void printBoard();			    	 //Print out the board values
	  void printConflicts();		     	 //Print out conflict vectors
      bool isBlank(int, int);			     //Determine if a cell is blank
	  bool isSolved();						 //Determine if board is solved
	  bool solvePuzzle();
      
   private:

      // The following matrices go from 1 to BoardSize in each
      // dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)

      matrix<ValueType> value;				 //Board values
	  matrix<bool> conf_rows;				 //Row conflicts
	  matrix<bool> conf_cols;				 //Column conflicts
	  matrix<bool> conf_squares;			 //Square conflicts
};

board::board(int sqSize)
   : value(BoardSize+1,BoardSize+1)
// Board constructor
{
   clear();
}//end constructor

void board::clear()
// Mark all possible values as legal for each board entry
{
   for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++)
      {
         value[i][j] = Blank;
      }
}//end clear

int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
   // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
   // coordinates of the square that i,j is in.  

   return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
}//end squareNumber

void board::clearCell(int i, int j, int val)
{
	value[i][j] = Blank;
	conf_rows[i][val] = false;
	conf_cols[j][val] = false;
	conf_squares[squareNumber(i,j)][val] = false;
}

void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
   char ch;
   clear();

   conf_rows.resize(BoardSize+1, BoardSize+1);
   conf_cols.resize(BoardSize+1, BoardSize+1);
   conf_squares.resize(BoardSize+1, BoardSize+1);

   for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++)
	    {
	       fin >> ch;
		   int val = ch-'0';

          // If the read char is not Blank
	      if (ch != '.')
             setCell(i,j, val);   // Convert char to int
        }	  
}//end initialize

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
   for (int i = 0; i < v.size(); i++)
   {
      ostr << v[i] << " ";
   }//end for
   return ostr;
}//end output operator

void  board::setCell(int i, int j, int val)
//Stores the digit with value 'val' in
//cell {i,j} of the board. Entry 'val' in
//row i, column j, and square k conflict vectors
//is changed to be true.
{
	//Store value
	value[i][j] = val;
	
	//Update conflict vectors
	conf_rows[i][val] = true;
	conf_cols[j][val] = true;
	conf_squares[squareNumber(i,j)][val] = true; 
}//end setCell

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
{
   if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
   {
      return value[i][j];
   }
   else
   {
      throw rangeError("bad value in getCell");
   }//end if
}//end getCell

bool board::isBlank(int i, int j)
//Returns true if cell i,j is blank, and false otherwise.
{
   if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
   {
      throw rangeError("bad value in setCell");
   }//end if
   return (getCell(i,j) == Blank);
}//end isBlank

bool board::isSolved()
//Returns true if every cell in the puzzle is filled,
//and false otherwise. 
{
	for(int i = 1; i <= 9; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			if (value[i][j] == Blank)
			{
				return false;
			}//end if
		}//end inner for
	}//end outer for
	return true;
}//end isSolved

bool board::solvePuzzle()
{
	this->printBoard();
    // If there is no unassigned location, we are done
    if (isSolved())
	{
       return true; // success!
	}
	else
	{
	for(int i = 1; i <= BoardSize; i++)
	{
		for(int j = 1; j <= BoardSize; j++)
		{
			if(isBlank(i,j))
			{
				
				for(int x = 1; x <= 9; x++)
				{
					if(conf_rows[i][x] == false && conf_cols[j][x] == false && conf_squares[squareNumber(i,j)][x] == false)
					{
						
						setCell(i,j, x);
						if(this->solvePuzzle())
						{
							return true;
						}
						clearCell(i, j, x);
						
					}
				}
			}
		
		}
	}
	}
	return false;
}

void board::printBoard()
// Prints the current board.
{
   for (int i = 1; i <= BoardSize; i++)
   {
      if ((i-1) % SquareSize == 0)
      {
         cout << " -";
	 for (int j = 1; j <= BoardSize; j++)
	    cout << "---";
         cout << "-";
	 cout << endl;
      }
      for (int j = 1; j <= BoardSize; j++)
      {
	 if ((j-1) % SquareSize == 0)
	    cout << "|";
	 if (!isBlank(i,j))
	    cout << " " << getCell(i,j) << " ";
	 else
	    cout << "   ";
      }
      cout << "|";
      cout << endl;
   }

   cout << " -";
   for (int j = 1; j <= BoardSize; j++)
      cout << "---";
   cout << "-";
   cout << endl;
}//end printBoard

void board::printConflicts()
//Prints out the row, column, and square conflict
//vectors for the board.
{
	//Print row conflicts
	cout << "---------------------------\n";
	cout << "Row Conflicts:\n";
	cout << "---------------------------\n";

	for(int i = 1; i <= 9; i++)
	{
		cout << "Row " << i << ":    ";

		for(int j = 1; j <= 9; j++)
		{
			cout << conf_rows[i][j] << " ";
		}//end for
		cout << "\n\n";
	}//end for

	//Print column conflicts
	cout << "---------------------------\n";
	cout << "Column Conflicts:\n";
	cout << "---------------------------\n";
	for(int i = 1; i <= 9; i++)
	{
		cout << "Column " << i << ": ";

		for(int j = 1; j <= 9; j++)
		{
			cout << conf_cols[i][j] << " ";
		}//end for
		cout << "\n\n";
	}//end for

	//Print square conflicts
	cout << "---------------------------\n";
	cout << "Square Conflicts:\n";
	cout << "---------------------------\n";
	for(int i = 1; i <= 9; i++)
	{
		cout << "Square " << i << ": ";

		for(int j = 1; j <= 9; j++)
		{
			cout << conf_squares[i][j] << " ";
		}//end for
		cout << "\n\n";
	}//end for
}//end printConflicts

//End of header file.

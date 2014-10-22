// Rob Smookler, Sean Flaherty
// Project 3A

//This file contains the class declaration for grid,
//as well as its constructor and get functions.

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "d_matrix.h"

class grid
{
public:
	grid(const string& fileName);     //Constructor
	matrix<char> getMatrix();         //Return matrix
private:
	matrix<char> mat;				  //Matrix of characters
};

grid::grid(const string& fileName)
//Constructor that opens an input file stream for a grid file,
//reads in the number of rows and columns, resizes the matrix 
//accordingly, and then fills it with the character values.
{
	//Create an input file stream from the given filename
	ifstream fin;
	fin.open(fileName.c_str());
	
	//Variables to hold the read-in values for matrix size
	int rows, cols;

	//Read in the first two values from the file, and resize the matrix
	fin >> rows >> cols;
	mat.resize(rows, cols);

	//While the file is not empty, read in the characters for each row and column
	while(!fin.eof())
	{

		for(int i = 0; i < rows; i++)
		{

			for (int j = 0; j < cols; j++)
			{
				fin >> mat[i][j];
			}//end inner for
		}//end outer for
	}//end for
}//end constructor

matrix<char> grid::getMatrix()
//Returns the matrix of characters.
{
	return mat;
}


//End of header file.

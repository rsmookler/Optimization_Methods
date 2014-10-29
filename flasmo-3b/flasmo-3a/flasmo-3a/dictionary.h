// Rob Smookler, Sean Flaherty
// Project 3A

//This file contains the class declaration for dictionary,
//as well as its constructor, get functions, and th
//checkDictionary function.

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class dictionary
{
public:
	dictionary(const string& fileName);		      //Constructor
	vector<string> getWords();				      //Return words vector
	void checkDictionarySequential(string candidateString); //Check dictionary for string, sequential search
	bool checkDictionaryBinary(string target, int first, int last); //Check dictionary for string, binary search
	void dQuickSort(int left, int right);												//Quick sort for dictionary
	void dSelectionSort();											//Selection sort for dictionary
	void printDictionary();
private:
	vector<string> words;						  //List of words
};

dictionary::dictionary(const string& fileName)
//Constructor that opens the file with the filename
//sent to it. For each word in the file, it will push
//the word into the words vector.
{
	//Create an input file stream from the given filename
	ifstream fin;
	fin.open(fileName.c_str());

	//Variable to hold each word read from the file
	string read_word;

	//While the file is not empty, read a single word and store it in the vector
	while(!fin.eof())
	{
		fin >> read_word;
		transform(read_word.begin(), read_word.end(), read_word.begin(), ::tolower);
		words.push_back(read_word);
	}//end while
}//end dictionary constructor

vector<string> dictionary::getWords()
//Returns the vector containing the list of words.
{
	return words;
}//end getWords

void dictionary::checkDictionarySequential(string candidateString)
//Iterates through the list of words to attempt to 
//find a match for the candidate string. If a match is found,
//the word is printed, and the dictionary is exited.
{
	for(int k = 0; k < words.size(); k++)
	{

		//If a match is found, print out the word and exit for-loop
		if (candidateString == words[k]) 
		{
			cout << words[k] << "\n";
			break;
		}//end if
	}//end for
}//end checkDictionary


bool dictionary::checkDictionaryBinary(string target, int first, int last)
{
	int mid;
    while (last >= first)
    {
      mid = (first + last) / 2;

      if(words[mid] == target)
	  {
          return true; 
	  }
      else if (words[mid] < target)
	  {
          first = mid + 1;
	  }
      else 
	  {
		  last = mid - 1;
	  }//end if
    }//end while
	return false;
}

void dictionary::dQuickSort(int left, int right)
{
      int i = left, j = right;
      string tmp;
      string pivot = words[(left + right) / 2];
 
      while (i <= j) {
            while (words[i] < pivot)
                  i++;
            while (words[j] > pivot)
                  j--;
            if (i <= j) 
			{
                  tmp = words[i];
                  words[i] = words[j];
                  words[j] = tmp;
                  i++;
                  j--;
            }
      }
      if (left < j)
            dQuickSort(left, j);
      if (i < right)
            dQuickSort(i, right);
}//end dQuickSort

void dictionary::dSelectionSort() 
{
	  int min;
	  string temp;
      for(int i = 0; i < words.size() - 1; i++)
	  {
		  min = i;

		  for(int j = i + 1; j < words.size(); j++)
		  {

			  if(words[j] < words[min])
			  {
				  min = j;
			  }//end if
		  }//end for

		  if(min != i)
		  {
			  temp = words[i];
			  words[i] = words[min];
			  words[min] = temp;
		  }//end if
	  }//end for
}//end dSelectionSort

void dictionary::printDictionary()
{
	for(int i = 0; i < words.size(); i++)
	{
		cout << words[i] << "\n";
	}
}


//End of header file.
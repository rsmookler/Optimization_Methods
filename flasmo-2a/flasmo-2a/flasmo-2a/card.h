// Rob Smookler, Sean Flaherty
// Project 2A

//This file contains the class declaration for card,
//as well as its constructor, set/get functions, 
//and a print operator that prints value and suit.

#include <iostream>
using namespace std;

class card
{
public:
	card(int v, char s);								  //Constructor
	void setValue(int v);							      //Set value of card
	void setSuit(char s);								  //Set suit of card
    int getValue();										  //Return value of card
	char getSuit();							              //Return suit of card
	friend ostream& operator <<(ostream& ostr, card& c);  //Print value and suit of card

private:
	int value;	//Card value: 1-13
	char suit;  //Card suit: C(Club), D(Diamond), H(Heart), S(Spade)
};

card::card(int v, char s)
//Constructor that calls setValue and setSuit for the values
//sent as arguments. The card is created with these values.
{
	setValue(v);
	setSuit(s);
}//end card

void card:: setValue(int v)
//Changes the value of a card to the value sent
//as an argument.
{
	value = v;
}//end setValue

void card:: setSuit(char s)
//Changes the suit of a card to the character sent
//as an argument.
{
	suit = s;
}//end setSuit

int card:: getValue()
//Returns the value of a card as an integer.
{
	return value;
}//end getValue

char card:: getSuit()
//Returns the suit of a card as a character.
{
	return suit;
}//end getSuit

ostream& operator <<(ostream& ostr, card& c)
//For a given card, creates an output stream with its
//suit and value, and returns this stream to be printed.
{
	ostr << "Suit: " << c.getSuit() << " Value: " << c.getValue();
	return ostr;
}//end operator

//End of header file.
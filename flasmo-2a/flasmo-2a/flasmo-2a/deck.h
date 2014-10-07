// Rob Smookler, Sean Flaherty
// Project 2A

//This file contains the class declaration for deck,
//as well as its constructor (which creates a deck with
//all 52 cards in order) and a print operator that prints
//all cards in the deck.

#include "d_nodel.h"

class deck
{
public:
	deck();												  //Constructor
	friend ostream& operator << (ostream& ostr, deck& d); //Print all cards in deck

private:
	node<card>* front;								      //Pointer to first card in deck
};

deck::deck()
//Creates a deck with 52 cards. The order is as follows:
//C(1-13), D(1-13), H(1-13), S(1-13). Each card is linked
//to the next card in the deck.
{
	//Front of the deck is initially set to null
    front = NULL;

    for(int x = 4; x >= 1; x--)
    {
		//Character to hold suit of a card
        char s;

		//Switch that decides the suit of a card based on iteration of outside loop
        switch (x)
        {
        case 1:
            s = 'c';
            break;
        case 2: 
            s = 'd';
            break;
        case 3:
            s = 'h';
            break;
        case 4:
            s = 's';
            break;
        }//end switch
        
        for(int y = 13; y >= 1; y--)
        {
			//Create a card with the determined suit and value
            card c(y, s);

			//Add this card to the front of the deck and make it the new front
            node<card>* newCard = new node<card> (c, front);
            front = newCard;
        }//end for
    } //end for
} //end deck

ostream& operator << (ostream& ostr, deck& d)
//For each card in the deck, add its suit and value to an output stream.
//While the current card is linked to another, continue to iterate.
//When no cards remain, the output stream is returned to be printed.
{
	//Create a card node that starts at the front of the deck
	node<card>* curr = d.front;

	//While the current card has values, add it to the output and continue
	while(curr != NULL)
	{
		ostr << curr->nodeValue << "\n";
		curr = curr -> next;		
	}		
	return ostr;
}//end operator

//End of header file.
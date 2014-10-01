#include "d_nodel.h"

class deck
{
public:
	deck();
	friend ostream& operator << (ostream& ostr, deck& d);

private:
	node<card>* front;
};
deck::deck()
{
    front = NULL;
    for(int x = 4; x >= 1; x--)
    {
        char s;
        switch (y)
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
        }
        
        for(int y = 13; y >= 1; y--)
        {
            card c(y, s);
            node<card>* newCard = new node<card> (c, front);
            front = newCard;
        }//end for
    } //end for
} //end deck
ostream& operator << (ostream& ostr, deck& d)
{
	node<card>* curr = d.front;
	while(curr != NULL)
	{
		ostr << curr->nodeValue << "\n";
		curr = curr -> next;		
	}		
	return ostr;
}
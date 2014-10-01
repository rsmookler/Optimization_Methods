#include <iostream>

using namespace std;

class card
{
public:
	card(int v, char s);
	void setValue(int v);
	void setSuit(char s);
    int getValue();
	char getSuit();
	friend ostream& operator <<(ostream& ostr, card& c);

private:
	int value;
	char suit;
};
card::card(int v, char s)
{
	setValue(v);
	setSuit(s);
}
void card:: setValue(int v)
{
	value = v;
}
void card:: setSuit(char s)
{
	suit = s;
}
int card:: getValue()
{
	return value;
}
char card:: getSuit()
{
	return suit;
}
ostream& operator <<(ostream& ostr, card& c)
{
	ostr << "Suit: " << c.getSuit() << " Value: " << c.getValue();
	return ostr;
}


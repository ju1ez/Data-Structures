#include <iostream>
using namespace std;
//structure for the cards deck..
struct CardDeck
{
//varaible declaration for loop..
	char c_suit;
	int c_rank;
};
//class for card deck..
class deckOfCards
{
public:
	deckOfCards();
	void prntdck();
private:
//array for the cards..
	CardDeck cad[52];
};

//constructor for rank and suit..
deckOfCards::deckOfCards()
{
	for (int i=0; i < 52; i++)
	{
		if (i <= 13)
		{   //club
			cad[i].c_suit = 'C';
			cad[i].c_rank = i;
		}
		else if (i <= 26)
		{
			//diamond
			cad[i].c_suit = 'D';
			cad[i].c_rank = i;
		}
		else if (i <= 39)
		{
			//heart
			cad[i].c_suit = 'H';
			cad[i].c_rank = i;
		}
		else if (i <= 52)
		{
			//spade
			cad[i].c_suit = 'S';
			cad[i].c_rank = i;
		}
	}
}
//void constrc for print rank and suit.. not nessessarly needed, method of staying organized
void deckOfCards::prntdck()
{
	for (int i = 0; i < 52; i++)
	{
		cout << endl << cad[i].c_rank;
		cout << " " << cad[i].c_suit << endl;
	}
}

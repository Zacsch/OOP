#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>

using namespace std;

class deck
{
	public:
		deck();
		string build(int Number_Of_Decks); //create the deck based on the number of decks desired
		void draw(); //remove card from deck
		~deck();
};

#endif

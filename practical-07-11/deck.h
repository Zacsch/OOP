#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

class deck
{
	public:
		deck();
		deck(int numberOfDecks);
		void build(int numberOfDecks); //create and shuffles the deck based on the number of decks desired
		card draw(); //remove card from deck
		int *dock;
		~deck();
};

#endif

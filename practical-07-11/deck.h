#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>

using namespace std;

class deck
{
private:
	string deck;	//string storing the deck
public:
	deck();
	void build(int Number_Of_Decks); //create and shuffles the deck based on the number of decks desired
	void draw(); //remove card from deck
	~deck();
};

#endif

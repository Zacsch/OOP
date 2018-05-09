#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class card
{
private:
	int suit; //card suit
	int number; //card number associated with type
	int value; //card value
	string type; //card type
public:
	card();
	card(int suit, int number); //card constructor

	int get_number();
	int get_value();
	string get_suit();

	~card();
};

#endif

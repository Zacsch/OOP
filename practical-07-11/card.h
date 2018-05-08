#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class card
{
private:
	string suit(); //card suit
	int value(); //card value
public:
	card();
	void suit(ins_suit); //designate a suit to card
	void value(ins_value); //designate a value to card
	~card();
};

#endif

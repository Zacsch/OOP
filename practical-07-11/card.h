#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class card
{
	public:
		card();
		string suit(); //designate a suit to each card
		int value(); //designate a value to each card
		~card();
};

#endif

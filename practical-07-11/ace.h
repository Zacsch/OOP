#ifndef ACE_H
#define ACE_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

class ace: public card
{
	public:
		ace();
		int ace_score(int score); //determine the score of aces
		~ace();
};

#endif

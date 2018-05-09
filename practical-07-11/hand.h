#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>

using namespace std;

class hand
{
	public:
		hand();
		void add(card cardToAdd); //add the card to the hand
		int score(); //obtain the score of the hand
		~hand();
};

#endif

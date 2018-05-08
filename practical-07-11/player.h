#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "player_setup.h"

using namespace std;

class player: public player_setup
{
	public:
		player();
		bool bust(int score); //check to see if player has gone bust
		bool winner_winner_chicken_dinner(int score) //check to see if player has blackjack with initial hand
		int dealer_swap(); //changes the dealer
		void hit_me(); //take a card from the deck
		int sit(); //finish turn and go to next player
		void show(); //show the results of the game
		~player();
};

#endif

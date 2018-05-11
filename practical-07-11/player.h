#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "card.h"
//#include "player_setup.h"

using namespace std;

class player
{
	public:
		player(int numberOfThePlayer, string nameOfPlayer);
		bool bust(int score); //check to see if player has gone bust
		bool winner_winner_chicken_dinner(int score); //check to see if player has blackjack with initial hand
		int dealer_swap(int dealer); //changes the dealer
		int hit_me(); //take a card from the deck
		void sit(); //finish turn and go to next player
		void show(); //show the results of the game
		int score(); //returns the value of the hand

		void winner(int bestScore, int numberOfPlayers);

		virtual int action(int dealer)=0;

		int playerNumber;
		string playerName;
		int playerType;
		int handSize;

		player *players;

		~player();
};

#endif

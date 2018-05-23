#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "card.h"
//#include "deck.cpp"
//#include "player_setup.h"

using namespace std;

class player
{
	public:
		player();
		player(int numberOfThePlayer, string nameOfPlayer, int numberOfDecks, card* deck);
		void bust(string playerName); //check to see if player has gone bust
		bool winner_winner_chicken_dinner(); //check to see if player has blackjack with initial hand
		void hit_me(int numberOfDecks, card* deck, card* hand); //take a card from the deck
		void sit(); //finish turn and go to next player
		void show(); //show the results of the game
		void winner(int dealer); //determine and show the winner
		int score(); //returns the value of the hand
		bool player_type(bool playerType); //return player type
		string get_name(); //return the player name
		int player_number(); //return the player number
		void reset_hand(int numberOfDecks, card* deck); //reset the hand


		int winner();

		virtual int action(int numberOfDecks, card* deck)=0;

		int playerNumber;
		string playerName;
		int handSize;

		player *players;
		card *hand;

		~player();
};

#endif

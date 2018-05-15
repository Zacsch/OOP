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
		void bust(int score, string playerName); //check to see if player has gone bust
		bool winner_winner_chicken_dinner(int score); //check to see if player has blackjack with initial hand
		int dealer_swap(int dealer); //changes the dealer
		void hit_me(int numberOfDecks, card* deck, card* hand); //take a card from the deck
		void sit(); //finish turn and go to next player
		void show(); //show the results of the game
		void winner(int dealer); //determine and show the winner
		int score(card* hand); //returns the value of the hand
		bool player_type(bool playerType); //return player type
		int player_number(); //return the player number


		void winner(int bestScore, int numberOfPlayers);

		virtual int action(int currentPlayer, string playerName, int numberOfDecks, card* deck, card* hand)=0;

		int playerNumber;
		string playerName;
		bool playerType;
		int handSize;

		player *players;
		card *hand;

		~player();
};

#endif

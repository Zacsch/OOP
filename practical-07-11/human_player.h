#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class human_player: public player
{
	public:
		human_player();
		human_player(int numberOfThePlayer, string nameOfPlayer, int numberOfDecks, card* deck);
		virtual int action(int currentPlayer, string playerName, int numberOfDecks, card* deck, card* hand);
		~human_player();
};

#endif

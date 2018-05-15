#ifndef COMP_PLAYER_H
#define COMP_PLAYER_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class comp_player: public player
{
	public:
		comp_player();
		comp_player(int numberOfThePlayer, string nameOfPlayer, int numberOfDecks, card* deck);
		virtual int action(int currentPlayer, string playerName, int numberOfDecks, card* deck, card* hand);
		~comp_player();
};

#endif

#ifndef COMP_PLAYER_H
#define COMP_PLAYER_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class comp_player: public player
{
	public:
		comp_player(int numberOfThePlayer, string nameOfPlayer);
		int action(int dealer);
		~comp_player();
};

#endif

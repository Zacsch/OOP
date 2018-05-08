#ifndef COMP_PLAYER_H
#define COMP_PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class comp_player: public player
{
	public:
		comp_player();
		bool should_I_hit(int score); //check to see if a card should be taken from deck, else miss
		~comp_player();
};

#endif

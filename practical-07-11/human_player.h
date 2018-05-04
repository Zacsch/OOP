#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class human_player: public player
{
	public:
		human_player();
		void action(); //determine the action taken by player
		~human_player();
};

#endif

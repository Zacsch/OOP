#ifndef PLAYER_SETUP_H
#define PLAYER_SETUP_H

#include <iostream>
#include <string>

using namespace std;

class player_setup
{
	public:
		player_setup();
		void player_type(); //determine if player is human or computer
		string player_name(); //input name for each player
		~player_setup();
};

#endif

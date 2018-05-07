#include <iostream>
#include <string>
#include "human_player.h"

using namespace std;

human_player::human_player()
{

}

int human_player::action()
{
	//get key press
	
	if (/*input*/==' ')
	{
		int player=human_player::sit(/*numberOfPlayers*/,/*dealer*/);
	}
	else if (/*input*/=='')
	{
		human_player::hit_me(/*playerNumber*/);
	}
	else
	{
		cout << "that is not a valid option!" << endl;
	}
	
	return player;
}

human_player::~human_player()
{
}

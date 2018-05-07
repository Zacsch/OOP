#include <iostream>
#include <string>
#include "human_player.h"
#include "stdio.h"

using namespace std;

human_player::human_player()
{

}

int human_player::action() //determine the action that is taken by the person
{
	cout << "press enter to hit or space to sit" << endl;

	char input=getchar();
	
	if (input==' ')
	{
		int player=human_player::sit(/*numberOfPlayers*/,/*dealer*/); 
	}
	else if (input=='')
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

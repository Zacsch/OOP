#include <iostream>
#include <string>
#include "player_setup.h"

using namespace std;

player_setup::player_setup()
{

}

bool player_setup::player_type(int playerNumber)
{
	cout << "Enter player type for player " << (playerNumber+1) << " (c=computer player, h=human player):" << endl;
	
	bool playerIsNotSet=true; //finish function when the player has been set
	
	while (playerIsNotSet)
	{
	
		input=getchar();
	
		if (input=='c')
		{
			*(playerType+playerNumber)="computer";
      playerIsNotSet=false;
			return 0;
		}
		else if (input=='h')
		{
			*(playerType+playerNumber)="Human";
      playerIsNotSet=false;
			return 1;
		}
		else
		{
	    cout << "That is not a valid type.\nPlease enter a valid type (c=computer player, h=human player):" << endl;
		}
  }
}

void player_setup::player_name(int playerNumber)
{
	
}

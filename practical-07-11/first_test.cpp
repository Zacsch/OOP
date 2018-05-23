#include <iostream>
#include <string>
#include "game_control_test1.cpp"
using namespace std;

int main()
{
  int numberOfPlayers=set_number_of_players();
  int numberOfDecks=set_number_of_decks(numberOfPlayers);
  string playerNames[numberOfPlayers]; //array used to store the names of players
  bool playerType[numberOfPlayers]; //array used to store the type of each player. Also used for referencing player number
  for (int i=0;i<numberOfPlayers;i++)
  {
    playerNames[i]=set_player_name(i+1); //set each players name and store to an array
    playerType[i]=set_player_type(i+1); //set each players type and store to an array
  }
  return 0;
}

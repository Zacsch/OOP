#include <iostream>
#include <string>
#include <vector>
#include "comp_player.h"
#include "human_player.h"
#include "card.h"
#include "deck.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "game_control.cpp"


using namespace std;
//extern card* build_deck(int numberOfDecks);

int main() //code snippet for testing code
{
  int numberOfPlayers=set_number_of_players();
  int numberOfDecks=set_number_of_decks();
  string playerNames[numberOfPlayers];
  bool playerType[numberOfPlayers];
  for (int i=0;i<numberOfPlayers;i++)
  {
    playerNames[i]=set_player_name(i+1);
    playerType[i]=set_player_type(i+1);
  }
  card *deck=build_deck(numberOfDecks);
  int numberOfHumans=0;
  for (int i=0;i<numberOfPlayers;i++)
  {
    if (playerType[i])
    {
      numberOfHumans++;
    }
  }
  player *humanPlayers;
  humanPlayers=new human_player[numberOfHumans];
  int currentHumanToSet=0; //used to determine which human object needs to be set next
  player *compPlayers;
  compPlayers=new comp_player[numberOfPlayers-numberOfHumans];
  int currentCompToSet=0; //same as that for human
  for (int i=0;i<numberOfPlayers;i++)
  {
    if (playerType[i]) //shows true if the player type is human_player
    {
      humanPlayers[currentHumanToSet]=new human_player(i,playerNames[i],numberOfDecks,deck);
      currentHumanToSet++;
    }

  }
  int humanPlayerTurn=0; //set to the next human player to have their turn
  int compPlayerTurn=0; //set to the next computer player to have their turn
  int firstPlayer=1; //get the number that represents the first player to indicate the round is complete. This initially the sfirst player (array position 1)
  int currentPlayer=1; //get the current player number, initially it is the first player
  while (true)
  {
    do
    {
      if (playerType[currentPlayer]) //is the next player a human player?
      {
        humanPlayers[currentPlayer].action(currentPlayer, playerName, numberOfDecks, deck, hand)
      }
      else //if the player is not human then the player must be computer
      {

      }
      currentPlayer++;
      if (currentPlayer==firstPlayer)
      {
        currentPlayer=0;
      }
    } while(currentPlayer!=firstPlayer);

  }
}

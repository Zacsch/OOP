#include <iostream>
#include <string>
#include "comp_player.h"
#include "human_player.h"
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
  int numberOfPlayers=5;
  int numberOfDecks;
  bool playerType[numberOfPlayers];
  cin >> numberOfDecks;
  string playerNames[5]={"a","b","c","d","e"};
  for (int i=0; i < numberOfPlayers; i++)
  {
    cin >> playerType[i];
  }
  card *deck=build_deck(numberOfDecks); //create a deck based on the number of decks selected
  int deckSize=52*numberOfDecks; //store the size of the deck
  for (int i = 0; i < deckSize; i++)
  {
      cout << deck[i].get_suit_name() << deck[i].get_type() << ": ";
  }
  cout << endl;
  int numberOfHumans=0; //used for recording the number of human players (number of computer players is the difference between the number of players and the number of human players)
  for (int i=0;i<numberOfPlayers;i++)
  {
    cout << playerType[i] << endl;
    if (playerType[i]) //check to see if the current player is a human player
    {
      numberOfHumans++; //increase the number of human players
      cout << numberOfHumans << endl;
    }
  }
  human_player **humanPlayers=new human_player*[numberOfHumans]; //initialise class array for all human players
  int currentHumanToSet=0; //used to determine which human object needs to be set next
  comp_player **compPlayers=new comp_player*[numberOfPlayers-numberOfHumans]; //initialise class array for all computer players
  int currentCompToSet=0; //same as the other variable baove but for the computer player
  for (int i=0;i<numberOfPlayers;i++) //for loop to create all the player objects
  {
    if (playerType[i]) //shows true if the player type is human_player
    {
      humanPlayers[currentHumanToSet]=new human_player(i,playerNames[i],numberOfDecks,deck); //create a human player object and store into class array
      currentHumanToSet++; //increment to move onto next position to create a human player object
    }
    else //show false for a computer player, same as for true but with computer players instead
    {
      compPlayers[currentCompToSet]=new comp_player(i,playerNames[i],numberOfDecks,deck);
      currentCompToSet++;
    }
  }
  deckSize-=2*numberOfPlayers;
  return 0;
}

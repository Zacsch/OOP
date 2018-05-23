#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
  int choice;
  cin >> choice;
  int numberOfDecks=1;
  int numberOfPlayers;
  cin >> numberOfPlayers;
  int numberOfHumans;
  cin >> numberOfHumans;
  int firstPlayer;
  cin >> firstPlayer;
  int deckSize;
  cin >> deckSize;
  bool playerType[numberOfPlayers];
  for (int i=0; i<numberOfPlayers; i++)
  {
    cin >> playerType[i];
  }
  card* deck=new card[52];
  for (int i = 0; i < 5; i++)
  {
      deck[i].set_blank();
  }
  for (int i = 0; i < 52; i++)
  {
      cout << deck[i].get_suit_name() << deck[i].get_type() << ": ";
  }
  cout << endl;
  if (choice==3)
  {
    return 0;
  }
  else if (choice==2)
  {
    deck=build_deck(numberOfDecks);
    deckSize=52*numberOfDecks;
  }
  for (int i = 0; i < 52; i++)
  {
      cout << deck[i].get_suit_name() << deck[i].get_type() << ": ";
  }
  cout << endl;
  if (deckSize<=12*numberOfPlayers)
  {
    deck=build_deck(numberOfDecks);
    int deckSize=52*numberOfDecks;
  }
  for (int i = 0; i < 52; i++)
  {
      cout << deck[i].get_suit_name() << deck[i].get_type() << ": ";
  }
  cout << endl;
  cout << firstPlayer << endl;
  firstPlayer++; //start next round with the player who went second
  if (firstPlayer==numberOfPlayers) //used to reset the value if the player who just went first was the last player inputted
  {
    firstPlayer=0;
  }
  int currentPlayer=firstPlayer; //set the current player to start with the first player
  cout << firstPlayer << endl;
  int humanPlayerTurn=0; //reset to 0 to allow for easier resetting
  int compPlayerTurn=0; //reset to 0 to allow for easier resetting
  for (int i=0;i<firstPlayer;i++) //use for loop to determine which human player and computer player goes before everyone else by checking playerType
  {
    if(playerType[i]) //check to see if the player is human
    {
      humanPlayerTurn++; //change to the next human player
      if (humanPlayerTurn==numberOfHumans) //if humanPlayerTurn is equal to the number of players
      {
        humanPlayerTurn=0; //change to the first human player inputted
      }
    }
    else //the player must be a computer player otherwise, runs exactly as tif the if statement was true but with computer players instead
    {
      compPlayerTurn++;
      if (compPlayerTurn==numberOfPlayers-numberOfHumans)
      {
        compPlayerTurn=0;
      }
    }
    cout << humanPlayerTurn << compPlayerTurn << endl;
  }
}

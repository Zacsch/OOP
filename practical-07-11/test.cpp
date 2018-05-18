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
  clear_terminal();
  int numberOfPlayers=set_number_of_players();
  int numberOfDecks=set_number_of_decks(numberOfPlayers);
  string playerNames[numberOfPlayers];
  bool playerType[numberOfPlayers];
  for (int i=0;i<numberOfPlayers;i++)
  {
    playerNames[i]=set_player_name(i+1);
    playerType[i]=set_player_type(i+1);
    cout << playerNames[i] << i << endl;
  }
  card *deck=build_deck(numberOfDecks);
  int deckSize=52*numberOfDecks;
  int numberOfHumans=0;
  for (int i=0;i<numberOfPlayers;i++)
  {
    if (playerType[i])
    {
      numberOfHumans++;
    }
  }
  human_player **humanPlayers=new human_player*[numberOfHumans];
  int currentHumanToSet=0; //used to determine which human object needs to be set next
  comp_player **compPlayers=new comp_player*[numberOfPlayers-numberOfHumans];
  int currentCompToSet=0; //same as that for human
  for (int i=0;i<numberOfPlayers;i++)
  {
    if (playerType[i]) //shows true if the player type is human_player
    {
      humanPlayers[currentHumanToSet]=new human_player(i,playerNames[i],numberOfDecks,deck);
      currentHumanToSet++;
    }
    else
    {
      compPlayers[currentCompToSet]=new comp_player(i,playerNames[i],numberOfDecks,deck);
      currentCompToSet++;
    }
  }
  deckSize-=2*numberOfPlayers;
  int dealer=0; //set the dealer. This is initially the first player
  int humanPlayerTurn=0; //set to the next human player to have their turn
  int compPlayerTurn=0; //set to the next computer player to have their turn
  int firstPlayer=1; //get the number that represents the first player to indicate the round is complete. This is initially player 2 (array position 1)
  int currentPlayer=1; //get the current player number, initially it is player 2
  if (playerType[0])
  {
    humanPlayerTurn++;
  }
  else
  {
    compPlayerTurn++;
  }
  string turnStart; //used later for holding play until an input is placed
  while (true)
  {
    cout << currentPlayer << endl;
    bool blackjack=0; //check for instant win condition
    int handScore; //return score of hand
    for (int i=0;i<numberOfHumans;i++)
    {
        bool win=humanPlayers[i]->winner_winner_chicken_dinner();
        if (win)
        {
          blackjack=1;
        }
    }
    for (int i=0;i<(numberOfPlayers-numberOfHumans);i++)
    {
        bool win=compPlayers[i]->winner_winner_chicken_dinner();
        if (win)
        {
          blackjack=1;
        }
    }
    do
    {
      clear_terminal();
      if (blackjack)
      {
        break;
      }
      cout << playerNames[currentPlayer] << " it is your turn (type something then press enter)" << endl;
      cin >> turnStart; //random variable to hold play until an input is placed
      if (playerType[currentPlayer]) //is the next player a human player?
      {
        deckSize-=humanPlayers[humanPlayerTurn]->action(numberOfDecks, deck);
        humanPlayerTurn++;
        if (humanPlayerTurn==numberOfHumans)
        {
          humanPlayerTurn=0;
        }
        cout << humanPlayerTurn << endl;
      }
      else //if the player is not human then the player must be computer
      {
        deckSize-=compPlayers[compPlayerTurn]->action(numberOfDecks, deck);
        compPlayerTurn++;
        if (compPlayerTurn==numberOfPlayers-numberOfHumans)
        {
          compPlayerTurn=0;
        }
        cout << compPlayerTurn << endl;
      }
      currentPlayer++;
      cout << currentPlayer << endl;
      if (currentPlayer==numberOfPlayers)
      {
        currentPlayer=0;
      }
    } while(currentPlayer!=firstPlayer);
    clear_terminal();
    humanPlayerTurn=0;
    compPlayerTurn=0;
    int bestScore=0;
    for (int i=0;i<numberOfPlayers;i++)
    {
      int handScore;
      if(playerType[i])
      {
        cout << playerNames[i] << "- ";
        humanPlayers[humanPlayerTurn]->show();
        handScore=humanPlayers[humanPlayerTurn]->score();
        if ((handScore>bestScore)&&(handScore<=21))
        {
          bestScore=handScore;
        }
        humanPlayerTurn++;
      }
      else
      {
        cout << playerNames[i] << "- ";
        compPlayers[compPlayerTurn]->show();
        handScore=compPlayers[compPlayerTurn]->score();
        if ((handScore>bestScore)&&(handScore<=21))
        {
          bestScore=handScore;
        }
        compPlayerTurn++;
      }
    }
    winner(bestScore, humanPlayers, compPlayers, playerNames, playerType, numberOfPlayers);
    int choice=end_of_round_decision();
    if (choice==3)
    {
      clear_terminal();
      return 0;
    }
    else if (choice==2)
    {
      deck=build_deck(numberOfDecks);
      deckSize=52*numberOfDecks;
    }
    if (deckSize<=12*numberOfPlayers)
    {
      card *deck=build_deck(numberOfDecks);
      int deckSize=52*numberOfDecks;
    }
    firstPlayer++;
    dealer=firstPlayer-1;
    if (firstPlayer==numberOfPlayers)
    {
      firstPlayer=0;
    }
    currentPlayer=firstPlayer;
    humanPlayerTurn=0;
    compPlayerTurn=0;
    for (int i=0;i<firstPlayer;i++)
    {
      if(playerType[i])
      {
        humanPlayerTurn++;
        if (humanPlayerTurn==numberOfHumans)
        {
          humanPlayerTurn=0;
        }
      }
      else
      {
        compPlayerTurn++;
        if (compPlayerTurn==numberOfPlayers-numberOfHumans)
        {
          compPlayerTurn=0;
        }
      }
    }
    for (int i=0;i<numberOfHumans;i++)
    {
        humanPlayers[i]->reset_hand(numberOfDecks,deck);
    }
    for (int i=0;i<(numberOfPlayers-numberOfHumans);i++)
    {
        compPlayers[i]->reset_hand(numberOfDecks,deck);
    }
    deckSize-=2*numberOfPlayers;
  }
}

#include <iostream>
#include <string>
#include "comp_player.h"
#include "human_player.h"
#include "card.h"
#include "deck.h"
#include "stdio.h"
#include <unistd.h>
#include "stdlib.h"
#include "time.h"
#include "game_control.cpp"

using namespace std;

int main()
{
  clear_terminal(); //run function to clear the terminal
  int numberOfPlayers=set_number_of_players();
  int numberOfDecks=set_number_of_decks(numberOfPlayers);
  string playerNames[numberOfPlayers]; //array used to store the names of players
  bool playerType[numberOfPlayers]; //array used to store the type of each player. Also used for referencing player number
  for (int i=0;i<numberOfPlayers;i++)
  {
    playerNames[i]=set_player_name(i+1); //set each players name and store to an array
    playerType[i]=set_player_type(i+1); //set each players type and store to an array
  }
  card *deck=build_deck(numberOfDecks); //create a deck based on the number of decks selected
  int deckSize=52*numberOfDecks; //store the size of the deck
  int numberOfHumans=0; //used for recording the number of human players (number of computer players is the difference between the number of players and the number of human players)
  for (int i=0;i<numberOfPlayers;i++)
  {
    if (playerType[i]) //check to see if the current player is a human player
    {
      numberOfHumans++; //increase the number of human players
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
  int dealer=0; //set the dealer. This is initially the first player
  int humanPlayerTurn=0; //set to the next human player to have their turn
  int compPlayerTurn=0; //set to the next computer player to have their turn
  int firstPlayer=1; //get the number that represents the first player to indicate the round is complete. This is initially player 2 (array position 1)
  int currentPlayer=1; //get the current player number, initially it is player 2
  if ((playerType[0]))
  {
    humanPlayerTurn++; //if the first player inputted was human, then the second human player will be the first human player to have their turn
    if (humanPlayerTurn==numberOfHumans)
    {
      humanPlayerTurn=0;
    }
  }
  else
  {
    compPlayerTurn++; //if the first player inputted was a computer player then the second computer player will be the first computer player to have their turn
    if (compPlayerTurn==numberOfPlayers-numberOfHumans)
    {
      compPlayerTurn=0;
    }
  }
  clear_terminal();
  string turnStart; //used later for holding play until an input is placed
  while (true)
  {
    bool blackjack=0; //check for instant win condition
    int handScore; //return score of hand
    for (int i=0;i<numberOfHumans;i++) //for loop to check the hand of each human player
    {
        bool win=humanPlayers[i]->winner_winner_chicken_dinner(); //run function to check if someone has 21 and display a message if they do
        if (win) //does someone have a hand value of 21
        {
          blackjack=1; //set condition used to skip next do loop
        }
    }
    for (int i=0;i<(numberOfPlayers-numberOfHumans);i++) //same as for loop above but for computer players
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
      if (blackjack) //did someone get 21 on their starting hand
      {
        break; //skip to the end of the loop if someone has blackjack
      }
      if (playerType[currentPlayer]) //is the next player a human player?
      {
        cout << playerNames[currentPlayer] << "- it is your turn (type something (it can be anything) then press enter)" << endl;
        cin >> turnStart; //random variable to hold play until an input is placed
        deckSize-=humanPlayers[humanPlayerTurn]->action(numberOfDecks, deck); //perform the action of the human player having a turn, change the deck size based on the result of the function
        humanPlayerTurn++; //increase to call for the next human player when their turn comes around
        if (humanPlayerTurn==numberOfHumans)
        {
          humanPlayerTurn=0; //reset to 0 if the last human player was the last one inputted
        }
      }
      else //if the player is not human then the player must be computer
      {
        cout << playerNames[currentPlayer] << "- it is your turn" << endl; //display who's turn it is
        sleep(2); //wait for 2 seconds
        deckSize-=compPlayers[compPlayerTurn]->action(numberOfDecks, deck); //perform the action of the computer player having a turn, change the deck size based on the result of the function
        compPlayerTurn++; //increase to call for the next computer player when their turn comes around
        if (compPlayerTurn==numberOfPlayers-numberOfHumans)
        {
          compPlayerTurn=0; //reset to 0 if the last computer player was the last one inputted
        }
      }
      currentPlayer++; //increment to call the next player
      if (currentPlayer==numberOfPlayers)
      {
        currentPlayer=0; //reset to 0 if current player was the last player just before
      }
    } while(currentPlayer!=firstPlayer);
    clear_terminal();
    end_round(humanPlayers, compPlayers, playerNames, playerType, numberOfPlayers);
    int choice=end_of_round_decision();
    clear_terminal();
    if (choice==3)
    {
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
    firstPlayer++; //start next round with the player who went second
    dealer=firstPlayer-1;
    if (firstPlayer==numberOfPlayers) //used to reset the value if the player who just went first was the last player inputted
    {
      firstPlayer=0;
    }
    currentPlayer=firstPlayer; //set the current player to start with the first player
    humanPlayerTurn=0; //reset to 0 to allow for easier resetting
    compPlayerTurn=0; //reset to 0 to allow for easier resetting
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
    }
    for (int i=0;i<numberOfHumans;i++) //for every human player, reset their hand
    {
        humanPlayers[i]->reset_hand(numberOfDecks,deck);
    }
    for (int i=0;i<(numberOfPlayers-numberOfHumans);i++) //same as previous loop but with computer players
    {
        compPlayers[i]->reset_hand(numberOfDecks,deck);
    }
    deckSize-=2*numberOfPlayers; //change the deck size based on the number of hands reset
  }
}

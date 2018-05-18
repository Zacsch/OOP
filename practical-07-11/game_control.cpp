#include <iostream>
#include <string>
#include "comp_player.h"
#include "human_player.h"
#include "card.h"
#include <unistd.h>
#include <term.h>

using namespace std;

int set_number_of_players()
{
  int numberOfPlayers;
  bool incorrectNumberOfPlayers; //used to see if there is a valid number of players
  cout << "Enter the number of players (must be two or more players)" << endl;
  do
  {
    cin >> numberOfPlayers;
    incorrectNumberOfPlayers=cin.fail(); //check to see if the input was a valid integer
    if(incorrectNumberOfPlayers)
    {
      cin.clear(); //clear the stream
      cin.ignore(); //clear the buffer
      cout << "That is not a proper number. Please enter a number" << endl;
      numberOfPlayers=10000; //arbitrary value to stop next condition from occurring
    }
    if(numberOfPlayers<2)
    {
      cin.clear(); //clear the stream
      cin.ignore(); //clear the buffer
      cout << "There must be at least two players. Please enter a number that is two or more" << endl;
      incorrectNumberOfPlayers=1; //set condition to continue running the loop until a suitable number of players is entered
    }
  } while(incorrectNumberOfPlayers);
  cout << "There are " << numberOfPlayers << " players" << endl;
  return numberOfPlayers;
}

int set_number_of_decks(int numberOfPlayers)
{
  int numberOfDecks;
  bool incorrectNumberOfDecks; //used to see if there is a valid number of decks
  cout << "Enter the number of decks (min. of " << 1+numberOfPlayers/4 << " decks for " << numberOfPlayers << " players)" << endl;
  do
  {
    cin >> numberOfDecks;
    incorrectNumberOfDecks=cin.fail(); //check to see if the input was a valid integer
    if(incorrectNumberOfDecks)
    {
      cin.clear(); //clear the stream
      cin.ignore(); //clear the buffer
      cout << "That is not a proper number. Please enter a number" << endl;
      numberOfDecks=10000000; //arbitrary value to stop next condition from occurring
    }
    if(numberOfDecks<(1+numberOfPlayers/4))
    {
      cin.clear(); //clear the stream
      cin.ignore(); //clear the buffer
      cout << "That is too few decks. Please enter a suitable number of decks (min. of " << numberOfPlayers/4 << " decks)" << endl;
      incorrectNumberOfDecks=1; //set condition to continue running the loop until a suitable number of decks is entered
    }
  } while(incorrectNumberOfDecks);
  cout << "There are " << numberOfDecks << " decks" << endl;
  return numberOfDecks;
}

string set_player_name(int playerNumber)
{
  string name;
  cout << "Enter a name for player " << playerNumber << endl; //ask the user for a player name
  cin >> name; //set the player name
  return name;
}

bool set_player_type(int playerNumber)
{
  int known=0;
  string input;
  int type;
  cout << "What kind of player is player " << playerNumber << " (c=computer player, h=human player)" << endl;
  while (!known) //check to see if the player type is known
  {
    cin >> input;
    if (input=="c") //has the user inputted c
    {
      type=0; //set 0 for a computer player
      known=1; //indicate that the player type is known
    }
    else if (input=="h") //has the user inputted h
    {
      type=1; //set 1 for a human player
      known=1; //indicate that the player type is known
    }
    else //has the user inputted anything else
    {
      cout << "That is not a player type. Enter a valid player type (c=computer player, h=human player)" << endl; //tell the user that theey have either inputted the wrong input accidentally or that the user cannot read
    }
  }
  return type;
}

int end_of_round_decision()
{
  string input;
  int decision=0; //return the decision the players make in numerical form, with 0 representing an unmade choice
  cout << "What do you want to do now?" << endl;
  cout << "Start new round (c)" << endl;
  cout << "Restart the game (r)" << endl;
  cout << "End the game (x)" << endl;
  do
  {
    cout << "Enter your choice" << endl;
    cin >> input;
    if (input=="c")
    {
      decision=1; //continue
    }
    else if (input=="r")
    {
      decision=2; //restart
    }
    else if (input=="x")
    {
      decision=3; //exit
    }
    else
    {
      cout << "That is not a valid choice" << endl;
    }
  } while(!decision); //keep running until a decision has been made
  return decision;
}

void winner(int bestScore, human_player *humanPlayers[], comp_player *compPlayers[], string playerNames[], bool playerType[], int numberOfPlayers)
{
  int numberOfWinners=0; //record the number of players who end up with the same top score
  int humanPlayerTurn=0;
  int compPlayerTurn=0;
  string winnerNames[numberOfPlayers]={}; //to store the names of the winners
  for (int i=0;i<numberOfPlayers;i++)
  {
    int handScore; //used for collecting the score of each player
    if(playerType[i]) //true if human player, false if computer player
    {
      handScore=humanPlayers[humanPlayerTurn]->score(); //get score of a person's hand
      if (handScore==bestScore) //check if the person got the best score
      {
        winnerNames[numberOfWinners]=playerNames[i]; //record the name of anyone with the best score
        numberOfWinners++; //increase the number of winners as more people get the best score
      }
      humanPlayerTurn++; //set to check the next human player
    }
    else //fsame as true condition but with computer player instead
    {
      handScore=compPlayers[compPlayerTurn]->score();
      if (handScore==bestScore)
      {
        winnerNames[numberOfWinners]=playerNames[i];
        numberOfWinners++;
      }
      compPlayerTurn++;
    }
  }
  /*Outcomes*/
  if (numberOfWinners==0) //everyone went bust
  {
    cout << "No one wins" << endl;
  }
  else if (numberOfWinners==1) //only one person has the best score
  {
    cout << winnerNames[0] << " has won" << endl; //output the winner
  }
  else //multiple people get the best score
  {
    cout << "There is a draw between:" << endl;
    for (int i=0;i<numberOfWinners;i++) //loop to print out each player
    {
      cout << winnerNames[i] << endl; //print each name
    }
  }
}

void end_round(human_player *humanPlayers[], comp_player *compPlayers[], string playerNames[], bool playerType[], int numberOfPlayers)
{
  int humanPlayerTurn=0;
  int compPlayerTurn=0;
  int bestScore=0; //the best score obtained by anyone (defaults to 0 if everyone busts)
  for (int i=0;i<numberOfPlayers;i++) //loop to show the results for each player (in order inputted at the start of the game)
  {
    int handScore;
    if(playerType[i]) //true if human player
    {
      cout << playerNames[i] << "- "; //print player name
      humanPlayers[humanPlayerTurn]->show(); //show the hand of each person
      handScore=humanPlayers[humanPlayerTurn]->score(); //obtain the score of the person's hand
      if ((handScore>bestScore)&&(handScore<=21)) //has the previous best score been beaten without going bust
      {
        bestScore=handScore; //set the best score with the best hand tested so far
      }
      humanPlayerTurn++; //increment to check the next human player
    }
    else // same as true condition but with computer player instead
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
  winner(bestScore, humanPlayers, compPlayers, playerNames, playerType, numberOfPlayers); //output the winner(s)
}

void clear_terminal() //bit of code taken from cplusplus.com and modified for particular code
{
  if (!cur_term)
  {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) ;
  }

  putp( tigetstr( "clear" ) );
}

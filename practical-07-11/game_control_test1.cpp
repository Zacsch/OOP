#include <iostream>
#include <string>
#include <limits>

using namespace std;

int set_number_of_players()
{
  int numberOfPlayers;
  bool incorrectNumberOfPlayers; //used to see if there is a valid number of players
  cout << "Enter the number of players (must be two or more players, if a number is entered first in a combination of numbers and letters the first number will be used)" << endl;
  do
  {
    cin >> numberOfPlayers;
    incorrectNumberOfPlayers=cin.fail(); //check to see if the input was a valid integer
    if(incorrectNumberOfPlayers)
    {
      cin.clear(); //clear the stream
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the buffer, condition is needed to fully clear the buffer (else cin runs for every character typed)
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
  cin.clear(); //clear the stream
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the buffer
  return numberOfPlayers;
}

int set_number_of_decks(int numberOfPlayers) //the structure of this function is mostly similar to set_number_of_players, with the biggest difference being some coondition changes
{
  int numberOfDecks; //the value to return
  bool incorrectNumberOfDecks; //used to see if there is a valid number of decks
  cout << "Enter the number of decks (min. of " << 1+numberOfPlayers/4 << " decks for " << numberOfPlayers << " players, if a number is entered first in a combination of numbers and letters the first number will be used)" << endl;
  do
  {
    cin >> numberOfDecks;
    incorrectNumberOfDecks=cin.fail(); //check to see if the input was a valid integer
    if(incorrectNumberOfDecks)
    {
      cin.clear(); //clear the stream
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the buffer
      cout << "That is not a proper number. Please enter a number" << endl;
      numberOfDecks=10000000; //arbitrary value to stop next condition from occurring
    }
    if(numberOfDecks<(1+numberOfPlayers/4))
    {
      cin.clear(); //clear the stream
      cin.ignore(); //clear the buffer
      cout << "That is too few decks. Please enter a suitable number of decks (min. of " << 1+numberOfPlayers/4 << " decks)" << endl;
      incorrectNumberOfDecks=1; //set condition to continue running the loop until a suitable number of decks is entered
    }
  } while(incorrectNumberOfDecks);
  cout << "There are " << numberOfDecks << " decks" << endl;
  cin.clear(); //clear the stream
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the buffer
  return numberOfDecks;
}

string set_player_name(int playerNumber)
{
  string name; //name to return
  cout << "Enter a name for player " << playerNumber << endl; //ask the user for a player name
  cin >> name; //set the player name
  return name;
}

bool set_player_type(int playerNumber)
{
  bool known=0; //value used to run a while loop while the player type is unknown
  string input; //stores the input from the keyboard
  bool type; //used to return the player type. Only two outcomes are possible
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

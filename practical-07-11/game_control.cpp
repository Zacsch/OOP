#include <iostream>
#include <string>

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
    if(numberOfPlayers<1)
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
  } while(!decision);
  return decision;
}

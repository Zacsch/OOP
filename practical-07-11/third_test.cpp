#include <iostream>
#include <string>

using namespace std;

int main()
{
  int numberOfHumans;
  cin >> numberOfHumans;
  int numberOfPlayers;
  cin >> numberOfPlayers;
  string playerNames[5]={"a","b","c","d","e"};
  bool playerType[numberOfPlayers];
  for (int i=0; i<numberOfPlayers; i++)
  {
    cin >> playerType[i];
  }
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
  cout << humanPlayerTurn << compPlayerTurn << endl;
  string turnStart; //used later for holding play until an input is placed
  while (true)
  {
    bool blackjack=0; //check for instant win condition
    int win; //return score of hand
    for (int i=0;i<numberOfHumans;i++) //for loop to check the hand of each human player
    {
        cin >> win;
        if (win) //does someone have a hand value of 21
        {
          blackjack=1; //set condition used to skip next do loop
        }
        cout << win << endl;
    }
    for (int i=0;i<(numberOfPlayers-numberOfHumans);i++) //same as for loop above but for computer players
    {
        cin >> win;
        if (win)
        {
          blackjack=1;
        }
        cout << win << endl;
    }
    do
    {
      if (blackjack) //did someone get 21 on their starting hand
      {
        cout << "break due to blackjack" << endl;
        break; //skip to the end of the loop if someone has blackjack
      }
      if (playerType[currentPlayer]) //is the next player a human player?
      {
        cout << playerNames[currentPlayer] << "- it is your turn (type something (it can be anything) then press enter)" << endl;
        cin >> turnStart; //random variable to hold play until an input is placed
        humanPlayerTurn++; //increase to call for the next human player when their turn comes around
        if (humanPlayerTurn==numberOfHumans)
        {
          humanPlayerTurn=0; //reset to 0 if the last human player was the last one inputted
        }
      }
      else //if the player is not human then the player must be computer
      {
        cout << playerNames[currentPlayer] << "- it is your turn" << endl; //display who's turn it is
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
      cout << humanPlayerTurn << compPlayerTurn << currentPlayer << endl;
    } while(currentPlayer!=firstPlayer);
    return 0;
  }
}

#include <iostream>
#include <string>
#include <unistd.h>
#include "player.h"
#include "card.h"
#include "deck.h"

using namespace std;

//extern card get_random_card(int numberOfDecks, card* deck);

player::player()
{

}

player::player(int numberOfThePlayer, string nameOfPlayer, int numberOfDecks, card* deck)
{
  playerName=nameOfPlayer;
  playerNumber=numberOfThePlayer;
  hand=new card[12];
  for (int i=0;i<2;i++)
  {
    hand[i]=get_random_card(numberOfDecks,deck);
  }
  handSize=2;
}

bool player::player_type(bool playerType)
{
  return playerType;
}

int player::player_number()
{
  return playerNumber;
}

void player::hit_me(int numberOfDecks, card* deck, card* hand)
{
  cout << "'Hit Me'" << endl;
  hand[handSize]=get_random_card(numberOfDecks, deck);
}

void player::sit()
{
  cout << playerName << " has decided to sit" << endl;
}

int player::score()
{
  int score=0;
  int numberOfAces=0;
  for (int i=0;i<handSize;i++) //get score without modifying tthe score of an ace
  {
    score+=hand[i].get_value();
    if (hand[i].get_value()==11) //is the current card an ace
    {
      numberOfAces++; //increase anytime there is an ace
    }
  }
  for (int i=0; i<numberOfAces; i++)
  {
    if (score>21)
    {
      score-=10;
    }
  }
  return score;
}

void player::bust(string playerName)
{
  cout << playerName << " has gone bust" << endl;
}

bool player::winner_winner_chicken_dinner()
{
  bool win=0;
  int handScore=score();
  if (handScore==21)
  {
    cout << "Winner Winner Chicken Dinnner!" << endl;
    cout << playerName << " has 21" << endl;
    sleep(2); //pause to allow fo rthe message to be read
    win=1;
  }
  return win;
}

void player::show()
{
  cout << "|";
  for (int i=0;i<handSize;i++)
  {
    cout << hand[i].get_suit_name() << hand[i].get_type() << "|";
  }
  cout << " - " << score() << endl;
}

void player::reset_hand(int numberOfDecks, card* deck)
{
  for (int i=0;i<2;i++)
  {
    hand[i]=get_random_card(numberOfDecks,deck);
  }
  for (int i=2;i<handSize;i++)
  {
    hand[i].set_blank();
  }
  handSize=2;
}

player::~player()
{
}

#include <iostream>
#include <string>
#include "player.h"
#include "card.h"
#include "deck.h"

using namespace std;

player::player(int numberOfThePlayer, string nameOfPlayer)
{
  playerName=nameOfPlayer;
  playerNumber=numberOfThePlayer;
  card *hand=new card[12];
  for (int i=0;i<2;i++)
  {
    hand[i]=get_random_card();
  }
  handSize=2;
}

int player::hit_me()
{
  hand[handSize-1]=get_random_card();
  handSize++;
  return handSize;
}

void player::sit()
{
  cout << playerName << " has decided to sit" << endl;
}

int player::dealer_swap(int dealer)
{
  dealer++;
  return dealer;
}

int player::score()
{
  int score=0;
  for (int i=0;i<handSize;i++)
  {
    score+=hand[i]->get_value();
  }
}

player::~player()
{
}

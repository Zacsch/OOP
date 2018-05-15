#include <iostream>
#include <string>
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
  card *hand=new card[12];
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
  hand[handSize-1]=get_random_card(numberOfDecks, deck);
  handSize++;
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

int player::score(card* hand)
{
  int score=0;
  for (int i=0;i<handSize;i++)
  {
    score+=hand[i].get_value();
  }
  return score;
}

void player::bust(int score, string playerName)
{
  cout << playerName << "has gone bust" << endl;
}

player::~player()
{
}

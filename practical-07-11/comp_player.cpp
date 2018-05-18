#include <iostream>
#include <string>
#include "comp_player.h"

using namespace std;

comp_player::comp_player()
{

}

comp_player::comp_player(int numberOfThePlayer, string nameOfPlayer, int numberOfDecks, card* deck):player(numberOfThePlayer,nameOfPlayer,numberOfDecks,deck)
{
  playerType=1;
}

int comp_player::action(int numberOfDecks, card* deck)
{
  int cardsDrawn=0;
  int handScore = score();
  while (handScore<17)
  {
    hit_me(numberOfDecks, deck, hand);
    handSize++;
    cardsDrawn++;
    handScore = score();
  }
  if (handScore>21)
  {
    bust(playerName);
  }
  else
  {
    sit();
  }
  return cardsDrawn;
}

comp_player::~comp_player()
{

}

#include <iostream>
#include <string>
#include "comp_player.h"
#include <unistd.h>

using namespace std;

comp_player::comp_player()
{

}

comp_player::comp_player(int numberOfThePlayer, string nameOfPlayer, int numberOfDecks, card* deck):player(numberOfThePlayer,nameOfPlayer,numberOfDecks,deck)
{

}

int comp_player::action(int numberOfDecks, card* deck)
{
  show();  //use only for testing
  int cardsDrawn=0;
  int handScore = score();
  while (handScore<17)
  {
    hit_me(numberOfDecks, deck, hand);
    handSize++;
    cardsDrawn++;
    handScore = score();
    show();  //use only for testing
    sleep(1);
  }
  if (handScore>21)
  {
    bust(playerName);
  }
  else
  {
    sit();
  }
  string endTurn;
  sleep(2);
  return cardsDrawn;
}

comp_player::~comp_player()
{

}

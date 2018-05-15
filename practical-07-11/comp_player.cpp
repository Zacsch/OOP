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

int comp_player::action(int currentPlayer, string playerName, int numberOfDecks, card* deck, card* hand)
{
  comp_player *currentCompPlayer;
  currentCompPlayer=new comp_player();
  int score = currentCompPlayer->score(hand);
  while (score<17)
  {
    currentCompPlayer->hit_me(numberOfDecks, deck, hand);
    handSize++;
    score = currentCompPlayer->score(hand);
  }
  if (score>21)
  {
    currentCompPlayer->bust(score,playerName);
  }
  else
  {
    currentCompPlayer->sit();
  }
  delete currentCompPlayer;
}

comp_player::~comp_player()
{

}

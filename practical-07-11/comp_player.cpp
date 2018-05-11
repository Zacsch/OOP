#include <iostream>
#include <string>
#include "comp_player.h"

using namespace std;

comp_player::comp_player(int numberOfThePlayer, string nameOfPlayer):player(numberOfThePlayer,nameOfPlayer)
{
  playerType=1;
}

int comp_player::action(int dealer)
{
  int score = score();
  while (score<17)
  {
    players[playerNumber]->hit_me();
    handSize++;
    score = players[playerNumber]->score();
  }
  if (score>21)
  {
    players[playerNumber]->bust(score);
  }
  else
  {
    players[playerNumber]->sit();
  }
}

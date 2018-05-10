#include <iostream>
#include <string>
#include "comp_player.h"

using namespace std;

comp_player::comp_player(int numberOfThePlayer, string nameOfPlayer):player(numberOfThePlayer,nameOfPlayer)
{
  playerNumber=numberOfThePlayer;
  playerName=nameOfPlayer;
}

int comp_player::action(int dealer)
{
  int score = hand::score();
  while (score<17)
  {
    player::hit_me();
    score = hand::score();
  }
  if (score>21)
  {
    bust(score);
  }
  else
  {
    player::sit(playerNumber,dealer);
  }
}

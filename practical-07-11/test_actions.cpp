#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "human_player.h"
#include "comp_player.h"

using namespace std;

int main()
{
  card *deck=build_deck(1);
  int deckSize=52;
  human_player **humanPlayers = new human_player*[0];
  humanPlayers[0]=new human_player(0,"Pill",1,deck);
  comp_player **compPlayers=new comp_player*[0];
  compPlayers[0]=new comp_player(1,"Bob",1,deck);
  deckSize-=compPlayers[0]->action(1,deck); //expected result- function should end after NPC gets a score over 17, with the outcome being bust if the hand has a value of over 21 or sit if it is equal to or less than 21
  deckSize-=humanPlayers[0]->action(1,deck); //expected result- function should run until user inputs s to sit or gets a hand score of 21 (going bust) with the appropriate response showing in either case
  cout << deckSize << endl; //expected result- should be equal to 52 and the number of times both players said hit me (i.e. draws a card)
  return 0;
}

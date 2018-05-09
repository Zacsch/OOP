#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

deck::deck(int numberOfDecks)
{
  for (int i=0; i<(52*numberOfDecks);i++)
  {
    *(dock+i)=0;
  }
}

void deck::build(int numberOfDecks)
{
  for (int i=0;i<numberOfDecks;i++)
  {
    for (int j=0;j<52;j++)
    {
      dock[j] = card[j];
    }
  }
}

card deck::draw()
{
  int value;
  card *result;
  srand(time(NULL));
  do
  {
    int cardNumber=rand()%52;
    *result=dock[cardNumber];
    value=result->get_value();
  } while(value==0);

  return *result;
}

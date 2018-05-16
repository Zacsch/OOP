#include <iostream>
#include <string>
#include <vector>
#include "deck.h"
#include "card.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

using namespace std;

//function to build deck of card objects, input number of decks, returns pointer to deck
card* build_deck(int numberOfDecks)
{
  card *deck = new card[52 * numberOfDecks];
  for (int i = 0; i < numberOfDecks; i++) //number of decks
  {
    for (int j = 0; j < 4; j++) //number of suits per deck
    {
      for (int k = 0; k < 13; k++) //number of cards per suit
      {
          deck[52*i + 13*j + k].set_card(j+1, k+1); //set the card giving suit and number
      }
    }
  }
  return deck;
}

//function that returns a random card, and removes it from deck
card get_random_card(int numberOfDecks, card* deck)
{
  srand(time(NULL));
  int cardNumber;
  int result;
  card getCard;
  do
  {
      cardNumber = rand()%(52*numberOfDecks);
      getCard = deck[cardNumber];
      result = getCard.get_value();
  } while (result == 0);

  deck[cardNumber].set_blank(); //set card in deck as a blank
  return getCard;
}

int main()
{
    card* deck = build_deck(1);
    card handCard;
    for (int i = 0; i < 50; i++)
    {
        deck[i].set_blank();
    }
    handCard = get_random_card(1, deck);
    cout << handCard.get_suit_name() << handCard.get_number() << endl;
    for (int i = 0; i < 52; i++)
    {
        cout << deck[i].get_suit_name() << deck[i].get_type() << ": ";
    }
    return 0;
}

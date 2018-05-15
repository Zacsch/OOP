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
card* build_deck(int numberOfDecks) {
  card *deck = new card[52 * numberOfDecks];
  for (int i = 0; i < numberOfDecks; i++) { //number of decks
    for (int j = 0; j < 4; j++) { //number of suits per deck
      for (int k = 0; k < 13; k++) { //number of cards per suit
          deck[52*i + 13*j + k].set_card(j+1, k+1);
      }
    }
  }
  return deck;
}

//function that returns a random card, and removes it from deck
card get_random_card(int numberOfDecks, card* deck) {
  srand(time(NULL));
  int cardNumber=rand()%(52*numberOfDecks);
  card card=deck[cardNumber];
  return card;
}

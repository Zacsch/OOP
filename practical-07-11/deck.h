#ifndef DECK_H
#define DECK_H
#include "card.h"

card* build_deck(int numberOfDecks);
card get_random_card(int numberOfDecks, card* deck);

#endif

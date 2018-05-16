#include <iostream>
#include <string>
#include "card.h"

using namespace std;

//default constructor
card::card() {
  suit = 0;
  number = 0;
  value = 0;
}

//constructor setup card suit, type and value
void card::set_card(int ins_suit, int ins_number) {
  suit = ins_suit;
  number = ins_number;
  switch (number) {
    case 1:
      value = 11;
      type = "A";
      break;
    case 11:
      value = 10;
      type = "J";
      break;
    case 12:
      value = 10;
      type = "Q";
      break;
    case 13:
      value = 10;
      type = "K";
      break;
    default:
      value = number;
      type = to_string(number);
  }
  switch (suit) {
    case 1:
      suit_name = "S";
      break;
    case 2:
      suit_name = "C";
      break;
    case 3:
      suit_name = "D";
      break;
    case 4:
      suit_name = "H";
      break;
  }
}

void card::set_blank() {
    number = 0;
    suit = 0;
    value = 0;
    type = "0";
    suit_name = "0";
}

int card::get_number() {
  return number;
}

int card::get_value() {
  return value;
}

int card::get_suit() {
  return suit;
}

string card::get_suit_name() {
  return suit_name;
}

string card::get_type() {
  return type;
}

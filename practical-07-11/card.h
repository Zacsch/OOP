#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class card
{
private:
	int suit; //card suit
	int number; //card number associated with type
	int value; //card value
	string type; //card type
	string suit_name;
public:
	card();
	void set_card(int suit, int number); //card constructor

	void set_blank(); //set blank cards
	
	int get_number();
	int get_value();
	int get_suit();
	string get_type();
	string get_suit_name();

	//~card();
};

#endif

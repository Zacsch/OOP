#include <iostream>
#include <string>
#include "human_player.h"
#include "stdio.h"

using namespace std;

human_player::human_player()
{

}

human_player::human_player(int numberOfThePlayer, string nameOfPlayer, int numberOfDecks, card* deck):player(numberOfThePlayer,nameOfPlayer,numberOfDecks,deck)
{

}

int human_player::action(int numberOfDecks, card* deck) //determine the action that is taken by the person
{
	int cardsDrawn=0; //record the number of cards the player has taken from the deck
	string input; //used for receiving the user input
	int handScore=score();

	while (true) //run until an end of turn condition
	{
		show(); //allow the player to see their hand and hand score anytime
		if (handScore>21) //has the player gone bust
		{
			bust(playerName); //display bust message
			break; //end turn
		}

		cout << "press h for hit or s for sit and hit enter" << endl;
		cin >> input;

		if (input=="s")
		{
			sit(); //perform actions following a person sitting
			break; //end turn
		}
		else if (input=="h")
		{
			hit_me(numberOfDecks, deck, hand); //run function to add a card to the hand
	    handSize++; //increase hand size
			cardsDrawn++; //increase the number of cards drawn
	    handScore = score(); //check the score of the hand
		}
		else
		{
			cout << "that is not a valid option!" << endl;
		}
	}
	string endTurn;
  cout << "type something (it can be anything) then press enter to continue" << endl;
  cin >> endTurn;
	return cardsDrawn;
}

human_player::~human_player()
{
}

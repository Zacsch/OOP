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
	playerType=0;
}

int human_player::action(int numberOfDecks, card* deck) //determine the action that is taken by the person
{
	int cardsDrawn=0;
	string input;
	int handScore=score();

	while (true) //run until an end of turn condition
	{
		show();
		if (handScore>21)
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
			hit_me(numberOfDecks, deck, hand);
	    handSize++;
			cardsDrawn++;
	    handScore = score();
		}
		else
		{
			cout << "that is not a valid option!" << endl;
		}
	}
	return cardsDrawn;
}

human_player::~human_player()
{
}

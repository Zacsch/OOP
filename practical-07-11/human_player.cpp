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

int human_player::action(int currentPlayer, string playerName, int numberOfDecks, card* deck, card* hand) //determine the action that is taken by the person
{
	string input;
	human_player *currentHumanPlayer;
	currentHumanPlayer = new human_player();
	int score=currentHumanPlayer->score(hand);

	while (true) //run until an end of turn condition
	{
		if (score>21)
		{
			currentHumanPlayer->bust(score,playerName); //display bust message
			break; //end turn
		}

		cout << "press h for hit or s for sit and hit enter" << endl;
		cin >> input;

		if (input=="s")
		{
			currentHumanPlayer->sit(); //perform actions following a person sitting
			break; //end turn
		}
		else if (input=="h")
		{
			currentHumanPlayer->hit_me(numberOfDecks, deck, hand);
	    handSize++;
	    score = currentHumanPlayer->score(hand);
		}
		else
		{
			cout << "that is not a valid option!" << endl;
		}
	}
	delete currentHumanPlayer;
}

human_player::~human_player()
{
}

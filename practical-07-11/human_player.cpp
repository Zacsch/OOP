#include <iostream>
#include <string>
#include "human_player.h"
#include "stdio.h"

using namespace std;

human_player::human_player(int numberOfThePlayer,string nameOfPlayer):player(numberOfThePlayer,nameOfPlayer)
{
	playerType=0;
}

int human_player::action(int playerNumber,int handSize,card* hand,string playerName,int dealer) //determine the action that is taken by the person
{
	string input;
	int score=player::score(hand,handSize);

	while true //run until an end of turn condition
	{
		if (score>21)
		{
			bust(int score); //display bust message
			break; //end turn
		}

		cout << "press h for hit or s for sit and hit enter" << endl;
		cin >> input;

		if (input=='s')
		{
			player::sit(string playerName); //perform actions following a person sitting
			break; //end turn
		}
		else if (input=='h')
		{
			player::hit_me();
			score=player::score(hand,handSize);
		}
		else
		{
			cout << "that is not a valid option!" << endl;
		}
}

human_player::~human_player()
{
}

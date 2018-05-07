#include <iostream>
#include <string>
#include "player.h"

using namespace std;

// /*######*/ used to denote a variable whose initialisation is unknown, this should allow for easier replacement later with find and replace

player::player()
{

}

void player::hit_me(int playerNumber)
{
	//run draw function
	//add card to the player's hand
	//run bust function
}

int player::sit(int numberOfPlayers, int dealer)
{
	cout << /*playerName*/ << " sits" << endl;
	
	//if (/*player*/==dealer)
	//{
		//run functions that occur at the end of each round
		// /*player*/=player::dealer_swap(numberOfPlayers);
	//}
	
	/*player*/++; //switch to next player
	
	if (/*player*/>=numberOfPlayers)
	{
		/*player*/=0; //swithch to player 1 if /*player*/ reaches the value of the number of players
	}
	
	//run next player function
	
	return /*player*/;
}

bool player::winner_winner_chicken_dinner(int score)
{
	if (score==21)
	{
		cout << "'Winner Winner Chicken Dinner'\n" << /*playerName*/ << "has 21 on their starting hand" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

int player::dealer_swap(int numberOfPlayers)
{
	/*dealer*/++; //dealer becomes next player
	
	if (/*dealer*/>=numberOfPlayers);
	{
		/*dealer*/=0; //the dealer becomes player 1 if the value of dealer has reached the number of players
	}
	
	return /*dealer*/;
}

bool bust(int score)
{
	if (score>21)
	{
		cout << /*playerName*/ << " has gone bust" << endl;
		return 1; //return true if player has a hand with a value of more than 21
	}
	else
	{
		return 0; //return false if player hasn't gone bust
	}
}

void player::show(int numberOfPlayers)
{
	int score;
	int bestScore=0;
	
	for (int i=0; i<numberOfPlayers; i++)
	{
		score=/*hand_value*/;
		cout << /*playerName*/ << "- " << /*playerHand*/ << " - " << score << endl;
		
		if (score<=21 && bestScore<score) //does the current player have the best score so far?
		{
			bestScore=score; //update the best score so far
		}
	}
	
	player::winner(bestScore,numberOfPlayer);
}

void player::winner(int bestScore, int numberOfPlayers)
{
	int numberOfWinners=0;
	int score
	string winnerNames[];
	int winnerNumber[];
	
	for (i=0; i<numberOfPlayers; i++)
	{
		score=/*hand_score*/ //collect the score of current player
		
		if (score==bestScore)
		{
			winnerName[numberOfWinners]=/*playerName(i)*/ //store the name of anyone who gets the best score
			winnerNumber[numberOfWinners]=/*playerNumber*/
			numberOfWinners++; //add another winner
		}
	}
	
	if (numberOfWinners==0) //no winner case
	{
		cout << "No one wins" << endl; //outcome if all players bust
	}
	
	if (numberOfWinners>1) //draw case
	{
		for (int i=0; i<numberOfWinners; i++) //case where dealer draws
		{
			int winner=winnerNumber[i];
			
			if (/*dealer(winner)*/==1) //is this person the dealer?
			{
				numberOfWinners=1; //reset the number of winners if the dealer drew
				winnerName[0]=/*playerName(winner)*/ //set the name of the dealer to the first position
			}
		}	
	
		if (numberOfWinners>1) //check draw case condition again in case the dealer was not one of the drawing players
		{
			cout << "there is a draw between-\n";
			
			for (int i=0; i<numberOfWinners; i++)
			{
				cout << winnerName[i] << "	";
			}
			
			cout << endl;
		}
		
	if (numberOfWinners==1) //ultimate winner case
	{
		cout << "The winner is: " << winnerName[0] << endl;
	}
}

player::~player()
{
}

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main()
{
	player *i;
	i=new player();
	i->bust(21);
	i->winner_winner_chicken_dinner(22);
	i->show(7);
}

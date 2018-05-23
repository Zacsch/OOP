int main()
{
  card *deck=build_deck(numberOfDecks); //create a deck based on the number of decks selected
  int deckSize=52*numberOfDecks; //store the size of the deck
  int numberOfHumans=0; //used for recording the number of human players (number of computer players is the difference between the number of players and the number of human players)
  for (int i=0;i<numberOfPlayers;i++)
  {
    if (playerType[i]) //check to see if the current player is a human player
    {
      numberOfHumans++; //increase the number of human players
    }
  }
}

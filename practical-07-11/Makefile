all:
	g++ -std=c++11 deck.cpp card.cpp player.cpp comp_player.cpp human_player.cpp main.cpp -o blackjack -lncurses
	./blackjack

compile:
	g++ -std=c++11 deck.cpp card.cpp player.cpp comp_player.cpp human_player.cpp main.cpp -o blackjack -lncurses

install curses:
	sudo apt-get install libncurses5-dev

testing:
		g++ first_test.cpp -o test
		./test < input_setup.txt | diff - output_setup.txt

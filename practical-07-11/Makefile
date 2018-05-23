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

testing2:
	g++ -std=c++11 deck.cpp card.cpp player.cpp comp_player.cpp human_player.cpp second_test.cpp -o test2 -lncurses
	./test2 < input_initialise.txt | diff - output_initialise.txt

testing3:
	g++ -std=c++11 third_test.cpp -o test3
	./test3 < input_play1.txt | diff - output_play1.txt
	./test3 < input_play2.txt | diff - output_play2.txt
	./test3 < input_play3.txt | diff - output_play3.txt

testing4:
	g++ fourth_test.cpp card.cpp deck.cpp -o test4
	./test4 < input_end1.txt | diff - output_end1.txt
	./test4 < input_end2.txt | diff - output_end2.txt
	./test4 < input_end3.txt | diff - output_end3.txt

testing5:
	g++ -std=c++11 deck.cpp card.cpp player.cpp comp_player.cpp human_player.cpp test_actions.cpp -o test5
	./test5

main: main.cpp GreenCards.cpp GreenCards.hpp BlackCards.cpp BlackCards.hpp Player.cpp Player.hpp GameBoard.cpp GameBoard.hpp DeckBuilder.cpp DeckBuilder.hpp
	g++ -o main -std=c++0x main.cpp GreenCards.cpp BlackCards.cpp GameBoard.cpp Player.cpp DeckBuilder.cpp
	./main
	rm main

clean:
	rm main
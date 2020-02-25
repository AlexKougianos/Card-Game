main: main.cpp GreenCards.cpp GreenCards.hpp BlackCards.cpp BlackCards.hpp Player.cpp Player.hpp GameBoard.cpp GameBoard.hpp DeckBuilder.cpp DeckBuilder.hpp TypeConverter.cpp TypeConverter.hpp
	g++ -o main -std=c++0x main.cpp GreenCards.cpp BlackCards.cpp GameBoard.cpp Player.cpp DeckBuilder.cpp TypeConverter.cpp
	./main
	rm main

clean:
	rm main
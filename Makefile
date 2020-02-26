# main: main.cpp GreenCards.cpp BlackCards.cpp Player.cpp GameBoard.cpp DeckBuilder.cpp
# 	g++ -Ι. -std=c++0x main.cpp GreenCards.cpp BlackCards.cpp GameBoard.cpp Player.cpp DeckBuilder.cpp -o main
main:
	g++ -I. *.cpp -o main
	./main
	rm main

clean:
	rm main

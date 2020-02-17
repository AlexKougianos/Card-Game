main: main.cpp GreenCards.cpp GreenCards.hpp
	g++ -o main -std=c++0x main.cpp GreenCards.cpp
	./main
	rm main

clean:
	rm main
main: main.cpp Player.cpp Player.hpp
	g++ -o main main.cpp Player.cpp
	./main
	rm main

clean:
	rm main
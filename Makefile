main:
	g++ -std=c++0x -o main -I. *.cpp
	./main

clean:
	rm main

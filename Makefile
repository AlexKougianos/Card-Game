main:
	g++ -std=c++0x -o main -I. *.cpp
	./main
	rm main

clean:
	rm main

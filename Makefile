all:
	g++ -o bin/TicTacToe src/main.cpp src/*.o

clean:
	rm bin/TicTacToe *~ src/main.o

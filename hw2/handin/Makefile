all: tictactoe

tictactoe: tictactoe.o GameLogic.o Board.o
	g++ -std=c++11 -Wall -o $@ $^

tictactoe.o: tictactoe.cpp GameLogic.h Board.h Util.h
	g++ -c -std=c++11 -Wall -O2 -o $@ $<

GameLogic.o: GameLogic.cpp GameLogic.h Board.h Util.h
	g++ -c -std=c++11 -Wall -O2 -o $@ $<

Board.o: Board.cpp Board.h Util.h
	g++ -c -std=c++11 -Wall -O2 -o $@ $<

clean:
	rm -f tictactoe tictactoe.o GameLogic.o Board.o


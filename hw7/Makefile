all: Vector2D_main Shapes_main Deque_main

Vector2D_main: Vector2D_main.cpp Vector2D.cpp Vector2D.hpp
	g++ -std=c++11 -Wall -o $@ Vector2D_main.cpp Vector2D.cpp

Shapes_main: Shapes_main.cpp Shapes.cpp Shapes.hpp Vector2D.cpp Vector2D.hpp
	g++ -std=c++11 -Wall -o $@ Shapes_main.cpp Shapes.cpp Vector2D.cpp

Deque_main: Deque_main.cpp Deque.hpp
	g++ -std=c++11 -Wall -o $@ Deque_main.cpp

clean:
	rm -f Vector2D_main Shapes_main Deque_main

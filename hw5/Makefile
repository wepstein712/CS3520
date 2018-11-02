all: words_main

words_main: words_main.o words.o
	g++ -std=c++11 -ggdb -w -o $@ $^

%.o: %.cpp
	g++ -c -std=c++11 -ggdb -w -O0 -o $@ $<

clean:
	rm -f *.o words_main

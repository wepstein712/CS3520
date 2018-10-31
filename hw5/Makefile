all: words_main

words_main: words_main.o words.o
	g++ -std=c++11 -w -o $@ $^

%.o: %.cpp
	g++ -c -std=c++11 -w -O2 -o $@ $<

clean:
	rm -f *.o words_main

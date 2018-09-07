PROGRAMS = fizzbuzz fib sum reverse frame

all: $(PROGRAMS)

%: %.cpp
	g++ -std=c++11 $< -o $@

clean:
	rm -f $(PROGRAMS)

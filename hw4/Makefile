CPPFLAGS=
LDFLAGS=

CPPFLAGS=-ggdb -O0 -fno-inline
LDFLAGS=

#CPPFLAGS=-fprofile-arcs -ftest-coverage
#LDFLAGS=-fprofile-arcs

#CPPFLAGS=-ggdb -O0 -pg
#LDFLAGS=-pg

PROGRAMS=check compare_vector print_buffer

all: $(PROGRAMS)

$(PROGRAMS): %: %.o
	g++ $(LDFLAGS) -std=c++11 $< -o $@

%.o: %.cpp Makefile
	g++ $(CPPFLAGS) -std=c++11 -c $< -o $@

clean:
	rm -f $(PROGRAMS) *.o *.gcda *.gcno *.gcov gmon.out

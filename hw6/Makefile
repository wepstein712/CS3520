CXXTEST_HOME ?= cxxtest-4.4
CXXTEST_GEN = $(CXXTEST_HOME)/bin/cxxtestgen
CXXTEST_INCLUDE = $(CXXTEST_HOME)


all: runner

runner: IntArray.o IntArrayAlgorithms.o IntArray.cxxtest.o IntArrayAlgorithms.cxxtest.o runner.o
	g++ -fprofile-arcs -std=c++11 $^ -I$(CXXTEST_INCLUDE) -o $@

%.o: %.cpp *.hpp
	g++  -fprofile-arcs -ftest-coverage -c -std=c++11 $< -I$(CXXTEST_INCLUDE) -o $@

%.cxxtest.cpp: %.cxxtest.hpp
	$(CXXTEST_GEN) --part --error-printer $< -o $@

runner.cpp:
	$(CXXTEST_GEN) --root --error-printer -o $@

clean:
	rm -f runner runner.cpp *.o *.cxxtest.cpp

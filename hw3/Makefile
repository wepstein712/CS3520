PROGRAMS = Arith Assign Choose Compute Countdown Ending Example Multiply Negative Odd OddEven

JAVA_PROGRAMS = Arith.class Assign.class Choose.class Compute.class Countdown.class Ending.class Multiply.class Negative.class Odd.class OddEven.class

all: $(PROGRAMS)

java: $(JAVA_PROGRAMS)

%: %.cpp
	g++ -std=c++11 -w $< -o $@

%.class: %.java
	-javac $<

clean:
	rm -f $(PROGRAMS) $(JAVA_PROGRAMS)

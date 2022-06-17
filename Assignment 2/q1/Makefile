all: x

x: StkTest.o Stack.o 
	g++ -Wall -o x StkTest.o Stack.o

StkTest.o: StkTest.cpp Stack.h 
	g++ -Wall -c StkTest.cpp

Stack.o: Stack.h Stack.cpp
	g++ -Wall -c Stack.cpp

clean:
	rm -f x *.o
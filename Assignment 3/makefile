all: x

x: main.o a3.o
	g++ -Wall -o x main.o a3.o

main.o: main.cpp a3.h
	g++ -Wall -c main.cpp

clean:
	rm -f x *.o
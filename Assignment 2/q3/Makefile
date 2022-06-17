
infixeval:	Scanner.o eval.o
	g++ -std=c++0x -o infixeval Scanner.o eval.o

Scanner.o:	Scanner.cpp Scanner.h
	g++ -std=c++0x -c Scanner.cpp
	
eval.o:	eval.cpp Scanner.h Stack.h
	g++ -std=c++0x -c eval.cpp
	
clean:	
	rm -f *.o infixeval


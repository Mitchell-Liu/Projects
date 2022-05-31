all: x

x: a1main.o Song.o PlayList.o
	g++ -Wall -o a1main.o Song.o PlayList.o

a1main.o: a1main.cpp Song.h PlayList.h
	g++ -Wall -c a1main.cpp

Song.o: Song.h Song.cpp	
	g++ -Wall -c Song.cpp

PlayList.o: PlayList.h PlayList.cpp
	g++ -Wall -c PlayList.cpp

clean:
	rm -f x *.o
LIBS = -lsfml-window -lsfml-graphics -lsfml-system

all: run

run: Game-Of-Life
	./Game-Of-Life

Cell.o: lib/Cell.cpp
	g++ -std=c++11 -c "lib/Cell.cpp" -o Cell.o

Grid.o: lib/Grid.cpp
	g++ -std=c++11 -c "lib/Grid.cpp" -o Grid.o 

main.o: main.cpp
	g++ -c "main.cpp" -o main.o -fopenmp

Game-Of-Life: main.o Grid.o Cell.o
	g++ -g -Wall -o Game-Of-Life main.o Cell.o Grid.o -lm $(LIBS) -fopenmp

clean:
	rm -f *.o
	rm -f Game-Of-Life
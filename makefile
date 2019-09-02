LIBS = -lsfml-window -lsfml-graphics -lsfml-system

all: run

run: Game-Of-Life
	./Game-Of-Life

Grid.o: lib/Grid.cpp
	g++ -std=c++11 -c "lib/Grid.cpp" -o Grid.o -fopenmp

main.o: main.cpp
	g++ -c "main.cpp" -o main.o

Game-Of-Life: main.o Grid.o
	g++ -g -Wall -o Game-Of-Life main.o Grid.o -lm $(LIBS) -fopenmp

clean:
	rm -f *.o
	rm -f Game-Of-Life

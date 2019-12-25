CC = g++
CFLAGS = -std=c++11 -g -Og -Wall -Werror -pedantic
OBJ = main.o PTree.o
EXE = Pythagoras
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm $(OBJ) $(EXE)
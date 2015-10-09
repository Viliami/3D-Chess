FLAGS = -lGL -lGLU -lglut -lGLEW -lassimp -lSOIL -w -std=c++11
PROG_NAME = test

all:
	g++ main.cpp pieces.cpp textfile.cpp $(FLAGS) -o $(PROG_NAME) 

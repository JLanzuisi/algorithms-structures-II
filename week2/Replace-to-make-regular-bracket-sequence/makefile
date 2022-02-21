CC = g++
CFLAGS = -Wall -Wpedantic -Wextra
CFILE = main-custom-stack

all: $(CFILE).cpp
	g++ $(CFLAGS) $(CFILE).cpp -o $(CFILE).out

run: all
	./$(CFILE).out

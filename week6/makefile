CC = g++
CFLAGS = -Wall -Wpedantic -Wextra
CFILE = orders

all: $(CFILE).cpp
	g++ $(CFLAGS) $(CFILE).cpp -o $(CFILE).out

run: all
	./$(CFILE).out

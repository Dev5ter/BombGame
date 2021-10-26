CC = g++
CFLAGS = -Wall

all: BombGame

BombGame: main.cpp bomb.cpp
	$(CC) $(CFLAGS) main.cpp bomb.cpp -o BombGame

clean: 
	rm BombGame

reset:
	rm BombGame
	make all
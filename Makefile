CFLAGS = -Wall -Werror -std=c99
CC = gcc

.PHONY: clean test

all:
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/main src/main.c 
	
clean:
	rm -rf bin build

CC = gcc
CFLAGS = -Wall -Werror -std=c99

OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD = mkdir -p build/src

.PHONY: clean test

default: bin/game

bin/game: build/src/main.o build/src/field.o build/src/mainloop.o
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

build/src/main.o: src/main.c
	$(MKDIR_BUILD)
	$(OBJ)

build/src/mainloop.o: src/mainloop.c src/mainloop.h
	$(MKDIR_BUILD)
	$(OBJ)

build/src/field.o: src/field.c src/field.h
	$(MKDIR_BUILD)
	$(OBJ)

clean:
	rm -rf bin build

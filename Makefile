CC = gcc
CFLAGS = -Wall -Werror -std=c99

OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD_SRC = mkdir -p build/src
MKDIR_BUILD_TEST = mkdir -p build/test

.PHONY: clean test

default: bin/game

test: bin/test
	$<

bin/test: build/test/main.o build/test/field_test.o
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

build/test/main.o: test/main.c thirdparty/ctest.h
	$(MKDIR_BUILD_TEST)
	$(OBJ) -I thirdparty -I src

build/test/field_test.o: src/field.c src/field.h
	$(MKDIR_BUILD_TEST)
	$(OBJ)

bin/game: build/src/main.o build/src/field.o build/src/mainloop.o
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

build/src/main.o: src/main.c
	$(MKDIR_BUILD_SRC)
	$(OBJ)

build/src/mainloop.o: src/mainloop.c src/mainloop.h
	$(MKDIR_BUILD_SRC)
	$(OBJ)

build/src/field.o: src/field.c src/field.h
	$(MKDIR_BUILD_SRC)
	$(OBJ)

clean:
	rm -rf bin build

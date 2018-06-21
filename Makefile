CC = gcc
CFLAGS = -Wall -Werror -std=c11

OBJ = $(CC) -c $< -o $@ $(CFLAGS)
MKDIR_BUILD_SRC = mkdir -p build/src
MKDIR_BUILD_TEST = mkdir -p build/test

.PHONY: clean test

default: bin/game

test: bin/test
	$<

bin/test: build/test/main.o build/src/field.o build/src/menu.o build/src/mainloop.o build/src/cell.o
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

build/test/main.o: test/main.c thirdparty/ctest.h
	$(MKDIR_BUILD_TEST)
	$(OBJ) -I thirdparty -I src

bin/game: build/src/main.o build/src/field.o build/src/mainloop.o build/src/field_print.o build/src/menu.o build/src/cell.o
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

build/src/field_print.o: src/field_print.c src/field_print.h
	$(MKDIR_BUILD_SRC)
	$(OBJ)

build/src/menu.o: src/menu.c src/menu.h
	$(MKDIR_BUILD_SRC)
	$(OBJ)

build/src/cell.o: src/cell.c src/cell.h
	$(MKDIR_BUILD_SRC)
	$(OBJ)

clean:
	rm -rf bin build

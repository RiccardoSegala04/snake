CC = gcc

CFLAGS = -g -Wall
INCLUDE = include
SOURCE = src
LIBRARIES = ncurses
BIN = bin
TARGET = snake

default: build

build:
	mkdir bin
	$(CC) $(CFLAGS) -I $(INCLUDE) -c src/*.c
	$(CC) *.o -l$(LIBRARIES) -o $(TARGET)
	mv *.o $(BIN)

run:
	./$(TARGET)

clean:
	rm $(TARGET)
	rm -r $(BIN)

install:
	cp ./snake /usr/local/bin/

remove:
	rm /usr/local/bin/snake

CC = gcc

CFLAGS = -g -Wall
INCLUDE = include
SOURCE = src
LIBRARIES = ncurses
BIN = bin
TARGET = snake

default: build

build:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c src/*.c
	$(CC) *.o -l$(LIBRARIES) -o $(TARGET)
	mv *.o $(BIN)

run:
	./$(TARGET)

clean:
	rm $(TARGET)
	rm $(BIN)/*.o

install:
	if[ -f "/usr/local/bin/snake" ]
	then
	make remove
	cp ./snake /usr/local/bin/
	fi

remove:
	rm /usr/local/bin

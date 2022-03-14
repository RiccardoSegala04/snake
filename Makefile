CC = gcc

CFLAGS = -g -Wall
INCLUDE = include
SOURCE = src
LIBRARIES = ncurses
BIN = /usr/local/bin
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
	rm $(BIN)/$(TARGET)
	fi
	cp ./$(TARGET) $(BIN)

remove:
	rm $(BIN)/$(TARGET)

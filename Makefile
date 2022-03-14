CC = gcc

CFLAGS = -g -Wall
INCLUDE = include
SOURCE = src
LIBRARIES = ncurses
BIN = bin
TARGET = snake
DEST = /usr/local/bin
RM = rm

default: build

build:
	mkdir $(BIN)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c src/*.c
	$(CC) *.o -l$(LIBRARIES) -o $(TARGET)
	mv *.o $(BIN)

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)
	$(RM) -r $(BIN)

install:
	cp ./$(TARGET) $(DEST)

remove:
	$(RM) $(DEST)/$(TARGET)

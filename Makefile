all:
	gcc -I include -Wall -c src/*.c 
	gcc *.o -lncurses -o snake.out

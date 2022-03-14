#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "front.h"


int main() {

	srand(time(NULL));

	initGraphics();

	char* startOptions[] = {"Snake", "Version: 1.0", "Press any key to start!", 0};

	drawMenu(startOptions);
	getch();

	int done=0;
	while(!done) {
		int snakeLen = startGame();

		timeout(-1);

		char endsub[50];
		sprintf(endsub, "You ate %d apples", snakeLen-1);

		char* endOptions[] = {"GAME OVER", endsub, "Press Q to quit", "Press R to restart", 0};

		drawMenu(endOptions);

		int ch;
		do {
			ch = getch();
		}while(ch!='q' && ch!='Q' && ch!='r' && ch!='R');

		if(ch == 'q' || ch =='q')
			done = 1;
	}
	
	endwin();
	
	return 0;
}
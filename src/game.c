#include <ncurses.h>
#include <string.h>
#include "front.h"
#include "snake.h"
#include "game.h"

int startGame() {

	timeout(100);

	const char moveMessage[] = "Use the arrow keys to move...";

	WINDOW* messageWindow = newwin(1, COLS, 1, 0);
	mvwprintw(messageWindow, 0, COLS/2-strlen(moveMessage)/2, moveMessage);
	wrefresh(messageWindow);

	WINDOW* gameWrapper = newwin(HEIGHT+5, WIDTH+4, LINES/2-HEIGHT/2-2, COLS/2-WIDTH/2-2);
	box(gameWrapper, 0, 0);
	wrefresh(gameWrapper);

	WINDOW *wrapper = newwin(HEIGHT+2, WIDTH+2, LINES/2-HEIGHT/2-1, COLS/2-WIDTH/2-1);
	box(wrapper, 0, 0);
	wrefresh(wrapper);


	WINDOW *gw = newwin(HEIGHT, WIDTH, LINES/2-HEIGHT/2, COLS/2-WIDTH/2);

	snake s;

	int l[HEIGHT][WIDTH];

	initGame(l, &s, HEIGHT, WIDTH);

	drawGame(gw, l, 0, HEIGHT, WIDTH);
	
	int done = 0;
	do{
		int ch = getch();

		if(ch==KEY_LEFT || ch==KEY_RIGHT || ch==KEY_UP || ch==KEY_DOWN) {
			werase(messageWindow);
			wrefresh(messageWindow);
		}

		updateDirection(&s, ch);

		done = step(l, &s, HEIGHT, WIDTH);

		if(!done) {
			drawGame(gw, l, s.lenght-1, HEIGHT, WIDTH);
		}
		
	}while(!done);


	delwin(gw);
	delwin(wrapper);
	delwin(gameWrapper);
	delwin(messageWindow);

	return s.lenght;
}



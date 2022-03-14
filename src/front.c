#include "front.h"
#include "snake.h"
#include <string.h>

void drawGame(WINDOW* gw, int l[][WIDTH], int points, int rows, int cols) {

	werase(gw);

	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if(l[i][j]==APPLE) {
				wattron(gw, COLOR_PAIR(1));
				mvwprintw(gw, i, j, " ");
				wattroff(gw, COLOR_PAIR(1));
			} else if(l[i][j]>0){
				wattron(gw, COLOR_PAIR(2));
				mvwprintw(gw, i, j, " ");
				wattroff(gw, COLOR_PAIR(2));
			}
		}
	}

	char name[] = "Snake v1.0";

	mvprintw(LINES/2-HEIGHT/2+HEIGHT+1, COLS/2-WIDTH/2+WIDTH-strlen(name)-1, name);

	mvprintw(LINES/2-HEIGHT/2+HEIGHT+1, COLS/2-WIDTH/2,"Apples: %d", points);

	refresh();
	wrefresh(gw);

}

void initGraphics() {

	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

	start_color();
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(1, COLOR_WHITE, COLOR_RED);
	use_default_colors();
	
}

void drawMenu(char* options[]) {

	erase();
	refresh();

	int len = 0;
	for (int i = 0; options[i]; ++i) {
		len++;
	}


	WINDOW* mw = newwin(MENU_HEIGHT, MENU_WIDTH, LINES/2-MENU_HEIGHT/2, COLS/2-MENU_WIDTH/2);
	box(mw, 0, 0);                      

	for (int i = 0; options[i]; ++i) {
		mvwprintw(mw, MENU_HEIGHT/2-len+i*2, MENU_WIDTH/2-strlen(options[i])/2, options[i]);
	}

	refresh();
	wrefresh(mw);

	delwin(mw);
}
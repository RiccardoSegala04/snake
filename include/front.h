#ifndef FRONT_H
#define FRONT_H

#include <ncurses.h>

#define WIDTH 58
#define HEIGHT 16

#define MENU_WIDTH 46
#define MENU_HEIGHT 16

void initGraphics();
void drawGame(WINDOW* gw, int l[][WIDTH], int points, int rows, int cols);
void drawMenu(char* options[]);

#endif
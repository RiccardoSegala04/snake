#ifndef SNAKE_H
#define SNAKE_H

#define NUM_APPLES 1
#define APPLE -1

#include "front.h"

enum direction {DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_STOP};

typedef struct {
	int x, y;
}point;

typedef struct {
	enum direction dir;
	point pos;
	int lenght;
}snake;

void addApple(int l[][WIDTH], int rows, int cols);
void initGame(int l[][WIDTH], snake *s, int rows, int cols);
point* pickPosition(int rows, int cols);
int step(int l[][WIDTH], snake* s, int rows, int cols);
void updateDirection(snake* s, int ch);

#endif
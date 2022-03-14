#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include "snake.h"
#include "front.h"

void initGame(int l[][WIDTH], snake *s, int rows, int cols) {

	point* player = pickPosition(rows, cols);

	s->dir = DIR_STOP;
	s->pos.x = player->x;
	s->pos.y = player->y;
	s->lenght = 1;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			l[i][j] = 0;
		}
	}

	for (int i = 0; i < NUM_APPLES; ++i) {
		addApple(l, rows, cols);
	}

	l[s->pos.y][s->pos.x] = 1; 
}

void addApple(int l[][WIDTH], int rows, int cols) {
	point *p = 0;
	do {
		free(p);
		p = pickPosition(rows, cols);
	} while(l[p->y][p->x]);

	l[p->y][p->x] = APPLE;

	free(p);
}

point* pickPosition(int rows, int cols) {
	point* p = (point*) malloc(sizeof(point));

	p->y = rand()%rows;
	p->x = rand()%cols;

	return p;
}

void updateDirection(snake* s, int ch) {
	switch(ch) {
		case KEY_LEFT:
			if(s->dir != DIR_RIGHT)
				s->dir = DIR_LEFT;
			//timeout(100);
			break;
		case KEY_RIGHT:
			if(s->dir != DIR_LEFT)
				s->dir = DIR_RIGHT;
			//timeout(100);
			break;
		case KEY_UP:
			if(s->dir != DIR_DOWN)
				s->dir = DIR_UP;
			//timeout(170);
			break;
		case KEY_DOWN:
			if(s->dir != DIR_UP)
				s->dir = DIR_DOWN;
			//timeout(170);
			break;
	}
}

int step(int l[][WIDTH], snake* s, int rows, int cols) {

	if(s->dir != DIR_STOP) {

		int head = l[s->pos.y][s->pos.x];

		switch(s->dir) {
			case DIR_LEFT:
				s->pos.x--;
				break;
			case DIR_RIGHT:
				s->pos.x++;
				break;
			case DIR_UP:
				s->pos.y--;
				break;
			case DIR_DOWN:
				s->pos.y++;
				break;
			case DIR_STOP:
				break;
		}

		if(s->pos.x<0 || s->pos.x>=cols || s->pos.y<0 || s->pos.y>=rows)
			return 1;

		if(l[s->pos.y][s->pos.x]>0)
			return 1;


		int foundApple = 0;
		if(l[s->pos.y][s->pos.x]==APPLE) {
			addApple(l, rows, cols);
			s->lenght++;
			foundApple = 1;
		}

		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
				if(l[i][j]>0)
					l[i][j]--;
			}
		}

		l[s->pos.y][s->pos.x] = head;

		if(foundApple)
			l[s->pos.y][s->pos.x]++;

	}
	
	return 0;


}
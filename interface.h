#ifndef INTERFACE
#define INTERFACE

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "map.h"
#include "piece.h"
#include "logic.h"

/* XSTART e YSTART são usados para renicializar o cursor*/
#define XSTART 2
#define YSTART 2

void display(State *state);
void printMap(Map *map);
void printPiece(Piece *piece, int rotation, Point *p);
void printScore(int score, int x, int y);

void printMapD(Map *map);

#endif

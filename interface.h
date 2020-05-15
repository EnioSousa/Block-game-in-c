#ifndef INTERFACE
#define INTERFACE

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "map.h"
#include "piece.h"
#include "logic.h"

/* XSTART e YSTART são usados para renicializar o cursor*/
#define XSTART 0
#define YSTART 0

void display(State *state);
void printMap(Map *map);
void printPiece(Piece *piece, int rotation, Point *p);

void printMapD(Map *map);

#endif

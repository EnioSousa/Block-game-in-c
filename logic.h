#ifndef LOGIC
#define LOGIC

#include <stdio.h>
#include <stdlib.h>

#include "piece.h"
#include "map.h"

typedef struct State
{
  Point *cur, *start;

  Piece *piece;

  int rotation, gameOver;

  Map *map;
  
}State;

State *newState(Map *map);
void resetState();
Piece *randomPiece(Piece **arrPiece, int num);

int possiblePossition(Map *map, Piece *piece, int rotation, Point *p);
int outOfBound(Map *map, Point *p);

void moveLeft(State *state);
void moveRight(State *state);
int moveDown(State *state);
void rotateLeft(State *state);
void rotateRight(State *state);

void playerInput(State *state, int key);

void forceDown(State *state);

void putPiece(Map *map, Piece *piece, int rotation, Point *p);

#endif
